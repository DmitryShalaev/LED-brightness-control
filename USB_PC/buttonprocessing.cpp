#include "MainWindow.h"

void MainWindow::on_B_Connect_clicked()
{
    if(!Connect){

        handle = libusb_open_device_with_vid_pid(nullptr, VID, PID);

        if(handle){

            if (libusb_kernel_driver_active(handle,0))
                if(libusb_detach_kernel_driver(handle, 0) == 0)
                    qDebug() << "Detach device";

            if(libusb_set_configuration(handle, 1) == 0)
                qDebug() << "Set configuration";

            if (libusb_claim_interface(handle,  0) == 0)
                qDebug() << "Claim 0 interface";

            ui->B_LED1->setEnabled(true);
            ui->B_LED2->setEnabled(true);
            ui->B_REL1->setEnabled(true);
            ui->B_REL2->setEnabled(true);
            ui->S_PWM1->setEnabled(true);
            ui->S_PWM2->setEnabled(true);
            ui->S_PWM3->setEnabled(true);
            ui->RB_ADC1->setEnabled(true);
            ui->RB_ADC2->setEnabled(true);
            ui->SB_PWM1->setEnabled(true);
            ui->SB_PWM2->setEnabled(true);
            ui->SB_PWM3->setEnabled(true);
            ui->RB_BH1750->setEnabled(true);
            ui->TE_TurnOffLight->setEnabled(true);
            ui->RB_TurnOffLight->setEnabled(true);
            ui->TE_SpeedOnOffLight->setEnabled(true);
            ui->SB_MaintainLuxLevel->setEnabled(true);
            ui->RB_MaintainLuxLevel->setEnabled(true);

            ui->B_Connect->setText("Disconnect");

            ui->statusBar->showMessage("Connect");

            BufSend[1] = 0x00;
            Send();

            RequestTimer->start(100);

            Connect = true;

        }else{
            ui->statusBar->showMessage("Connect error");
        }

    }else{

        ui->B_LED1->setEnabled(false);
        ui->B_LED2->setEnabled(false);
        ui->B_REL1->setEnabled(false);
        ui->B_REL2->setEnabled(false);
        ui->S_PWM1->setEnabled(false);
        ui->S_PWM2->setEnabled(false);
        ui->S_PWM3->setEnabled(false);
        ui->RB_ADC1->setEnabled(false);
        ui->RB_ADC2->setEnabled(false);
        ui->SB_PWM1->setEnabled(false);
        ui->SB_PWM2->setEnabled(false);
        ui->SB_PWM3->setEnabled(false);
        ui->RB_BH1750->setEnabled(false);
        ui->TE_TurnOffLight->setEnabled(false);
        ui->RB_TurnOffLight->setEnabled(false);
        ui->TE_SpeedOnOffLight->setEnabled(false);
        ui->SB_MaintainLuxLevel->setEnabled(false);
        ui->RB_MaintainLuxLevel->setEnabled(false);

        ui->B_Connect->setText("Connect");

        ui->statusBar->showMessage("Disconnect");

        RequestTimer->stop();
        MotionTimer->stop();
        RequestLuxTimer->stop();

        if(libusb_attach_kernel_driver(handle, 0) == 0)
            qDebug() << "Attach device";

        if (libusb_release_interface(handle,0) == 0)
            qDebug() << "Release 0 interface";

        libusb_close(handle);

        Connect = false;
    }
}

void MainWindow::on_B_LED1_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x01;

    if(LED1){
        BufSend[2] = 0x00;
    }else{
        BufSend[2] = 0x01;
    }

    Send();
}

void MainWindow::on_B_LED2_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x02;

    if(LED2){
        BufSend[2] = 0x00;
    }else{
        BufSend[2] = 0x01;
    }

    Send();
}

void MainWindow::on_B_REL1_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x03;

    if(REL1){
        BufSend[2] = 0x00;
    }else{
        BufSend[2] = 0x01;
    }

    Send();
}

void MainWindow::on_B_REL2_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x04;

    if(REL2){
        BufSend[2] = 0x00;
    }else{
        BufSend[2] = 0x01;
    }

    Send();
}

void MainWindow::on_S_PWM1_valueChanged(int value)
{
    memset(BufSend, 0, sizeof(BufSend));

    ui->SB_PWM1->setValue(value/2.55);

    BufSend[1] = 0x05;

    PWM1 = static_cast<uint8_t> (value);

    BufSend[2] = PWM1;

    Send();
}

void MainWindow::on_S_PWM2_valueChanged(int value)
{
    memset(BufSend, 0, sizeof(BufSend));

    ui->SB_PWM2->setValue(value/2.55);

    BufSend[1] = 0x06;

    PWM2 = static_cast<uint8_t> (value);

    BufSend[2] = PWM2;

    Send();
}

void MainWindow::on_S_PWM3_valueChanged(int value)
{
    memset(BufSend, 0, sizeof(BufSend));

    ui->SB_PWM3->setValue(value/2.55);

    BufSend[1] = 0x07;

    PWM3 = static_cast<uint8_t> (value);

    BufSend[2] = PWM3;

    Send();
}

void MainWindow::on_TE_SpeedOnOffLight_editingFinished()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x0D;

    BufSend[2] = static_cast<uint8_t> (ui->TE_SpeedOnOffLight->time().minute());
    BufSend[3] = static_cast<uint8_t> (ui->TE_SpeedOnOffLight->time().second());

    Send();
}

void MainWindow::on_RB_ADC1_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x08;

    Send();
}

void MainWindow::on_RB_ADC2_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x09;

    Send();
}

void MainWindow::on_RB_BH1750_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x0C;

    Send();
}

void MainWindow::on_RB_MaintainLuxLevel_clicked(bool checked)
{
    if(checked){

        ui->SB_PWM1->setEnabled(false);
        ui->SB_PWM2->setEnabled(false);
        ui->SB_PWM3->setEnabled(false);
        ui->S_PWM1->setEnabled(false);
        ui->S_PWM2->setEnabled(false);
        ui->S_PWM3->setEnabled(false);

        MeanPWM = (PWM1 + PWM2 + PWM3) / 3;

        RequestLuxTimer->start(ui->TE_SpeedOnOffLight->time().minute() * 60000 +
                               ui->TE_SpeedOnOffLight->time().second() * 1000);
    }else {

        RequestLuxTimer->stop();

        ui->SB_PWM1->setEnabled(true);
        ui->SB_PWM2->setEnabled(true);
        ui->SB_PWM3->setEnabled(true);
        ui->S_PWM1->setEnabled(true);
        ui->S_PWM2->setEnabled(true);
        ui->S_PWM3->setEnabled(true);
    }
}

void MainWindow::on_SB_PWM1_editingFinished()
{
    ui->S_PWM1->setValue(static_cast<int> (2.56 * (ui->SB_PWM1->value())));
}

void MainWindow::on_SB_PWM2_editingFinished()
{
    ui->S_PWM2->setValue(static_cast<int> (2.56 * (ui->SB_PWM2->value())));
}

void MainWindow::on_SB_PWM3_editingFinished()
{
    ui->S_PWM3->setValue(static_cast<int> (2.56 * (ui->SB_PWM3->value())));
}

