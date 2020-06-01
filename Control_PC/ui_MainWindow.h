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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_8;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_7;
    CustomLabel *L_OUT1;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_6;
    CustomLabel *L_OUT2;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_5;
    CustomLabel *L_OUT3;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_4;
    CustomLabel *L_OUT4;
    QLabel *label_14;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_12;
    QComboBox *CB_SerialPort;
    QPushButton *B_Scan;
    QSpacerItem *verticalSpacer_2;
    QPushButton *B_Connect;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_15;
    CustomLabel *L_ADC1;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_20;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_21;
    CustomLabel *L_ADC2;
    QSpacerItem *horizontalSpacer_22;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_23;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_24;
    CustomLabel *L_LUX;
    QSpacerItem *horizontalSpacer_25;
    QSpacerItem *verticalSpacer_11;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_12;
    QLabel *L_IN1;
    QLabel *label_20;
    QVBoxLayout *verticalLayout_13;
    QLabel *L_IN2;
    QLabel *label_22;
    QVBoxLayout *verticalLayout_14;
    QLabel *L_IN3;
    QLabel *label_23;
    QSpacerItem *verticalSpacer_12;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QComboBox *CB_ID;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *S_PWM1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *S_PWM2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *S_PWM3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QSlider *S_ALLPWM;
    QVBoxLayout *verticalLayout_11;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_21;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_10;
    QTimeEdit *TE_PWMSpeed;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_10;
    QFrame *line;
    QSpacerItem *verticalSpacer_8;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_17;
    QSpinBox *SB_MaintainLux;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_25;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_21;
    QSpinBox *SB_MaintainLuxDeadband;
    QSpacerItem *horizontalSpacer_18;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_19;
    QSpinBox *SB_MaintainLuxStep;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_7;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_18;
    QTimeEdit *TE_TurnOffLight;
    QHBoxLayout *horizontalLayout_18;
    QSpacerItem *horizontalSpacer_6;
    QRadioButton *RB_TurnOffLight;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_5;
    QFrame *line_3;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_22;
    QSpacerItem *horizontalSpacer_13;
    QRadioButton *RB_AutoControl;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(722, 451);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(722, 451));
        MainWindow->setMaximumSize(QSize(722, 451));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 681, 411));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget);
        horizontalLayout_13->setSpacing(30);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(15);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        L_OUT1 = new CustomLabel(layoutWidget);
        L_OUT1->setObjectName(QString::fromUtf8("L_OUT1"));
        L_OUT1->setEnabled(false);
        L_OUT1->setMinimumSize(QSize(70, 70));
        L_OUT1->setMaximumSize(QSize(70, 70));
        L_OUT1->setMouseTracking(true);
        L_OUT1->setStyleSheet(QString::fromUtf8(""));
        L_OUT1->setFrameShape(QFrame::Box);

        verticalLayout_7->addWidget(L_OUT1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(70, 23));
        label_12->setMaximumSize(QSize(70, 23));
        label_12->setMouseTracking(true);

        verticalLayout_7->addWidget(label_12);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        L_OUT2 = new CustomLabel(layoutWidget);
        L_OUT2->setObjectName(QString::fromUtf8("L_OUT2"));
        L_OUT2->setEnabled(false);
        L_OUT2->setMinimumSize(QSize(70, 70));
        L_OUT2->setMaximumSize(QSize(70, 70));
        L_OUT2->setMouseTracking(true);
        L_OUT2->setStyleSheet(QString::fromUtf8(""));
        L_OUT2->setFrameShape(QFrame::Box);

        verticalLayout_6->addWidget(L_OUT2);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(70, 23));
        label_13->setMaximumSize(QSize(70, 23));
        label_13->setMouseTracking(true);

        verticalLayout_6->addWidget(label_13);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        L_OUT3 = new CustomLabel(layoutWidget);
        L_OUT3->setObjectName(QString::fromUtf8("L_OUT3"));
        L_OUT3->setEnabled(false);
        L_OUT3->setMinimumSize(QSize(70, 70));
        L_OUT3->setMaximumSize(QSize(70, 70));
        L_OUT3->setMouseTracking(true);
        L_OUT3->setStyleSheet(QString::fromUtf8(""));
        L_OUT3->setFrameShape(QFrame::Box);

        verticalLayout_5->addWidget(L_OUT3);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(70, 23));
        label_15->setMaximumSize(QSize(70, 23));
        label_15->setMouseTracking(true);

        verticalLayout_5->addWidget(label_15);


        formLayout->setLayout(1, QFormLayout::LabelRole, verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        L_OUT4 = new CustomLabel(layoutWidget);
        L_OUT4->setObjectName(QString::fromUtf8("L_OUT4"));
        L_OUT4->setEnabled(false);
        L_OUT4->setMinimumSize(QSize(70, 70));
        L_OUT4->setMaximumSize(QSize(70, 70));
        L_OUT4->setMouseTracking(true);
        L_OUT4->setStyleSheet(QString::fromUtf8(""));
        L_OUT4->setFrameShape(QFrame::Box);

        verticalLayout_4->addWidget(L_OUT4);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(70, 23));
        label_14->setMaximumSize(QSize(70, 23));
        label_14->setMouseTracking(true);

        verticalLayout_4->addWidget(label_14);


        formLayout->setLayout(1, QFormLayout::FieldRole, verticalLayout_4);


        verticalLayout_8->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(15);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        CB_SerialPort = new QComboBox(layoutWidget);
        CB_SerialPort->setObjectName(QString::fromUtf8("CB_SerialPort"));
        CB_SerialPort->setEnabled(true);
        CB_SerialPort->setEditable(false);

        horizontalLayout_12->addWidget(CB_SerialPort);

        B_Scan = new QPushButton(layoutWidget);
        B_Scan->setObjectName(QString::fromUtf8("B_Scan"));

        horizontalLayout_12->addWidget(B_Scan);


        verticalLayout_8->addLayout(horizontalLayout_12);

        verticalSpacer_2 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_8->addItem(verticalSpacer_2);

        B_Connect = new QPushButton(layoutWidget);
        B_Connect->setObjectName(QString::fromUtf8("B_Connect"));
        B_Connect->setEnabled(true);
        B_Connect->setMinimumSize(QSize(160, 70));
        B_Connect->setMaximumSize(QSize(160, 70));

        verticalLayout_8->addWidget(B_Connect);


        horizontalLayout_13->addLayout(verticalLayout_8);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(15);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_16 = new QSpacerItem(57, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_16);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(0, 23));
        label_4->setMaximumSize(QSize(41, 23));
        label_4->setMouseTracking(true);

        horizontalLayout_9->addWidget(label_4);

        horizontalSpacer_15 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_15);

        L_ADC1 = new CustomLabel(layoutWidget);
        L_ADC1->setObjectName(QString::fromUtf8("L_ADC1"));
        L_ADC1->setEnabled(false);
        L_ADC1->setMinimumSize(QSize(80, 23));
        L_ADC1->setMaximumSize(QSize(80, 23));
        L_ADC1->setMouseTracking(true);

        horizontalLayout_9->addWidget(L_ADC1);

        horizontalSpacer_19 = new QSpacerItem(32, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_19);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_20 = new QSpacerItem(57, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_20);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(0, 23));
        label_5->setMaximumSize(QSize(41, 23));
        label_5->setMouseTracking(true);

        horizontalLayout_8->addWidget(label_5);

        horizontalSpacer_21 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_21);

        L_ADC2 = new CustomLabel(layoutWidget);
        L_ADC2->setObjectName(QString::fromUtf8("L_ADC2"));
        L_ADC2->setEnabled(false);
        L_ADC2->setMinimumSize(QSize(80, 23));
        L_ADC2->setMaximumSize(QSize(80, 23));
        L_ADC2->setMouseTracking(true);

        horizontalLayout_8->addWidget(L_ADC2);

        horizontalSpacer_22 = new QSpacerItem(32, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_22);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_23);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(0, 23));
        label_6->setMaximumSize(QSize(65, 23));
        label_6->setMouseTracking(true);

        horizontalLayout_7->addWidget(label_6);

        horizontalSpacer_24 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_24);

        L_LUX = new CustomLabel(layoutWidget);
        L_LUX->setObjectName(QString::fromUtf8("L_LUX"));
        L_LUX->setEnabled(false);
        L_LUX->setMinimumSize(QSize(80, 23));
        L_LUX->setMaximumSize(QSize(80, 23));
        L_LUX->setMouseTracking(true);

        horizontalLayout_7->addWidget(L_LUX);

        horizontalSpacer_25 = new QSpacerItem(32, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_25);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_11);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(15);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        L_IN1 = new QLabel(layoutWidget);
        L_IN1->setObjectName(QString::fromUtf8("L_IN1"));
        L_IN1->setMinimumSize(QSize(70, 70));
        L_IN1->setMaximumSize(QSize(70, 70));
        L_IN1->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_12->addWidget(L_IN1);

        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(70, 23));
        label_20->setMaximumSize(QSize(70, 23));
        label_20->setMouseTracking(true);

        verticalLayout_12->addWidget(label_20);


        horizontalLayout_6->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        L_IN2 = new QLabel(layoutWidget);
        L_IN2->setObjectName(QString::fromUtf8("L_IN2"));
        L_IN2->setMinimumSize(QSize(70, 70));
        L_IN2->setMaximumSize(QSize(70, 70));
        L_IN2->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_13->addWidget(L_IN2);

        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(70, 23));
        label_22->setMaximumSize(QSize(70, 23));
        label_22->setMouseTracking(true);

        verticalLayout_13->addWidget(label_22);


        horizontalLayout_6->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        L_IN3 = new QLabel(layoutWidget);
        L_IN3->setObjectName(QString::fromUtf8("L_IN3"));
        L_IN3->setMinimumSize(QSize(70, 70));
        L_IN3->setMaximumSize(QSize(70, 70));
        L_IN3->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_14->addWidget(L_IN3);

        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(70, 23));
        label_23->setMaximumSize(QSize(70, 23));
        label_23->setMouseTracking(true);

        verticalLayout_14->addWidget(label_23);


        horizontalLayout_6->addLayout(verticalLayout_14);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(20, 23));
        label_16->setMaximumSize(QSize(20, 23));

        horizontalLayout_5->addWidget(label_16);

        CB_ID = new QComboBox(layoutWidget);
        CB_ID->setObjectName(QString::fromUtf8("CB_ID"));
        CB_ID->setEnabled(false);
        CB_ID->setMinimumSize(QSize(56, 23));
        CB_ID->setMaximumSize(QSize(56, 23));
        CB_ID->setEditable(false);

        horizontalLayout_5->addWidget(CB_ID);


        horizontalLayout_11->addLayout(horizontalLayout_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_11);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(51, 16));
        label->setMaximumSize(QSize(51, 16));

        horizontalLayout->addWidget(label);

        S_PWM1 = new QSlider(layoutWidget);
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

        horizontalLayout->addWidget(S_PWM1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(51, 16));
        label_2->setMaximumSize(QSize(51, 16));

        horizontalLayout_2->addWidget(label_2);

        S_PWM2 = new QSlider(layoutWidget);
        S_PWM2->setObjectName(QString::fromUtf8("S_PWM2"));
        S_PWM2->setEnabled(false);
        S_PWM2->setMinimumSize(QSize(172, 16));
        S_PWM2->setMaximumSize(QSize(172, 16));
        S_PWM2->setMinimum(0);
        S_PWM2->setMaximum(255);
        S_PWM2->setPageStep(1);
        S_PWM2->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(S_PWM2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(51, 16));
        label_3->setMaximumSize(QSize(51, 16));

        horizontalLayout_3->addWidget(label_3);

        S_PWM3 = new QSlider(layoutWidget);
        S_PWM3->setObjectName(QString::fromUtf8("S_PWM3"));
        S_PWM3->setEnabled(false);
        S_PWM3->setMinimumSize(QSize(172, 16));
        S_PWM3->setMaximumSize(QSize(172, 16));
        S_PWM3->setMinimum(0);
        S_PWM3->setMaximum(255);
        S_PWM3->setPageStep(1);
        S_PWM3->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(S_PWM3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(51, 16));
        label_11->setMaximumSize(QSize(51, 16));

        horizontalLayout_4->addWidget(label_11);

        S_ALLPWM = new QSlider(layoutWidget);
        S_ALLPWM->setObjectName(QString::fromUtf8("S_ALLPWM"));
        S_ALLPWM->setEnabled(false);
        S_ALLPWM->setMinimumSize(QSize(172, 16));
        S_ALLPWM->setMaximumSize(QSize(172, 16));
        S_ALLPWM->setMinimum(0);
        S_ALLPWM->setMaximum(255);
        S_ALLPWM->setPageStep(1);
        S_ALLPWM->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(S_ALLPWM);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout_13->addLayout(verticalLayout_3);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalSpacer_9 = new QSpacerItem(17, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_9);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(0);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_11);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(65, 23));
        label_10->setMaximumSize(QSize(71, 23));

        horizontalLayout_16->addWidget(label_10);

        TE_PWMSpeed = new QTimeEdit(layoutWidget);
        TE_PWMSpeed->setObjectName(QString::fromUtf8("TE_PWMSpeed"));
        TE_PWMSpeed->setEnabled(false);
        TE_PWMSpeed->setMinimumSize(QSize(56, 23));
        TE_PWMSpeed->setMaximumSize(QSize(56, 23));
        TE_PWMSpeed->setAcceptDrops(true);
        TE_PWMSpeed->setWrapping(true);
        TE_PWMSpeed->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        TE_PWMSpeed->setProperty("showGroupSeparator", QVariant(false));
        TE_PWMSpeed->setMaximumDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 59, 59)));
        TE_PWMSpeed->setMaximumTime(QTime(0, 59, 59));
        TE_PWMSpeed->setMinimumTime(QTime(0, 0, 1));
        TE_PWMSpeed->setCurrentSection(QDateTimeEdit::MinuteSection);
        TE_PWMSpeed->setCalendarPopup(false);
        TE_PWMSpeed->setCurrentSectionIndex(0);
        TE_PWMSpeed->setTimeSpec(Qt::LocalTime);
        TE_PWMSpeed->setTime(QTime(0, 0, 1));

        horizontalLayout_16->addWidget(TE_PWMSpeed);


        horizontalLayout_21->addLayout(horizontalLayout_16);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_12);


        verticalLayout_11->addLayout(horizontalLayout_21);

        verticalSpacer_10 = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_10);

        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_11->addWidget(line);

        verticalSpacer_8 = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_8);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(15);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(0);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_9);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(0);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(71, 23));
        label_17->setMaximumSize(QSize(71, 23));

        horizontalLayout_15->addWidget(label_17);

        SB_MaintainLux = new QSpinBox(layoutWidget);
        SB_MaintainLux->setObjectName(QString::fromUtf8("SB_MaintainLux"));
        SB_MaintainLux->setEnabled(false);
        SB_MaintainLux->setMinimumSize(QSize(56, 23));
        SB_MaintainLux->setMaximumSize(QSize(56, 23));
        SB_MaintainLux->setMaximum(65535);
        SB_MaintainLux->setValue(0);

        horizontalLayout_15->addWidget(SB_MaintainLux);


        horizontalLayout_19->addLayout(horizontalLayout_15);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_10);


        verticalLayout_10->addLayout(horizontalLayout_19);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(0);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_17);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(0);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        label_21 = new QLabel(layoutWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(56, 23));
        label_21->setMaximumSize(QSize(950, 230));

        horizontalLayout_26->addWidget(label_21);

        SB_MaintainLuxDeadband = new QSpinBox(layoutWidget);
        SB_MaintainLuxDeadband->setObjectName(QString::fromUtf8("SB_MaintainLuxDeadband"));
        SB_MaintainLuxDeadband->setEnabled(false);
        SB_MaintainLuxDeadband->setMinimumSize(QSize(56, 23));
        SB_MaintainLuxDeadband->setMaximumSize(QSize(56, 23));
        SB_MaintainLuxDeadband->setMinimum(1);
        SB_MaintainLuxDeadband->setMaximum(1000);
        SB_MaintainLuxDeadband->setValue(1);

        horizontalLayout_26->addWidget(SB_MaintainLuxDeadband);


        horizontalLayout_25->addLayout(horizontalLayout_26);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_18);


        verticalLayout_10->addLayout(horizontalLayout_25);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(0);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_8);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(0);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(30, 23));
        label_19->setMaximumSize(QSize(95, 23));

        horizontalLayout_17->addWidget(label_19);

        SB_MaintainLuxStep = new QSpinBox(layoutWidget);
        SB_MaintainLuxStep->setObjectName(QString::fromUtf8("SB_MaintainLuxStep"));
        SB_MaintainLuxStep->setEnabled(false);
        SB_MaintainLuxStep->setMinimumSize(QSize(56, 23));
        SB_MaintainLuxStep->setMaximumSize(QSize(56, 23));
        SB_MaintainLuxStep->setMinimum(1);
        SB_MaintainLuxStep->setMaximum(255);
        SB_MaintainLuxStep->setValue(1);

        horizontalLayout_17->addWidget(SB_MaintainLuxStep);


        horizontalLayout_20->addLayout(horizontalLayout_17);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_7);


        verticalLayout_10->addLayout(horizontalLayout_20);


        verticalLayout_11->addLayout(verticalLayout_10);

        verticalSpacer_7 = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_7);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_11->addWidget(line_2);

        verticalSpacer_6 = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_6);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(15);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(130, 23));
        label_18->setMaximumSize(QSize(131, 23));

        horizontalLayout_14->addWidget(label_18);

        TE_TurnOffLight = new QTimeEdit(layoutWidget);
        TE_TurnOffLight->setObjectName(QString::fromUtf8("TE_TurnOffLight"));
        TE_TurnOffLight->setEnabled(false);
        TE_TurnOffLight->setMinimumSize(QSize(56, 23));
        TE_TurnOffLight->setMaximumSize(QSize(56, 23));
        TE_TurnOffLight->setAcceptDrops(true);
        TE_TurnOffLight->setWrapping(true);
        TE_TurnOffLight->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        TE_TurnOffLight->setProperty("showGroupSeparator", QVariant(false));
        TE_TurnOffLight->setMaximumDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 59, 59)));
        TE_TurnOffLight->setMaximumTime(QTime(0, 59, 59));
        TE_TurnOffLight->setMinimumTime(QTime(0, 0, 1));
        TE_TurnOffLight->setCurrentSection(QDateTimeEdit::MinuteSection);
        TE_TurnOffLight->setCalendarPopup(false);
        TE_TurnOffLight->setCurrentSectionIndex(0);
        TE_TurnOffLight->setTimeSpec(Qt::LocalTime);
        TE_TurnOffLight->setTime(QTime(0, 0, 1));

        horizontalLayout_14->addWidget(TE_TurnOffLight);


        verticalLayout_9->addLayout(horizontalLayout_14);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_6);

        RB_TurnOffLight = new QRadioButton(layoutWidget);
        RB_TurnOffLight->setObjectName(QString::fromUtf8("RB_TurnOffLight"));
        RB_TurnOffLight->setEnabled(false);
        RB_TurnOffLight->setMinimumSize(QSize(111, 23));
        RB_TurnOffLight->setMaximumSize(QSize(111, 23));
        RB_TurnOffLight->setAutoExclusive(false);

        horizontalLayout_18->addWidget(RB_TurnOffLight);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_5);


        verticalLayout_9->addLayout(horizontalLayout_18);


        verticalLayout_11->addLayout(verticalLayout_9);

        verticalSpacer_5 = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_5);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_11->addWidget(line_3);

        verticalSpacer_4 = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_4);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_13);

        RB_AutoControl = new QRadioButton(layoutWidget);
        RB_AutoControl->setObjectName(QString::fromUtf8("RB_AutoControl"));
        RB_AutoControl->setEnabled(false);
        RB_AutoControl->setAutoExclusive(false);

        horizontalLayout_22->addWidget(RB_AutoControl);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_14);


        verticalLayout_11->addLayout(horizontalLayout_22);

        verticalSpacer_3 = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_3);


        horizontalLayout_13->addLayout(verticalLayout_11);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(B_Connect, SIGNAL(clicked()), MainWindow, SLOT(ButtonProcessing()));
        QObject::connect(B_Scan, SIGNAL(clicked()), MainWindow, SLOT(ButtonProcessing()));
        QObject::connect(S_PWM1, SIGNAL(sliderReleased()), MainWindow, SLOT(SliderProcessing()));
        QObject::connect(S_PWM2, SIGNAL(sliderReleased()), MainWindow, SLOT(SliderProcessing()));
        QObject::connect(S_PWM3, SIGNAL(sliderReleased()), MainWindow, SLOT(SliderProcessing()));
        QObject::connect(S_ALLPWM, SIGNAL(sliderReleased()), MainWindow, SLOT(SliderProcessing()));
        QObject::connect(TE_PWMSpeed, SIGNAL(userTimeChanged(QTime)), MainWindow, SLOT(TimeEditProcessing(QTime)));
        QObject::connect(CB_ID, SIGNAL(currentIndexChanged(int)), MainWindow, SLOT(ChangeRecipientID()));
        QObject::connect(RB_AutoControl, SIGNAL(clicked()), MainWindow, SLOT(ButtonProcessing()));
        QObject::connect(SB_MaintainLux, SIGNAL(valueChanged(int)), MainWindow, SLOT(SpinBoxProcessing(int)));
        QObject::connect(RB_TurnOffLight, SIGNAL(clicked()), MainWindow, SLOT(ButtonProcessing()));
        QObject::connect(SB_MaintainLuxStep, SIGNAL(valueChanged(int)), MainWindow, SLOT(SpinBoxProcessing(int)));
        QObject::connect(TE_TurnOffLight, SIGNAL(userTimeChanged(QTime)), MainWindow, SLOT(TimeEditProcessing(QTime)));
        QObject::connect(SB_MaintainLuxDeadband, SIGNAL(valueChanged(int)), MainWindow, SLOT(SpinBoxProcessing(int)));

        CB_ID->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        L_OUT1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT1</p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT1</p></body></html>", nullptr));
        L_OUT2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT2</p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT2</p></body></html>", nullptr));
        L_OUT3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT3</p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT3</p></body></html>", nullptr));
        L_OUT4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT4</p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OUT4</p></body></html>", nullptr));
        B_Scan->setText(QCoreApplication::translate("MainWindow", "Scan", nullptr));
        B_Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">ADC 1:</p></body></html>", nullptr));
        L_ADC1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>0.000 V.</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">ADC 2:</p></body></html>", nullptr));
        L_ADC2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>0.000 V.</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Light meter:</p></body></html>", nullptr));
        L_LUX->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>00.00 lx.</p></body></html>", nullptr));
        L_IN1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">IN1</p></body></html>", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">IN1</p></body></html>", nullptr));
        L_IN2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">IN2</p></body></html>", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">IN2</p></body></html>", nullptr));
        L_IN3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">IN3</p></body></html>", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">IN3</p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        CB_ID->setCurrentText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "PWM1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "PWM2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "PWM3", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "ALL PWM", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "PWM Speed:", nullptr));
        TE_PWMSpeed->setDisplayFormat(QCoreApplication::translate("MainWindow", "mm:ss", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Maintain Lux:", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Deadband:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Step:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Turn off the light through: ", nullptr));
        TE_TurnOffLight->setDisplayFormat(QCoreApplication::translate("MainWindow", "mm:ss", nullptr));
        RB_TurnOffLight->setText(QCoreApplication::translate("MainWindow", "Turn off the light", nullptr));
        RB_AutoControl->setText(QCoreApplication::translate("MainWindow", "Automatic control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
