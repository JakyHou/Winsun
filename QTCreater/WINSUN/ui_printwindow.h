/********************************************************************************
** Form generated from reading UI file 'printwindow.ui'
**
** Created: Mon Sep 3 15:35:46 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTWINDOW_H
#define UI_PRINTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrintWindow
{
public:
    QSpinBox *spinBox_BlueLEDCurrent;
    QPushButton *pushButtonBoardOFF;
    QLabel *label_6;
    QPushButton *pushButtonBoardON;
    QLineEdit *lineEditTgtPos;
    QLabel *label_30;
    QPushButton *pushButtonResetHomePos;
    QCheckBox *checkBox;
    QLineEdit *lineEditHomePos;
    QComboBox *comboBoxMaterial_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QPushButton *pushButtonFindHomePos;
    QPushButton *pushButtonStop;
    QLabel *label;
    QPushButton *pushButtonProjPowerON;
    QPushButton *pushButtonProjPowerOFF;
    QDoubleSpinBox *doubleSpinBoxToverMS;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBoxZHeightToPrint;
    QPushButton *pushButtonSelectAll;
    QLabel *label_9;
    QLabel *label_8;
    QSpinBox *spinBoxLayersToPrint;
    QTabWidget *tabWidgetPrinter;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_11;
    QLineEdit *lineEditZSizeMicrons;
    QLabel *label_10;
    QLineEdit *lineEditNumOfLayers;
    QLineEdit *lineEditXYPixelSizeMicrons;
    QLineEdit *lineEditZHeight;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButtonTerminal;
    QWidget *tab_4;
    QGridLayout *gridLayout_6;
    QLabel *label_4;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBoxTattachMS;
    QSpinBox *spinBoxNumAttach;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBoxTbaseMS;
    QLabel *label_LEDBlue;
    QSpinBox *spinBox_BlueLEDExposure;
    QLabel *label_18;
    QPushButton *pushButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_20;
    QLineEdit *projectorStatus;
    QLineEdit *lineEditName;
    QLabel *label_22;
    QPushButton *pushButtonShowSlice;
    QLCDNumber *lcdNumberTimeRequired;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonCancel;
    QDoubleSpinBox *doubleSpinBoxRaiseSpd1;
    QDoubleSpinBox *doubleSpinBoxLowerSpd1;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QLabel *label_16;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *pushButtonRestoreDefaults;
    QLabel *label_21;
    QSpinBox *spinBoxRaiseSpd1;
    QSpinBox *spinBoxLowerSpd1;
    QDoubleSpinBox *doubleSpinBoxOverlift1;
    QDoubleSpinBox *doubleSpinBoxBreathe1;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_7;
    QLabel *labelPrinter;
    QLineEdit *commStatus;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *label_12;
    QLineEdit *lineEditInfo;
    QPushButton *pushButtonBrowse;
    QLabel *label_5;
    QComboBox *comboBoxMaterial;
    QPushButton *pushButton_MaterialsEdit;
    QLabel *label_7;
    QLineEdit *lineEditTimeRequired;
    QPushButton *pushButtonPrint;
    QToolButton *toolButtonAdvanced;

    void setupUi(QWidget *PrintWindow)
    {
        if (PrintWindow->objectName().isEmpty())
            PrintWindow->setObjectName(QString::fromUtf8("PrintWindow"));
        PrintWindow->resize(374, 287);
        PrintWindow->setMinimumSize(QSize(0, 0));
        PrintWindow->setMaximumSize(QSize(4200, 2800));
        spinBox_BlueLEDCurrent = new QSpinBox(PrintWindow);
        spinBox_BlueLEDCurrent->setObjectName(QString::fromUtf8("spinBox_BlueLEDCurrent"));
        spinBox_BlueLEDCurrent->setGeometry(QRect(200, 630, 80, 20));
        spinBox_BlueLEDCurrent->setMaximum(0);
        spinBox_BlueLEDCurrent->setSingleStep(5);
        pushButtonBoardOFF = new QPushButton(PrintWindow);
        pushButtonBoardOFF->setObjectName(QString::fromUtf8("pushButtonBoardOFF"));
        pushButtonBoardOFF->setGeometry(QRect(721, 310, 75, 23));
        label_6 = new QLabel(PrintWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(520, 310, 89, 23));
        pushButtonBoardON = new QPushButton(PrintWindow);
        pushButtonBoardON->setObjectName(QString::fromUtf8("pushButtonBoardON"));
        pushButtonBoardON->setGeometry(QRect(625, 310, 80, 23));
        lineEditTgtPos = new QLineEdit(PrintWindow);
        lineEditTgtPos->setObjectName(QString::fromUtf8("lineEditTgtPos"));
        lineEditTgtPos->setEnabled(true);
        lineEditTgtPos->setGeometry(QRect(190, 700, 80, 20));
        lineEditTgtPos->setMaximumSize(QSize(80, 16777215));
        label_30 = new QLabel(PrintWindow);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(40, 700, 89, 23));
        pushButtonResetHomePos = new QPushButton(PrintWindow);
        pushButtonResetHomePos->setObjectName(QString::fromUtf8("pushButtonResetHomePos"));
        pushButtonResetHomePos->setEnabled(false);
        pushButtonResetHomePos->setGeometry(QRect(350, 670, 75, 23));
        checkBox = new QCheckBox(PrintWindow);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(143, 673, 89, 16));
        lineEditHomePos = new QLineEdit(PrintWindow);
        lineEditHomePos->setObjectName(QString::fromUtf8("lineEditHomePos"));
        lineEditHomePos->setEnabled(false);
        lineEditHomePos->setGeometry(QRect(251, 671, 80, 20));
        lineEditHomePos->setMaximumSize(QSize(80, 16777215));
        comboBoxMaterial_2 = new QComboBox(PrintWindow);
        comboBoxMaterial_2->setObjectName(QString::fromUtf8("comboBoxMaterial_2"));
        comboBoxMaterial_2->setGeometry(QRect(470, 590, 125, 20));
        layoutWidget = new QWidget(PrintWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(430, 620, 311, 121));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonFindHomePos = new QPushButton(layoutWidget);
        pushButtonFindHomePos->setObjectName(QString::fromUtf8("pushButtonFindHomePos"));

        gridLayout_3->addWidget(pushButtonFindHomePos, 0, 1, 1, 1);

        pushButtonStop = new QPushButton(layoutWidget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));

        gridLayout_3->addWidget(pushButtonStop, 0, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        pushButtonProjPowerON = new QPushButton(layoutWidget);
        pushButtonProjPowerON->setObjectName(QString::fromUtf8("pushButtonProjPowerON"));

        gridLayout_3->addWidget(pushButtonProjPowerON, 1, 1, 1, 1);

        pushButtonProjPowerOFF = new QPushButton(layoutWidget);
        pushButtonProjPowerOFF->setObjectName(QString::fromUtf8("pushButtonProjPowerOFF"));

        gridLayout_3->addWidget(pushButtonProjPowerOFF, 1, 2, 1, 1);

        doubleSpinBoxToverMS = new QDoubleSpinBox(PrintWindow);
        doubleSpinBoxToverMS->setObjectName(QString::fromUtf8("doubleSpinBoxToverMS"));
        doubleSpinBoxToverMS->setGeometry(QRect(670, 540, 134, 20));
        doubleSpinBoxToverMS->setMaximum(5);
        doubleSpinBoxToverMS->setValue(0);
        label_17 = new QLabel(PrintWindow);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(450, 540, 180, 20));
        doubleSpinBoxZHeightToPrint = new QDoubleSpinBox(PrintWindow);
        doubleSpinBoxZHeightToPrint->setObjectName(QString::fromUtf8("doubleSpinBoxZHeightToPrint"));
        doubleSpinBoxZHeightToPrint->setGeometry(QRect(640, 500, 183, 20));
        doubleSpinBoxZHeightToPrint->setReadOnly(true);
        doubleSpinBoxZHeightToPrint->setMaximum(100000);
        pushButtonSelectAll = new QPushButton(PrintWindow);
        pushButtonSelectAll->setObjectName(QString::fromUtf8("pushButtonSelectAll"));
        pushButtonSelectAll->setGeometry(QRect(747, 450, 75, 23));
        label_9 = new QLabel(PrintWindow);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(520, 450, 126, 65));
        label_8 = new QLabel(PrintWindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(508, 500, 126, 20));
        spinBoxLayersToPrint = new QSpinBox(PrintWindow);
        spinBoxLayersToPrint->setObjectName(QString::fromUtf8("spinBoxLayersToPrint"));
        spinBoxLayersToPrint->setGeometry(QRect(641, 451, 100, 20));
        spinBoxLayersToPrint->setMinimumSize(QSize(100, 0));
        spinBoxLayersToPrint->setMaximumSize(QSize(81, 16777215));
        spinBoxLayersToPrint->setMaximum(9999);
        spinBoxLayersToPrint->setSingleStep(5);
        tabWidgetPrinter = new QTabWidget(PrintWindow);
        tabWidgetPrinter->setObjectName(QString::fromUtf8("tabWidgetPrinter"));
        tabWidgetPrinter->setGeometry(QRect(530, 30, 411, 210));
        tabWidgetPrinter->setMaximumSize(QSize(16777215, 320));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        lineEditZSizeMicrons = new QLineEdit(tab_2);
        lineEditZSizeMicrons->setObjectName(QString::fromUtf8("lineEditZSizeMicrons"));
        lineEditZSizeMicrons->setEnabled(true);
        lineEditZSizeMicrons->setReadOnly(true);

        gridLayout->addWidget(lineEditZSizeMicrons, 1, 1, 1, 1);

        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        lineEditNumOfLayers = new QLineEdit(tab_2);
        lineEditNumOfLayers->setObjectName(QString::fromUtf8("lineEditNumOfLayers"));
        lineEditNumOfLayers->setEnabled(true);
        lineEditNumOfLayers->setReadOnly(true);

        gridLayout->addWidget(lineEditNumOfLayers, 2, 1, 1, 1);

        lineEditXYPixelSizeMicrons = new QLineEdit(tab_2);
        lineEditXYPixelSizeMicrons->setObjectName(QString::fromUtf8("lineEditXYPixelSizeMicrons"));
        lineEditXYPixelSizeMicrons->setEnabled(true);
        lineEditXYPixelSizeMicrons->setReadOnly(true);

        gridLayout->addWidget(lineEditXYPixelSizeMicrons, 0, 1, 1, 1);

        lineEditZHeight = new QLineEdit(tab_2);
        lineEditZHeight->setObjectName(QString::fromUtf8("lineEditZHeight"));
        lineEditZHeight->setEnabled(true);
        lineEditZHeight->setReadOnly(true);

        gridLayout->addWidget(lineEditZHeight, 3, 1, 1, 1);

        tabWidgetPrinter->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));

        gridLayout_2->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));

        gridLayout_2->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));

        gridLayout_2->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));

        gridLayout_2->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));

        gridLayout_2->addLayout(horizontalLayout_9, 4, 0, 1, 1);

        pushButtonTerminal = new QPushButton(tab_3);
        pushButtonTerminal->setObjectName(QString::fromUtf8("pushButtonTerminal"));

        gridLayout_2->addWidget(pushButtonTerminal, 5, 0, 1, 1);

        tabWidgetPrinter->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_6 = new QGridLayout(tab_4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_6->addWidget(label_4, 0, 0, 1, 1);

        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_6->addWidget(label_13, 1, 0, 1, 1);

        doubleSpinBoxTattachMS = new QDoubleSpinBox(tab_4);
        doubleSpinBoxTattachMS->setObjectName(QString::fromUtf8("doubleSpinBoxTattachMS"));
        doubleSpinBoxTattachMS->setMaximum(20);
        doubleSpinBoxTattachMS->setValue(0);

        gridLayout_6->addWidget(doubleSpinBoxTattachMS, 1, 1, 1, 1);

        spinBoxNumAttach = new QSpinBox(tab_4);
        spinBoxNumAttach->setObjectName(QString::fromUtf8("spinBoxNumAttach"));
        spinBoxNumAttach->setMaximum(10);
        spinBoxNumAttach->setValue(0);

        gridLayout_6->addWidget(spinBoxNumAttach, 2, 1, 1, 1);

        label_19 = new QLabel(tab_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_6->addWidget(label_19, 3, 0, 1, 1);

        doubleSpinBoxTbaseMS = new QDoubleSpinBox(tab_4);
        doubleSpinBoxTbaseMS->setObjectName(QString::fromUtf8("doubleSpinBoxTbaseMS"));
        doubleSpinBoxTbaseMS->setMaximum(20);
        doubleSpinBoxTbaseMS->setValue(0);

        gridLayout_6->addWidget(doubleSpinBoxTbaseMS, 3, 1, 1, 1);

        label_LEDBlue = new QLabel(tab_4);
        label_LEDBlue->setObjectName(QString::fromUtf8("label_LEDBlue"));

        gridLayout_6->addWidget(label_LEDBlue, 4, 0, 1, 1);

        spinBox_BlueLEDExposure = new QSpinBox(tab_4);
        spinBox_BlueLEDExposure->setObjectName(QString::fromUtf8("spinBox_BlueLEDExposure"));
        spinBox_BlueLEDExposure->setMaximum(255);
        spinBox_BlueLEDExposure->setSingleStep(5);
        spinBox_BlueLEDExposure->setValue(100);

        gridLayout_6->addWidget(spinBox_BlueLEDExposure, 4, 1, 1, 1);

        label_18 = new QLabel(tab_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_6->addWidget(label_18, 2, 0, 1, 1);

        pushButton = new QPushButton(tab_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_6->addWidget(pushButton, 5, 1, 1, 1);

        tabWidgetPrinter->addTab(tab_4, QString());
        layoutWidget1 = new QWidget(PrintWindow);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(480, 410, 331, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(layoutWidget1);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_4->addWidget(label_20);

        projectorStatus = new QLineEdit(layoutWidget1);
        projectorStatus->setObjectName(QString::fromUtf8("projectorStatus"));

        horizontalLayout_4->addWidget(projectorStatus);

        lineEditName = new QLineEdit(PrintWindow);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setEnabled(true);
        lineEditName->setGeometry(QRect(870, 580, 176, 20));
        lineEditName->setReadOnly(true);
        label_22 = new QLabel(PrintWindow);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(730, 590, 78, 20));
        pushButtonShowSlice = new QPushButton(PrintWindow);
        pushButtonShowSlice->setObjectName(QString::fromUtf8("pushButtonShowSlice"));
        pushButtonShowSlice->setGeometry(QRect(750, 480, 301, 23));
        lcdNumberTimeRequired = new QLCDNumber(PrintWindow);
        lcdNumberTimeRequired->setObjectName(QString::fromUtf8("lcdNumberTimeRequired"));
        lcdNumberTimeRequired->setGeometry(QRect(520, 240, 214, 60));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdNumberTimeRequired->sizePolicy().hasHeightForWidth());
        lcdNumberTimeRequired->setSizePolicy(sizePolicy);
        lcdNumberTimeRequired->setMinimumSize(QSize(0, 60));
        QPalette palette;
        QBrush brush(QColor(170, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush2(QColor(85, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        QBrush brush4(QColor(255, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        lcdNumberTimeRequired->setPalette(palette);
        lcdNumberTimeRequired->setAutoFillBackground(true);
        layoutWidget2 = new QWidget(PrintWindow);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(490, 350, 379, 37));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonCancel = new QPushButton(layoutWidget2);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(0, 35));

        horizontalLayout_3->addWidget(pushButtonCancel);

        doubleSpinBoxRaiseSpd1 = new QDoubleSpinBox(PrintWindow);
        doubleSpinBoxRaiseSpd1->setObjectName(QString::fromUtf8("doubleSpinBoxRaiseSpd1"));
        doubleSpinBoxRaiseSpd1->setGeometry(QRect(880, 610, 151, 40));
        doubleSpinBoxRaiseSpd1->setMinimumSize(QSize(0, 40));
        doubleSpinBoxRaiseSpd1->setMaximum(520);
        doubleSpinBoxLowerSpd1 = new QDoubleSpinBox(PrintWindow);
        doubleSpinBoxLowerSpd1->setObjectName(QString::fromUtf8("doubleSpinBoxLowerSpd1"));
        doubleSpinBoxLowerSpd1->setGeometry(QRect(880, 660, 151, 40));
        doubleSpinBoxLowerSpd1->setMinimumSize(QSize(0, 40));
        doubleSpinBoxLowerSpd1->setMaximum(520);
        groupBox_2 = new QGroupBox(PrintWindow);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(13, 293, 361, 281));
        groupBox_2->setMaximumSize(QSize(3500, 350));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(0, 40));

        gridLayout_4->addWidget(label_16, 1, 0, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(0, 40));

        gridLayout_4->addWidget(label_14, 2, 0, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(0, 40));

        gridLayout_4->addWidget(label_15, 3, 0, 1, 1);

        pushButtonRestoreDefaults = new QPushButton(groupBox_2);
        pushButtonRestoreDefaults->setObjectName(QString::fromUtf8("pushButtonRestoreDefaults"));
        pushButtonRestoreDefaults->setMinimumSize(QSize(0, 40));

        gridLayout_4->addWidget(pushButtonRestoreDefaults, 6, 0, 1, 2);

        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(0, 40));

        gridLayout_4->addWidget(label_21, 4, 0, 1, 1);

        spinBoxRaiseSpd1 = new QSpinBox(groupBox_2);
        spinBoxRaiseSpd1->setObjectName(QString::fromUtf8("spinBoxRaiseSpd1"));
        spinBoxRaiseSpd1->setMinimumSize(QSize(0, 40));
        spinBoxRaiseSpd1->setMinimum(120);
        spinBoxRaiseSpd1->setMaximum(800);
        spinBoxRaiseSpd1->setSingleStep(4);
        spinBoxRaiseSpd1->setValue(480);

        gridLayout_4->addWidget(spinBoxRaiseSpd1, 1, 1, 1, 1);

        spinBoxLowerSpd1 = new QSpinBox(groupBox_2);
        spinBoxLowerSpd1->setObjectName(QString::fromUtf8("spinBoxLowerSpd1"));
        spinBoxLowerSpd1->setMinimumSize(QSize(0, 40));
        spinBoxLowerSpd1->setMinimum(120);
        spinBoxLowerSpd1->setMaximum(800);
        spinBoxLowerSpd1->setSingleStep(4);
        spinBoxLowerSpd1->setValue(480);

        gridLayout_4->addWidget(spinBoxLowerSpd1, 2, 1, 1, 1);

        doubleSpinBoxOverlift1 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBoxOverlift1->setObjectName(QString::fromUtf8("doubleSpinBoxOverlift1"));
        doubleSpinBoxOverlift1->setMinimumSize(QSize(0, 40));
        doubleSpinBoxOverlift1->setMaximum(9);
        doubleSpinBoxOverlift1->setValue(4);

        gridLayout_4->addWidget(doubleSpinBoxOverlift1, 3, 1, 1, 1);

        doubleSpinBoxBreathe1 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBoxBreathe1->setObjectName(QString::fromUtf8("doubleSpinBoxBreathe1"));
        doubleSpinBoxBreathe1->setMinimumSize(QSize(0, 40));
        doubleSpinBoxBreathe1->setMaximum(60);
        doubleSpinBoxBreathe1->setValue(1.5);

        gridLayout_4->addWidget(doubleSpinBoxBreathe1, 4, 1, 1, 1);

        layoutWidget3 = new QWidget(PrintWindow);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(13, 5, 353, 271));
        gridLayout_7 = new QGridLayout(layoutWidget3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        labelPrinter = new QLabel(layoutWidget3);
        labelPrinter->setObjectName(QString::fromUtf8("labelPrinter"));
        labelPrinter->setMinimumSize(QSize(110, 35));

        gridLayout_7->addWidget(labelPrinter, 0, 0, 1, 1);

        commStatus = new QLineEdit(layoutWidget3);
        commStatus->setObjectName(QString::fromUtf8("commStatus"));
        commStatus->setEnabled(true);
        commStatus->setMinimumSize(QSize(0, 35));
        commStatus->setReadOnly(true);

        gridLayout_7->addWidget(commStatus, 0, 1, 1, 1);

        groupBox = new QGroupBox(layoutWidget3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 200));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(0, 35));

        gridLayout_5->addWidget(label_12, 0, 0, 1, 1);

        lineEditInfo = new QLineEdit(groupBox);
        lineEditInfo->setObjectName(QString::fromUtf8("lineEditInfo"));
        lineEditInfo->setEnabled(true);
        lineEditInfo->setMinimumSize(QSize(0, 35));
        lineEditInfo->setReadOnly(true);

        gridLayout_5->addWidget(lineEditInfo, 0, 1, 1, 1);

        pushButtonBrowse = new QPushButton(groupBox);
        pushButtonBrowse->setObjectName(QString::fromUtf8("pushButtonBrowse"));
        pushButtonBrowse->setMinimumSize(QSize(0, 35));

        gridLayout_5->addWidget(pushButtonBrowse, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 35));

        gridLayout_5->addWidget(label_5, 1, 0, 1, 1);

        comboBoxMaterial = new QComboBox(groupBox);
        comboBoxMaterial->setObjectName(QString::fromUtf8("comboBoxMaterial"));
        comboBoxMaterial->setMinimumSize(QSize(0, 35));

        gridLayout_5->addWidget(comboBoxMaterial, 1, 1, 1, 1);

        pushButton_MaterialsEdit = new QPushButton(groupBox);
        pushButton_MaterialsEdit->setObjectName(QString::fromUtf8("pushButton_MaterialsEdit"));
        pushButton_MaterialsEdit->setMinimumSize(QSize(0, 35));

        gridLayout_5->addWidget(pushButton_MaterialsEdit, 1, 2, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(110, 0));

        gridLayout_5->addWidget(label_7, 2, 0, 1, 1);

        lineEditTimeRequired = new QLineEdit(groupBox);
        lineEditTimeRequired->setObjectName(QString::fromUtf8("lineEditTimeRequired"));
        lineEditTimeRequired->setEnabled(true);
        lineEditTimeRequired->setMinimumSize(QSize(0, 40));
        lineEditTimeRequired->setReadOnly(true);

        gridLayout_5->addWidget(lineEditTimeRequired, 2, 1, 1, 1);

        pushButtonPrint = new QPushButton(groupBox);
        pushButtonPrint->setObjectName(QString::fromUtf8("pushButtonPrint"));
        pushButtonPrint->setEnabled(true);
        pushButtonPrint->setMinimumSize(QSize(0, 35));

        gridLayout_5->addWidget(pushButtonPrint, 2, 2, 1, 1);


        gridLayout_7->addWidget(groupBox, 1, 0, 1, 2);

        toolButtonAdvanced = new QToolButton(layoutWidget3);
        toolButtonAdvanced->setObjectName(QString::fromUtf8("toolButtonAdvanced"));
        toolButtonAdvanced->setMinimumSize(QSize(340, 40));
        toolButtonAdvanced->setPopupMode(QToolButton::InstantPopup);
        toolButtonAdvanced->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButtonAdvanced->setArrowType(Qt::RightArrow);

        gridLayout_7->addWidget(toolButtonAdvanced, 2, 0, 1, 2);

        groupBox_2->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        spinBox_BlueLEDCurrent->raise();
        pushButtonBoardOFF->raise();
        label_6->raise();
        pushButtonBoardON->raise();
        lineEditTgtPos->raise();
        label_30->raise();
        pushButtonResetHomePos->raise();
        checkBox->raise();
        lineEditHomePos->raise();
        comboBoxMaterial_2->raise();
        layoutWidget->raise();
        doubleSpinBoxToverMS->raise();
        label_17->raise();
        doubleSpinBoxZHeightToPrint->raise();
        pushButtonSelectAll->raise();
        label_9->raise();
        label_8->raise();
        spinBoxLayersToPrint->raise();
        tabWidgetPrinter->raise();
        lineEditName->raise();
        label_22->raise();
        pushButtonShowSlice->raise();
        lcdNumberTimeRequired->raise();
        layoutWidget->raise();
        doubleSpinBoxRaiseSpd1->raise();
        doubleSpinBoxLowerSpd1->raise();

        retranslateUi(PrintWindow);

        comboBoxMaterial_2->setCurrentIndex(0);
        tabWidgetPrinter->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(PrintWindow);
    } // setupUi

    void retranslateUi(QWidget *PrintWindow)
    {
        PrintWindow->setWindowTitle(QApplication::translate("PrintWindow", "Print", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonBoardOFF->setToolTip(QApplication::translate("PrintWindow", "\345\205\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonBoardOFF->setText(QApplication::translate("PrintWindow", "OFF", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("PrintWindow", "\351\201\256\345\205\211\346\235\277", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("PrintWindow", "Board\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonBoardON->setToolTip(QApplication::translate("PrintWindow", "\345\274\200", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonBoardON->setText(QApplication::translate("PrintWindow", "ON", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEditTgtPos->setToolTip(QApplication::translate("PrintWindow", "\347\233\256\346\240\207\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_30->setToolTip(QApplication::translate("PrintWindow", "\347\224\265\346\234\272\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_30->setText(QApplication::translate("PrintWindow", "Position\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonResetHomePos->setToolTip(QApplication::translate("PrintWindow", "\350\256\276\347\275\256\351\233\266\347\202\271", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonResetHomePos->setText(QApplication::translate("PrintWindow", "Reset", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("PrintWindow", "\351\207\215\350\256\276\351\233\266\347\202\271", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox->setText(QApplication::translate("PrintWindow", "Reaset Home", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEditHomePos->setToolTip(QApplication::translate("PrintWindow", "\346\204\237\345\272\224\345\231\250\344\273\245\344\270\213\347\232\204\344\275\215\347\275\256\344\270\272\351\233\266\347\202\271", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        comboBoxMaterial_2->clear();
        comboBoxMaterial_2->insertItems(0, QStringList()
         << QApplication::translate("PrintWindow", "200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrintWindow", "150", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrintWindow", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrintWindow", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrintWindow", "10", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        pushButtonFindHomePos->setToolTip(QApplication::translate("PrintWindow", "\351\233\266\347\202\271\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonFindHomePos->setText(QApplication::translate("PrintWindow", "Find Home", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonStop->setToolTip(QApplication::translate("PrintWindow", "\347\224\265\346\234\272\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonStop->setText(QApplication::translate("PrintWindow", "Stop", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("PrintWindow", "\346\212\225\345\275\261\344\273\252", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("PrintWindow", "Projector\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonProjPowerON->setToolTip(QApplication::translate("PrintWindow", "\345\274\200", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonProjPowerON->setText(QApplication::translate("PrintWindow", "ON", 0, QApplication::UnicodeUTF8));
        pushButtonProjPowerOFF->setText(QApplication::translate("PrintWindow", "OFF", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_17->setToolTip(QApplication::translate("PrintWindow", "\345\221\250\350\276\271\346\233\235\345\205\211\346\227\266\351\227\264\357\274\210\350\276\271\347\274\230\345\244\204\347\220\206\357\274\211", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_17->setText(QApplication::translate("PrintWindow", "Perimeter Exposure(s):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonSelectAll->setToolTip(QApplication::translate("PrintWindow", "\345\205\250\351\200\211", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonSelectAll->setText(QApplication::translate("PrintWindow", "Select All", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_9->setToolTip(QApplication::translate("PrintWindow", "\346\211\223\345\215\260\345\261\202\346\225\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_9->setText(QApplication::translate("PrintWindow", "Num of Print Layers\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("PrintWindow", "\351\253\230\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("PrintWindow", "Height(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidgetPrinter->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        tab_2->setToolTip(QApplication::translate("PrintWindow", "\346\250\241\345\236\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("PrintWindow", "\345\210\207\347\211\207\345\216\232\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("PrintWindow", "Thickness(\316\274m)\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("PrintWindow", "\345\203\217\347\264\240\347\262\276\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("PrintWindow", "Pixel(\316\274m)\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_11->setToolTip(QApplication::translate("PrintWindow", "\351\253\230\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_11->setText(QApplication::translate("PrintWindow", "Height(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEditZSizeMicrons->setToolTip(QApplication::translate("PrintWindow", "\345\210\207\347\211\207\345\216\232\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_10->setToolTip(QApplication::translate("PrintWindow", "\345\261\202\346\225\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("PrintWindow", "Total Layers\357\274\232", 0, QApplication::UnicodeUTF8));
        tabWidgetPrinter->setTabText(tabWidgetPrinter->indexOf(tab_2), QApplication::translate("PrintWindow", "Model", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tab_3->setToolTip(QApplication::translate("PrintWindow", "\346\211\223\345\215\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButtonTerminal->setToolTip(QApplication::translate("PrintWindow", "\347\273\210\347\253\257", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonTerminal->setText(QApplication::translate("PrintWindow", "Terminal", 0, QApplication::UnicodeUTF8));
        tabWidgetPrinter->setTabText(tabWidgetPrinter->indexOf(tab_3), QApplication::translate("PrintWindow", "Setting", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tab_4->setToolTip(QApplication::translate("PrintWindow", "\346\235\220\346\226\231\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("PrintWindow", "\345\210\207\347\211\207\345\216\232\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("PrintWindow", "Material\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_13->setToolTip(QApplication::translate("PrintWindow", "\345\233\272\345\256\232\345\261\202\346\233\235\345\205\211\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_13->setText(QApplication::translate("PrintWindow", "Attach Exposure(sec):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_19->setToolTip(QApplication::translate("PrintWindow", "\345\233\272\350\257\235\346\233\235\345\205\211\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_19->setText(QApplication::translate("PrintWindow", "Time of Exposure(sec):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_LEDBlue->setToolTip(QApplication::translate("PrintWindow", "\346\233\235\345\205\211\345\274\272\345\272\246\357\274\210\346\212\225\345\275\261\344\273\252\344\272\256\345\272\246\357\274\211", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_LEDBlue->setText(QApplication::translate("PrintWindow", "Intensity of Exposure(0-255)\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_18->setToolTip(QApplication::translate("PrintWindow", "\345\233\272\345\256\232\345\261\202\346\225\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_18->setText(QApplication::translate("PrintWindow", "Num of Attach Layers\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("PrintWindow", "Add", 0, QApplication::UnicodeUTF8));
        tabWidgetPrinter->setTabText(tabWidgetPrinter->indexOf(tab_4), QApplication::translate("PrintWindow", "Material", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_20->setToolTip(QApplication::translate("PrintWindow", "\346\212\225\345\275\261\344\273\252\350\277\236\346\216\245\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_20->setText(QApplication::translate("PrintWindow", "Projector Status\357\274\232", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("PrintWindow", "Info:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonShowSlice->setToolTip(QApplication::translate("PrintWindow", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonShowSlice->setText(QApplication::translate("PrintWindow", "Preview", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonCancel->setToolTip(QApplication::translate("PrintWindow", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonCancel->setText(QApplication::translate("PrintWindow", "Cancel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox_2->setToolTip(QApplication::translate("PrintWindow", "\351\242\204\344\274\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QApplication::translate("PrintWindow", "setting", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_16->setToolTip(QApplication::translate("PrintWindow", "\347\224\265\346\234\272\344\270\213\351\231\215\351\200\237\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_16->setText(QApplication::translate("PrintWindow", "Raise Speed(mm/min)\357\274\210120~800\357\274\211", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_14->setToolTip(QApplication::translate("PrintWindow", "\347\224\265\346\234\272\344\270\212\345\215\207\351\200\237\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_14->setText(QApplication::translate("PrintWindow", "Lower Speed(mm/min)\357\274\210120~800\357\274\211", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_15->setToolTip(QApplication::translate("PrintWindow", "\351\242\235\345\244\226\351\253\230\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_15->setText(QApplication::translate("PrintWindow", "Raise Height(mm)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonRestoreDefaults->setToolTip(QApplication::translate("PrintWindow", "\351\273\230\350\256\244\345\200\274", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonRestoreDefaults->setText(QApplication::translate("PrintWindow", "Default", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_21->setToolTip(QApplication::translate("PrintWindow", "\347\255\211\345\276\205\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_21->setText(QApplication::translate("PrintWindow", "Wait for Exposure(sec)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        labelPrinter->setToolTip(QApplication::translate("PrintWindow", "\346\211\223\345\215\260\346\234\272\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelPrinter->setText(QApplication::translate("PrintWindow", " Printer Status\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox->setToolTip(QApplication::translate("PrintWindow", "\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("PrintWindow", "Parameters", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_12->setToolTip(QApplication::translate("PrintWindow", "\346\250\241\345\236\213\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_12->setText(QApplication::translate("PrintWindow", "model\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEditInfo->setToolTip(QApplication::translate("PrintWindow", "\346\211\223\345\215\260\346\234\272   \345\210\207\347\211\207\345\216\232\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButtonBrowse->setToolTip(QApplication::translate("PrintWindow", "\346\265\217\350\247\210", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonBrowse->setText(QApplication::translate("PrintWindow", "Browse", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("PrintWindow", "\346\235\220\346\226\231", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("PrintWindow", "Material\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBoxMaterial->clear();
        comboBoxMaterial->insertItems(0, QStringList()
         << QApplication::translate("PrintWindow", "Transparent Yellow", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrintWindow", "Transparent Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrintWindow", "Transparent Blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrintWindow", "Transparent Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrintWindow", "Opaque Grey", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBoxMaterial->setToolTip(QApplication::translate("PrintWindow", "\346\235\220\346\226\231\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButton_MaterialsEdit->setToolTip(QApplication::translate("PrintWindow", "\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_MaterialsEdit->setText(QApplication::translate("PrintWindow", "Edit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("PrintWindow", "\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("PrintWindow", "Time(hh:mm)\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEditTimeRequired->setToolTip(QApplication::translate("PrintWindow", "\351\242\204\350\256\241\346\211\200\351\234\200\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButtonPrint->setToolTip(QApplication::translate("PrintWindow", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonPrint->setText(QApplication::translate("PrintWindow", "Print", 0, QApplication::UnicodeUTF8));
        toolButtonAdvanced->setText(QApplication::translate("PrintWindow", "         Advanced Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PrintWindow: public Ui_PrintWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTWINDOW_H
