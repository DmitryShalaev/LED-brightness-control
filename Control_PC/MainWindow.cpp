#include "MainWindow.h"
#include <QDebug>
#include "ui_MainWindow.h"

#include "../general/id.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

	Init();
	SearchForUARTDevices();
}

MainWindow::~MainWindow() {
	if (Serial->isOpen())
		Serial->close();

	delete UpdateDataTimer;
	delete Settings;
	delete Serial;
	delete ui;
}

void MainWindow::ConnectionCheck() {
	if (!Connect) {
		if (Serial->isOpen())
			Serial->close();

		Serial->setPortName(ui->CB_SerialPort->currentText());
		Serial->setBaudRate(QSerialPort::Baud115200);
		Serial->setDataBits(QSerialPort::Data8);
		Serial->setParity(QSerialPort::NoParity);
		Serial->setStopBits(QSerialPort::OneStop);
		Serial->setFlowControl(QSerialPort::NoFlowControl);

		if (Serial->open(QIODevice::ReadWrite)) {

			uint8_t dataToSend[PACKET_SIZE] = {0};

			dataToSend[1] = CONNECTED;

			Send(dataToSend, true);

		} else {
			qCritical() << "Connect error";
		}

	} else {
		if (Serial->isOpen())
			Serial->close();

		ui->CB_ID->setEnabled(false);
		ui->B_Scan->setEnabled(true);
		ui->L_OUT1->setEnabled(false);
		ui->L_OUT2->setEnabled(false);
		ui->L_OUT3->setEnabled(false);
		ui->L_OUT4->setEnabled(false);
		ui->S_PWM1->setEnabled(false);
		ui->S_PWM2->setEnabled(false);
		ui->S_PWM3->setEnabled(false);
		ui->S_ALLPWM->setEnabled(false);
		ui->RB_Update->setEnabled(false);
		ui->RB_Update->setChecked(false);
		ui->TE_PWMSpeed->setEnabled(false);
		ui->CB_SerialPort->setEnabled(true);

		ui->B_Connect->setText("Connect");

		qDebug() << "Disconnect";

		UpdateDataTimer->stop();

		Connect = false;
	}
}

void MainWindow::Connected() {
	ui->CB_ID->setEnabled(true);
	ui->S_PWM1->setEnabled(true);
	ui->S_PWM2->setEnabled(true);
	ui->S_PWM3->setEnabled(true);
	ui->L_OUT1->setEnabled(true);
	ui->L_OUT2->setEnabled(true);
	ui->L_OUT3->setEnabled(true);
	ui->L_OUT4->setEnabled(true);
	ui->B_Scan->setEnabled(false);
	ui->S_ALLPWM->setEnabled(true);
	ui->RB_Update->setEnabled(true);
	ui->TE_PWMSpeed->setEnabled(true);
	ui->CB_SerialPort->setEnabled(false);

	ui->B_Connect->setText("Disconnect");

	qDebug() << "Connect";

	uint8_t dataToSend[PACKET_SIZE] = {0};

	dataToSend[1] = INIT;
	dataToSend[2] = MasterID & 0x0FF;
	dataToSend[3] = static_cast<uint8_t>((MasterID & 0x0F00) >> 3);

	Send(dataToSend, true);

	ui->TE_PWMSpeed->setTime(Settings->value("PWMSpeed").toTime());

	Connect = true;
}

void MainWindow::SearchForUARTDevices() {
	qDebug() << "Searching for compatible devices";

	ui->CB_SerialPort->clear();
	const QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();

	if (!infos.isEmpty()) {
		for (const QSerialPortInfo& info : infos) {
			ui->CB_SerialPort->addItem(info.portName());
			qDebug() << info.portName() << info.description();
		}
	} else {
		qDebug() << "Could not find compatible devices";
	}
}

void MainWindow::Send(uint8_t dataToSend[], const bool broadcast) {
	const QSerialPortInfo* PortCheck = new QSerialPortInfo(ui->CB_SerialPort->currentText());

	if (!PortCheck->isNull() && Serial->isOpen()) {

		const uint16_t R_ID = ui->CB_ID->currentText().toInt();
		dataToSend[0] = static_cast<uint8_t>((broadcast ? 0x0 : R_ID) & 0x00FF);
		dataToSend[1] |= static_cast<uint8_t>(((broadcast ? 0x0 : R_ID) & 0x0F00) >> 3);

		QByteArray Data = QByteArray::fromRawData(reinterpret_cast<const char*>(dataToSend), sizeof(dataToSend));
		Data.resize(PACKET_SIZE);

		qDebug() << "Sent to :   " << QString().setNum(R_ID) << " Message: " << ByteArrayToString(Data) << " Time: " <<
			QDateTime::currentDateTime().toString("hh:mm:ss.zzz");

		Serial->write(Data);

	} else {
		ConnectionCheck();
	}

	qApp->processEvents();
}

void MainWindow::RequestData() {
	QByteArray Data = Serial->readAll();

	std::vector<unsigned char> buffer(Data.begin(), Data.end());

	qDebug() << "Taken from: " << QString().setNum(((buffer[1] & 0xE0) << 3) | buffer[0]) << " Message: " <<
		ByteArrayToString(Data) << " Time: " << QDateTime::currentDateTime().toString("hh:mm:ss.zzz");

	ProcessingReceivedData(buffer.data());

	qApp->processEvents();
}

void MainWindow::RequestUpdateData() {
	uint8_t dataToSend[PACKET_SIZE] = {0};

	if (RequestUpdateDataFlag) {
		dataToSend[1] = LUX;
		RequestUpdateDataFlag = false;
	} else {
		dataToSend[1] = ADC;
		RequestUpdateDataFlag = true;
	}

	Send(dataToSend);
}

void MainWindow::Init() {
	ChangePixmap(ui->L_OUT1, ":/IMG/Resource/Out_off.png");
	ChangePixmap(ui->L_OUT2, ":/IMG/Resource/Out_off.png");
	ChangePixmap(ui->L_OUT3, ":/IMG/Resource/Out_off.png");
	ChangePixmap(ui->L_OUT4, ":/IMG/Resource/Out_off.png");

	ChangePixmap(ui->L_IN1, ":/IMG/Resource/Closed_eye.png");
	ChangePixmap(ui->L_IN2, ":/IMG/Resource/Closed_eye.png");
	ChangePixmap(ui->L_IN3, ":/IMG/Resource/Closed_eye.png");

	connect(ui->L_OUT1, SIGNAL(Clicked()), this, SLOT(ButtonProcessing()));
	connect(ui->L_OUT2, SIGNAL(Clicked()), this, SLOT(ButtonProcessing()));
	connect(ui->L_OUT3, SIGNAL(Clicked()), this, SLOT(ButtonProcessing()));
	connect(ui->L_OUT4, SIGNAL(Clicked()), this, SLOT(ButtonProcessing()));

	connect(Serial, SIGNAL(readyRead()), this, SLOT(RequestData()));

	connect(UpdateDataTimer, SIGNAL(timeout()), this, SLOT(RequestUpdateData()));
}
