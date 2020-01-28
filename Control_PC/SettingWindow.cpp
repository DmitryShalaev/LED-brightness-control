#include "SettingWindow.h"
#include "ui_SettingWindow.h"

SettingWindow::SettingWindow(QWidget *parent) : QDialog(parent), ui(new Ui::SettingWindow)
{
    ui->setupUi(this);

    QSettings Settings("LightControl", "Main");

    ui->TE_SpeedOnOffLight->setTime(Settings.value("TE_SpeedOnOffLight").toTime());

}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::on_buttonBox_accepted()
{
    QSettings Settings("LightControl", "Main");

    Settings.setValue("Save", true);

    Settings.setValue("TE_SpeedOnOffLight", ui->TE_SpeedOnOffLight->time());

    emit Signal();
}
