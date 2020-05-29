#include <QDebug>
#include <QSerialPortInfo>
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "../general/id.h"

void MainWindow::ButtonProcessing() {
	const QString SenderName = sender()->objectName();

	const uint16_t R_ID = ui->CB_ID->currentText().toUInt();
	const uint8_t logicIO = HashNodesStatus->value(R_ID).logicIO;

	uint8_t dataToSend[PACKET_SIZE] = {0};

	if (SenderName == "L_OUT1") {
		dataToSend[1] = OUT_1;

		if ((logicIO & 0x01) == 0x01)
			dataToSend[2] = OFF;
		else
			dataToSend[2] = ON;

		Send(dataToSend);
	}

	if (SenderName == "L_OUT2") {
		dataToSend[1] = OUT_2;

		if ((logicIO & 0x02) == 0x02)
			dataToSend[2] = OFF;
		else
			dataToSend[2] = ON;

		Send(dataToSend);
		return;
	}

	if (SenderName == "L_OUT3") {
		dataToSend[1] = OUT_3;

		if ((logicIO & 0x04) == 0x04)
			dataToSend[2] = OFF;
		else
			dataToSend[2] = ON;

		Send(dataToSend);
		return;
	}

	if (SenderName == "L_OUT4") {
		dataToSend[1] = OUT_4;

		if ((logicIO & 0x08) == 0x08)
			dataToSend[2] = OFF;
		else
			dataToSend[2] = ON;

		Send(dataToSend);
		return;
	}

	if (SenderName == "RB_Update") {
		if (ui->RB_Update->isChecked())
			UpdateDataTimer->start(500);
		else
			UpdateDataTimer->stop();
		return;
	}

	if (SenderName == "B_Connect") {
		if (ui->B_Connect->text() == "Connect") {
			if (LoadingJSONFile())
				ConnectionCheck();
		} else {
			ConnectionCheck();
		}

		return;
	}

	if (SenderName == "B_Scan") {
		SearchForUARTDevices();
	}

}

void MainWindow::SliderProcessing() {
	const QString SenderName = sender()->objectName();

	const uint16_t R_ID = ui->CB_ID->currentText().toUInt();

	NodeStatus Node = HashNodesStatus->value(R_ID);

	uint8_t dataToSend[PACKET_SIZE] = {0};

	if (SenderName == "S_PWM1") {
		Node.PWM1 = ui->S_PWM1->value();

		dataToSend[1] = PWM_1;
		dataToSend[2] = Node.PWM1;

		Send(dataToSend);

		HashNodesStatus->insert(R_ID, Node);
		UpdateMainWindow();
		return;
	}

	if (SenderName == "S_PWM2") {
		Node.PWM2 = ui->S_PWM2->value();

		dataToSend[1] = PWM_2;
		dataToSend[2] = Node.PWM2;

		Send(dataToSend);

		HashNodesStatus->insert(R_ID, Node);
		UpdateMainWindow();
		return;
	}

	if (SenderName == "S_PWM3") {
		Node.PWM3 = ui->S_PWM3->value();

		dataToSend[1] = PWM_3;
		dataToSend[2] = Node.PWM3;

		Send(dataToSend);

		HashNodesStatus->insert(R_ID, Node);
		UpdateMainWindow();
		return;
	}

	if (SenderName == "S_ALLPWM") {
		Node.PWM1 = ui->S_ALLPWM->value();
		Node.PWM2 = ui->S_ALLPWM->value();
		Node.PWM3 = ui->S_ALLPWM->value();

		dataToSend[1] = ALLPWM;
		dataToSend[2] = static_cast<uint8_t>(ui->S_ALLPWM->value());

		Send(dataToSend);

		HashNodesStatus->insert(R_ID, Node);
		UpdateMainWindow();
	}
}

void MainWindow::PWMSpeedChange(const QTime& time) {
	uint8_t dataToSend[PACKET_SIZE] = {0};

	dataToSend[1] = TIME;
	dataToSend[2] = static_cast<uint8_t>(time.minute());
	dataToSend[3] = static_cast<uint8_t>(time.second());

	Send(dataToSend, true);
}

void MainWindow::ChangeRecipientID() {
	UpdateMainWindow();
}

void MainWindow::ConnectionCheck() {
	if (!Connect) {
		if (Serial->isOpen())
			Serial->close();

		Serial->setPortName(ui->CB_SerialPort->currentText());
		Serial->setBaudRate(QSerialPort::Baud115200);
		Serial->setDataBits(QSerialPort::Data8);
		Serial->setParity(QSerialPort::NoParity);
		Serial->setStopBits(QSerialPort::OneStop);
		Serial->setFlowControl(QSerialPort::NoFlowControl);

		if (Serial->open(QIODevice::ReadWrite)) {

			uint8_t dataToSend[PACKET_SIZE] = {0};

			dataToSend[1] = CONNECTED;

			Send(dataToSend, true);

		} else {
			qCritical() << "Connect error";
		}

	} else {
		if (Serial->isOpen())
			Serial->close();

		ui->CB_ID->setEnabled(false);
		ui->B_Scan->setEnabled(true);
		ui->L_OUT1->setEnabled(false);
		ui->L_OUT2->setEnabled(false);
		ui->L_OUT3->setEnabled(false);
		ui->L_OUT4->setEnabled(false);
		ui->S_PWM1->setEnabled(false);
		ui->S_PWM2->setEnabled(false);
		ui->S_PWM3->setEnabled(false);
		ui->B_Debug->setEnabled(false);
		ui->S_ALLPWM->setEnabled(false);
		ui->RB_Update->setEnabled(false);
		ui->RB_Update->setChecked(false);
		ui->TE_PWMSpeed->setEnabled(false);
		ui->CB_SerialPort->setEnabled(true);

		ui->B_Connect->setText("Connect");

		qDebug() << "Disconnect";

		UpdateDataTimer->stop();

		Connect = false;
	}
}

void MainWindow::Connected() {
	ui->CB_ID->setEnabled(true);
	ui->S_PWM1->setEnabled(true);
	ui->S_PWM2->setEnabled(true);
	ui->S_PWM3->setEnabled(true);
	ui->L_OUT1->setEnabled(true);
	ui->L_OUT2->setEnabled(true);
	ui->L_OUT3->setEnabled(true);
	ui->L_OUT4->setEnabled(true);
	ui->B_Scan->setEnabled(false);
	ui->B_Debug->setEnabled(true);
	ui->S_ALLPWM->setEnabled(true);
	ui->RB_Update->setEnabled(true);
	ui->TE_PWMSpeed->setEnabled(true);
	ui->CB_SerialPort->setEnabled(false);

	ui->B_Connect->setText("Disconnect");

	qDebug() << "Connect";

	uint8_t dataToSend[PACKET_SIZE] = {0};

	dataToSend[1] = INIT;
	dataToSend[2] = MasterID & 0x0FF;
	dataToSend[3] = static_cast<uint8_t>((MasterID & 0x0F00) >> 3);

	Send(dataToSend, true);

	ui->TE_PWMSpeed->setTime(Settings->value("PWMSpeed").toTime());

	Connect = true;
}

void MainWindow::SearchForUARTDevices() {
	qDebug() << "Searching for compatible devices";

	ui->CB_SerialPort->clear();
	const QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();

	if (!infos.isEmpty()) {
		for (const QSerialPortInfo& info : infos) {
			ui->CB_SerialPort->addItem(info.portName());
			qDebug() << info.portName() << info.description();
		}
	} else {
		qDebug() << "Could not find compatible devices";
	}
}

void MainWindow::RequestUpdateData() {
	uint8_t dataToSend[PACKET_SIZE] = {0};

	if (RequestUpdateDataFlag) {
		dataToSend[1] = LUX;
		RequestUpdateDataFlag = false;
	} else {
		dataToSend[1] = ADC;
		RequestUpdateDataFlag = true;
	}

	Send(dataToSend);
}

void MainWindow::DebugButton() {
	qDebug() << "";
	qDebug() << "";

	foreach(uint16_t key, HashNodesStatus->keys())
		qDebug() << "ID:" << key << "IO:" << HashNodesStatus->value(key).logicIO << "SN:" <<
			HashNodesStatus->value(key).SlavesNodes << "\t\tADC1:" <<
			HashNodesStatus->value(key).ADC1 << "ADC2:" <<
			HashNodesStatus->value(key).ADC2 << "LX:" <<
			HashNodesStatus->value(key).LX << "PWM1:" <<
			HashNodesStatus->value(key).PWM1 << "PWM2:" <<
			HashNodesStatus->value(key).PWM2 << "PWM3:" <<
			HashNodesStatus->value(key).PWM3;

	qDebug() << "";
	qDebug() << "";
}
