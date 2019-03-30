#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QDialog>
#include <QTime>

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr);
    ~SettingWindow();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SettingWindow *ui;

signals:
    void Signal(int SB_MaintainLuxLevel,int SB_MaintainLuxLevelStep,
                QTime TE_TurnOffLight, QTime TE_SpeedOnOffLight,
                bool RB_TurnOffLight, bool RB_MaintainLuxLevel);
};

#endif // SETTINGWINDOW_H
