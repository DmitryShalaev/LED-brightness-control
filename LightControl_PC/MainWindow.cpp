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

    on_B_Scan_clicked();

    Init();
}

MainWindow::~MainWindow()
{
    if (Serial->isOpen())
        Serial->close();

    delete ui;
}

void MainWindow::Send()
{
    if (Serial->isOpen()){

        QByteArray Data = QByteArray::fromRawData(reinterpret_cast<const char*>(BufSend), sizeof(BufSend));
        Serial->write(Data);
        qApp->processEvents();
    }
}

void MainWindow::RequestData()
{
    if (Serial->isOpen()){

        QByteArray Data = Serial->readAll();

        std::vector<unsigned char> buffer(Data.begin(), Data.end());
        ProcessingReceivedData(buffer.data());

        qApp->processEvents();
    }
}

void MainWindow::RequestUpdateData()
{
    memset(BufSend, 0, sizeof(BufSend));

    if (RequestUpdateDataFlag){

        BufSend[0] = LUX;

        Send();

        RequestUpdateDataFlag = false;

    }else {

        BufSend[0] = ADC;

        Send();

        RequestUpdateDataFlag = true;
    }
}

void MainWindow::Connected()
{
    ui->S_PWM1->setEnabled(true);
    ui->S_PWM2->setEnabled(true);
    ui->S_PWM3->setEnabled(true);
    ui->S_ALLPWM->setEnabled(true);
    ui->RB_Update->setEnabled(true);
    ui->actionAutomatic_control_setting->setEnabled(true);
    ui->B_Scan->setEnabled(false);
    ui->CB_SerialPort->setEnabled(false);

    connect(ui->L_LED1, SIGNAL(Clicked()), this, SLOT(L_LED1_clicked()));
    connect(ui->L_LED2, SIGNAL(Clicked()), this, SLOT(L_LED2_clicked()));
    connect(ui->L_REL1, SIGNAL(Clicked()), this, SLOT(L_REL1_clicked()));
    connect(ui->L_REL2, SIGNAL(Clicked()), this, SLOT(L_REL2_clicked()));

    ui->B_Connect->setText("Disconnect");

    ui->statusBar->showMessage("Connect");

    memset(BufSend, 0, sizeof(BufSend));
    BufSend[0] = INIT;
    Send();

    QSettings Settings("LightControl", "Main");

    if(Settings.value("Save").toBool()){

        MaintainLuxLevelValue = Settings.value("SB_MaintainLuxLevel").toInt();
        MaintainLuxLevelStep = static_cast<uint8_t>(Settings.value("SB_MaintainLuxLevelstep").toInt());
        MotionTime = Settings.value("TE_TurnOffLight").toTime().minute() * 60000 + Settings.value("TE_TurnOffLight").toTime().second() * 1000;
        RequestLuxTime = Settings.value("TE_SpeedOnOffLight").toTime().minute() * 60000 + Settings.value("TE_SpeedOnOffLight").toTime().second() * 1000;
        TurnOffLightIsChecked = Settings.value("RB_TurnOffLight").toBool();
        MaintainLuxLevelIsChecked = Settings.value("RB_MaintainLuxLevel").toBool();
        OnOffTimeIsChecked = Settings.value("RB_OnOffTime").toBool();
        OnTime = Settings.value("TE_OnTime").toTime();
        OffTime = Settings.value("TE_OffTime").toTime();

        memset(BufSend, 0, sizeof(BufSend));

        BufSend[0] = TIME;

        BufSend[1] = static_cast<uint8_t> (Settings.value("TE_SpeedOnOffLight").toTime().minute());
        BufSend[2] = static_cast<uint8_t> (Settings.value("TE_SpeedOnOffLight").toTime().second());

        Send();

        ui->RB_AutomaticControl->setEnabled(true);

    }else{

        on_actionAutomatic_control_setting_triggered();
    }

    Connect = true;
}


void MainWindow::Init()
{
    MotionTimer->setSingleShot(true);
    connect(MotionTimer, SIGNAL(timeout()), SLOT(TurningOffTheLights()));

    connect(RequestLuxTimer, SIGNAL(timeout()), SLOT(RequestLuxLevel()));

    connect(UpdateDataTimer, SIGNAL(timeout()), SLOT(RequestUpdateData()));

    connect(OnOffTimer, SIGNAL(timeout()), SLOT(TimeCheck()));

    connect(Serial, SIGNAL(readyRead()), this, SLOT(RequestData()));
}
