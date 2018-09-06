/********************************************************************************
** Form generated from reading UI file 'sliceslider.ui'
**
** Created: Fri Aug 31 18:03:02 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLICESLIDER_H
#define UI_SLICESLIDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SliceSlider
{
public:
    QGridLayout *gridLayout;
    QLabel *labelTotalLayers;
    QSlider *curNumOfLayersSlider;
    QLineEdit *lineEditCurNumOfLayers;

    void setupUi(QWidget *SliceSlider)
    {
        if (SliceSlider->objectName().isEmpty())
            SliceSlider->setObjectName(QString::fromUtf8("SliceSlider"));
        SliceSlider->resize(49, 312);
        SliceSlider->setMaximumSize(QSize(50, 16777215));
        gridLayout = new QGridLayout(SliceSlider);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelTotalLayers = new QLabel(SliceSlider);
        labelTotalLayers->setObjectName(QString::fromUtf8("labelTotalLayers"));
        labelTotalLayers->setMaximumSize(QSize(61, 21));
        QFont font;
        font.setPointSize(10);
        labelTotalLayers->setFont(font);

        gridLayout->addWidget(labelTotalLayers, 0, 0, 1, 1);

        curNumOfLayersSlider = new QSlider(SliceSlider);
        curNumOfLayersSlider->setObjectName(QString::fromUtf8("curNumOfLayersSlider"));
        curNumOfLayersSlider->setMaximum(145);
        curNumOfLayersSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(curNumOfLayersSlider, 1, 0, 1, 1);

        lineEditCurNumOfLayers = new QLineEdit(SliceSlider);
        lineEditCurNumOfLayers->setObjectName(QString::fromUtf8("lineEditCurNumOfLayers"));
        lineEditCurNumOfLayers->setMinimumSize(QSize(38, 0));

        gridLayout->addWidget(lineEditCurNumOfLayers, 2, 0, 1, 1);


        retranslateUi(SliceSlider);

        QMetaObject::connectSlotsByName(SliceSlider);
    } // setupUi

    void retranslateUi(QWidget *SliceSlider)
    {
        SliceSlider->setWindowTitle(QApplication::translate("SliceSlider", "Form", 0, QApplication::UnicodeUTF8));
        labelTotalLayers->setText(QApplication::translate("SliceSlider", "145", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SliceSlider: public Ui_SliceSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLICESLIDER_H
