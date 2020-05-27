#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QJsonArray>
#include <QMainWindow>
#include <QSerialPort>
#include <QSettings>
#include <QTimer>

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
	void PWMSpeedChange(const QTime& time);
	void ButtonProcessing();
	void SliderProcessing();

	private:

	void Init();
	void ConnectionCheck();
	void Send(uint8_t dataToSend[], bool broadcast = false);
	void ProcessingReceivedData(const uint8_t Data[]);
	void SearchForUARTDevices();
	void Connected();

	static QString ByteArrayToString(const QByteArray& arr);
	bool LoadingJSONFile();

	template <typename T>
	static void ChangePixmap(T& Label, const QString& str) {
		Label->setPixmap(QPixmap(str).scaled(Label->width(), Label->height(), Qt::KeepAspectRatio));
	}

	Ui::MainWindow* ui;

	QTimer* UpdateDataTimer = new QTimer(this);

	QSerialPort* Serial = new QSerialPort(this);
	QSettings* Settings = new QSettings(QCoreApplication::applicationDirPath() +
																			"/Settings.ini", QSettings::IniFormat, this);

	uint16_t MasterID = 0x0;

	bool Connect = false;

	struct NodeStatus {
		uint8_t logicIO = 0x0;
		uint8_t PWM1 = 0;
		uint8_t PWM2 = 0;
		uint8_t PWM3 = 0;
		QJsonArray SlavesNodes;
	};

	QHash<uint16_t, NodeStatus> *HashNodesStatus = new QHash<uint16_t, NodeStatus>;

	bool OUT1 = false;
	bool OUT2 = false;
	bool OUT3 = false;
	bool OUT4 = false;

	bool RequestUpdateDataFlag = false;
};

#endif // MAINWINDOW_H
