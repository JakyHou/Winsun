/********************************************************************************
** Form generated from reading UI file 'printsettingdialog.ui'
**
** Created: Fri Aug 31 18:03:02 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTSETTINGDIALOG_H
#define UI_PRINTSETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_PrintSettingDialog
{
public:
    QGridLayout *gridLayout_3;
    QLabel *label;
    QComboBox *printercombo;
    QGroupBox *groupBox_BuildSpace;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_pixelsize;
    QHBoxLayout *horizontalLayout;
    QLabel *label_35;
    QLabel *label_6;
    QLineEdit *Print_Extents_X;
    QLabel *label_33;
    QLineEdit *Print_Extents_Y;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_36;
    QLineEdit *Print_Extents_Z;
    QCheckBox *checkBoxAppears;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOK;

    void setupUi(QDialog *PrintSettingDialog)
    {
        if (PrintSettingDialog->objectName().isEmpty())
            PrintSettingDialog->setObjectName(QString::fromUtf8("PrintSettingDialog"));
        PrintSettingDialog->resize(419, 347);
        gridLayout_3 = new QGridLayout(PrintSettingDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(PrintSettingDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        printercombo = new QComboBox(PrintSettingDialog);
        printercombo->setObjectName(QString::fromUtf8("printercombo"));
        printercombo->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(printercombo, 0, 1, 1, 2);

        groupBox_BuildSpace = new QGroupBox(PrintSettingDialog);
        groupBox_BuildSpace->setObjectName(QString::fromUtf8("groupBox_BuildSpace"));
        groupBox_BuildSpace->setFlat(false);
        gridLayout_4 = new QGridLayout(groupBox_BuildSpace);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(groupBox_BuildSpace);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(140, 40));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_pixelsize = new QLineEdit(groupBox_BuildSpace);
        lineEdit_pixelsize->setObjectName(QString::fromUtf8("lineEdit_pixelsize"));
        lineEdit_pixelsize->setMinimumSize(QSize(0, 40));
        lineEdit_pixelsize->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_pixelsize, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_35 = new QLabel(groupBox_BuildSpace);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMinimumSize(QSize(140, 40));

        horizontalLayout->addWidget(label_35);

        label_6 = new QLabel(groupBox_BuildSpace);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(25, 0));

        horizontalLayout->addWidget(label_6);

        Print_Extents_X = new QLineEdit(groupBox_BuildSpace);
        Print_Extents_X->setObjectName(QString::fromUtf8("Print_Extents_X"));
        Print_Extents_X->setEnabled(true);
        Print_Extents_X->setMinimumSize(QSize(0, 40));
        Print_Extents_X->setReadOnly(true);

        horizontalLayout->addWidget(Print_Extents_X);

        label_33 = new QLabel(groupBox_BuildSpace);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setMinimumSize(QSize(25, 40));

        horizontalLayout->addWidget(label_33);

        Print_Extents_Y = new QLineEdit(groupBox_BuildSpace);
        Print_Extents_Y->setObjectName(QString::fromUtf8("Print_Extents_Y"));
        Print_Extents_Y->setEnabled(true);
        Print_Extents_Y->setMinimumSize(QSize(0, 40));
        Print_Extents_Y->setReadOnly(true);

        horizontalLayout->addWidget(Print_Extents_Y);


        gridLayout_4->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_36 = new QLabel(groupBox_BuildSpace);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setMinimumSize(QSize(140, 40));

        horizontalLayout_2->addWidget(label_36);

        Print_Extents_Z = new QLineEdit(groupBox_BuildSpace);
        Print_Extents_Z->setObjectName(QString::fromUtf8("Print_Extents_Z"));
        Print_Extents_Z->setEnabled(true);
        Print_Extents_Z->setMinimumSize(QSize(0, 40));
        Print_Extents_Z->setReadOnly(true);

        horizontalLayout_2->addWidget(Print_Extents_Z);


        gridLayout_4->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_BuildSpace, 1, 0, 1, 3);

        checkBoxAppears = new QCheckBox(PrintSettingDialog);
        checkBoxAppears->setObjectName(QString::fromUtf8("checkBoxAppears"));
        checkBoxAppears->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(checkBoxAppears, 2, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 3, 0, 1, 2);

        pushButtonOK = new QPushButton(PrintSettingDialog);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(pushButtonOK, 3, 2, 1, 1);


        retranslateUi(PrintSettingDialog);

        QMetaObject::connectSlotsByName(PrintSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *PrintSettingDialog)
    {
        PrintSettingDialog->setWindowTitle(QApplication::translate("PrintSettingDialog", "Select Printer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        PrintSettingDialog->setToolTip(QApplication::translate("PrintSettingDialog", "\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("PrintSettingDialog", "\346\234\272\345\236\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("PrintSettingDialog", "Printer:", 0, QApplication::UnicodeUTF8));
        printercombo->clear();
        printercombo->insertItems(0, QStringList()
         << QApplication::translate("PrintSettingDialog", "M50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PrintSettingDialog", "M100", 0, QApplication::UnicodeUTF8)
        );
        groupBox_BuildSpace->setTitle(QApplication::translate("PrintSettingDialog", "Build Space:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("PrintSettingDialog", "\345\203\217\347\264\240\347\262\276\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("PrintSettingDialog", "Pixel Size(\302\265m):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_35->setToolTip(QApplication::translate("PrintSettingDialog", "\346\211\223\345\215\260\351\235\242\347\247\257", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_35->setText(QApplication::translate("PrintSettingDialog", "Build Table Area(mm):", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PrintSettingDialog", "X:", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("PrintSettingDialog", "Y:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_36->setToolTip(QApplication::translate("PrintSettingDialog", "\346\211\223\345\215\260\346\234\200\345\244\247\351\253\230\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_36->setText(QApplication::translate("PrintSettingDialog", "Max Height(mm):", 0, QApplication::UnicodeUTF8));
        Print_Extents_Z->setText(QApplication::translate("PrintSettingDialog", "130", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBoxAppears->setToolTip(QApplication::translate("PrintSettingDialog", "\345\275\223\350\275\257\344\273\266\346\211\223\345\274\200\346\227\266\357\274\214\347\252\227\345\217\243\344\270\215\345\206\215\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBoxAppears->setText(QApplication::translate("PrintSettingDialog", "Did'n show it again.", 0, QApplication::UnicodeUTF8));
        pushButtonOK->setText(QApplication::translate("PrintSettingDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PrintSettingDialog: public Ui_PrintSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTSETTINGDIALOG_H
