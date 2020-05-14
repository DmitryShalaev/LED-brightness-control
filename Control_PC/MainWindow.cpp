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

void MainWindow::Send(const bool broadcast) {
	const QSerialPortInfo* PortCheck = new QSerialPortInfo(ui->CB_SerialPort->currentText());
	if (PortCheck->isNull())
		on_B_Connect_clicked();

	if (Serial->isOpen()) {
		BufSend[0] = static_cast<uint8_t>((broadcast ? 0x0 : ui->SB_ID->value()) & 0x00FF);
		BufSend[1] |= static_cast<uint8_t>(((broadcast ? 0x0 : ui->SB_ID->value()) & 0x0F00) >> 3);

		const QByteArray Data = QByteArray::fromRawData(reinterpret_cast<const char*>(BufSend), sizeof(BufSend));

		qDebug() << "Sent to :   " << QString().setNum(((BufSend[1] & 0xE0) << 3) | BufSend[0]) << " Message: " <<
			ByteArrayToString(Data) << " Time: " << QDateTime::currentDateTime().toString("hh:mm:ss.zzz");

		Serial->write(Data);

		qApp->processEvents();
	}
}

void MainWindow::RequestData() {
	if (Serial->isOpen()) {
		QByteArray Data = Serial->readAll();

		std::vector<unsigned char> buffer(Data.begin(), Data.end());

		qDebug() << "Taken from: " << QString().setNum(((buffer.data()[1] & 0xE0) << 3) | buffer.data()[0]) << " Message: "
			<< ByteArrayToString(Data) << " Time: " << QDateTime::currentDateTime().toString("hh:mm:ss.zzz");

		ProcessingReceivedData(buffer.data());

		qApp->processEvents();
	}
}

void MainWindow::RequestUpdateData() {
	memset(BufSend, 0, sizeof(BufSend));

	if (RequestUpdateDataFlag) {
		BufSend[1] = LUX;
		Send();

		RequestUpdateDataFlag = false;
	} else {
		BufSend[1] = ADC;
		Send();

		RequestUpdateDataFlag = true;
	}
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

	memset(BufSend, 0, sizeof(BufSend));

	BufSend[1] = INIT;
	BufSend[2] = MasterID & 0x0FF;
	BufSend[3] = static_cast<uint8_t>((MasterID & 0x0F00) >> 3);

	Send(true);

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
