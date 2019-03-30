#include "SettingWindow.h"
#include "ui_SettingWindow.h"

SettingWindow::SettingWindow(QWidget *parent) : QDialog(parent), ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::on_buttonBox_accepted()
{
    emit Signal(ui->SB_MaintainLuxLevel->value(), ui->SB_MaintainLuxLevelstep->value(),
                ui->TE_TurnOffLight->time(), ui->TE_SpeedOnOffLight->time(),
                ui->RB_TurnOffLight->isChecked(), ui->RB_MaintainLuxLevel->isChecked());
}
