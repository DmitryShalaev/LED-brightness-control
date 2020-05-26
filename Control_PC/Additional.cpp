#include <QDebug>
#include <QFile>
#include <QJsonArray>
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
	QJsonDocument jDoc;

	if (!File.exists()) {
		qCritical() << "ERROR: NodeSettings.json file not found";
		return false;
	}

	if (File.open(QIODevice::ReadOnly | QFile::Text))
		jDoc = QJsonDocument::fromJson(QByteArray(File.readAll()));
	else {
		qCritical() << "ERROR: NodeSettings.json file could not be opened";
		return false;
	}

	File.close();

	ui->CB_ID->clear();
	const QJsonArray jArr = QJsonValue(jDoc.object().value("ID_OfAllNodes")).toArray();
	if (jArr.isEmpty()) {
		qCritical() << "ERROR: Syntax error in Node-Settings.json file";
		return false;
	}
	
	for (int i = 0; i < jArr.count(); i++) {
		ui->CB_ID->addItem(QString::number(jArr.at(i).toInt()));
	}

	return true;
}
