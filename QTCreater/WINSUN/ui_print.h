/********************************************************************************
** Form generated from reading UI file 'print.ui'
**
** Created: Fri Aug 31 18:03:01 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINT_H
#define UI_PRINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Print
{
public:
    QLCDNumber *lcdNumberTimeRemaining;
    QLCDNumber *lcdNumberTime;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditLayerCount;
    QProgressBar *progressBarPrintProgress;
    QLabel *label;
    QLineEdit *lineEditLayerTimeRemaining;
    QLabel *label_2;
    QLineEdit *lineEditLayerTimeCompletion;
    QPushButton *pushButtonAbort;
    QPushButton *pushButtonPauseResume;

    void setupUi(QWidget *Print)
    {
        if (Print->objectName().isEmpty())
            Print->setObjectName(QString::fromUtf8("Print"));
        Print->resize(300, 340);
        Print->setMaximumSize(QSize(3220, 3010));
        lcdNumberTimeRemaining = new QLCDNumber(Print);
        lcdNumberTimeRemaining->setObjectName(QString::fromUtf8("lcdNumberTimeRemaining"));
        lcdNumberTimeRemaining->setGeometry(QRect(450, 410, 181, 51));
        lcdNumberTimeRemaining->setMinimumSize(QSize(0, 51));
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
        QBrush brush5(QColor(85, 85, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        QBrush brush6(QColor(51, 153, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush6);
        lcdNumberTimeRemaining->setPalette(palette);
        lcdNumberTimeRemaining->setAutoFillBackground(true);
        lcdNumberTime = new QLCDNumber(Print);
        lcdNumberTime->setObjectName(QString::fromUtf8("lcdNumberTime"));
        lcdNumberTime->setGeometry(QRect(450, 490, 181, 51));
        lcdNumberTime->setMinimumSize(QSize(0, 51));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush6);
        lcdNumberTime->setPalette(palette1);
        lcdNumberTime->setAutoFillBackground(true);
        layoutWidget = new QWidget(Print);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 281, 331));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEditLayerCount = new QLineEdit(layoutWidget);
        lineEditLayerCount->setObjectName(QString::fromUtf8("lineEditLayerCount"));
        lineEditLayerCount->setEnabled(true);
        lineEditLayerCount->setMinimumSize(QSize(0, 40));
        lineEditLayerCount->setReadOnly(true);

        gridLayout->addWidget(lineEditLayerCount, 0, 0, 1, 3);

        progressBarPrintProgress = new QProgressBar(layoutWidget);
        progressBarPrintProgress->setObjectName(QString::fromUtf8("progressBarPrintProgress"));
        progressBarPrintProgress->setMinimumSize(QSize(0, 40));
        progressBarPrintProgress->setValue(5);

        gridLayout->addWidget(progressBarPrintProgress, 1, 0, 1, 3);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lineEditLayerTimeRemaining = new QLineEdit(layoutWidget);
        lineEditLayerTimeRemaining->setObjectName(QString::fromUtf8("lineEditLayerTimeRemaining"));
        lineEditLayerTimeRemaining->setEnabled(true);
        lineEditLayerTimeRemaining->setMinimumSize(QSize(0, 40));
        lineEditLayerTimeRemaining->setReadOnly(true);

        gridLayout->addWidget(lineEditLayerTimeRemaining, 2, 1, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        lineEditLayerTimeCompletion = new QLineEdit(layoutWidget);
        lineEditLayerTimeCompletion->setObjectName(QString::fromUtf8("lineEditLayerTimeCompletion"));
        lineEditLayerTimeCompletion->setEnabled(true);
        lineEditLayerTimeCompletion->setMinimumSize(QSize(0, 40));
        lineEditLayerTimeCompletion->setReadOnly(true);

        gridLayout->addWidget(lineEditLayerTimeCompletion, 3, 1, 1, 2);

        pushButtonAbort = new QPushButton(layoutWidget);
        pushButtonAbort->setObjectName(QString::fromUtf8("pushButtonAbort"));
        pushButtonAbort->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pushButtonAbort, 4, 2, 1, 1);

        pushButtonPauseResume = new QPushButton(layoutWidget);
        pushButtonPauseResume->setObjectName(QString::fromUtf8("pushButtonPauseResume"));
        pushButtonPauseResume->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pushButtonPauseResume, 4, 1, 1, 1);


        retranslateUi(Print);

        QMetaObject::connectSlotsByName(Print);
    } // setupUi

    void retranslateUi(QWidget *Print)
    {
        Print->setWindowTitle(QApplication::translate("Print", "Printing", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEditLayerCount->setToolTip(QApplication::translate("Print", "\345\275\223\345\211\215\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        progressBarPrintProgress->setToolTip(QApplication::translate("Print", "\350\277\233\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("Print", "\345\211\251\344\275\231\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Print", "Remaining Time\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEditLayerTimeRemaining->setToolTip(QApplication::translate("Print", "\345\275\223\345\211\215\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("Print", "\345\256\214\346\210\220\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("Print", "Completion Time\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEditLayerTimeCompletion->setToolTip(QApplication::translate("Print", "\345\275\223\345\211\215\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButtonAbort->setToolTip(QApplication::translate("Print", "\347\273\210\346\255\242", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonAbort->setText(QApplication::translate("Print", "Abort", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonPauseResume->setToolTip(QApplication::translate("Print", "\346\232\202\345\201\234", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonPauseResume->setText(QApplication::translate("Print", "Pause", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Print: public Ui_Print {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINT_H
