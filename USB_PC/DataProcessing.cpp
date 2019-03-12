#include "MainWindow.h"

void MainWindow::ProcessingReceivedData()
{
    switch (BufReceive[1]) {

    case 0x00:

        if ((BufReceive[2] & 0x01) == 0x01) {
            ui->L_LED1->setStyleSheet("QLabel { background-color : green; }");
            LED1 = true;
        } else {
            ui->L_LED1->setStyleSheet("QLabel { background-color : red; }");
            LED1 = false;
        }

        if ((BufReceive[2] & 0x02) == 0x02) {
            ui->L_LED2->setStyleSheet("QLabel { background-color : green; }");
            LED2 = true;
        } else {
            ui->L_LED2->setStyleSheet("QLabel { background-color : red; }");
            LED2 = false;
        }

        if ((BufReceive[2] & 0x04) == 0x04) {
            ui->L_REL1->setStyleSheet("QLabel { background-color : green; }");
            REL1 = true;
        } else {
            ui->L_REL1->setStyleSheet("QLabel { background-color : red; }");
            REL1 = false;
        }

        if ((BufReceive[2] & 0x08) == 0x08) {
            ui->L_REL2->setStyleSheet("QLabel { background-color : green; }");
            REL2 = true;
        } else {
            ui->L_REL2->setStyleSheet("QLabel { background-color : red; }");
            REL2 = false;
        }

        PWM1 = BufReceive[3];
        PWM2 = BufReceive[4];
        PWM3 = BufReceive[5];

        ui->S_PWM1->setValue(PWM1);
        ui->S_PWM2->setValue(PWM2);
        ui->S_PWM3->setValue(PWM3);

        break;

    case 0x01:

        if (BufReceive[2] == 0x01) {
            ui->L_LED1->setStyleSheet("QLabel { background-color : green; }");
            LED1 = true;
        } else {
            ui->L_LED1->setStyleSheet("QLabel { background-color : red; }");
            LED1 = false;
        }

        break;

    case 0x02:

        if (BufReceive[2] == 0x01) {
            ui->L_LED2->setStyleSheet("QLabel { background-color : green; }");
            LED2 = true;
        } else {
            ui->L_LED2->setStyleSheet("QLabel { background-color : red; }");
            LED2 = false;
        }

        break;

    case 0x03:

        if (BufReceive[2] == 0x01) {
            ui->L_REL1->setStyleSheet("QLabel { background-color : green; }");
            REL1 = true;
        } else {
            ui->L_REL1->setStyleSheet("QLabel { background-color : red; }");
            REL1 = false;
        }

        break;

    case 0x04:

        if (BufReceive[2] == 0x01) {
            ui->L_REL2->setStyleSheet("QLabel { background-color : green; }");
            REL2 = true;
        } else {
            ui->L_REL2->setStyleSheet("QLabel { background-color : red; }");
            REL2 = false;
        }

        break;

    case 0x08:

        ui->L_ADC1->setText(QString::number((static_cast<double>((BufReceive[2] << 8) |
                                             BufReceive[3])*3/4096),'f',3) + " V.");

        break;

    case 0x09:

        ui->L_ADC2->setText(QString::number((static_cast<double>((BufReceive[2] << 8) |
                                             BufReceive[3])*3/4096),'f',3) + " V.");

        break;

    case 0x0A:

        if (BufReceive[2] == 0x01) {
            ui->L_DK1->setStyleSheet("QLabel { background-color : green; }");
            MotionDetection(true);
        } else {
            ui->L_DK1->setStyleSheet("QLabel { background-color : red; }");
            MotionDetection(false);
        }

        break;

    case 0x0B:

        if (BufReceive[2] == 0x01) {
            ui->L_DK2->setStyleSheet("QLabel { background-color : green; }");
        } else {
            ui->L_DK2->setStyleSheet("QLabel { background-color : red; }");
        }

        break;

    case 0x0C:

        ui->L_BH1750->setText(QString::number((static_cast<double>((BufReceive[2] << 8) |
                                               BufReceive[3])/1.2),'f',2) + " lx.");

        if(MaintainLux)
            MaintainLuxLevel(((BufReceive[2] << 8) | BufReceive[3]) / 1.2);

        break;

    }
}

