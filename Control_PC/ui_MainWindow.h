/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <CustomLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget47454;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLabel *L_ADC1;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLabel *L_ADC2;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QLabel *L_BH1750;
    QWidget *layoutWidget111;
    QHBoxLayout *horizontalLayout_16;
    QLabel *L_IN1;
    QLabel *L_IN2;
    QLabel *L_IN3;
    QRadioButton *RB_Update;
    QWidget *layoutWidget212;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *S_PWM1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSlider *S_PWM2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_3;
    QSlider *S_PWM3;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QSlider *S_ALLPWM;
    QPushButton *B_Connect;
    QWidget *layoutWidget131313;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_6;
    CustomLabel *L_OUT1;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_7;
    CustomLabel *L_OUT2;
    QLabel *label_13;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_5;
    CustomLabel *L_OUT3;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_2;
    CustomLabel *L_OUT4;
    QLabel *label_14;
    QComboBox *CB_SerialPort;
    QPushButton *B_Scan;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QTimeEdit *TE_PWMSpeed;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_16;
    QComboBox *CB_ID;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(460, 388);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(460, 388));
        MainWindow->setMaximumSize(QSize(460, 388));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget47454 = new QWidget(centralWidget);
        layoutWidget47454->setObjectName(QString::fromUtf8("layoutWidget47454"));
        layoutWidget47454->setGeometry(QRect(200, 11, 241, 77));
        verticalLayout_3 = new QVBoxLayout(layoutWidget47454);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget47454);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        L_ADC1 = new QLabel(layoutWidget47454);
        L_ADC1->setObjectName(QString::fromUtf8("L_ADC1"));

        horizontalLayout_5->addWidget(L_ADC1);


        horizontalLayout->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(layoutWidget47454);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        L_ADC2 = new QLabel(layoutWidget47454);
        L_ADC2->setObjectName(QString::fromUtf8("L_ADC2"));

        horizontalLayout_6->addWidget(L_ADC2);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_6 = new QLabel(layoutWidget47454);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_9->addWidget(label_6);

        L_BH1750 = new QLabel(layoutWidget47454);
        L_BH1750->setObjectName(QString::fromUtf8("L_BH1750"));

        horizontalLayout_9->addWidget(L_BH1750);


        horizontalLayout_8->addLayout(horizontalLayout_9);


        verticalLayout_3->addLayout(horizontalLayout_8);

        layoutWidget111 = new QWidget(centralWidget);
        layoutWidget111->setObjectName(QString::fromUtf8("layoutWidget111"));
        layoutWidget111->setGeometry(QRect(210, 110, 221, 74));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget111);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        L_IN1 = new QLabel(layoutWidget111);
        L_IN1->setObjectName(QString::fromUtf8("L_IN1"));
        L_IN1->setMinimumSize(QSize(69, 72));
        L_IN1->setMaximumSize(QSize(69, 72));
        L_IN1->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_16->addWidget(L_IN1);

        L_IN2 = new QLabel(layoutWidget111);
        L_IN2->setObjectName(QString::fromUtf8("L_IN2"));
        L_IN2->setMinimumSize(QSize(69, 72));
        L_IN2->setMaximumSize(QSize(69, 72));
        L_IN2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_16->addWidget(L_IN2);

        L_IN3 = new QLabel(layoutWidget111);
        L_IN3->setObjectName(QString::fromUtf8("L_IN3"));
        L_IN3->setMinimumSize(QSize(69, 72));
        L_IN3->setMaximumSize(QSize(69, 72));
        L_IN3->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_16->addWidget(L_IN3);

        RB_Update = new QRadioButton(centralWidget);
        RB_Update->setObjectName(QString::fromUtf8("RB_Update"));
        RB_Update->setEnabled(false);
        RB_Update->setGeometry(QRect(290, 90, 61, 19));
        RB_Update->setCheckable(true);
        RB_Update->setChecked(false);
        RB_Update->setAutoExclusive(false);
        layoutWidget212 = new QWidget(centralWidget);
        layoutWidget212->setObjectName(QString::fromUtf8("layoutWidget212"));
        layoutWidget212->setGeometry(QRect(210, 220, 233, 148));
        verticalLayout = new QVBoxLayout(layoutWidget212);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget212);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(51, 30));
        label->setMaximumSize(QSize(51, 30));

        horizontalLayout_2->addWidget(label);

        S_PWM1 = new QSlider(layoutWidget212);
        S_PWM1->setObjectName(QString::fromUtf8("S_PWM1"));
        S_PWM1->setEnabled(false);
        S_PWM1->setMinimumSize(QSize(172, 16));
        S_PWM1->setMaximumSize(QSize(172, 16));
        S_PWM1->setMouseTracking(false);
        S_PWM1->setTabletTracking(false);
        S_PWM1->setAcceptDrops(false);
        S_PWM1->setMinimum(0);
        S_PWM1->setMaximum(255);
        S_PWM1->setSingleStep(1);
        S_PWM1->setPageStep(1);
        S_PWM1->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(S_PWM1);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget212);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(51, 30));
        label_2->setMaximumSize(QSize(51, 30));

        horizontalLayout_3->addWidget(label_2);

        S_PWM2 = new QSlider(layoutWidget212);
        S_PWM2->setObjectName(QString::fromUtf8("S_PWM2"));
        S_PWM2->setEnabled(false);
        S_PWM2->setMinimumSize(QSize(172, 16));
        S_PWM2->setMaximumSize(QSize(172, 16));
        S_PWM2->setMinimum(0);
        S_PWM2->setMaximum(255);
        S_PWM2->setPageStep(1);
        S_PWM2->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(S_PWM2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_3 = new QLabel(layoutWidget212);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(51, 30));
        label_3->setMaximumSize(QSize(51, 30));

        horizontalLayout_12->addWidget(label_3);

        S_PWM3 = new QSlider(layoutWidget212);
        S_PWM3->setObjectName(QString::fromUtf8("S_PWM3"));
        S_PWM3->setEnabled(false);
        S_PWM3->setMinimumSize(QSize(172, 16));
        S_PWM3->setMaximumSize(QSize(172, 16));
        S_PWM3->setMinimum(0);
        S_PWM3->setMaximum(255);
        S_PWM3->setPageStep(1);
        S_PWM3->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(S_PWM3);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_11 = new QLabel(layoutWidget212);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(51, 30));
        label_11->setMaximumSize(QSize(51, 30));

        horizontalLayout_13->addWidget(label_11);

        S_ALLPWM = new QSlider(layoutWidget212);
        S_ALLPWM->setObjectName(QString::fromUtf8("S_ALLPWM"));
        S_ALLPWM->setEnabled(false);
        S_ALLPWM->setMinimumSize(QSize(172, 16));
        S_ALLPWM->setMaximumSize(QSize(172, 16));
        S_ALLPWM->setMinimum(0);
        S_ALLPWM->setMaximum(255);
        S_ALLPWM->setPageStep(1);
        S_ALLPWM->setOrientation(Qt::Horizontal);

        horizontalLayout_13->addWidget(S_ALLPWM);


        verticalLayout->addLayout(horizontalLayout_13);

        B_Connect = new QPushButton(centralWidget);
        B_Connect->setObjectName(QString::fromUtf8("B_Connect"));
        B_Connect->setEnabled(true);
        B_Connect->setGeometry(QRect(10, 300, 191, 71));
        layoutWidget131313 = new QWidget(centralWidget);
        layoutWidget131313->setObjectName(QString::fromUtf8("layoutWidget131313"));
        layoutWidget131313->setGeometry(QRect(20, 20, 154, 211));
        verticalLayout_8 = new QVBoxLayout(layoutWidget131313);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        L_OUT1 = new CustomLabel(layoutWidget131313);
        L_OUT1->setObjectName(QString::fromUtf8("L_OUT1"));
        L_OUT1->setEnabled(false);
        L_OUT1->setMinimumSize(QSize(70, 70));
        L_OUT1->setMaximumSize(QSize(70, 70));
        L_OUT1->setMouseTracking(true);
        L_OUT1->setStyleSheet(QString::fromUtf8(""));
        L_OUT1->setFrameShape(QFrame::Box);

        verticalLayout_6->addWidget(L_OUT1);

        label_12 = new QLabel(layoutWidget131313);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(70, 16));
        label_12->setMaximumSize(QSize(70, 16));

        verticalLayout_6->addWidget(label_12);


        horizontalLayout_14->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        L_OUT2 = new CustomLabel(layoutWidget131313);
        L_OUT2->setObjectName(QString::fromUtf8("L_OUT2"));
        L_OUT2->setEnabled(false);
        L_OUT2->setMinimumSize(QSize(70, 70));
        L_OUT2->setMaximumSize(QSize(70, 70));
        L_OUT2->setMouseTracking(true);
        L_OUT2->setStyleSheet(QString::fromUtf8(""));
        L_OUT2->setFrameShape(QFrame::Box);

        verticalLayout_7->addWidget(L_OUT2);

        label_13 = new QLabel(layoutWidget131313);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(70, 16));
        label_13->setMaximumSize(QSize(70, 16));

        verticalLayout_7->addWidget(label_13);


        horizontalLayout_14->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_14);

        verticalSpacer = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        L_OUT3 = new CustomLabel(layoutWidget131313);
        L_OUT3->setObjectName(QString::fromUtf8("L_OUT3"));
        L_OUT3->setEnabled(false);
        L_OUT3->setMinimumSize(QSize(70, 70));
        L_OUT3->setMaximumSize(QSize(70, 70));
        L_OUT3->setMouseTracking(true);
        L_OUT3->setStyleSheet(QString::fromUtf8(""));
        L_OUT3->setFrameShape(QFrame::Box);

        verticalLayout_5->addWidget(L_OUT3);

        label_15 = new QLabel(layoutWidget131313);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(70, 16));
        label_15->setMaximumSize(QSize(70, 16));

        verticalLayout_5->addWidget(label_15);


        horizontalLayout_17->addLayout(verticalLayout_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        L_OUT4 = new CustomLabel(layoutWidget131313);
        L_OUT4->setObjectName(QString::fromUtf8("L_OUT4"));
        L_OUT4->setEnabled(false);
        L_OUT4->setMinimumSize(QSize(70, 70));
        L_OUT4->setMaximumSize(QSize(70, 70));
        L_OUT4->setMouseTracking(true);
        L_OUT4->setStyleSheet(QString::fromUtf8(""));
        L_OUT4->setFrameShape(QFrame::Box);

        verticalLayout_2->addWidget(L_OUT4);

        label_14 = new QLabel(layoutWidget131313);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(70, 16));
        label_14->setMaximumSize(QSize(70, 16));

        verticalLayout_2->addWidget(label_14);


        horizontalLayout_17->addLayout(verticalLayout_2);


        verticalLayout_8->addLayout(horizontalLayout_17);

        CB_SerialPort = new QComboBox(centralWidget);
        CB_SerialPort->setObjectName(QString::fromUtf8("CB_SerialPort"));
        CB_SerialPort->setEnabled(true);
        CB_SerialPort->setGeometry(QRect(20, 270, 80, 20));
        CB_SerialPort->setEditable(false);
        B_Scan = new QPushButton(centralWidget);
        B_Scan->setObjectName(QString::fromUtf8("B_Scan"));
        B_Scan->setGeometry(QRect(110, 270, 80, 20));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 190, 125, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 0));
        label_10->setMaximumSize(QSize(999999, 999999));

        horizontalLayout_4->addWidget(label_10);

        TE_PWMSpeed = new QTimeEdit(layoutWidget);
        TE_PWMSpeed->setObjectName(QString::fromUtf8("TE_PWMSpeed"));
        TE_PWMSpeed->setEnabled(false);
        TE_PWMSpeed->setMinimumSize(QSize(0, 0));
        TE_PWMSpeed->setMaximumSize(QSize(9999999, 999999));
        TE_PWMSpeed->setWrapping(true);
        TE_PWMSpeed->setFrame(true);
        TE_PWMSpeed->setReadOnly(false);
        TE_PWMSpeed->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        TE_PWMSpeed->setAccelerated(false);
        TE_PWMSpeed->setKeyboardTracking(true);
        TE_PWMSpeed->setProperty("showGroupSeparator", QVariant(false));
        TE_PWMSpeed->setMinimumTime(QTime(0, 0, 1));
        TE_PWMSpeed->setCurrentSection(QDateTimeEdit::MinuteSection);
        TE_PWMSpeed->setCalendarPopup(false);
        TE_PWMSpeed->setTimeSpec(Qt::LocalTime);
        TE_PWMSpeed->setTime(QTime(0, 0, 1));

        horizontalLayout_4->addWidget(TE_PWMSpeed);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(360, 190, 75, 25));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(0, 0));
        label_16->setMaximumSize(QSize(16, 23));

        horizontalLayout_10->addWidget(label_16);

        CB_ID = new QComboBox(layoutWidget1);
        CB_ID->setObjectName(QString::fromUtf8("CB_ID"));
        CB_ID->setEnabled(false);
        CB_ID->setMaximumSize(QSize(51, 20));
        CB_ID->setEditable(true);

        horizontalLayout_10->addWidget(CB_ID);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(B_Connect, SIGNAL(clicked()), MainWindow, SLOT(ButtonProcessing()));
        QObject::connect(B_Scan, SIGNAL(clicked()), MainWindow, SLOT(ButtonProcessing()));
        QObject::connect(S_PWM1, SIGNAL(sliderReleased()), MainWindow, SLOT(SliderProcessing()));
        QObject::connect(S_PWM2, SIGNAL(sliderReleased()), MainWindow, SLOT(SliderProcessing()));
        QObject::connect(S_PWM3, SIGNAL(sliderReleased()), MainWindow, SLOT(SliderProcessing()));
        QObject::connect(S_ALLPWM, SIGNAL(sliderReleased()), MainWindow, SLOT(SliderProcessing()));
        QObject::connect(RB_Update, SIGNAL(clicked()), MainWindow, SLOT(ButtonProcessing()));
        QObject::connect(TE_PWMSpeed, SIGNAL(userTimeChanged(QTime)), MainWindow, SLOT(PWMSpeedChange(QTime)));

        CB_ID->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "ADC 1", nullptr));
        L_ADC1->setText(QCoreApplication::translate("MainWindow", "0.000 V.", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "ADC 2", nullptr));
        L_ADC2->setText(QCoreApplication::translate("MainWindow", "0.000 V.", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "BH1750", nullptr));
        L_BH1750->setText(QCoreApplication::translate("MainWindow", "00.00 lx.", nullptr));
        L_IN1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">IN1</p></body></html>", nullptr));
        L_IN2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">IN2</p></body></html>", nullptr));
        L_IN3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">IN3</p></body></html>", nullptr));
        RB_Update->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "PWM1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "PWM2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "PWM3", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "ALL PWM", nullptr));
        B_Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        L_OUT1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT1</p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT1</p></body></html>", nullptr));
        L_OUT2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT2</p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT2</p></body></html>", nullptr));
        L_OUT3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT3</p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT3</p></body></html>", nullptr));
        L_OUT4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT4</p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT4</p></body></html>", nullptr));
        B_Scan->setText(QCoreApplication::translate("MainWindow", "Scan", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "PWM Speed:", nullptr));
        TE_PWMSpeed->setDisplayFormat(QCoreApplication::translate("MainWindow", "mm:ss", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        CB_ID->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
