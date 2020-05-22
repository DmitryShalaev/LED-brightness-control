#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

#include "../general/id.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

	Init();

	on_B_Scan_clicked();
}

MainWindow::~MainWindow() {
	if (Serial->isOpen())
		Serial->close();

	delete UpdateDataTimer;
	delete Settings;
	delete Serial;
	delete ui;
}

void MainWindow::Send(uint8_t dataToSend[], const bool broadcast) {
	const QSerialPortInfo* PortCheck = new QSerialPortInfo(ui->CB_SerialPort->currentText());
	
	if (!PortCheck->isNull() && Serial->isOpen()) {
		
		dataToSend[0] = static_cast<uint8_t>((broadcast ? 0x0 : ui->SB_ID->value()) & 0x00FF);
		dataToSend[1] |= static_cast<uint8_t>(((broadcast ? 0x0 : ui->SB_ID->value()) & 0x0F00) >> 3);

		QByteArray Data = QByteArray::fromRawData(reinterpret_cast<const char*>(dataToSend), sizeof(dataToSend));
		Data.resize(PACKET_SIZE);

		qDebug() << "Sent to :   " << QString().setNum(((dataToSend[1] & 0xE0) << 3) | dataToSend[0]) << " Message: " <<
								ByteArrayToString(Data) << " Time: " << QDateTime::currentDateTime().toString("hh:mm:ss.zzz");

		Serial->write(Data);
		
	} else {
		on_B_Connect_clicked();
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

void MainWindow::Connected() {
	ui->SB_ID->setEnabled(true);
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

	ui->TE_PWMSpeed->setTime(Settings->value("TE_PWMSpeed").toTime());

	Connect = true;
}

void MainWindow::Init() {
	ChangePixmap(ui->L_OUT1, ":/IMG/Resource/Out_off.png");
	ChangePixmap(ui->L_OUT2, ":/IMG/Resource/Out_off.png");
	ChangePixmap(ui->L_OUT3, ":/IMG/Resource/Out_off.png");
	ChangePixmap(ui->L_OUT4, ":/IMG/Resource/Out_off.png");

	ChangePixmap(ui->L_IN1, ":/IMG/Resource/Closed_eye.png");
	ChangePixmap(ui->L_IN2, ":/IMG/Resource/Closed_eye.png");
	ChangePixmap(ui->L_IN3, ":/IMG/Resource/Closed_eye.png");

	connect(ui->L_OUT1, SIGNAL(Clicked()), this, SLOT(L_OUT1_clicked()));
	connect(ui->L_OUT2, SIGNAL(Clicked()), this, SLOT(L_OUT2_clicked()));
	connect(ui->L_OUT3, SIGNAL(Clicked()), this, SLOT(L_OUT3_clicked()));
	connect(ui->L_OUT4, SIGNAL(Clicked()), this, SLOT(L_OUT4_clicked()));

	connect(Serial, SIGNAL(readyRead()), this, SLOT(RequestData()));

	connect(UpdateDataTimer, SIGNAL(timeout()), this, SLOT(RequestUpdateData()));
}
