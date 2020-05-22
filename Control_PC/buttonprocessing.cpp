#include <QDebug>
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "../general/id.h"

void MainWindow::on_B_Connect_clicked() {
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
			qDebug() << "Connect error";
		}

	} else {
		if (Serial->isOpen())
			Serial->close();

		ui->SB_ID->setEnabled(false);
		ui->B_Scan->setEnabled(true);
		ui->L_OUT1->setEnabled(false);
		ui->L_OUT2->setEnabled(false);
		ui->L_OUT3->setEnabled(false);
		ui->L_OUT4->setEnabled(false);
		ui->S_PWM1->setEnabled(false);
		ui->S_PWM2->setEnabled(false);
		ui->S_PWM3->setEnabled(false);
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

void MainWindow::L_OUT1_clicked() {
	uint8_t dataToSend[PACKET_SIZE] = {0};

	dataToSend[1] = OUT_1;

	if (OUT1)
		dataToSend[2] = OFF;
	else
		dataToSend[2] = ON;

	Send(dataToSend);
}

void MainWindow::L_OUT2_clicked() {
	uint8_t dataToSend[PACKET_SIZE] = {0};

	dataToSend[1] = OUT_2;

	if (OUT2)
		dataToSend[2] = OFF;
	else
		dataToSend[2] = ON;

	Send(dataToSend);
}

void MainWindow::L_OUT3_clicked() {
	uint8_t dataToSend[PACKET_SIZE] = {0};

	dataToSend[1] = OUT_3;

	if (OUT3)
		dataToSend[2] = OFF;
	else
		dataToSend[2] = ON;

	Send(dataToSend);
}

void MainWindow::L_OUT4_clicked() {
	uint8_t dataToSend[PACKET_SIZE] = {0};

	dataToSend[1] = OUT_4;

	if (OUT4)
		dataToSend[2] = OFF;
	else
		dataToSend[2] = ON;

	Send(dataToSend);
}

void MainWindow::on_S_PWM1_sliderReleased() {
	uint8_t dataToSend[PACKET_SIZE] = {0};

	dataToSend[1] = PWM_1;
	dataToSend[2] = static_cast<uint8_t>(ui->S_PWM1->value());

	Send(dataToSend);
}

void MainWindow::on_S_PWM2_sliderReleased() {
	uint8_t dataToSend[PACKET_SIZE] = {0};

	dataToSend[1] = PWM_2;
	dataToSend[2] = static_cast<uint8_t>(ui->S_PWM2->value());

	Send(dataToSend);
}

void MainWindow::on_S_PWM3_sliderReleased() {
	uint8_t dataToSend[PACKET_SIZE] = {0};

	dataToSend[1] = PWM_3;
	dataToSend[2] = static_cast<uint8_t>(ui->S_PWM3->value());

	Send(dataToSend);
}

void MainWindow::on_S_ALLPWM_sliderReleased() {
	uint8_t dataToSend[PACKET_SIZE] = {0};

	ui->S_PWM1->setValue(ui->S_ALLPWM->value());
	ui->S_PWM2->setValue(ui->S_ALLPWM->value());
	ui->S_PWM3->setValue(ui->S_ALLPWM->value());

	dataToSend[1] = ALLPWM;
	dataToSend[2] = static_cast<uint8_t>(ui->S_ALLPWM->value());

	Send(dataToSend);
}

void MainWindow::on_TE_PWMSpeed_userTimeChanged(const QTime& time) {
	Settings->setValue("TE_PWMSpeed", time);

	uint8_t dataToSend[PACKET_SIZE] = {0};

	dataToSend[1] = TIME;
	dataToSend[2] = static_cast<uint8_t>(time.minute());
	dataToSend[3] = static_cast<uint8_t>(time.second());

	Send(dataToSend, true);
}

void MainWindow::on_RB_Update_clicked(const bool checked) {
	if (checked)
		UpdateDataTimer->start(500);
	else
		UpdateDataTimer->stop();
}

void MainWindow::on_B_Scan_clicked() {
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
