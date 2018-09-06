/********************************************************************************
** Form generated from reading UI file 'orientationwidget.ui'
**
** Created: Fri Aug 31 18:03:02 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORIENTATIONWIDGET_H
#define UI_ORIENTATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrientationWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *rotx;
    QLabel *label_3;
    QLineEdit *roty;
    QLabel *label_4;
    QLineEdit *rotz;
    QPushButton *pushButtonDrop_To_Floor;

    void setupUi(QWidget *OrientationWidget)
    {
        if (OrientationWidget->objectName().isEmpty())
            OrientationWidget->setObjectName(QString::fromUtf8("OrientationWidget"));
        OrientationWidget->resize(190, 202);
        OrientationWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(OrientationWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(OrientationWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(30, 30));
        label->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_2 = new QLabel(OrientationWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 30));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        rotx = new QLineEdit(OrientationWidget);
        rotx->setObjectName(QString::fromUtf8("rotx"));
        rotx->setEnabled(true);
        rotx->setMinimumSize(QSize(70, 30));
        rotx->setMaximumSize(QSize(100, 20));
        rotx->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        rotx->setReadOnly(false);

        gridLayout->addWidget(rotx, 1, 1, 1, 1);

        label_3 = new QLabel(OrientationWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(50, 30));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        roty = new QLineEdit(OrientationWidget);
        roty->setObjectName(QString::fromUtf8("roty"));
        roty->setEnabled(true);
        roty->setMinimumSize(QSize(70, 30));
        roty->setMaximumSize(QSize(100, 20));
        roty->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        roty->setReadOnly(false);

        gridLayout->addWidget(roty, 2, 1, 1, 1);

        label_4 = new QLabel(OrientationWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(50, 30));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        rotz = new QLineEdit(OrientationWidget);
        rotz->setObjectName(QString::fromUtf8("rotz"));
        rotz->setEnabled(true);
        rotz->setMinimumSize(QSize(70, 30));
        rotz->setMaximumSize(QSize(100, 20));
        rotz->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        rotz->setReadOnly(false);

        gridLayout->addWidget(rotz, 3, 1, 1, 1);

        pushButtonDrop_To_Floor = new QPushButton(OrientationWidget);
        pushButtonDrop_To_Floor->setObjectName(QString::fromUtf8("pushButtonDrop_To_Floor"));
        pushButtonDrop_To_Floor->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(pushButtonDrop_To_Floor, 4, 0, 1, 2);


        retranslateUi(OrientationWidget);

        QMetaObject::connectSlotsByName(OrientationWidget);
    } // setupUi

    void retranslateUi(QWidget *OrientationWidget)
    {
        OrientationWidget->setWindowTitle(QApplication::translate("OrientationWidget", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        OrientationWidget->setToolTip(QApplication::translate("OrientationWidget", "\346\227\213\350\275\254", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("OrientationWidget", "\345\260\272\345\257\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("OrientationWidget", "Orientation(mm):", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OrientationWidget", " X( \302\260)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("OrientationWidget", " Y( \302\260)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("OrientationWidget", " Z( \302\260)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonDrop_To_Floor->setToolTip(QApplication::translate("OrientationWidget", "\350\220\275\345\272\225", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonDrop_To_Floor->setStyleSheet(QApplication::translate("OrientationWidget", "background-color: rgb(248, 248,248);", 0, QApplication::UnicodeUTF8));
        pushButtonDrop_To_Floor->setText(QApplication::translate("OrientationWidget", "Drop to Floor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OrientationWidget: public Ui_OrientationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORIENTATIONWIDGET_H
