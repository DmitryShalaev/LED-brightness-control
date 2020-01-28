#include "MainWindow.h"
#include "SettingWindow.h"

void MainWindow::on_actionSetting_triggered()
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
}

