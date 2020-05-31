#include <QDebug>
#include <QSerialPortInfo>
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "../general/id.h"

void MainWindow::Send(uint8_t dataToSend[], const bool broadcast, uint16_t R_ID) {
	const QSerialPortInfo* PortCheck = new QSerialPortInfo(ui->CB_SerialPort->currentText());

	if (!PortCheck->isNull() && Serial->isOpen()) {

		if (R_ID == NULL)
			R_ID = ui->CB_ID->currentText().toUInt();

		dataToSend[0] = static_cast<uint8_t>((broadcast ? 0x0 : R_ID) & 0x00FF);
		dataToSend[1] |= static_cast<uint8_t>(((broadcast ? 0x0 : R_ID) & 0x0F00) >> 3);

		QByteArray Data = QByteArray::fromRawData(reinterpret_cast<const char*>(dataToSend), sizeof(dataToSend));
		Data.resize(PACKET_SIZE);

		qDebug() << "Sent to :   " << QString().setNum(((dataToSend[1] & 0xE0) << 3) | dataToSend[0]) << " Message: " <<
			ByteArrayToString(Data) << " Time: " << QDateTime::currentDateTime().toString("hh:mm:ss.zzz");

		Serial->write(Data);

	} else {
		ConnectionCheck();
	}
	
	qApp->processEvents();
}

void MainWindow::RequestData() {
	QByteArray Data = Serial->readAll();

	std::vector<unsigned char> buffer(Data.begin(), Data.end());

	qDebug() << "Taken from: " << QString().setNum(((buffer[1] & 0xE0) << 3) | buffer[0]) << " Message: " <<
		ByteArrayToString(Data) << " Time: " << QDateTime::currentDateTime().toString("hh:mm:ss.zzz");

	ProcessingReceivedData(buffer.data());

	qApp->processEvents();
}
