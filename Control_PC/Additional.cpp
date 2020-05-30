#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "../general/id.h"

QString MainWindow::ByteArrayToString(const QByteArray& arr) {
	QString str;
	for (int i = 0; i < PACKET_SIZE; i++)
		if (i != PACKET_SIZE - 1)
			str += QString("%1:").arg(static_cast<unsigned char>(arr[i]), 2, 16, QChar('0')).toUpper();
		else
			str += QString("%1").arg(static_cast<unsigned char>(arr[i]), 2, 16, QChar('0')).toUpper();
	return str;
}

bool MainWindow::LoadingJSONFile() {
	QFile File(QCoreApplication::applicationDirPath() + "/NodesSettings.json");

	if (!File.exists()) {
		if (File.open(QIODevice::WriteOnly)) {
			File.write("{\n\t\"ID_OfAllNodes\": [ 1, 2, 3, 4 ],\n\t\"Configurations\": [\n\t");
			File.write("\t{\n\t\t\t\"Host\": 2,\n\t\t\t\"Slaves\": [ 1, 3, 4 ]\n\t\t}\n\t]\n}");

			qDebug() << "An example configuration file \"Node Settings.json\"" <<
				"was created in the folder with the executable file";
		} else {
			qCritical() << "ERROR: Failed to create sample configuration file \"NodeSettings.json\"";
			return false;
		}
		File.close();
	}

	QJsonDocument jDoc;
	if (File.open(QIODevice::ReadOnly | QFile::Text))
		jDoc = QJsonDocument::fromJson(QByteArray(File.readAll()));
	else {
		qCritical() << "ERROR: NodeSettings.json file could not be opened";
		return false;
	}
	File.close();

	if (jDoc.isEmpty()) {
		qCritical() << "ERROR: Syntax error in Node-Settings.json file";
		return false;
	}

	HashNodesStatus->clear();
	ui->CB_ID->clear();

	jID_OfAllNodes = QJsonValue(jDoc.object().value("ID_OfAllNodes")).toArray();
	if (!jID_OfAllNodes.isEmpty()) {
		for (uint16_t i = 0; i < static_cast<uint16_t>(jID_OfAllNodes.count()); i++) {
			const uint16_t ID = jID_OfAllNodes.at(i).toInt();
			if (ID != 0) {
				if (!HashNodesStatus->contains(ID)) {
					ui->CB_ID->addItem(QString::number(jID_OfAllNodes.at(i).toInt()));
					NodeStatus Node;
					HashNodesStatus->insert(jID_OfAllNodes.at(i).toInt(), Node);
				} else {
					qWarning() << "WARNING: Duplicate node ID(" << ID << ") in \"ID_OfAllNodes\" was ignored";
				}
			} else {
				qWarning() << "WARNING: The null node ID(" << ID << ") in \"ID_OfAllNodes\" was ignored";
			}
		}
	} else {
		qCritical() << "ERROR: Syntax error in Node-Settings.json file, \"ID_OfAllNode\" field not found";
		return false;
	}

	uint16_t CountHost = 0;
	const QJsonArray jArrConf = QJsonValue(jDoc.object().value("Configurations")).toArray();
	if (!jArrConf.isEmpty()) {
		for (uint16_t i = 0; i < static_cast<uint16_t>(jArrConf.count()); i++) {
			const QJsonArray jArrConfSlave = QJsonValue(jArrConf.at(i).toObject().value("Slaves")).toArray();
			const uint16_t ConfHostID = jArrConf.at(i).toObject().value("Host").toInt();
			if (!jArrConfSlave.isEmpty()) {
				if (ConfHostID != 0) {
					NodeStatus Node;
					if (HashNodesStatus->contains(ConfHostID)) {
						Node.SlavesNodes = jArrConfSlave;
						HashNodesStatus->insert(ConfHostID, Node);
						CountHost++;
					} else {
						qWarning() << "WARNING: An error occurred in the configuration of the nodes, node" << ConfHostID <<
							"was not declared in \"ID_OfAllNodes\"";
					}
				} else {
					qWarning() << "WARNING: A node with a null identifier cannot be declared in the \"Host\"";
				}
			} else {
				qWarning() << "WARNING: The \"Slaves\" field of node" << ConfHostID << "is empty or not declared";
			}
		}
	}
	if (CountHost == 0) {
		Automatically.CanAutomatically = false;
		qWarning() << "WARNING: \"Configurations\" field is not declared or is empty, automatic control is blocked";
	} else {
		Automatically.CanAutomatically = true;
	}
	return true;
}
