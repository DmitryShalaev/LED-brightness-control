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

            ui->S_PWM1->setEnabled(true);
            ui->S_PWM2->setEnabled(true);
            ui->S_PWM3->setEnabled(true);
            ui->S_ALLPWM->setEnabled(true);
            ui->RB_Update->setEnabled(true);
            ui->RB_AutomaticControl->setEnabled(true);

            connect(ui->L_LED1, SIGNAL(Clicked()), this, SLOT(L_LED1_clicked()));
            connect(ui->L_LED2, SIGNAL(Clicked()), this, SLOT(L_LED2_clicked()));
            connect(ui->L_REL1, SIGNAL(Clicked()), this, SLOT(L_REL1_clicked()));
            connect(ui->L_REL2, SIGNAL(Clicked()), this, SLOT(L_REL2_clicked()));

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

        ui->S_PWM1->setEnabled(false);
        ui->S_PWM2->setEnabled(false);
        ui->S_PWM3->setEnabled(false);
        ui->S_ALLPWM->setEnabled(false);
        ui->RB_Update->setEnabled(false);
        ui->RB_AutomaticControl->setEnabled(false);

        disconnect(ui->L_LED1, SIGNAL(Clicked()), this, SLOT(L_LED1_clicked()));
        disconnect(ui->L_LED2, SIGNAL(Clicked()), this, SLOT(L_LED2_clicked()));
        disconnect(ui->L_REL1, SIGNAL(Clicked()), this, SLOT(L_REL1_clicked()));
        disconnect(ui->L_REL2, SIGNAL(Clicked()), this, SLOT(L_REL2_clicked()));

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

void MainWindow::L_LED1_clicked()
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

void MainWindow::L_LED2_clicked()
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

void MainWindow::L_REL1_clicked()
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

void MainWindow::L_REL2_clicked()
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

    PWM1 = static_cast<uint8_t> (value);

    if(ALLPWMChanged){

        ALLPWMChanged = false;

    }else {

        BufSend[1] = 0x05;
        BufSend[2] = PWM1;

        Send();
    }
}

void MainWindow::on_S_PWM2_valueChanged(int value)
{
    memset(BufSend, 0, sizeof(BufSend));

    PWM2 = static_cast<uint8_t> (value);

    if(ALLPWMChanged){

        ALLPWMChanged = false;

    }else {

        BufSend[1] = 0x06;
        BufSend[2] = PWM2;

        Send();
    }
}

void MainWindow::on_S_PWM3_valueChanged(int value)
{
    memset(BufSend, 0, sizeof(BufSend));

    PWM3 = static_cast<uint8_t> (value);

    if(ALLPWMChanged){

        ALLPWMChanged = false;

    }else {

        BufSend[1] = 0x07;
        BufSend[2] = PWM3;

        Send();
    }

}

void MainWindow::on_S_ALLPWM_valueChanged(int value)
{
    memset(BufSend, 0, sizeof(BufSend));

    ALLPWMChanged = true;
    ui->S_PWM1->setValue(value);

    ALLPWMChanged = true;
    ui->S_PWM2->setValue(value);

    ALLPWMChanged = true;
    ui->S_PWM3->setValue(value);

    BufSend[1] = 0x0D;
    BufSend[2] = static_cast<uint8_t> (value);

    Send();
}

void MainWindow::on_RB_Update_clicked(bool checked)
{
    if(checked){
        UpdateDataTimer->start(250);
    }else {
        UpdateDataTimer->stop();
    }

}

void MainWindow::on_RB_AutomaticControl_clicked(bool checked)
{

    if(checked){

        ui->S_PWM1->setEnabled(false);
        ui->S_PWM2->setEnabled(false);
        ui->S_PWM3->setEnabled(false);
        ui->S_ALLPWM->setEnabled(false);

        MeanPWM = (PWM1 + PWM2 + PWM3) / 3;

        RequestLuxTimer->start(RequestLuxTime);

    }else {

        ui->S_PWM1->setEnabled(true);
        ui->S_PWM2->setEnabled(true);
        ui->S_PWM3->setEnabled(true);
        ui->S_ALLPWM->setEnabled(true);

        RequestLuxTimer->stop();
    }
}
