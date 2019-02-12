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
