/********************************************************************************
** Form generated from reading UI file 'showslices.ui'
**
** Created: Fri Aug 31 18:03:01 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWSLICES_H
#define UI_SHOWSLICES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowSlices
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditThickness;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBoxCurNumOfLayers;
    QLabel *labelTotalLayers;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QSlider *curNumOfLayersSlider;

    void setupUi(QWidget *ShowSlices)
    {
        if (ShowSlices->objectName().isEmpty())
            ShowSlices->setObjectName(QString::fromUtf8("ShowSlices"));
        ShowSlices->resize(1056, 808);
        gridLayout = new QGridLayout(ShowSlices);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ShowSlices);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditThickness = new QLineEdit(ShowSlices);
        lineEditThickness->setObjectName(QString::fromUtf8("lineEditThickness"));
        lineEditThickness->setEnabled(false);
        lineEditThickness->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(lineEditThickness);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        spinBoxCurNumOfLayers = new QSpinBox(ShowSlices);
        spinBoxCurNumOfLayers->setObjectName(QString::fromUtf8("spinBoxCurNumOfLayers"));
        spinBoxCurNumOfLayers->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(spinBoxCurNumOfLayers);

        labelTotalLayers = new QLabel(ShowSlices);
        labelTotalLayers->setObjectName(QString::fromUtf8("labelTotalLayers"));
        labelTotalLayers->setMaximumSize(QSize(61, 21));
        QFont font;
        font.setPointSize(10);
        labelTotalLayers->setFont(font);

        horizontalLayout->addWidget(labelTotalLayers);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        scrollArea = new QScrollArea(ShowSlices);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1009, 758));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        curNumOfLayersSlider = new QSlider(ShowSlices);
        curNumOfLayersSlider->setObjectName(QString::fromUtf8("curNumOfLayersSlider"));
        curNumOfLayersSlider->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(curNumOfLayersSlider);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(ShowSlices);

        QMetaObject::connectSlotsByName(ShowSlices);
    } // setupUi

    void retranslateUi(QWidget *ShowSlices)
    {
        ShowSlices->setWindowTitle(QApplication::translate("ShowSlices", "Show Slices", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ShowSlices", "Thickness(\316\274m)\357\274\232", 0, QApplication::UnicodeUTF8));
        labelTotalLayers->setText(QApplication::translate("ShowSlices", "/145", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ShowSlices: public Ui_ShowSlices {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWSLICES_H
