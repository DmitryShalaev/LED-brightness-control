#include "MainWindow.h"

void MainWindow::on_B_Connect_clicked()
{
    if(!Connect){

        if (Serial->isOpen())
            Serial->close();

        Serial->setPortName(ui->CB_SerialPort->currentText());
        Serial->setBaudRate(QSerialPort::Baud115200);
        Serial->setDataBits(QSerialPort::Data8);
        Serial->setParity(QSerialPort::NoParity);
        Serial->setStopBits(QSerialPort::OneStop);
        Serial->setFlowControl(QSerialPort::NoFlowControl);

        if (Serial->open(QIODevice::ReadWrite)) {

            ui->TE_Log->clear();

            memset(BufSend, 0, sizeof(BufSend));
            BufSend[1] = CONNECTED;
            Send();

        }else{

            ui->TE_Log->append("Connect error");
        }

    }else{

        if (Serial->isOpen())
            Serial->close();

        ui->S_PWM1->setEnabled(false);
        ui->S_PWM2->setEnabled(false);
        ui->S_PWM3->setEnabled(false);
        ui->S_ALLPWM->setEnabled(false);
        ui->RB_Update->setEnabled(false);
        ui->RB_Update->setChecked(false);
        ui->RB_AutomaticControl->setEnabled(false);
        ui->RB_AutomaticControl->setChecked(false);
        ui->actionAutomatic_control_setting->setEnabled(false);
        ui->B_Scan->setEnabled(true);
        ui->CB_SerialPort->setEnabled(true);
        ui-> SB_ID->setEnabled(false);
        ui-> SB_ID->setValue(0);

        disconnect(ui->L_LED1, SIGNAL(Clicked()), this, SLOT(L_LED1_clicked()));
        disconnect(ui->L_LED2, SIGNAL(Clicked()), this, SLOT(L_LED2_clicked()));
        disconnect(ui->L_REL1, SIGNAL(Clicked()), this, SLOT(L_REL1_clicked()));
        disconnect(ui->L_REL2, SIGNAL(Clicked()), this, SLOT(L_REL2_clicked()));

        ui->B_Connect->setText("Connect");

        ui->TE_Log->append("Disconnect");

        MotionTimer->stop();
        RequestLuxTimer->stop();
        UpdateDataTimer->stop();
        OnOffTimer->stop();

        Connect = false;
    }
}

void MainWindow::L_LED1_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = LED_1;

    if(LED1){
        BufSend[2] = OFF;
    }else{
        BufSend[2] = ON;
    }

    Send();
}

void MainWindow::L_LED2_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = LED_2;

    if(LED2){
        BufSend[2] = OFF;
    }else{
        BufSend[2] = ON;
    }

    Send();
}

void MainWindow::L_REL1_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = REL_1;

    if(REL1){
        BufSend[2] = OFF;
    }else{
        BufSend[2] = ON;
    }

    Send();
}

void MainWindow::L_REL2_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = REL_2;

    if(REL2){
        BufSend[2] = OFF;
    }else{
        BufSend[2] = ON;
    }

    Send();
}

void MainWindow::on_S_PWM1_sliderReleased()
{
    memset(BufSend, 0, sizeof(BufSend));

    PWM1 = static_cast<uint8_t> (ui->S_PWM1->value());

    BufSend[1] = PWM_1;
    BufSend[2] = PWM1;

    Send();
}

void MainWindow::on_S_PWM2_sliderReleased()
{
    memset(BufSend, 0, sizeof(BufSend));

    PWM2 = static_cast<uint8_t> (ui->S_PWM2->value());

    BufSend[1] = PWM_2;
    BufSend[2] = PWM2;

    Send();
}

void MainWindow::on_S_PWM3_sliderReleased()
{
    memset(BufSend, 0, sizeof(BufSend));

    PWM3 = static_cast<uint8_t> (ui->S_PWM3->value());

    BufSend[1] = PWM_3;
    BufSend[2] = PWM3;

    Send();
}

void MainWindow::on_S_ALLPWM_sliderReleased()
{
    memset(BufSend, 0, sizeof(BufSend));

    ui->S_PWM1->setValue(ui->S_ALLPWM->value());
    ui->S_PWM2->setValue(ui->S_ALLPWM->value());
    ui->S_PWM3->setValue(ui->S_ALLPWM->value());

    BufSend[1] = ALLPWM;
    BufSend[2] = static_cast<uint8_t> (ui->S_ALLPWM->value());

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
    AutomaticControlActivated = checked;

    if(checked){

        ui->S_PWM1->setEnabled(false);
        ui->S_PWM2->setEnabled(false);
        ui->S_PWM3->setEnabled(false);
        ui->S_ALLPWM->setEnabled(false);

        MeanPWM = (PWM1 + PWM2 + PWM3) / 3;

        if (TurnOffLightIsChecked) {

            BufSend[1] = ALLPWM;

            BufSend[2] = 0;

            Send();

        }

        if(OnOffTimeIsChecked){

            TheTimeHasCome = false;
            OnOffTimer->start(10000);

        }else if(MaintainLuxLevelIsChecked && !TurnOffLightIsChecked){

            RequestLuxTimer->start(RequestLuxTime);

        }else {

            TheTimeHasCome = true;
        }

    }else {

        ui->S_PWM1->setEnabled(true);
        ui->S_PWM2->setEnabled(true);
        ui->S_PWM3->setEnabled(true);
        ui->S_ALLPWM->setEnabled(true);

        TheTimeHasCome = false;

        RequestLuxTimer->stop();
        OnOffTimer->stop();
    }
}

void MainWindow::on_B_Scan_clicked()
{
    ui->CB_SerialPort->clear();
    const QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();

    for (const QSerialPortInfo &info : infos)
        ui->CB_SerialPort->addItem(info.portName());
}
