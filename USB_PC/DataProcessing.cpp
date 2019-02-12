#include "MainWindow.h"

void MainWindow::ProcessingReceivedData()
{
    switch (BufReceive[1] & 0xF8) {

    case 0x00:
        if ((BufReceive[1] & 0x01) == 0x01) {
            ui->L_LED1->setStyleSheet("QLabel { background-color : green; }");
            LED1 = true;
        } else {
            ui->L_LED1->setStyleSheet("QLabel { background-color : red; }");
            LED1 = false;
        }

        if ((BufReceive[1] & 0x02) == 0x02) {
            ui->L_LED2->setStyleSheet("QLabel { background-color : green; }");
            LED2 = true;
        } else {
            ui->L_LED2->setStyleSheet("QLabel { background-color : red; }");
            LED2 = false;
        }

        if ((BufReceive[1] & 0x04) == 0x04) {
            ui->L_REL1->setStyleSheet("QLabel { background-color : green; }");
            REL1 = true;
        } else {
            ui->L_REL1->setStyleSheet("QLabel { background-color : red; }");
            REL1 = false;
        }

        if ((BufReceive[1] & 0x08) == 0x08) {
            ui->L_REL2->setStyleSheet("QLabel { background-color : green; }");
            REL2 = true;
        } else {
            ui->L_REL2->setStyleSheet("QLabel { background-color : red; }");
            REL2 = false;
        }

        ui->S_PWM1->setValue(BufReceive[2]);
        ui->S_PWM2->setValue(BufReceive[3]);
        ui->S_PWM3->setValue(BufReceive[4]);

        break;

    case 0x08:
        if ((BufReceive[1] & 0x01) == 0x01) {
            ui->L_LED1->setStyleSheet("QLabel { background-color : green; }");
            LED1 = true;
        } else {
            ui->L_LED1->setStyleSheet("QLabel { background-color : red; }");
            LED1 = false;
        }
        break;

    case 0x10:
        if ((BufReceive[1] & 0x01) == 0x01) {
            ui->L_LED2->setStyleSheet("QLabel { background-color : green; }");
            LED2 = true;
        } else {
            ui->L_LED2->setStyleSheet("QLabel { background-color : red; }");
            LED2 = false;
        }
        break;

    case 0x18:
        if ((BufReceive[1] & 0x01) == 0x01) {
            ui->L_REL1->setStyleSheet("QLabel { background-color : green; }");
            REL1 = true;
        } else {
            ui->L_REL1->setStyleSheet("QLabel { background-color : red; }");
            REL1 = false;
        }
        break;

    case 0x20:
        if ((BufReceive[1] & 0x01) == 0x01) {
            ui->L_REL2->setStyleSheet("QLabel { background-color : green; }");
            REL2 = true;
        } else {
            ui->L_REL2->setStyleSheet("QLabel { background-color : red; }");
            REL2 = false;
        }
        break;

    case 0xF8:

        if ((BufReceive[1] & 0x01) != 0x01) {
            ui->L_DK1->setStyleSheet("QLabel { background-color : green; }");
        } else {
            ui->L_DK1->setStyleSheet("QLabel { background-color : red; }");
        }

        if ((BufReceive[1] & 0x02) != 0x02) {
            ui->L_DK2->setStyleSheet("QLabel { background-color : green; }");
        } else {
            ui->L_DK2->setStyleSheet("QLabel { background-color : red; }");
        }

        ui->L_ADC1->setText(QString::number((static_cast<double>(((BufReceive[2] & 0x0F) << 8) |
                                             BufReceive[3])*3/4096),'f',3) + " V");

        ui->L_ADC2->setText(QString::number((static_cast<double>(((BufReceive[2] & 0xF0) << 4) |
                                             BufReceive[4])*3/4096),'f',3) + " V");
        break;

    }
}

void MainWindow::SendingRequest()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0xF8;
    Send(true);
}
