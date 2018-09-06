/********************************************************************************
** Form generated from reading UI file 'viewwidget.ui'
**
** Created: Fri Aug 31 18:03:02 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWWIDGET_H
#define UI_VIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_viewWidget
{
public:
    QPushButton *pushButtonTop;
    QPushButton *pushButtonBottom;
    QPushButton *pushButtonLeft;
    QPushButton *pushButtonRight;
    QPushButton *pushButtonFront;
    QPushButton *pushButtonBack;
    QSlider *verticalSlider;
    QScrollBar *horizontalScrollBar;

    void setupUi(QWidget *viewWidget)
    {
        if (viewWidget->objectName().isEmpty())
            viewWidget->setObjectName(QString::fromUtf8("viewWidget"));
        viewWidget->resize(633, 498);
        pushButtonTop = new QPushButton(viewWidget);
        pushButtonTop->setObjectName(QString::fromUtf8("pushButtonTop"));
        pushButtonTop->setGeometry(QRect(19, 10, 40, 40));
        pushButtonTop->setMinimumSize(QSize(40, 40));
        pushButtonTop->setMaximumSize(QSize(40, 40));
        pushButtonBottom = new QPushButton(viewWidget);
        pushButtonBottom->setObjectName(QString::fromUtf8("pushButtonBottom"));
        pushButtonBottom->setGeometry(QRect(75, 10, 40, 40));
        pushButtonBottom->setMinimumSize(QSize(40, 40));
        pushButtonBottom->setMaximumSize(QSize(40, 40));
        pushButtonLeft = new QPushButton(viewWidget);
        pushButtonLeft->setObjectName(QString::fromUtf8("pushButtonLeft"));
        pushButtonLeft->setGeometry(QRect(19, 57, 40, 40));
        pushButtonLeft->setMinimumSize(QSize(40, 40));
        pushButtonLeft->setMaximumSize(QSize(40, 40));
        pushButtonRight = new QPushButton(viewWidget);
        pushButtonRight->setObjectName(QString::fromUtf8("pushButtonRight"));
        pushButtonRight->setGeometry(QRect(75, 57, 40, 40));
        pushButtonRight->setMinimumSize(QSize(40, 40));
        pushButtonRight->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/B9Edit/icons/boxsupporticon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRight->setIcon(icon);
        pushButtonRight->setIconSize(QSize(40, 40));
        pushButtonRight->setFlat(true);
        pushButtonFront = new QPushButton(viewWidget);
        pushButtonFront->setObjectName(QString::fromUtf8("pushButtonFront"));
        pushButtonFront->setGeometry(QRect(19, 104, 40, 40));
        pushButtonFront->setMinimumSize(QSize(40, 40));
        pushButtonFront->setMaximumSize(QSize(40, 40));
        pushButtonBack = new QPushButton(viewWidget);
        pushButtonBack->setObjectName(QString::fromUtf8("pushButtonBack"));
        pushButtonBack->setGeometry(QRect(75, 104, 40, 40));
        pushButtonBack->setMinimumSize(QSize(40, 40));
        pushButtonBack->setMaximumSize(QSize(40, 40));
        verticalSlider = new QSlider(viewWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(310, 210, 19, 160));
        verticalSlider->setValue(50);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setInvertedAppearance(false);
        verticalSlider->setInvertedControls(false);
        verticalSlider->setTickInterval(0);
        horizontalScrollBar = new QScrollBar(viewWidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(30, 400, 160, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        retranslateUi(viewWidget);

        QMetaObject::connectSlotsByName(viewWidget);
    } // setupUi

    void retranslateUi(QWidget *viewWidget)
    {
        viewWidget->setWindowTitle(QApplication::translate("viewWidget", "Form", 0, QApplication::UnicodeUTF8));
        pushButtonTop->setText(QApplication::translate("viewWidget", "Top", 0, QApplication::UnicodeUTF8));
        pushButtonBottom->setText(QApplication::translate("viewWidget", "btm", 0, QApplication::UnicodeUTF8));
        pushButtonLeft->setText(QApplication::translate("viewWidget", "Left", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonRight->setToolTip(QApplication::translate("viewWidget", "Right", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonRight->setText(QString());
        pushButtonFront->setText(QApplication::translate("viewWidget", "Front", 0, QApplication::UnicodeUTF8));
        pushButtonBack->setText(QApplication::translate("viewWidget", "back", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class viewWidget: public Ui_viewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWWIDGET_H
