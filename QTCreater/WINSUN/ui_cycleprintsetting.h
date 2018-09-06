/********************************************************************************
** Form generated from reading UI file 'cycleprintsetting.ui'
**
** Created: Fri Aug 31 18:03:01 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYCLEPRINTSETTING_H
#define UI_CYCLEPRINTSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CyclePrintSetting
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButtonRestoreDefaults;
    QPushButton *pushButtonOK;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBoxBreathe1;
    QDoubleSpinBox *doubleSpinBoxOverlift1;
    QDoubleSpinBox *doubleSpinBoxSettle1;
    QSpinBox *spinBoxRaiseSpd1;
    QLabel *label_6;
    QSpinBox *spinBoxLowerSpd1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;

    void setupUi(QWidget *CyclePrintSetting)
    {
        if (CyclePrintSetting->objectName().isEmpty())
            CyclePrintSetting->setObjectName(QString::fromUtf8("CyclePrintSetting"));
        CyclePrintSetting->setWindowModality(Qt::NonModal);
        CyclePrintSetting->resize(186, 187);
        CyclePrintSetting->setMaximumSize(QSize(474, 237));
        CyclePrintSetting->setFocusPolicy(Qt::NoFocus);
        gridLayout = new QGridLayout(CyclePrintSetting);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButtonRestoreDefaults = new QPushButton(CyclePrintSetting);
        pushButtonRestoreDefaults->setObjectName(QString::fromUtf8("pushButtonRestoreDefaults"));

        gridLayout->addWidget(pushButtonRestoreDefaults, 5, 0, 1, 1);

        pushButtonOK = new QPushButton(CyclePrintSetting);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));

        gridLayout->addWidget(pushButtonOK, 5, 1, 1, 2);

        label_7 = new QLabel(CyclePrintSetting);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 2);

        doubleSpinBoxBreathe1 = new QDoubleSpinBox(CyclePrintSetting);
        doubleSpinBoxBreathe1->setObjectName(QString::fromUtf8("doubleSpinBoxBreathe1"));
        doubleSpinBoxBreathe1->setMaximum(60);
        doubleSpinBoxBreathe1->setValue(0);

        gridLayout->addWidget(doubleSpinBoxBreathe1, 3, 2, 1, 1);

        doubleSpinBoxOverlift1 = new QDoubleSpinBox(CyclePrintSetting);
        doubleSpinBoxOverlift1->setObjectName(QString::fromUtf8("doubleSpinBoxOverlift1"));
        doubleSpinBoxOverlift1->setMaximum(9);
        doubleSpinBoxOverlift1->setValue(4);

        gridLayout->addWidget(doubleSpinBoxOverlift1, 2, 2, 1, 1);

        doubleSpinBoxSettle1 = new QDoubleSpinBox(CyclePrintSetting);
        doubleSpinBoxSettle1->setObjectName(QString::fromUtf8("doubleSpinBoxSettle1"));
        doubleSpinBoxSettle1->setMaximum(60);
        doubleSpinBoxSettle1->setValue(3);

        gridLayout->addWidget(doubleSpinBoxSettle1, 4, 2, 1, 1);

        spinBoxRaiseSpd1 = new QSpinBox(CyclePrintSetting);
        spinBoxRaiseSpd1->setObjectName(QString::fromUtf8("spinBoxRaiseSpd1"));
        spinBoxRaiseSpd1->setMaximum(130);
        spinBoxRaiseSpd1->setValue(120);

        gridLayout->addWidget(spinBoxRaiseSpd1, 0, 2, 1, 1);

        label_6 = new QLabel(CyclePrintSetting);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 2);

        spinBoxLowerSpd1 = new QSpinBox(CyclePrintSetting);
        spinBoxLowerSpd1->setObjectName(QString::fromUtf8("spinBoxLowerSpd1"));
        spinBoxLowerSpd1->setMaximum(130);
        spinBoxLowerSpd1->setValue(120);

        gridLayout->addWidget(spinBoxLowerSpd1, 1, 2, 1, 1);

        label = new QLabel(CyclePrintSetting);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_2 = new QLabel(CyclePrintSetting);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        label_5 = new QLabel(CyclePrintSetting);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 2);


        retranslateUi(CyclePrintSetting);

        QMetaObject::connectSlotsByName(CyclePrintSetting);
    } // setupUi

    void retranslateUi(QWidget *CyclePrintSetting)
    {
        CyclePrintSetting->setWindowTitle(QApplication::translate("CyclePrintSetting", "\346\211\223\345\215\260\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButtonRestoreDefaults->setText(QApplication::translate("CyclePrintSetting", "\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButtonOK->setText(QApplication::translate("CyclePrintSetting", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CyclePrintSetting", "\346\262\211\346\267\200\346\227\266\351\227\264(s)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("CyclePrintSetting", "\345\201\234\347\225\231\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("CyclePrintSetting", "Residence(s)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CyclePrintSetting", "Raise Speed(r/min)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CyclePrintSetting", "Lower Speed(r/min)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CyclePrintSetting", "Extra heiight(mm)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CyclePrintSetting: public Ui_CyclePrintSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYCLEPRINTSETTING_H
