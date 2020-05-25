#include <QDebug>
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

uint16_t MainWindow::RecipientID() {
	const int16_t R_ID = ui->CB_ID->currentText().toInt();
	if (R_ID >= 0)
		return R_ID;
	
	ui->CB_ID->setCurrentText("0");
	return 0;
}

