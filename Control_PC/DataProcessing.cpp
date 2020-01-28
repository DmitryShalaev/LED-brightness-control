#include "MainWindow.h"

void MainWindow::ProcessingReceivedData(uint8_t Data[])
{
    switch (Data[1] & 0x1F) {

    case INIT:

        if ((Data[2] & 0x01) == 0x01) {
            ui->L_LED1->setPixmap(QPixmap(":/IMG/Resource/lamp_on.png").scaled(ui->L_LED1->width(),ui->L_LED1->height(),Qt::KeepAspectRatio));
            LED1 = true;
        } else {
            ui->L_LED1->setPixmap(QPixmap(":/IMG/Resource/lamp_off.png").scaled(ui->L_LED1->width(),ui->L_LED1->height(),Qt::KeepAspectRatio));
            LED1 = false;
        }

        if ((Data[2] & 0x02) == 0x02) {
            ui->L_LED2->setPixmap(QPixmap(":/IMG/Resource/lamp_on.png").scaled(ui->L_LED2->width(),ui->L_LED2->height(),Qt::KeepAspectRatio));
            LED2 = true;
        } else {
            ui->L_LED2->setPixmap(QPixmap(":/IMG/Resource/lamp_off.png").scaled(ui->L_LED2->width(),ui->L_LED2->height(),Qt::KeepAspectRatio));
            LED2 = false;
        }

        if ((Data[2] & 0x04) == 0x04) {
            ui->L_REL1->setPixmap(QPixmap(":/IMG/Resource/Relay_on.png").scaled(ui->L_REL1->width(),ui->L_REL1->height(),Qt::KeepAspectRatio));
            REL1 = true;
        } else {
            ui->L_REL1->setPixmap(QPixmap(":/IMG/Resource/Relay_off.png").scaled(ui->L_REL1->width(),ui->L_REL1->height(),Qt::KeepAspectRatio));
            REL1 = false;
        }

        if ((Data[2] & 0x08) == 0x08) {
            ui->L_REL2->setPixmap(QPixmap(":/IMG/Resource/Relay_on.png").scaled(ui->L_REL2->width(),ui->L_REL2->height(),Qt::KeepAspectRatio));
            REL2 = true;
        } else {
            ui->L_REL2->setPixmap(QPixmap(":/IMG/Resource/Relay_off.png").scaled(ui->L_REL2->width(),ui->L_REL2->height(),Qt::KeepAspectRatio));
            REL2 = false;
        }

        PWM1 = Data[3];
        PWM2 = Data[4];
        PWM3 = Data[5];

        ui->S_PWM1->setValue(PWM1);
        ui->S_PWM2->setValue(PWM2);
        ui->S_PWM3->setValue(PWM3);

        break;

    case LED_1:

        if (Data[2] == ON) {
            ui->L_LED1->setPixmap(QPixmap(":/IMG/Resource/lamp_on.png").scaled(ui->L_LED1->width(),ui->L_LED1->height(),Qt::KeepAspectRatio));
            LED1 = true;
        } else {
            ui->L_LED1->setPixmap(QPixmap(":/IMG/Resource/lamp_off.png").scaled(ui->L_LED1->width(),ui->L_LED1->height(),Qt::KeepAspectRatio));
            LED1 = false;
        }

        break;

    case LED_2:

        if (Data[2] == ON) {
            ui->L_LED2->setPixmap(QPixmap(":/IMG/Resource/lamp_on.png").scaled(ui->L_LED2->width(),ui->L_LED2->height(),Qt::KeepAspectRatio));
            LED2 = true;
        } else {
            ui->L_LED2->setPixmap(QPixmap(":/IMG/Resource/lamp_off.png").scaled(ui->L_LED2->width(),ui->L_LED2->height(),Qt::KeepAspectRatio));
            LED2 = false;
        }

        break;

    case REL_1:

        if (Data[2] == ON) {
            ui->L_REL1->setPixmap(QPixmap(":/IMG/Resource/Relay_on.png").scaled(ui->L_REL1->width(),ui->L_REL1->height(),Qt::KeepAspectRatio));
            REL1 = true;
        } else {
            ui->L_REL1->setPixmap(QPixmap(":/IMG/Resource/Relay_off.png").scaled(ui->L_REL1->width(),ui->L_REL1->height(),Qt::KeepAspectRatio));
            REL1 = false;
        }

        break;

    case REL_2:

        if (Data[2] == ON) {
            ui->L_REL2->setPixmap(QPixmap(":/IMG/Resource/Relay_on.png").scaled(ui->L_REL2->width(),ui->L_REL2->height(),Qt::KeepAspectRatio));
            REL2 = true;
        } else {
            ui->L_REL2->setPixmap(QPixmap(":/IMG/Resource/Relay_off.png").scaled(ui->L_REL2->width(),ui->L_REL2->height(),Qt::KeepAspectRatio));
            REL2 = false;
        }

        break;

    case ADC:

        ui->L_ADC1->setText(QString::number((static_cast<double>(((Data[2] & 0xF0) << 4) |
                                             Data[3])*3.3/4095),'f',3) + " V");

        ui->L_ADC2->setText(QString::number((static_cast<double>(((Data[2] & 0x0F) << 8) |
                                             Data[4])*3.3/4095),'f',3) + " V");

        break;

    case DK_1:

        if (Data[2] == ON) {
            ui->L_DK1->setPixmap(QPixmap(":/IMG/Resource/Button_on.png").scaled(ui->L_DK1->width(),ui->L_DK1->height(),Qt::KeepAspectRatio));
        } else {
            ui->L_DK1->setPixmap(QPixmap(":/IMG/Resource/Button_off.png").scaled(ui->L_DK1->width(),ui->L_DK1->height(),Qt::KeepAspectRatio));
        }

        break;

    case DK_2:

        if (Data[2] == ON) {
            ui->L_DK2->setPixmap(QPixmap(":/IMG/Resource/Button_on.png").scaled(ui->L_DK2->width(),ui->L_DK2->height(),Qt::KeepAspectRatio));
        } else {
            ui->L_DK2->setPixmap(QPixmap(":/IMG/Resource/Button_off.png").scaled(ui->L_DK2->width(),ui->L_DK2->height(),Qt::KeepAspectRatio));
        }

        break;

    case LUX:

        ui->L_BH1750->setText(QString::number((static_cast<double>((Data[2] << 8) |
                                               Data[3])/1.2),'f',2) + " lx.");
        break;

    case MOTION:

        if (Data[2] == ON) {
            ui->L_MOTION->setPixmap(QPixmap(":/IMG/Resource/Open_eye.png").scaled(ui->L_MOTION->width(),ui->L_MOTION->height(),Qt::KeepAspectRatio));
        } else {
            ui->L_MOTION->setPixmap(QPixmap(":/IMG/Resource/Closed_eye.png").scaled(ui->L_MOTION->width(),ui->L_MOTION->height(),Qt::KeepAspectRatio));
        }

        break;

    case CONNECTED:

         MasterID = static_cast<uint16_t>(((Data[1] & 0xE0) << 3) | Data[0]);
         Connected();

        break;

    }
}
