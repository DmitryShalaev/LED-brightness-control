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

            BufSend[1] = 0x00;
            Send(true);

            Timer = new QTimer;
            connect(Timer, SIGNAL(timeout()), SLOT(SendingRequest()));
            Timer->start(150);

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

void MainWindow::Send(bool Request)
{
    BufSend[0] = 0x01;        //REPORT ID

    Res =  libusb_bulk_transfer(handle, EP_OUT, BufSend, 5, &ActualLength, 0);

    if(Request){
        RequestData();
    }

    if (Res == 0 && ActualLength == 5)
    {
        ui->statusBar->showMessage("Successful data transfer");
    }else if(Connect){
        on_B_Connect_clicked();
        QMessageBox::critical(this, tr("Error"), tr("Error data transfer"));
    }
}

void MainWindow::RequestData()
{
    Res =  libusb_bulk_transfer(handle, EP_IN, BufReceive, 5, &ActualLength, 1);
    if (Res == 0 && ActualLength == 5)
    {
        qDebug() << "Reed successful! " << ActualLength;

        ProcessingReceivedData();

    }else if(Connect){
        on_B_Connect_clicked();
        QMessageBox::critical(this, tr("Error"), tr("Error data receiving"));
    }

}

void MainWindow::SendingRequest()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0xF0;
    Send(true);
}

void MainWindow::on_B_LED1_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x80;

    if(LED1)
    {
        BufSend[1] &= ~0x01;
    }else{
        BufSend[1] |= 0x01;
    }

    Send(true);
}

void MainWindow::on_B_LED2_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x40;

    if(LED2)
    {
        BufSend[1] &= ~0x01;
    }else{
        BufSend[1] |= 0x01;
    }

    Send(true);
}

void MainWindow::on_B_REL1_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x90;

    if(REL1)
    {
        BufSend[1] &= ~0x01;
    }else{
        BufSend[1] |= 0x01;
    }

    Send(true);
}

void MainWindow::on_B_REL2_clicked()
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x50;

    if(REL2)
    {
        BufSend[1] &= ~0x01;
    }else{
        BufSend[1] |= 0x01;
    }

    Send(true);
}

void MainWindow::on_S_PWM1_valueChanged(int value)
{
    memset(BufSend, 0, sizeof(BufSend));

    ui->L_PWM1->setText(QString::number((value/2.55),'f',2) + " %");

    BufSend[1] = 0xA0;

    if(InvertPWM){
        BufSend[2] = static_cast<uint8_t> (255 - value);
    }else{
        BufSend[2] = static_cast<uint8_t> (value);
    }

    Send(false);
}

void MainWindow::on_S_PWM2_valueChanged(int value)
{
    memset(BufSend, 0, sizeof(BufSend));

    ui->L_PWM2->setText(QString::number((value/2.55),'f',2) + " %");

    BufSend[1] = 0x60;

    if(InvertPWM){
        BufSend[2] = static_cast<uint8_t> (255 - value);
    }else{
        BufSend[2] = static_cast<uint8_t> (value);
    }

    Send(false);
}

void MainWindow::on_S_PWM3_valueChanged(int value)
{
    memset(BufSend, 0, sizeof(BufSend));

    ui->L_PWM3->setText(QString::number((value/2.55),'f',2) + " %");

    BufSend[1] = 0xE0;

    if(InvertPWM){
        BufSend[2] = static_cast<uint8_t> (255 - value);
    }else{
        BufSend[2] = static_cast<uint8_t> (value);
    }

    Send(false);
}

void MainWindow::on_RB_InvertPWM_clicked(bool checked)
{
    InvertPWM = checked;
}
