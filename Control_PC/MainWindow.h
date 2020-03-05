#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "ui_MainWindow.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QSettings>
#include <QSerialPortInfo>
#include <QSerialPort>

#include "CustomLabel.h"
#include "../GENERAL/id.h"

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

    void Init();
    void Send();
    void RequestData();
    void RequestUpdateData();
    void ProcessingReceivedData(uint8_t Data[]);
    void on_B_Connect_clicked();
    void L_LED1_clicked();
    void L_LED2_clicked();
    void L_REL1_clicked();
    void L_REL2_clicked();
    void on_S_PWM1_sliderReleased();
    void on_S_PWM2_sliderReleased();
    void on_S_PWM3_sliderReleased();
    void on_RB_Update_clicked(bool checked);
    void on_S_ALLPWM_sliderReleased();
    void on_B_Scan_clicked();
    void Connected();
    void on_TE_PWMSpeed_userTimeChanged(const QTime &time);

private:

    Ui::MainWindow *ui;

    QTimer *UpdateDataTimer = new QTimer;

    QSerialPort *Serial = new QSerialPort;
    QSettings *Settings = new QSettings(this);

    uint16_t MasterID = 0x0;

    uint8_t BufSend[8] = {0};

    bool Connect = false;

    bool LED1 = false;
    bool LED2 = false;
    bool REL1 = false;
    bool REL2 = false;

    bool RequestUpdateDataFlag = false;

    uint8_t PWM1 = 0;
    uint8_t PWM2 = 0;
    uint8_t PWM3 = 0;

    uint8_t MeanPWM = 0;
};

#endif // MAINWINDOW_H
