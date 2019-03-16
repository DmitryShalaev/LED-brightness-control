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

    void TimerInit();

    void Send();

    void RequestData();

    void ProcessingReceivedData();

    void MotionDetection(bool MotionDetected);

    void MaintainLuxLevel(double value);

    void RequestLuxLevel();

    void TurningOffTheLights();

    void on_B_Connect_clicked();

    void on_B_LED1_clicked();

    void on_B_LED2_clicked();

    void on_B_REL1_clicked();

    void on_B_REL2_clicked();

    void on_S_PWM1_valueChanged(int value);

    void on_S_PWM2_valueChanged(int value);

    void on_S_PWM3_valueChanged(int value);

    void on_TE_SpeedOnOffLight_editingFinished();

    void on_SB_PWM1_editingFinished();

    void on_SB_PWM2_editingFinished();

    void on_SB_PWM3_editingFinished();

    void on_RB_MaintainLuxLevel_clicked(bool checked);

    void on_RB_ADC1_clicked();

    void on_RB_ADC2_clicked();

    void on_RB_BH1750_clicked();

    void on_SB_MaintainLuxLevelstep_valueChanged(int arg1);

private:

    Ui::MainWindow *ui;

    libusb_device_handle *handle;

    QTimer *RequestTimer = new QTimer;
    QTimer *MotionTimer = new QTimer;
    QTimer *RequestLuxTimer = new QTimer;

    uint8_t BufSend[6] = {0};
    uint8_t BufReceive[6] = {0};

    int ActualLength;
    int Res;

    bool Connect = false;

    bool LED1 = false;
    bool LED2 = false;
    bool REL1 = false;
    bool REL2 = false;

    uint8_t PWM1 = 0;
    uint8_t PWM2 = 0;
    uint8_t PWM3 = 0;

    uint8_t MeanPWM = 0;

    uint8_t MaintainLuxLevelStep = 5;

    bool MaintainLux = false;

};

#endif // MAINWINDOW_H
