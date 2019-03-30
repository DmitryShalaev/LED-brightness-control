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
                                     bool RB_TurnOffLight, bool RB_MaintainLuxLevel)
{
    memset(BufSend, 0, sizeof(BufSend));

    BufSend[1] = 0x0C;

    BufSend[2] = static_cast<uint8_t> (TE_SpeedOnOffLight.minute());
    BufSend[3] = static_cast<uint8_t> (TE_SpeedOnOffLight.second());

    Send();

    RequestLuxTime = TE_SpeedOnOffLight.minute() * 60000 + TE_SpeedOnOffLight.second() * 1000;

    MotionTime = TE_TurnOffLight.minute() * 60000 + TE_TurnOffLight.second() * 1000;

    MaintainLuxLevelValue = SB_MaintainLuxLevel;

    TurnOffLightIsChecked = RB_TurnOffLight;
    MaintainLuxLevelIsChecked =  RB_MaintainLuxLevel;

    MaintainLuxLevelStep = static_cast<uint8_t>(SB_MaintainLuxLevelStep);

    ui->RB_AutomaticControl->setEnabled(true);
}

