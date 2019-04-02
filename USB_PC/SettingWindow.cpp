#include "SettingWindow.h"
#include "ui_SettingWindow.h"

SettingWindow::SettingWindow(QWidget *parent) : QDialog(parent), ui(new Ui::SettingWindow)
{
    ui->setupUi(this);

    QSettings Settings("USBProtocol", "Main");

    ui->SB_MaintainLuxLevel->setValue(Settings.value("SB_MaintainLuxLevel").toInt());
    ui->SB_MaintainLuxLevelstep->setValue(Settings.value("SB_MaintainLuxLevelstep").toInt());
    ui->TE_TurnOffLight->setTime(Settings.value("TE_TurnOffLight").toTime());
    ui->TE_SpeedOnOffLight->setTime(Settings.value("TE_SpeedOnOffLight").toTime());
    ui->RB_TurnOffLight->setChecked(Settings.value("RB_TurnOffLight").toBool());
    ui->RB_MaintainLuxLevel->setChecked(Settings.value("RB_MaintainLuxLevel").toBool());
    ui->RB_OnOffTime->setChecked(Settings.value("RB_OnOffTime").toBool());
    ui->TE_OnTime->setTime(Settings.value("TE_OnTime").toTime());
    ui->TE_OffTime->setTime(Settings.value("TE_OffTime").toTime());

}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::on_buttonBox_accepted()
{
    QSettings Settings("USBProtocol", "Main");

    Settings.setValue("Save", true);

    Settings.setValue("SB_MaintainLuxLevel", ui->SB_MaintainLuxLevel->value());
    Settings.setValue("SB_MaintainLuxLevelstep", ui->SB_MaintainLuxLevelstep->value());
    Settings.setValue("TE_TurnOffLight", ui->TE_TurnOffLight->time());
    Settings.setValue("TE_SpeedOnOffLight", ui->TE_SpeedOnOffLight->time());
    Settings.setValue("RB_TurnOffLight", ui->RB_TurnOffLight->isChecked());
    Settings.setValue("RB_MaintainLuxLevel", ui->RB_MaintainLuxLevel->isChecked());
    Settings.setValue("RB_OnOffTime", ui->RB_OnOffTime->isChecked());
    Settings.setValue("TE_OnTime", ui->TE_OnTime->time());
    Settings.setValue("TE_OffTime", ui->TE_OffTime->time());

    emit Signal(ui->SB_MaintainLuxLevel->value(), ui->SB_MaintainLuxLevelstep->value(),
                ui->TE_TurnOffLight->time(), ui->TE_SpeedOnOffLight->time(),
                ui->RB_TurnOffLight->isChecked(), ui->RB_MaintainLuxLevel->isChecked(),
                ui->TE_OnTime->time(), ui->TE_OffTime->time(), ui->RB_OnOffTime->isChecked());
}
