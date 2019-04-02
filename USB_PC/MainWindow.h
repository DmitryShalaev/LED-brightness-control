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

#include "libusb.h"
#include "CustomLabel.h"

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

    void RequestUpdateData();

    void ProcessingReceivedData();

    void TimeCheck();

    void MotionDetection(bool MotionDetected);

    void MaintainLuxLevel(double value);

    void RequestLuxLevel();

    void TurningOffTheLights();

    void on_B_Connect_clicked();

    void L_LED1_clicked();

    void L_LED2_clicked();

    void L_REL1_clicked();

    void L_REL2_clicked();

    void on_S_PWM1_valueChanged(int value);

    void on_S_PWM2_valueChanged(int value);

    void on_S_PWM3_valueChanged(int value);

    void on_RB_Update_clicked(bool checked);

    void on_S_ALLPWM_valueChanged(int value);

    void on_RB_AutomaticControl_clicked(bool checked);

    void on_actionAutomatic_control_setting_triggered();

    void SettingWindowSignal(int SB_MaintainLuxLevel,int SB_MaintainLuxLevelStep,
                             QTime TE_TurnOffLight, QTime TE_SpeedOnOffLight,
                             bool RB_TurnOffLight, bool RB_MaintainLuxLevel,
                             QTime TE_OnTime, QTime TE_OFFTime, bool RB_OnOffTime);

private:

    Ui::MainWindow *ui;

    libusb_device_handle *handle;

    QTime CurrentTime = QTime::currentTime();

    QTimer *RequestTimer = new QTimer;
    QTimer *MotionTimer = new QTimer;
    QTimer *RequestLuxTimer = new QTimer;
    QTimer *UpdateDataTimer = new QTimer;
    QTimer *OnOffTimer = new QTimer;

    uint8_t BufSend[6] = {0};
    uint8_t BufReceive[6] = {0};

    int ActualLength;
    int Res;

    bool Connect = false;

    bool LED1 = false;
    bool LED2 = false;
    bool REL1 = false;
    bool REL2 = false;

    bool RequestUpdateDataFlag = false;

    uint8_t PWM1 = 0;
    uint8_t PWM2 = 0;
    uint8_t PWM3 = 0;

    bool ALLPWMChanged = false;

    uint8_t MeanPWM = 0;

    uint8_t MaintainLuxLevelStep = 5;
    int MaintainLuxLevelValue = 0;

    int RequestLuxTime = 0;
    int MotionTime = 0;

    bool MaintainLux = false;

    bool TurnOffLightIsChecked = false;
    bool MaintainLuxLevelIsChecked = false;

    bool AutomaticControlActivated = false;

    bool OnOffTimeIsChecked = false;

    bool TheTimeHasCome = false;

    QTime OnTime;
    QTime OffTime;

};

#endif // MAINWINDOW_H
