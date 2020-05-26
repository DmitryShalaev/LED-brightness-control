#include "MainWindow.h"
#include "ui_MainWindow.h"
#include	<QDebug>

#include "../general/id.h"

void MainWindow::ButtonProcessing() {
	const QString SenderName = sender()->objectName();

	uint8_t dataToSend[PACKET_SIZE] = {0};

	if (SenderName == "L_OUT1") {
		dataToSend[1] = OUT_1;

		if (OUT1)
			dataToSend[2] = OFF;
		else
			dataToSend[2] = ON;

		Send(dataToSend);
	}

	if (SenderName == "L_OUT2") {
		dataToSend[1] = OUT_2;

		if (OUT2)
			dataToSend[2] = OFF;
		else
			dataToSend[2] = ON;

		Send(dataToSend);
		return;
	}

	if (SenderName == "L_OUT3") {
		dataToSend[1] = OUT_3;

		if (OUT3)
			dataToSend[2] = OFF;
		else
			dataToSend[2] = ON;

		Send(dataToSend);
		return;
	}

	if (SenderName == "L_OUT4") {
		dataToSend[1] = OUT_4;

		if (OUT4)
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
		if (LoadingJSONFile())
			ConnectionCheck();
		
		return;
	}

	if (SenderName == "B_Scan") {
		SearchForUARTDevices();
	}

}

void MainWindow::SliderProcessing() {
	const QString SenderName = sender()->objectName();

	uint8_t dataToSend[PACKET_SIZE] = {0};

	if (SenderName == "S_PWM1") {
		dataToSend[1] = PWM_1;
		dataToSend[2] = static_cast<uint8_t>(ui->S_PWM1->value());

		Send(dataToSend);
		return;
	}

	if (SenderName == "S_PWM2") {
		dataToSend[1] = PWM_2;
		dataToSend[2] = static_cast<uint8_t>(ui->S_PWM2->value());

		Send(dataToSend);
		return;
	}

	if (SenderName == "S_PWM3") {
		dataToSend[1] = PWM_3;
		dataToSend[2] = static_cast<uint8_t>(ui->S_PWM3->value());

		Send(dataToSend);
		return;
	}

	if (SenderName == "S_ALLPWM") {
		ui->S_PWM1->setValue(ui->S_ALLPWM->value());
		ui->S_PWM2->setValue(ui->S_ALLPWM->value());
		ui->S_PWM3->setValue(ui->S_ALLPWM->value());

		dataToSend[1] = ALLPWM;
		dataToSend[2] = static_cast<uint8_t>(ui->S_ALLPWM->value());

		Send(dataToSend);
	}
}

void MainWindow::PWMSpeedChange(const QTime& time) {
	uint8_t dataToSend[PACKET_SIZE] = {0};

	dataToSend[1] = TIME;
	dataToSend[2] = static_cast<uint8_t>(time.minute());
	dataToSend[3] = static_cast<uint8_t>(time.second());

	Send(dataToSend, true);
}