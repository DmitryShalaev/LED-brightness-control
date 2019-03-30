#include "MainWindow.h"

void MainWindow::ProcessingReceivedData()
{
    switch (BufReceive[1]) {

    case 0x00:

        if ((BufReceive[2] & 0x01) == 0x01) {
            ui->L_LED1->setPixmap(QPixmap(":/IMG/Resource/lamp_on.png").scaled(ui->L_LED1->width(),ui->L_LED1->height(),Qt::KeepAspectRatio));
            LED1 = true;
        } else {
            ui->L_LED1->setPixmap(QPixmap(":/IMG/Resource/lamp_off.png").scaled(ui->L_LED1->width(),ui->L_LED1->height(),Qt::KeepAspectRatio));
            LED1 = false;
        }

        if ((BufReceive[2] & 0x02) == 0x02) {
            ui->L_LED2->setPixmap(QPixmap(":/IMG/Resource/lamp_on.png").scaled(ui->L_LED2->width(),ui->L_LED2->height(),Qt::KeepAspectRatio));
            LED2 = true;
        } else {
            ui->L_LED2->setPixmap(QPixmap(":/IMG/Resource/lamp_off.png").scaled(ui->L_LED2->width(),ui->L_LED2->height(),Qt::KeepAspectRatio));
            LED2 = false;
        }

        if ((BufReceive[2] & 0x04) == 0x04) {
            ui->L_REL1->setPixmap(QPixmap(":/IMG/Resource/Relay_on.png").scaled(ui->L_REL1->width(),ui->L_REL1->height(),Qt::KeepAspectRatio));
            REL1 = true;
        } else {
            ui->L_REL1->setPixmap(QPixmap(":/IMG/Resource/Relay_off.png").scaled(ui->L_REL1->width(),ui->L_REL1->height(),Qt::KeepAspectRatio));
            REL1 = false;
        }

        if ((BufReceive[2] & 0x08) == 0x08) {
            ui->L_REL2->setPixmap(QPixmap(":/IMG/Resource/Relay_on.png").scaled(ui->L_REL2->width(),ui->L_REL2->height(),Qt::KeepAspectRatio));
            REL2 = true;
        } else {
            ui->L_REL2->setPixmap(QPixmap(":/IMG/Resource/Relay_off.png").scaled(ui->L_REL2->width(),ui->L_REL2->height(),Qt::KeepAspectRatio));
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
            ui->L_LED1->setPixmap(QPixmap(":/IMG/Resource/lamp_on.png").scaled(ui->L_LED1->width(),ui->L_LED1->height(),Qt::KeepAspectRatio));
            LED1 = true;
        } else {
            ui->L_LED1->setPixmap(QPixmap(":/IMG/Resource/lamp_off.png").scaled(ui->L_LED1->width(),ui->L_LED1->height(),Qt::KeepAspectRatio));
            LED1 = false;
        }

        break;

    case 0x02:

        if (BufReceive[2] == 0x01) {
            ui->L_LED2->setPixmap(QPixmap(":/IMG/Resource/lamp_on.png").scaled(ui->L_LED2->width(),ui->L_LED2->height(),Qt::KeepAspectRatio));
            LED2 = true;
        } else {
            ui->L_LED2->setPixmap(QPixmap(":/IMG/Resource/lamp_off.png").scaled(ui->L_LED2->width(),ui->L_LED2->height(),Qt::KeepAspectRatio));
            LED2 = false;
        }

        break;

    case 0x03:

        if (BufReceive[2] == 0x01) {
            ui->L_REL1->setPixmap(QPixmap(":/IMG/Resource/Relay_on.png").scaled(ui->L_REL1->width(),ui->L_REL1->height(),Qt::KeepAspectRatio));
            REL1 = true;
        } else {
            ui->L_REL1->setPixmap(QPixmap(":/IMG/Resource/Relay_off.png").scaled(ui->L_REL1->width(),ui->L_REL1->height(),Qt::KeepAspectRatio));
            REL1 = false;
        }

        break;

    case 0x04:

        if (BufReceive[2] == 0x01) {
            ui->L_REL2->setPixmap(QPixmap(":/IMG/Resource/Relay_on.png").scaled(ui->L_REL2->width(),ui->L_REL2->height(),Qt::KeepAspectRatio));
            REL2 = true;
        } else {
            ui->L_REL2->setPixmap(QPixmap(":/IMG/Resource/Relay_off.png").scaled(ui->L_REL2->width(),ui->L_REL2->height(),Qt::KeepAspectRatio));
            REL2 = false;
        }

        break;

    case 0x08:

        ui->L_ADC1->setText(QString::number((static_cast<double>(((BufReceive[2] & 0x0F) << 8) |
                                             BufReceive[3])*3/4096),'f',3) + " V");

        ui->L_ADC2->setText(QString::number((static_cast<double>(((BufReceive[2] & 0xF0) << 4) |
                                             BufReceive[4])*3/4096),'f',3) + " V");

        break;

    case 0x09:

        if (BufReceive[2] == 0x01) {
            ui->L_DK1->setPixmap(QPixmap(":/IMG/Resource/Button_on.png").scaled(ui->L_DK1->width(),ui->L_DK1->height(),Qt::KeepAspectRatio));
        } else {
            ui->L_DK1->setPixmap(QPixmap(":/IMG/Resource/Button_off.png").scaled(ui->L_DK1->width(),ui->L_DK1->height(),Qt::KeepAspectRatio));
        }

        break;

    case 0x0A:

        if (BufReceive[2] == 0x01) {
            ui->L_DK2->setPixmap(QPixmap(":/IMG/Resource/Button_on.png").scaled(ui->L_DK2->width(),ui->L_DK2->height(),Qt::KeepAspectRatio));
        } else {
            ui->L_DK2->setPixmap(QPixmap(":/IMG/Resource/Button_off.png").scaled(ui->L_DK2->width(),ui->L_DK2->height(),Qt::KeepAspectRatio));
        }

        break;

    case 0x0B:

        ui->L_BH1750->setText(QString::number((static_cast<double>((BufReceive[2] << 8) |
                                               BufReceive[3])/1.2),'f',2) + " lx.");

        if(MaintainLux)
            MaintainLuxLevel(((BufReceive[2] << 8) | BufReceive[3]) / 1.2);

        break;

    case 0x0E:

        if (BufReceive[2] == 0x01) {
            ui->L_DK3->setPixmap(QPixmap(":/IMG/Resource/Open_eye.png").scaled(ui->L_DK3->width(),ui->L_DK3->height(),Qt::KeepAspectRatio));
            MotionDetection(true);
        } else {
            ui->L_DK3->setPixmap(QPixmap(":/IMG/Resource/Closed_eye.png").scaled(ui->L_DK3->width(),ui->L_DK3->height(),Qt::KeepAspectRatio));
            MotionDetection(false);
        }

        break;

    }
}
