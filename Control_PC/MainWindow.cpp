#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    ui->L_MOTION->setPixmap(QPixmap(":/IMG/Resource/Closed_eye.png").scaled(ui->L_MOTION->width(),ui->L_MOTION->height(),Qt::KeepAspectRatio));
    ui->L_LED1->setPixmap(QPixmap(":/IMG/Resource/lamp_off.png").scaled(ui->L_LED1->width(),ui->L_LED1->height(),Qt::KeepAspectRatio));
    ui->L_LED2->setPixmap(QPixmap(":/IMG/Resource/lamp_off.png").scaled(ui->L_LED2->width(),ui->L_LED2->height(),Qt::KeepAspectRatio));
    ui->L_REL1->setPixmap(QPixmap(":/IMG/Resource/Relay_off.png").scaled(ui->L_REL1->width(),ui->L_REL1->height(),Qt::KeepAspectRatio));
    ui->L_REL2->setPixmap(QPixmap(":/IMG/Resource/Relay_off.png").scaled(ui->L_REL2->width(),ui->L_REL2->height(),Qt::KeepAspectRatio));
    ui->L_DK1->setPixmap(QPixmap(":/IMG/Resource/Button_off.png").scaled(ui->L_DK1->width(),ui->L_DK1->height(),Qt::KeepAspectRatio));
    ui->L_DK2->setPixmap(QPixmap(":/IMG/Resource/Button_off.png").scaled(ui->L_DK2->width(),ui->L_DK2->height(),Qt::KeepAspectRatio));

    connect(ui->L_LED1, SIGNAL(Clicked()), this, SLOT(L_LED1_clicked()));
    connect(ui->L_LED2, SIGNAL(Clicked()), this, SLOT(L_LED2_clicked()));
    connect(ui->L_REL1, SIGNAL(Clicked()), this, SLOT(L_REL1_clicked()));
    connect(ui->L_REL2, SIGNAL(Clicked()), this, SLOT(L_REL2_clicked()));

    on_B_Scan_clicked();

    Init();
}

MainWindow::~MainWindow()
{
    if (Serial->isOpen())
        Serial->close();

    delete UpdateDataTimer;
    delete Settings;
    delete Serial;
    delete ui;
}

void MainWindow::Send()
{
    QSerialPortInfo *PortCheck = new QSerialPortInfo(ui->CB_SerialPort->currentText());
    if(PortCheck->isNull())
        on_B_Connect_clicked();

    if (Serial->isOpen()){

        BufSend[0] = static_cast<uint8_t>(ui->SB_ID->value() & 0x00FF);
        BufSend[1] |= static_cast<uint8_t>((ui->SB_ID->value() & 0x0F00) >> 3);

        QByteArray Data = QByteArray::fromRawData(reinterpret_cast<const char*>(BufSend), sizeof(BufSend));

        QString str;
        for (int i = 0; i < 8; i++)
            str += static_cast<QString>(BufSend[i]).toLocal8Bit().toHex() + (i == 7 ? "" : ":");

        Serial->write(Data);

        qDebug() << "Sent to : " << QString().setNum(((BufSend[1] & 0xE0) << 3) | BufSend[0]) << " Message: " << str;

        qApp->processEvents();
    }
}

void MainWindow::RequestData()
{
    if (Serial->isOpen()){

        QByteArray Data = Serial->readAll();

        std::vector<unsigned char> buffer(Data.begin(), Data.end());

        QString str;
        for (int i = 0; i < 8; i++)
            str += static_cast<QString>(buffer.data()[i]).toLocal8Bit().toHex() + (i == 7 ? "" : ":");

        ProcessingReceivedData(buffer.data());

        qDebug() << "Taken from: " << QString().setNum(((buffer.data()[1] & 0xE0) << 3) | buffer.data()[0]) << "  Message: " << str;

        qApp->processEvents();
    }
}

void MainWindow::RequestUpdateData()
{
    memset(BufSend, 0, sizeof(BufSend));

    if (RequestUpdateDataFlag){

        BufSend[1] = LUX;

        Send();

        RequestUpdateDataFlag = false;

    }else {

        BufSend[1] = ADC;

        Send();

        RequestUpdateDataFlag = true;
    }
}

void MainWindow::Connected()
{
    ui->SB_ID->setEnabled(true);
    ui->S_PWM1->setEnabled(true);
    ui->S_PWM2->setEnabled(true);
    ui->S_PWM3->setEnabled(true);
    ui->L_LED1->setEnabled(true);
    ui->L_LED2->setEnabled(true);
    ui->L_REL1->setEnabled(true);
    ui->L_REL2->setEnabled(true);
    ui->B_Scan->setEnabled(false);
    ui->S_ALLPWM->setEnabled(true);
    ui->RB_Update->setEnabled(true);
    ui->TE_PWMSpeed->setEnabled(true);
    ui->CB_SerialPort->setEnabled(false);

    ui->B_Connect->setText("Disconnect");

    qDebug() << "Connect";

    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = INIT;
    BufSend[2] = MasterID & 0x0FF;
    BufSend[3] = static_cast<uint8_t>((MasterID & 0x0F00) >> 3);

    Send();

    ui->TE_PWMSpeed->setTime(Settings->value("TE_PWMSpeed").toTime());

    Connect = true;
}

void MainWindow::Init()
{
    connect(Serial, SIGNAL(readyRead()), this, SLOT(RequestData()));

    connect(UpdateDataTimer, SIGNAL(timeout()), SLOT(RequestUpdateData()));
}
