#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    ui->L_DK3->setPixmap(QPixmap(":/IMG/Resource/Closed_eye.png").scaled(ui->L_DK3->width(),ui->L_DK3->height(),Qt::KeepAspectRatio));
    ui->L_LED1->setPixmap(QPixmap(":/IMG/Resource/lamp_off.png").scaled(ui->L_LED1->width(),ui->L_LED1->height(),Qt::KeepAspectRatio));
    ui->L_LED2->setPixmap(QPixmap(":/IMG/Resource/lamp_off.png").scaled(ui->L_LED2->width(),ui->L_LED2->height(),Qt::KeepAspectRatio));
    ui->L_REL1->setPixmap(QPixmap(":/IMG/Resource/Relay_off.png").scaled(ui->L_REL1->width(),ui->L_REL1->height(),Qt::KeepAspectRatio));
    ui->L_REL2->setPixmap(QPixmap(":/IMG/Resource/Relay_off.png").scaled(ui->L_REL2->width(),ui->L_REL2->height(),Qt::KeepAspectRatio));
    ui->L_DK1->setPixmap(QPixmap(":/IMG/Resource/Button_off.png").scaled(ui->L_DK1->width(),ui->L_DK1->height(),Qt::KeepAspectRatio));
    ui->L_DK2->setPixmap(QPixmap(":/IMG/Resource/Button_off.png").scaled(ui->L_DK2->width(),ui->L_DK2->height(),Qt::KeepAspectRatio));

    TimerInit();
    libusb_init(nullptr);
}

MainWindow::~MainWindow()
{
    libusb_exit(nullptr);
    delete ui;
}

void MainWindow::Send()
{
    BufSend[0] = 0x01;        //REPORT ID

    Res =  libusb_bulk_transfer(handle, EP_OUT, BufSend, 6, &ActualLength, 0);

    if (Res == 0 && ActualLength == 6){

        ui->statusBar->showMessage("Successful data transfer");

    }else if(Connect){

        on_B_Connect_clicked();
        QMessageBox::critical(this, tr("Error"), tr("Error data transfer"));
    }

    qApp->processEvents();
}

void MainWindow::RequestData()
{
    Res = libusb_bulk_transfer(handle, EP_IN, BufReceive, 6, &ActualLength, 1);

    if (Res == 0 && ActualLength == 6){

        qDebug() << "Reed successful! " << ActualLength;

        ProcessingReceivedData();

    }else{

        qDebug() << "No Reed! ";

    }

    qApp->processEvents();
}

void MainWindow::RequestUpdateData()
{
    if (RequestUpdateDataFlag){

        memset(BufSend, 0, sizeof(BufSend));

        BufSend[1] = 0x0B;

        Send();

        RequestUpdateDataFlag = false;

    }else {

        memset(BufSend, 0, sizeof(BufSend));

        BufSend[1] = 0x08;

        Send();

        RequestUpdateDataFlag = true;
    }
}

void MainWindow::TimerInit()
{
    MotionTimer->setSingleShot(true);
    connect(MotionTimer, SIGNAL(timeout()), SLOT(TurningOffTheLights()));

    connect(RequestTimer, SIGNAL(timeout()), SLOT(RequestData()));

    connect(RequestLuxTimer, SIGNAL(timeout()), SLOT(RequestLuxLevel()));

    connect(UpdateDataTimer, SIGNAL(timeout()), SLOT(RequestUpdateData()));
}
