#include "MainWindow.h"
#include "SettingWindow.h"

void MainWindow::on_actionAutomatic_control_setting_triggered()
{
    SettingWindow SettingWindow;

    connect(&SettingWindow, &SettingWindow::Signal, this, &MainWindow::SettingWindowSignal);

    SettingWindow.exec();
}

void MainWindow::SettingWindowSignal()
{
    memset(BufSend, 0, sizeof(BufSend));

    QSettings Settings("LightControl", "Main");

    BufSend[1] = TIME;

    BufSend[2] = static_cast<uint8_t> (Settings.value("TE_SpeedOnOffLight").toTime().minute());
    BufSend[3] = static_cast<uint8_t> (Settings.value("TE_SpeedOnOffLight").toTime().second());

    Send();

    RequestLuxTime = Settings.value("TE_SpeedOnOffLight").toTime().minute() * 60000 + Settings.value("TE_SpeedOnOffLight").toTime().second() * 1000;
    MotionTime = Settings.value("TE_TurnOffLight").toTime().minute() * 60000 + Settings.value("TE_TurnOffLight").toTime().second() * 1000;

    TurnOffLightIsChecked = Settings.value("RB_TurnOffLight").toBool();
    MaintainLuxLevelIsChecked = Settings.value("RB_MaintainLuxLevel").toBool();
    OnOffTimeIsChecked = Settings.value("RB_OnOffTime").toBool();

    OnTime = Settings.value("TE_OnTime").toTime();
    OffTime = Settings.value("TE_OffTime").toTime();

    MaintainLuxLevelStep = static_cast<uint8_t>(Settings.value("SB_MaintainLuxLevelstep").toInt());
    MaintainLuxLevelValue = Settings.value("SB_MaintainLuxLevel").toInt();

    ui->RB_AutomaticControl->setEnabled(true);
}

