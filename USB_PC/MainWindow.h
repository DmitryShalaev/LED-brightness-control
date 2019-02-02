#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "ui_MainWindow.h"
#include <QDebug>
#include <QTimer>

#include "libusb.h"

#define VID 0x483
#define PID 0x5750

#define EP_OUT 0x01
#define EP_IN 0x81

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_B_Connect_clicked();

    void Send();

    void RequestData();

    void ProcessingReceivedData();

    void on_B_LED1_clicked();

    void on_B_LED2_clicked();

    void on_B_REL1_clicked();

    void on_B_REL2_clicked();

    void on_S_PWM1_valueChanged(int value);

    void on_S_PWM2_valueChanged(int value);

    void on_S_PWM3_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    libusb_device_handle *handle;

    uint8_t BufSend[10] = {0};
    uint8_t BufReceive[10] = {0};

    int ActualLength;
    int Res;

    bool Connect = false;

    bool LED1 = false;
    bool LED2 = false;
    bool REL1 = false;
    bool REL2 = false;

};

#endif // MAINWINDOW_H
