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
			qCritical() << "Failed to create sample configuration file \"NodeSettings.json\"";
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

	const QJsonArray jArrID = QJsonValue(jDoc.object().value("ID_OfAllNodes")).toArray();
	if (!jArrID.isEmpty()) {
		for (uint16_t i = 0; i < static_cast<uint16_t>(jArrID.count()); i++) {
			ui->CB_ID->addItem(QString::number(jArrID.at(i).toInt()));

			NodeStatus Node;
			HashNodesStatus->insert(jArrID.at(i).toInt(), Node);
		}
	} else {
		qCritical() << "ERROR: Syntax error in Node-Settings.json file, \"ID_OfAllNode\" field not found";
		return false;
	}

	const QJsonArray jArrConf = QJsonValue(jDoc.object().value("Configurations")).toArray();
	if (!jArrConf.isEmpty()) {
		for (uint16_t i = 0; i < static_cast<uint16_t>(jArrConf.count()); i++) {
			const QJsonArray jArrConfSlave = QJsonValue(jArrConf.at(i).toObject().value("Slaves")).toArray();
			const uint16_t ConfHostID = jArrConf.at(i).toObject().value("Host").toInt();
			if (!jArrConfSlave.isEmpty()) {
				NodeStatus Node;
				Node.SlavesNodes = jArrConfSlave;
				if (HashNodesStatus->contains(ConfHostID))
					HashNodesStatus->insert(ConfHostID, Node);
				else
					qWarning() << "WARNING: An error occurred in the configuration of the nodes, node" << ConfHostID <<
						"was not declared in \"ID_OfAllNodes\"";
			} else {
				qWarning() << "WARNING: The \"Slaves\" field of node" << ConfHostID << "is empty or not declared";
			}

		}
	} else {
		qWarning() << "WARNING: \"Configurations\" field is not declared or is empty, automatic control is blocked";
	}

	return true;
}
