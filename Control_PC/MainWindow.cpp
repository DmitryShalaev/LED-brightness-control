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

	delete Automatically.Timer;
	delete InitialState.Timer;
	delete UpdateDataTimer;
	delete Settings;
	delete Serial;
	delete ui;
}

void MainWindow::UpdateMainWindow() {
	const uint16_t R_ID = ui->CB_ID->currentText().toUInt();

	const NodeStatus Node = HashNodesStatus->value(R_ID);

	if ((Node.logicIO & 0x01) == 0x01)
		ChangePixmap(ui->L_OUT1, ":/IMG/Resource/Out_on.png");
	else
		ChangePixmap(ui->L_OUT1, ":/IMG/Resource/Out_off.png");

	if ((Node.logicIO & 0x02) == 0x02)
		ChangePixmap(ui->L_OUT2, ":/IMG/Resource/Out_on.png");
	else
		ChangePixmap(ui->L_OUT2, ":/IMG/Resource/Out_off.png");

	if ((Node.logicIO & 0x04) == 0x04)
		ChangePixmap(ui->L_OUT3, ":/IMG/Resource/Out_on.png");
	else
		ChangePixmap(ui->L_OUT3, ":/IMG/Resource/Out_off.png");

	if ((Node.logicIO & 0x08) == 0x08)
		ChangePixmap(ui->L_OUT4, ":/IMG/Resource/Out_on.png");
	else
		ChangePixmap(ui->L_OUT4, ":/IMG/Resource/Out_off.png");

	if ((Node.logicIO & 0x10) == 0x10)
		ChangePixmap(ui->L_IN1, ":/IMG/Resource/Open_eye.png");
	else
		ChangePixmap(ui->L_IN1, ":/IMG/Resource/Closed_eye.png");

	if ((Node.logicIO & 0x20) == 0x20)
		ChangePixmap(ui->L_IN2, ":/IMG/Resource/Open_eye.png");
	else
		ChangePixmap(ui->L_IN2, ":/IMG/Resource/Closed_eye.png");

	if ((Node.logicIO & 0x40) == 0x40)
		ChangePixmap(ui->L_IN3, ":/IMG/Resource/Open_eye.png");
	else
		ChangePixmap(ui->L_IN3, ":/IMG/Resource/Closed_eye.png");

	ui->S_PWM1->setValue(Node.PWM1);
	ui->S_PWM2->setValue(Node.PWM2);
	ui->S_PWM3->setValue(Node.PWM3);
	ui->S_ALLPWM->setValue(static_cast<uint8_t>((Node.PWM1 + Node.PWM2 + Node.PWM3) / 3));

	ui->L_ADC1->setText(QString::number(Node.ADC1, 'f', 3) + " V");
	ui->L_ADC2->setText(QString::number(Node.ADC2, 'f', 3) + " V");

	ui->L_LUX->setText(QString::number(Node.LX, 'f', 2) + " lx");
}

void MainWindow::InitialStateRequest() {
	do {
		if (InitialState.Counter >= jID_OfAllNodes.count()) {
			continue;
		}
		InitialState.Counter++;

		memset(dataToSend, 0, sizeof(dataToSend));

		dataToSend[1] = INIT;
		dataToSend[2] = MasterID & 0x0FF;
		dataToSend[3] = static_cast<uint8_t>((MasterID & 0x0F00) >> 3);

		Send(dataToSend, false, jID_OfAllNodes.at(InitialState.Counter - 1).toInt()); //TODO

		InitialState.Timer->start(1000);
		return;
	}
	while (jID_OfAllNodes.count() > InitialState.Counter);
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

	Automatically.Timer = new QTimer(this);
	connect(Automatically.Timer, SIGNAL(timeout()), this, SLOT(AutomationCallback()));
	Automatically.Timer->setSingleShot(true);

	InitialState.Timer = new QTimer(this);
	connect(InitialState.Timer, SIGNAL(timeout()), this, SLOT(InitialStateRequest()));
	InitialState.Timer->setSingleShot(true);
}
