#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    libusb_init(nullptr);
}

MainWindow::~MainWindow()
{
    libusb_exit(nullptr);

    delete ui;
}

void MainWindow::on_B_Connect_clicked()
{
    static  QTimer* Timer = nullptr;

    if(!Connect)
    {
        handle = libusb_open_device_with_vid_pid(nullptr, VID, PID);

        if(handle)
        {
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

            RequestData();

            Timer = new QTimer;
            connect(Timer, SIGNAL(timeout()), SLOT(RequestData()));
            Timer->start(50);

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
        disconnect(Timer);
        delete Timer;
        Timer = nullptr;

        if(libusb_attach_kernel_driver(handle, 0) == 0)
            qDebug() << "Attach device";

        if (libusb_release_interface(handle,0) == 0)
            qDebug() << "Release 0 interface";

        libusb_close(handle);

        Connect = false;
    }
}

void MainWindow::Send()
{
    BufSend[0] = 0x01;        //REPORT ID

    Res =  libusb_bulk_transfer(handle, EP_OUT, BufSend, 11, &ActualLength, 0);
    if (Res == 0 && ActualLength == 11)
    {
        ui->statusBar->showMessage("Successful data transfer");

    }else{
        on_B_Connect_clicked();
        QMessageBox::critical(this, tr("Error"), tr("Error data transfer"));
    }
}

void MainWindow::RequestData()
{
    BufSend[1] = 0xF;        //START BYTE

    Send();

    Res =  libusb_bulk_transfer(handle, EP_IN, BufReceive, 64, &ActualLength, 1000);
    if (Res == 0 && ActualLength == 11)
    {
        qDebug() << "Reed successful! " << ActualLength;

        ProcessingReceivedData();

    }else{
        on_B_Connect_clicked();
        QMessageBox::critical(this, tr("Error"), tr("Error data receiving"));
    }

}

void MainWindow::ProcessingReceivedData()
{
    BufSend[2]=BufReceive[1];

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

    if ((BufReceive[1] & 0x10) != 0x10) {
        ui->L_DK1->setStyleSheet("QLabel { background-color : green; }");
    } else {
        ui->L_DK1->setStyleSheet("QLabel { background-color : red; }");
    }

    if ((BufReceive[1] & 0x20) != 0x20) {
        ui->L_DK2->setStyleSheet("QLabel { background-color : green; }");
    } else {
        ui->L_DK2->setStyleSheet("QLabel { background-color : red; }");
    }

    ui->L_ADC1->setText(QString::number((static_cast<double>(((BufReceive[2] & 0x0F) << 8) |
                                         BufReceive[3])*3/4096),'f',3) + " V");

    ui->L_ADC2->setText(QString::number((static_cast<double>(((BufReceive[2] & 0xF0) << 4) |
                                         BufReceive[4])*3/4096),'f',3) + " V");
}


void MainWindow::on_B_LED1_clicked()
{
    if(LED1)
    {
        BufSend[2] &= ~0x01;
    }else{
        BufSend[2] |= 0x01;
    }

    BufSend[1] = 0xFF;        //START BYTE
    Send();
}

void MainWindow::on_B_LED2_clicked()
{
    if(LED2)
    {
        BufSend[2] &= ~0x02;
    }else{
        BufSend[2] |= 0x02;
    }

    BufSend[1] = 0xFF;        //START BYTE
    Send();
}

void MainWindow::on_B_REL1_clicked()
{
    if(REL1)
    {
        BufSend[2] &= ~0x04;
    }else{
        BufSend[2] |= 0x04;
    }

    BufSend[1] = 0xFF;        //START BYTE
    Send();
}

void MainWindow::on_B_REL2_clicked()
{
    if(REL2)
    {
        BufSend[2] &= ~0x08;
    }else{
        BufSend[2] |= 0x08;
    }

    BufSend[1] = 0xFF;        //START BYTE
    Send();
}

void MainWindow::on_S_PWM1_valueChanged(int value)
{
    ui->L_PWM1->setText(QString::number((value/2.55),'f',2) + " %");
    BufSend[3] = static_cast<uint8_t> (value);
    BufSend[1] = 0xFF;
    Send();
}

void MainWindow::on_S_PWM2_valueChanged(int value)
{
    ui->L_PWM2->setText(QString::number((value/2.55),'f',2) + " %");
    BufSend[4] = static_cast<uint8_t> (value);
    BufSend[1] = 0xFF;
    Send();
}

void MainWindow::on_S_PWM3_valueChanged(int value)
{
    ui->L_PWM3->setText(QString::number((value/2.55),'f',2) + " %");
    BufSend[5] = static_cast<uint8_t> (value);
    BufSend[1] = 0xFF;
    Send();
}
