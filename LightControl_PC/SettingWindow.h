#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QDialog>
#include <QTime>
#include <QSettings>

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
    void Signal();
};

#endif // SETTINGWINDOW_H
