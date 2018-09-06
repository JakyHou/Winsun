/********************************************************************************
** Form generated from reading UI file 'positionwidget.ui'
**
** Created: Fri Aug 31 18:03:02 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITIONWIDGET_H
#define UI_POSITIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PositionWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *posx;
    QLabel *label_3;
    QLineEdit *posy;
    QLineEdit *posz;
    QLabel *label_4;

    void setupUi(QWidget *PositionWidget)
    {
        if (PositionWidget->objectName().isEmpty())
            PositionWidget->setObjectName(QString::fromUtf8("PositionWidget"));
        PositionWidget->resize(190, 160);
        PositionWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(PositionWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(PositionWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(70, 30));
        label->setMaximumSize(QSize(10000, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_2 = new QLabel(PositionWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 30));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        posx = new QLineEdit(PositionWidget);
        posx->setObjectName(QString::fromUtf8("posx"));
        posx->setEnabled(true);
        posx->setMinimumSize(QSize(0, 30));
        posx->setMaximumSize(QSize(100, 20));
        posx->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        posx->setReadOnly(false);

        gridLayout->addWidget(posx, 1, 1, 1, 1);

        label_3 = new QLabel(PositionWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(60, 30));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        posy = new QLineEdit(PositionWidget);
        posy->setObjectName(QString::fromUtf8("posy"));
        posy->setEnabled(true);
        posy->setMinimumSize(QSize(0, 30));
        posy->setMaximumSize(QSize(100, 20));
        posy->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        posy->setReadOnly(false);

        gridLayout->addWidget(posy, 2, 1, 1, 1);

        posz = new QLineEdit(PositionWidget);
        posz->setObjectName(QString::fromUtf8("posz"));
        posz->setEnabled(true);
        posz->setMinimumSize(QSize(0, 30));
        posz->setMaximumSize(QSize(100, 20));
        posz->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        posz->setReadOnly(false);

        gridLayout->addWidget(posz, 3, 1, 1, 1);

        label_4 = new QLabel(PositionWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(60, 30));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);


        retranslateUi(PositionWidget);

        QMetaObject::connectSlotsByName(PositionWidget);
    } // setupUi

    void retranslateUi(QWidget *PositionWidget)
    {
        PositionWidget->setWindowTitle(QApplication::translate("PositionWidget", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        PositionWidget->setToolTip(QApplication::translate("PositionWidget", "\345\271\263\347\247\273", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("PositionWidget", "\345\260\272\345\257\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("PositionWidget", "Position(mm):", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PositionWidget", " X(mm)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PositionWidget", " Y(mm)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PositionWidget", " Z(mm)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PositionWidget: public Ui_PositionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITIONWIDGET_H
