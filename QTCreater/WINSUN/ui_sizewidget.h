/********************************************************************************
** Form generated from reading UI file 'sizewidget.ui'
**
** Created: Fri Aug 31 18:03:02 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIZEWIDGET_H
#define UI_SIZEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sizeWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *modelsizex;
    QLabel *label_3;
    QLineEdit *modelsizey;
    QLabel *label_4;
    QLineEdit *modelsizez;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_scale;
    QPushButton *pushButtonDrop_To_Floor;

    void setupUi(QWidget *sizeWidget)
    {
        if (sizeWidget->objectName().isEmpty())
            sizeWidget->setObjectName(QString::fromUtf8("sizeWidget"));
        sizeWidget->resize(207, 240);
        sizeWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 255);"));
        gridLayout = new QGridLayout(sizeWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(sizeWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(70, 30));
        label->setMaximumSize(QSize(70, 30));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(sizeWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 30));
        label_2->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        modelsizex = new QLineEdit(sizeWidget);
        modelsizex->setObjectName(QString::fromUtf8("modelsizex"));
        modelsizex->setEnabled(true);
        modelsizex->setMinimumSize(QSize(70, 30));
        modelsizex->setMaximumSize(QSize(100, 30));
        modelsizex->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        modelsizex->setReadOnly(true);

        gridLayout->addWidget(modelsizex, 1, 1, 1, 1);

        label_3 = new QLabel(sizeWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 30));
        label_3->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        modelsizey = new QLineEdit(sizeWidget);
        modelsizey->setObjectName(QString::fromUtf8("modelsizey"));
        modelsizey->setEnabled(true);
        modelsizey->setMinimumSize(QSize(70, 30));
        modelsizey->setMaximumSize(QSize(100, 30));
        modelsizey->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        modelsizey->setReadOnly(true);

        gridLayout->addWidget(modelsizey, 2, 1, 1, 1);

        label_4 = new QLabel(sizeWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 30));
        label_4->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        modelsizez = new QLineEdit(sizeWidget);
        modelsizez->setObjectName(QString::fromUtf8("modelsizez"));
        modelsizez->setEnabled(true);
        modelsizez->setMinimumSize(QSize(70, 30));
        modelsizez->setMaximumSize(QSize(100, 30));
        modelsizez->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        modelsizez->setReadOnly(true);

        gridLayout->addWidget(modelsizez, 3, 1, 1, 1);

        label_7 = new QLabel(sizeWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 30));
        label_7->setMaximumSize(QSize(45, 30));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        doubleSpinBox_scale = new QDoubleSpinBox(sizeWidget);
        doubleSpinBox_scale->setObjectName(QString::fromUtf8("doubleSpinBox_scale"));
        doubleSpinBox_scale->setMinimumSize(QSize(68, 30));
        doubleSpinBox_scale->setMaximumSize(QSize(100, 30));
        doubleSpinBox_scale->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        doubleSpinBox_scale->setDecimals(4);
        doubleSpinBox_scale->setSingleStep(0.2);

        gridLayout->addWidget(doubleSpinBox_scale, 4, 1, 1, 1);

        pushButtonDrop_To_Floor = new QPushButton(sizeWidget);
        pushButtonDrop_To_Floor->setObjectName(QString::fromUtf8("pushButtonDrop_To_Floor"));
        pushButtonDrop_To_Floor->setMinimumSize(QSize(0, 30));
        pushButtonDrop_To_Floor->setMaximumSize(QSize(16777215, 30));
        pushButtonDrop_To_Floor->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));

        gridLayout->addWidget(pushButtonDrop_To_Floor, 5, 0, 1, 2);


        retranslateUi(sizeWidget);

        QMetaObject::connectSlotsByName(sizeWidget);
    } // setupUi

    void retranslateUi(QWidget *sizeWidget)
    {
        sizeWidget->setWindowTitle(QApplication::translate("sizeWidget", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sizeWidget->setToolTip(QApplication::translate("sizeWidget", "\347\274\251\346\224\276", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("sizeWidget", "\345\260\272\345\257\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("sizeWidget", "Size(mm):", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("sizeWidget", " X(mm)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("sizeWidget", " Y(mm)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("sizeWidget", " Z(mm)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("sizeWidget", "\347\274\251\346\224\276", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("sizeWidget", "Scale\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        doubleSpinBox_scale->setToolTip(QApplication::translate("sizeWidget", "\346\257\224\344\276\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButtonDrop_To_Floor->setToolTip(QApplication::translate("sizeWidget", "\350\220\275\345\272\225", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonDrop_To_Floor->setText(QApplication::translate("sizeWidget", "Drop to Floor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sizeWidget: public Ui_sizeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIZEWIDGET_H
