#include "MainWindow.h"
#include "SettingWindow.h"

void MainWindow::on_actionAutomatic_control_setting_triggered()
{
    SettingWindow SettingWindow;

    connect(&SettingWindow, &SettingWindow::Signal, this, &MainWindow::SettingWindowSignal);

    SettingWindow.exec();
}

void MainWindow::SettingWindowSignal(int SB_MaintainLuxLevel,int SB_MaintainLuxLevelStep,
                                     QTime TE_TurnOffLight, QTime TE_SpeedOnOffLight,
                                     bool RB_TurnOffLight, bool RB_MaintainLuxLevel,
                                     QTime TE_OnTime, QTime TE_OFFTime, bool RB_OnOffTime)
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = TIME;

    BufSend[2] = static_cast<uint8_t> (TE_SpeedOnOffLight.minute());
    BufSend[3] = static_cast<uint8_t> (TE_SpeedOnOffLight.second());

    Send();

    RequestLuxTime = TE_SpeedOnOffLight.minute() * 60000 + TE_SpeedOnOffLight.second() * 1000;
    MotionTime = TE_TurnOffLight.minute() * 60000 + TE_TurnOffLight.second() * 1000;

    TurnOffLightIsChecked = RB_TurnOffLight;
    MaintainLuxLevelIsChecked =  RB_MaintainLuxLevel;
    OnOffTimeIsChecked = RB_OnOffTime;

    OnTime = TE_OnTime;
    OffTime = TE_OFFTime;

    MaintainLuxLevelStep = static_cast<uint8_t>(SB_MaintainLuxLevelStep);
    MaintainLuxLevelValue = SB_MaintainLuxLevel;

    ui->RB_AutomaticControl->setEnabled(true);
}

