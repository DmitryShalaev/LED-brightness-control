#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

#include "../general/id.h"

void MainWindow::ProcessingReceivedData(const uint8_t Data[8]) {
	switch (Data[1] & 0x1F) {
		case INIT:

			if ((Data[2] & 0x01) == 0x01) {
				ChangePixmap(ui->L_OUT1, ":/IMG/Resource/Out_on.png");
				OUT1 = true;
			} else {
				ChangePixmap(ui->L_OUT1, ":/IMG/Resource/Out_off.png");
				OUT1 = false;
			}

			if ((Data[2] & 0x02) == 0x02) {
				ChangePixmap(ui->L_OUT2, ":/IMG/Resource/Out_on.png");
				OUT2 = true;
			} else {
				ChangePixmap(ui->L_OUT2, ":/IMG/Resource/Out_off.png");
				OUT2 = false;
			}

			if ((Data[2] & 0x04) == 0x04) {
				ChangePixmap(ui->L_OUT3, ":/IMG/Resource/Out_on.png");
				OUT3 = true;
			} else {
				ChangePixmap(ui->L_OUT3, ":/IMG/Resource/Out_off.png");
				OUT3 = false;
			}

			if ((Data[2] & 0x08) == 0x08) {
				ChangePixmap(ui->L_OUT4, ":/IMG/Resource/Out_on.png");
				OUT4 = true;
			} else {
				ChangePixmap(ui->L_OUT4, ":/IMG/Resource/Out_off.png");
				OUT4 = false;
			}

			PWM1 = Data[3];
			PWM2 = Data[4];
			PWM3 = Data[5];

			ui->S_PWM1->setValue(PWM1);
			ui->S_PWM2->setValue(PWM2);
			ui->S_PWM3->setValue(PWM3);

			break;

		case OUT_1:

			if (Data[2] == ON) {
				ChangePixmap(ui->L_OUT1, ":/IMG/Resource/Out_on.png");
				OUT1 = true;
			} else {
				ChangePixmap(ui->L_OUT1, ":/IMG/Resource/Out_off.png");
				OUT1 = false;
			}

			break;

		case OUT_2:

			if (Data[2] == ON) {
				ChangePixmap(ui->L_OUT2, ":/IMG/Resource/Out_on.png");
				OUT2 = true;
			} else {
				ChangePixmap(ui->L_OUT2, ":/IMG/Resource/Out_off.png");
				OUT2 = false;
			}

			break;

		case OUT_3:

			if (Data[2] == ON) {
				ChangePixmap(ui->L_OUT3, ":/IMG/Resource/Out_on.png");
				OUT3 = true;
			} else {
				ChangePixmap(ui->L_OUT3, ":/IMG/Resource/Out_off.png");
				OUT3 = false;
			}

			break;

		case OUT_4:

			if (Data[2] == ON) {
				ChangePixmap(ui->L_OUT4, ":/IMG/Resource/Out_on.png");
				OUT4 = true;
			} else {
				ChangePixmap(ui->L_OUT4, ":/IMG/Resource/Out_off.png");
				OUT4 = false;
			}

			break;

		case ADC:

			ui->L_ADC1->setText(QString::number((static_cast<double>(((Data[2] & 0xF0) << 4) |
				                                    Data[3]) * 3.3 / 4095), 'f', 3) + " V");

			ui->L_ADC2->setText(QString::number((static_cast<double>(((Data[2] & 0x0F) << 8) |
				                                    Data[4]) * 3.3 / 4095), 'f', 3) + " V");

			break;

		case IN_1:

			if (Data[2] == ON)
				ChangePixmap(ui->L_IN1, ":/IMG/Resource/Open_eye.png");
			else
				ChangePixmap(ui->L_IN1, ":/IMG/Resource/Closed_eye.png");

			break;

		case IN_2:

			if (Data[2] == ON)
				ChangePixmap(ui->L_IN2, ":/IMG/Resource/Open_eye.png");
			else
				ChangePixmap(ui->L_IN2, ":/IMG/Resource/Closed_eye.png");

			break;

		case LUX:

			ui->L_BH1750->setText(QString::number((static_cast<double>((Data[2] << 8) |
				                                      Data[3]) / 1.2), 'f', 2) + " lx.");
			break;

		case IN_3:

			if (Data[2] == ON)
				ChangePixmap(ui->L_IN3, ":/IMG/Resource/Open_eye.png");
			else
				ChangePixmap(ui->L_IN3, ":/IMG/Resource/Closed_eye.png");

			break;

		case CONNECTED:

			MasterID = static_cast<uint16_t>(((Data[1] & 0xE0) << 3) | Data[0]);
			qDebug() << "Master ID : " << QString().setNum(MasterID);
			Connected();

			break;

		default: ;
	}
}
