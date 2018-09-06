/********************************************************************************
** Form generated from reading UI file 'terminal.ui'
**
** Created: Wed Sep 5 10:45:25 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMINAL_H
#define UI_TERMINAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Terminal
{
public:
    QLabel *label;
    QPushButton *pushButtonResetHomePos;
    QLineEdit *lineEditCurZPosInPU;
    QPushButton *pushButtonFindHomePos;
    QLineEdit *lineEditHomePos;
    QLabel *label_30;
    QPushButton *pushButtonStop;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelPrinter;
    QLineEdit *commStatus;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBoxDistance;
    QToolButton *toolButtonUp;
    QToolButton *toolButtonDown;
    QPushButton *pushButtonCalibration;
    QLabel *label_4;
    QSpinBox *spinBox_BlueLEDCurrent;
    QPushButton *pushButtonSubtract;
    QPushButton *pushButtonAdd;
    QCheckBox *checkBox;
    QLabel *label_LEDBlue;
    QPushButton *pushButtonProjPowerON;
    QPushButton *pushButtonProjPowerOFF;
    QLabel *label_20;
    QLineEdit *projectorStatus;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *Terminal)
    {
        if (Terminal->objectName().isEmpty())
            Terminal->setObjectName(QString::fromUtf8("Terminal"));
        Terminal->setEnabled(true);
        Terminal->resize(377, 301);
        Terminal->setMaximumSize(QSize(3510, 3030));
        label = new QLabel(Terminal);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 550, 165, 40));
        label->setMinimumSize(QSize(0, 40));
        pushButtonResetHomePos = new QPushButton(Terminal);
        pushButtonResetHomePos->setObjectName(QString::fromUtf8("pushButtonResetHomePos"));
        pushButtonResetHomePos->setEnabled(false);
        pushButtonResetHomePos->setGeometry(QRect(260, 519, 75, 23));
        lineEditCurZPosInPU = new QLineEdit(Terminal);
        lineEditCurZPosInPU->setObjectName(QString::fromUtf8("lineEditCurZPosInPU"));
        lineEditCurZPosInPU->setEnabled(true);
        lineEditCurZPosInPU->setGeometry(QRect(170, 461, 80, 20));
        lineEditCurZPosInPU->setMaximumSize(QSize(80, 16777215));
        pushButtonFindHomePos = new QPushButton(Terminal);
        pushButtonFindHomePos->setObjectName(QString::fromUtf8("pushButtonFindHomePos"));
        pushButtonFindHomePos->setGeometry(QRect(260, 490, 75, 23));
        lineEditHomePos = new QLineEdit(Terminal);
        lineEditHomePos->setObjectName(QString::fromUtf8("lineEditHomePos"));
        lineEditHomePos->setEnabled(false);
        lineEditHomePos->setGeometry(QRect(170, 520, 80, 20));
        lineEditHomePos->setMaximumSize(QSize(80, 16777215));
        label_30 = new QLabel(Terminal);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(16, 460, 60, 16));
        pushButtonStop = new QPushButton(Terminal);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(260, 460, 75, 23));
        layoutWidget = new QWidget(Terminal);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 357, 281));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelPrinter = new QLabel(layoutWidget);
        labelPrinter->setObjectName(QString::fromUtf8("labelPrinter"));
        labelPrinter->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(labelPrinter, 0, 0, 1, 1);

        commStatus = new QLineEdit(layoutWidget);
        commStatus->setObjectName(QString::fromUtf8("commStatus"));
        commStatus->setEnabled(true);
        commStatus->setMinimumSize(QSize(0, 40));
        commStatus->setReadOnly(true);

        gridLayout->addWidget(commStatus, 0, 1, 1, 4);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        doubleSpinBoxDistance = new QDoubleSpinBox(layoutWidget);
        doubleSpinBoxDistance->setObjectName(QString::fromUtf8("doubleSpinBoxDistance"));
        doubleSpinBoxDistance->setMinimumSize(QSize(0, 40));
        doubleSpinBoxDistance->setMaximum(100);

        gridLayout->addWidget(doubleSpinBoxDistance, 1, 1, 1, 2);

        toolButtonUp = new QToolButton(layoutWidget);
        toolButtonUp->setObjectName(QString::fromUtf8("toolButtonUp"));
        toolButtonUp->setMinimumSize(QSize(40, 40));
        toolButtonUp->setArrowType(Qt::UpArrow);

        gridLayout->addWidget(toolButtonUp, 1, 3, 1, 1);

        toolButtonDown = new QToolButton(layoutWidget);
        toolButtonDown->setObjectName(QString::fromUtf8("toolButtonDown"));
        toolButtonDown->setMinimumSize(QSize(40, 40));
        toolButtonDown->setArrowType(Qt::DownArrow);

        gridLayout->addWidget(toolButtonDown, 1, 4, 1, 1);

        pushButtonCalibration = new QPushButton(layoutWidget);
        pushButtonCalibration->setObjectName(QString::fromUtf8("pushButtonCalibration"));
        pushButtonCalibration->setMinimumSize(QSize(200, 40));

        gridLayout->addWidget(pushButtonCalibration, 2, 1, 1, 4);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(120, 40));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        spinBox_BlueLEDCurrent = new QSpinBox(layoutWidget);
        spinBox_BlueLEDCurrent->setObjectName(QString::fromUtf8("spinBox_BlueLEDCurrent"));
        spinBox_BlueLEDCurrent->setMinimumSize(QSize(0, 40));
        spinBox_BlueLEDCurrent->setMouseTracking(false);
        spinBox_BlueLEDCurrent->setFocusPolicy(Qt::WheelFocus);
        spinBox_BlueLEDCurrent->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_BlueLEDCurrent->setWrapping(false);
        spinBox_BlueLEDCurrent->setFrame(true);
        spinBox_BlueLEDCurrent->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_BlueLEDCurrent->setAccelerated(false);
        spinBox_BlueLEDCurrent->setKeyboardTracking(true);
        spinBox_BlueLEDCurrent->setMaximum(255);
        spinBox_BlueLEDCurrent->setSingleStep(5);

        gridLayout->addWidget(spinBox_BlueLEDCurrent, 4, 1, 1, 2);

        pushButtonSubtract = new QPushButton(Terminal);
        pushButtonSubtract->setObjectName(QString::fromUtf8("pushButtonSubtract"));
        pushButtonSubtract->setEnabled(false);
        pushButtonSubtract->setGeometry(QRect(226, 670, 40, 40));
        pushButtonSubtract->setMaximumSize(QSize(40, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        pushButtonSubtract->setFont(font);
        pushButtonAdd = new QPushButton(Terminal);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setEnabled(false);
        pushButtonAdd->setGeometry(QRect(180, 670, 40, 40));
        pushButtonAdd->setMaximumSize(QSize(40, 40));
        pushButtonAdd->setFont(font);
        checkBox = new QCheckBox(Terminal);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 510, 179, 40));
        checkBox->setMinimumSize(QSize(0, 40));
        label_LEDBlue = new QLabel(Terminal);
        label_LEDBlue->setObjectName(QString::fromUtf8("label_LEDBlue"));
        label_LEDBlue->setGeometry(QRect(30, 580, 215, 129));
        label_LEDBlue->setMinimumSize(QSize(0, 40));
        pushButtonProjPowerON = new QPushButton(Terminal);
        pushButtonProjPowerON->setObjectName(QString::fromUtf8("pushButtonProjPowerON"));
        pushButtonProjPowerON->setGeometry(QRect(176, 580, 40, 40));
        pushButtonProjPowerON->setMinimumSize(QSize(0, 40));
        pushButtonProjPowerON->setMaximumSize(QSize(40, 16777215));
        pushButtonProjPowerOFF = new QPushButton(Terminal);
        pushButtonProjPowerOFF->setObjectName(QString::fromUtf8("pushButtonProjPowerOFF"));
        pushButtonProjPowerOFF->setGeometry(QRect(230, 580, 40, 40));
        pushButtonProjPowerOFF->setMinimumSize(QSize(0, 40));
        pushButtonProjPowerOFF->setMaximumSize(QSize(40, 16777215));
        label_20 = new QLabel(Terminal);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 410, 143, 40));
        label_20->setMinimumSize(QSize(0, 40));
        projectorStatus = new QLineEdit(Terminal);
        projectorStatus->setObjectName(QString::fromUtf8("projectorStatus"));
        projectorStatus->setEnabled(true);
        projectorStatus->setGeometry(QRect(140, 410, 200, 40));
        projectorStatus->setMinimumSize(QSize(0, 40));
        projectorStatus->setReadOnly(true);
        lineEdit = new QLineEdit(Terminal);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 350, 131, 20));
        lineEdit->setReadOnly(true);
        label_3 = new QLabel(Terminal);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 350, 120, 23));
        pushButton_2 = new QPushButton(Terminal);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 310, 141, 23));
        pushButton = new QPushButton(Terminal);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 310, 157, 23));

        retranslateUi(Terminal);
        QObject::connect(checkBox, SIGNAL(toggled(bool)), pushButtonAdd, SLOT(setEnabled(bool)));
        QObject::connect(checkBox, SIGNAL(toggled(bool)), pushButtonSubtract, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(Terminal);
    } // setupUi

    void retranslateUi(QWidget *Terminal)
    {
        Terminal->setWindowTitle(QApplication::translate("Terminal", "Terminal", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Terminal->setToolTip(QApplication::translate("Terminal", "\347\273\210\347\253\257\346\223\215\344\275\234", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Terminal", "Reaset Home:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonResetHomePos->setToolTip(QApplication::translate("Terminal", "\350\256\276\347\275\256\351\233\266\347\202\271", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonResetHomePos->setText(QApplication::translate("Terminal", "Reset", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEditCurZPosInPU->setToolTip(QApplication::translate("Terminal", "\347\233\256\346\240\207\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButtonFindHomePos->setToolTip(QApplication::translate("Terminal", "\351\233\266\347\202\271\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonFindHomePos->setText(QApplication::translate("Terminal", "Find Home", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEditHomePos->setToolTip(QApplication::translate("Terminal", "\346\204\237\345\272\224\345\231\250\344\273\245\344\270\213\347\232\204\344\275\215\347\275\256\344\270\272\351\233\266\347\202\271", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_30->setToolTip(QApplication::translate("Terminal", "\347\224\265\346\234\272\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_30->setText(QApplication::translate("Terminal", "Position\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonStop->setToolTip(QApplication::translate("Terminal", "\347\224\265\346\234\272\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonStop->setText(QApplication::translate("Terminal", "Stop", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        labelPrinter->setToolTip(QApplication::translate("Terminal", "\346\211\223\345\215\260\346\234\272\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelPrinter->setText(QApplication::translate("Terminal", "Printer Status\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Terminal", "Manual Move(mm):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonUp->setToolTip(QApplication::translate("Terminal", "Up", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonUp->setText(QApplication::translate("Terminal", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonDown->setToolTip(QApplication::translate("Terminal", "Down", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonDown->setText(QApplication::translate("Terminal", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonCalibration->setToolTip(QApplication::translate("Terminal", "\344\274\240\346\204\237\345\231\250\347\232\204\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonCalibration->setText(QApplication::translate("Terminal", "Go To Calibration Position", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("Terminal", "\346\212\225\345\275\261\344\273\252", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("Terminal", "Light Intensity\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox_BlueLEDCurrent->setToolTip(QApplication::translate("Terminal", "Light Intensity(0-255)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButtonSubtract->setToolTip(QApplication::translate("Terminal", "Subtract", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonSubtract->setText(QApplication::translate("Terminal", "-", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonAdd->setToolTip(QApplication::translate("Terminal", "Add", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonAdd->setText(QApplication::translate("Terminal", "+", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("Terminal", "\351\207\215\350\256\276\351\233\266\347\202\271", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox->setText(QApplication::translate("Terminal", "Reaset Home", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_LEDBlue->setToolTip(QApplication::translate("Terminal", "\346\233\235\345\205\211\345\274\272\345\272\246\357\274\210\346\212\225\345\275\261\344\273\252\344\272\256\345\272\246\357\274\211", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_LEDBlue->setText(QApplication::translate("Terminal", "Light Intensity(0-255)\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonProjPowerON->setToolTip(QApplication::translate("Terminal", "\345\274\200", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonProjPowerON->setText(QApplication::translate("Terminal", "ON", 0, QApplication::UnicodeUTF8));
        pushButtonProjPowerOFF->setText(QApplication::translate("Terminal", "OFF", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_20->setToolTip(QApplication::translate("Terminal", "\346\212\225\345\275\261\344\273\252\350\277\236\346\216\245\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_20->setText(QApplication::translate("Terminal", "Projector Status\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Terminal", "Position:", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Terminal", "FindHome", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Terminal", "ResetHome", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Terminal: public Ui_Terminal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMINAL_H
