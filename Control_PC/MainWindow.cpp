#include "MainWindow.h"
#include <QDebug>
#include "ui_MainWindow.h"

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

void MainWindow::UpdateMainWindow() {
	const uint16_t R_ID = ui->CB_ID->currentText().toUInt();
	const uint8_t logicIO = HashNodesStatus->value(R_ID).logicIO;
	const uint8_t PWM1 = HashNodesStatus->value(R_ID).PWM1;
	const uint8_t PWM2 = HashNodesStatus->value(R_ID).PWM2;
	const uint8_t PWM3 = HashNodesStatus->value(R_ID).PWM3;
	const double ADC1 = HashNodesStatus->value(R_ID).ADC1;
	const double ADC2 = HashNodesStatus->value(R_ID).ADC2;
	const double LX = HashNodesStatus->value(R_ID).LX;

	if ((logicIO & 0x01) == 0x01)
		ChangePixmap(ui->L_OUT1, ":/IMG/Resource/Out_on.png");
	else
		ChangePixmap(ui->L_OUT1, ":/IMG/Resource/Out_off.png");

	if ((logicIO & 0x02) == 0x02)
		ChangePixmap(ui->L_OUT2, ":/IMG/Resource/Out_on.png");
	else
		ChangePixmap(ui->L_OUT2, ":/IMG/Resource/Out_off.png");

	if ((logicIO & 0x04) == 0x04)
		ChangePixmap(ui->L_OUT3, ":/IMG/Resource/Out_on.png");
	else
		ChangePixmap(ui->L_OUT3, ":/IMG/Resource/Out_off.png");

	if ((logicIO & 0x08) == 0x08)
		ChangePixmap(ui->L_OUT4, ":/IMG/Resource/Out_on.png");
	else
		ChangePixmap(ui->L_OUT4, ":/IMG/Resource/Out_off.png");

	if ((logicIO & 0x10) == 0x10)
		ChangePixmap(ui->L_IN1, ":/IMG/Resource/Open_eye.png");
	else
		ChangePixmap(ui->L_IN1, ":/IMG/Resource/Closed_eye.png");

	if ((logicIO & 0x20) == 0x20)
		ChangePixmap(ui->L_IN2, ":/IMG/Resource/Open_eye.png");
	else
		ChangePixmap(ui->L_IN2, ":/IMG/Resource/Closed_eye.png");

	if ((logicIO & 0x40) == 0x40)
		ChangePixmap(ui->L_IN3, ":/IMG/Resource/Open_eye.png");
	else
		ChangePixmap(ui->L_IN3, ":/IMG/Resource/Closed_eye.png");

	ui->S_PWM1->setValue(PWM1);
	ui->S_PWM2->setValue(PWM2);
	ui->S_PWM3->setValue(PWM3);
	ui->S_ALLPWM->setValue(static_cast<uint8_t>((PWM1 + PWM2 + PWM3) / 3));

	ui->L_ADC1->setText(QString::number(ADC1, 'f', 3) + " V");
	ui->L_ADC2->setText(QString::number(ADC2, 'f', 3) + " V");

	ui->L_LUX->setText(QString::number(LX, 'f', 2) + " lx");
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
