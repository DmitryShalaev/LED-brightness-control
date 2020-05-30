#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QJsonArray>
#include <QMainWindow>
#include <QSerialPort>
#include <QSettings>
#include <QTimer>

#include "../general/id.h"

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
	void ChangeRecipientID();
	void DebugButton();
	void AutomationCallback(bool init = false);
	void InitialStateRequest();

	private:

	void Init();
	void ConnectionCheck();
	void Send(uint8_t dataToSend[], bool broadcast = false, uint16_t R_ID = NULL);
	void ProcessingReceivedData(const uint8_t Data[]);
	void UpdateMainWindow();
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

	uint8_t dataToSend[PACKET_SIZE] = {0};
	uint16_t MasterID = 0x0;

	bool Connect = false;

	struct NodeStatus {
		uint8_t logicIO = 0x0;
		uint8_t PWM1 = 0;
		uint8_t PWM2 = 0;
		uint8_t PWM3 = 0;
		uint8_t EstimatedValue = 0;
		double ADC1 = 0.0;
		double ADC2 = 0.0;
		double LX = 0.0;
		QJsonArray SlavesNodes;
	};

	QHash<uint16_t, NodeStatus>* HashNodesStatus = new QHash<uint16_t, NodeStatus>;

	QJsonArray jID_OfAllNodes;
	
	struct {
		uint16_t Counter = 0;
		QTimer* Timer = nullptr;
	} InitialState;

	struct {
		bool CanAutomatically = false;
		bool LUXRequested = false;
		uint16_t ExternalCounter = 0;
		uint16_t InternalCounter = 0;
		QTimer* Timer = nullptr;
	} Automatically;

	bool RequestUpdateDataFlag = false;
};

#endif // MAINWINDOW_H
