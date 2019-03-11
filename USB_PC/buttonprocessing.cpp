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
            ui->B_Connect->setText("Disconnect");

            ui->statusBar->showMessage("Connect");

            BufSend[1] = 0x00;
            Send();

            Timer->start(100);

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
        ui->B_Connect->setText("Connect");

        ui->statusBar->showMessage("Disconnect");

        Timer->stop();

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

    ui->L_PWM1->setText(QString::number((value/2.55),'f',2) + " %");

    BufSend[1] = 0x05;

    BufSend[2] = static_cast<uint8_t> (255 - value);

    Send();
}

void MainWindow::on_S_PWM2_valueChanged(int value)
{
    memset(BufSend, 0, sizeof(BufSend));

    ui->L_PWM2->setText(QString::number((value/2.55),'f',2) + " %");

    BufSend[1] = 0x06;

    BufSend[2] = static_cast<uint8_t> (255 - value);

    Send();
}

void MainWindow::on_S_PWM3_valueChanged(int value)
{
    memset(BufSend, 0, sizeof(BufSend));

    ui->L_PWM3->setText(QString::number((value/2.55),'f',2) + " %");

    BufSend[1] = 0x07;

    BufSend[2] = static_cast<uint8_t> (255 - value);

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

void MainWindow::on_RB_ADC1_clicked(bool checked)
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x08;

    if(checked){

        BufSend[2] = 0x01;

    }else{

        BufSend[2] = 0x00;

    }

    Send();
}

void MainWindow::on_RB_ADC2_clicked(bool checked)
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x09;

    if(checked){

        BufSend[2] = 0x01;

    }else{

        BufSend[2] = 0x00;

    }

    Send();
}

void MainWindow::on_RB_BH1750_clicked(bool checked)
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x0C;

    if(checked){

        BufSend[2] = 0x01;

    }else{

        BufSend[2] = 0x00;

    }

    Send();
}

