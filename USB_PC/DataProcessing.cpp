#include "MainWindow.h"

void MainWindow::ProcessingReceivedData()
{
    switch (BufReceive[1] & 0xF0) {

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

        ui->S_PWM1->setValue(255 - BufReceive[2]);
        ui->S_PWM2->setValue(255 - BufReceive[3]);
        ui->S_PWM3->setValue(255 - BufReceive[4]);

        break;

    case 0x10:

        if ((BufReceive[1] & 0x01) == 0x01) {
            ui->L_LED1->setStyleSheet("QLabel { background-color : green; }");
            LED1 = true;
        } else {
            ui->L_LED1->setStyleSheet("QLabel { background-color : red; }");
            LED1 = false;
        }

        break;

    case 0x20:

        if ((BufReceive[1] & 0x01) == 0x01) {
            ui->L_LED2->setStyleSheet("QLabel { background-color : green; }");
            LED2 = true;
        } else {
            ui->L_LED2->setStyleSheet("QLabel { background-color : red; }");
            LED2 = false;
        }

        break;

    case 0x30:

        if ((BufReceive[1] & 0x01) == 0x01) {
            ui->L_REL1->setStyleSheet("QLabel { background-color : green; }");
            REL1 = true;
        } else {
            ui->L_REL1->setStyleSheet("QLabel { background-color : red; }");
            REL1 = false;
        }

        break;

    case 0x40:

        if ((BufReceive[1] & 0x01) == 0x01) {
            ui->L_REL2->setStyleSheet("QLabel { background-color : green; }");
            REL2 = true;
        } else {
            ui->L_REL2->setStyleSheet("QLabel { background-color : red; }");
            REL2 = false;
        }

        break;

    case 0x80:

        ui->L_ADC1->setText(QString::number((static_cast<double>((BufReceive[2] << 8) |
                                             BufReceive[3])*3/4096),'f',3) + " V");
        break;

    case 0x90:

        ui->L_ADC2->setText(QString::number((static_cast<double>((BufReceive[2] << 8) |
                                             BufReceive[3])*3/4096),'f',3) + " V");
        break;

    case 0xA0:

        if ((BufReceive[1] & 0x01) != 0x01) {
            ui->L_DK1->setStyleSheet("QLabel { background-color : green; }");
        } else {
            ui->L_DK1->setStyleSheet("QLabel { background-color : red; }");
        }

        break;

    case 0xB0:

        if ((BufReceive[1] & 0x01) != 0x01) {
            ui->L_DK2->setStyleSheet("QLabel { background-color : green; }");
        } else {
            ui->L_DK2->setStyleSheet("QLabel { background-color : red; }");
        }

        break;

    case 0xC0:

        //BH1750

        break;

    }
}

void MainWindow::SendingRequest()
{
    memset(BufSend, 0, sizeof(BufSend));

    if(ui->RB_ADC1->isChecked()){
    BufSend[1] = 0x80;
    Send(true);
    }

    if(ui->RB_ADC2->isChecked()){
    BufSend[1] = 0x90;
    Send(true);
    }

    if(ui->RB_DK1->isChecked()){
    BufSend[1] = 0xA0;
    Send(true);
    }

    if(ui->RB_DK2->isChecked()){
    BufSend[1] = 0xB0;
    Send(true);
    }

//    BufSend[1] = 0xC0;

}

