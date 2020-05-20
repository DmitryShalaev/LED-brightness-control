#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QSettings>
#include <QSerialPortInfo>
#include <QSerialPort>

namespace Ui {
	class MainWindow;
}

class MainWindow final : public QMainWindow {
	Q_OBJECT

	public:

	explicit MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	private slots:

	void RequestData();
	void RequestUpdateData();
	void on_B_Connect_clicked();
	void L_OUT1_clicked();
	void L_OUT2_clicked();
	void L_OUT3_clicked();
	void L_OUT4_clicked();
	void on_S_PWM1_sliderReleased();
	void on_S_PWM2_sliderReleased();
	void on_S_PWM3_sliderReleased();
	void on_RB_Update_clicked(bool checked);
	void on_S_ALLPWM_sliderReleased();
	void on_B_Scan_clicked();
	void on_TE_PWMSpeed_userTimeChanged(const QTime& time);

	private:

	void Init();
	void Send(uint8_t* BufSend, bool broadcast = false);
	void ProcessingReceivedData(const uint8_t Data[8]);
	void Connected();

	static QString ByteArrayToString(const QByteArray& arr);

	template <typename T>
	static void ChangePixmap(T& Label, const QString& str) {
		Label->setPixmap(QPixmap(str).scaled(Label->width(), Label->height(), Qt::KeepAspectRatio));
	}

	Ui::MainWindow* ui;

	QTimer* UpdateDataTimer = new QTimer(this);

	QSerialPort* Serial = new QSerialPort(this);
	QSettings* Settings = new QSettings(this);

	uint16_t MasterID = 0x0;

	bool Connect = false;

	bool OUT1 = false;
	bool OUT2 = false;
	bool OUT3 = false;
	bool OUT4 = false;

	bool RequestUpdateDataFlag = false;

};

#endif // MAINWINDOW_H
