/********************************************************************************
** Form generated from reading UI file 'statuswidget.ui'
**
** Created: Fri Aug 31 18:03:02 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSWIDGET_H
#define UI_STATUSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statusWidget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *printercombo;
    QLabel *label_8;
    QComboBox *thicknesscombo;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonPrint;
    QComboBox *comboBox;
    QLabel *label_3;

    void setupUi(QWidget *statusWidget)
    {
        if (statusWidget->objectName().isEmpty())
            statusWidget->setObjectName(QString::fromUtf8("statusWidget"));
        statusWidget->setEnabled(true);
        statusWidget->resize(726, 300);
        QFont font;
        font.setPointSize(9);
        statusWidget->setFont(font);
        statusWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 247 ,250);"));
        layoutWidget = new QWidget(statusWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 461, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        printercombo = new QComboBox(layoutWidget);
        printercombo->setObjectName(QString::fromUtf8("printercombo"));
        printercombo->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(printercombo);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        thicknesscombo = new QComboBox(layoutWidget);
        thicknesscombo->setObjectName(QString::fromUtf8("thicknesscombo"));
        thicknesscombo->setEnabled(true);
        thicknesscombo->setMinimumSize(QSize(50, 0));

        horizontalLayout->addWidget(thicknesscombo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonPrint = new QPushButton(layoutWidget);
        pushButtonPrint->setObjectName(QString::fromUtf8("pushButtonPrint"));
        pushButtonPrint->setStyleSheet(QString::fromUtf8("background-color: rgb(70, 130, 180);"));

        horizontalLayout->addWidget(pushButtonPrint);

        comboBox = new QComboBox(statusWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(510, 230, 134, 20));
        label_3 = new QLabel(statusWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(450, 230, 54, 20));

        retranslateUi(statusWidget);

        thicknesscombo->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(statusWidget);
    } // setupUi

    void retranslateUi(QWidget *statusWidget)
    {
        statusWidget->setWindowTitle(QApplication::translate("statusWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("statusWidget", " Printer:", 0, QApplication::UnicodeUTF8));
        printercombo->clear();
        printercombo->insertItems(0, QStringList()
         << QApplication::translate("statusWidget", "M50  \357\274\210 64x40\357\274\211", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statusWidget", "M100\357\274\210128x80\357\274\211", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("statusWidget", "\345\210\207\347\211\207\345\216\232\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("statusWidget", " Thickness(\316\274m)\357\274\232", 0, QApplication::UnicodeUTF8));
        thicknesscombo->clear();
        thicknesscombo->insertItems(0, QStringList()
         << QApplication::translate("statusWidget", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statusWidget", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statusWidget", "20", 0, QApplication::UnicodeUTF8)
        );
        pushButtonPrint->setText(QApplication::translate("statusWidget", "Print", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("statusWidget", "Transparent Yellow", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statusWidget", "Transparent Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statusWidget", "Transparent Blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statusWidget", "Transparent Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("statusWidget", "Opaque Grey", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("statusWidget", "Material:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class statusWidget: public Ui_statusWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSWIDGET_H
