/********************************************************************************
** Form generated from reading UI file 'modellist.ui'
**
** Created: Fri Aug 31 18:03:01 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELLIST_H
#define UI_MODELLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelList
{
public:
    QWidget *widget;
    QPushButton *ApplyButton;
    QListWidget *ModelList_2;
    QLabel *label_8;
    QComboBox *thicknesscombo;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *modelsizex;
    QLineEdit *modelsizey;
    QLineEdit *modelsizez;
    QLabel *label_5;
    QLineEdit *posx;
    QLineEdit *posy;
    QLineEdit *posz;
    QLabel *label_6;
    QLineEdit *rotx;
    QLineEdit *roty;
    QLineEdit *rotz;
    QLabel *label_7;
    QLineEdit *scalex;
    QLineEdit *scaley;
    QLineEdit *scalez;
    QPushButton *RemoveButton;
    QPushButton *AddButton;
    QPushButton *duplicateButton;

    void setupUi(QWidget *ModelList)
    {
        if (ModelList->objectName().isEmpty())
            ModelList->setObjectName(QString::fromUtf8("ModelList"));
        ModelList->resize(1246, 816);
        ModelList->setMinimumSize(QSize(337, 0));
        ModelList->setMaximumSize(QSize(59999, 41500));
        ModelList->setStyleSheet(QString::fromUtf8("background-color: rgba(224, 252, 227);"));
        widget = new QWidget(ModelList);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 337, 351));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(400, 16777215));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 222, 222);"));
        ApplyButton = new QPushButton(widget);
        ApplyButton->setObjectName(QString::fromUtf8("ApplyButton"));
        ApplyButton->setGeometry(QRect(10, 310, 311, 23));
        ApplyButton->setStyleSheet(QString::fromUtf8(""));
        ApplyButton->setFlat(false);
        ModelList_2 = new QListWidget(widget);
        ModelList_2->setObjectName(QString::fromUtf8("ModelList_2"));
        ModelList_2->setGeometry(QRect(10, 33, 321, 121));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ModelList_2->sizePolicy().hasHeightForWidth());
        ModelList_2->setSizePolicy(sizePolicy1);
        ModelList_2->setMinimumSize(QSize(0, 0));
        ModelList_2->setMaximumSize(QSize(370, 16777215));
        ModelList_2->setStyleSheet(QString::fromUtf8(""));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 160, 101, 21));
        thicknesscombo = new QComboBox(widget);
        thicknesscombo->setObjectName(QString::fromUtf8("thicknesscombo"));
        thicknesscombo->setGeometry(QRect(100, 160, 221, 20));
        thicknesscombo->setMinimumSize(QSize(200, 0));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(87, 184, 70, 16));
        label_2->setMinimumSize(QSize(70, 0));
        label_2->setMaximumSize(QSize(70, 16777215));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 184, 70, 16));
        label_3->setMinimumSize(QSize(70, 0));
        label_3->setMaximumSize(QSize(70, 16777215));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(253, 184, 70, 16));
        label_4->setMinimumSize(QSize(70, 0));
        label_4->setMaximumSize(QSize(70, 16777215));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 202, 70, 16));
        label->setMinimumSize(QSize(70, 0));
        label->setMaximumSize(QSize(70, 16777215));
        modelsizex = new QLineEdit(widget);
        modelsizex->setObjectName(QString::fromUtf8("modelsizex"));
        modelsizex->setEnabled(true);
        modelsizex->setGeometry(QRect(87, 202, 70, 20));
        modelsizex->setMinimumSize(QSize(70, 20));
        modelsizex->setMaximumSize(QSize(70, 20));
        modelsizex->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        modelsizex->setReadOnly(true);
        modelsizey = new QLineEdit(widget);
        modelsizey->setObjectName(QString::fromUtf8("modelsizey"));
        modelsizey->setEnabled(true);
        modelsizey->setGeometry(QRect(170, 202, 70, 20));
        modelsizey->setMinimumSize(QSize(70, 20));
        modelsizey->setMaximumSize(QSize(70, 20));
        modelsizey->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        modelsizey->setReadOnly(true);
        modelsizez = new QLineEdit(widget);
        modelsizez->setObjectName(QString::fromUtf8("modelsizez"));
        modelsizez->setEnabled(true);
        modelsizez->setGeometry(QRect(253, 202, 70, 20));
        modelsizez->setMinimumSize(QSize(70, 20));
        modelsizez->setMaximumSize(QSize(70, 20));
        modelsizez->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        modelsizez->setReadOnly(true);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 230, 70, 16));
        label_5->setMinimumSize(QSize(70, 0));
        label_5->setMaximumSize(QSize(70, 39));
        posx = new QLineEdit(widget);
        posx->setObjectName(QString::fromUtf8("posx"));
        posx->setGeometry(QRect(87, 228, 70, 20));
        posx->setMinimumSize(QSize(70, 20));
        posx->setMaximumSize(QSize(70, 20));
        posx->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        posy = new QLineEdit(widget);
        posy->setObjectName(QString::fromUtf8("posy"));
        posy->setGeometry(QRect(170, 228, 70, 20));
        posy->setMinimumSize(QSize(70, 20));
        posy->setMaximumSize(QSize(70, 20));
        posy->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        posz = new QLineEdit(widget);
        posz->setObjectName(QString::fromUtf8("posz"));
        posz->setGeometry(QRect(253, 228, 70, 20));
        posz->setMinimumSize(QSize(70, 20));
        posz->setMaximumSize(QSize(70, 20));
        posz->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 258, 70, 16));
        label_6->setMinimumSize(QSize(70, 0));
        label_6->setMaximumSize(QSize(70, 16777215));
        rotx = new QLineEdit(widget);
        rotx->setObjectName(QString::fromUtf8("rotx"));
        rotx->setGeometry(QRect(87, 254, 70, 20));
        rotx->setMinimumSize(QSize(70, 0));
        rotx->setMaximumSize(QSize(70, 20));
        rotx->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        roty = new QLineEdit(widget);
        roty->setObjectName(QString::fromUtf8("roty"));
        roty->setGeometry(QRect(170, 254, 70, 20));
        roty->setMinimumSize(QSize(70, 0));
        roty->setMaximumSize(QSize(70, 20));
        roty->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        rotz = new QLineEdit(widget);
        rotz->setObjectName(QString::fromUtf8("rotz"));
        rotz->setGeometry(QRect(253, 254, 70, 20));
        rotz->setMinimumSize(QSize(70, 0));
        rotz->setMaximumSize(QSize(70, 20));
        rotz->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 286, 70, 16));
        label_7->setMinimumSize(QSize(70, 0));
        label_7->setMaximumSize(QSize(70, 16777215));
        scalex = new QLineEdit(widget);
        scalex->setObjectName(QString::fromUtf8("scalex"));
        scalex->setGeometry(QRect(87, 280, 70, 20));
        scalex->setMinimumSize(QSize(70, 0));
        scalex->setMaximumSize(QSize(70, 20));
        scalex->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        scaley = new QLineEdit(widget);
        scaley->setObjectName(QString::fromUtf8("scaley"));
        scaley->setGeometry(QRect(170, 280, 70, 20));
        scaley->setMinimumSize(QSize(70, 0));
        scaley->setMaximumSize(QSize(70, 16777215));
        scaley->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        scaley->setReadOnly(true);
        scalez = new QLineEdit(widget);
        scalez->setObjectName(QString::fromUtf8("scalez"));
        scalez->setGeometry(QRect(253, 280, 70, 20));
        scalez->setMinimumSize(QSize(70, 0));
        scalez->setMaximumSize(QSize(70, 20));
        scalez->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        scalez->setReadOnly(true);
        RemoveButton = new QPushButton(widget);
        RemoveButton->setObjectName(QString::fromUtf8("RemoveButton"));
        RemoveButton->setGeometry(QRect(220, 0, 71, 31));
        RemoveButton->setMaximumSize(QSize(83, 16777215));
        RemoveButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/B9Edit/icons/delete2.png"), QSize(), QIcon::Normal, QIcon::Off);
        RemoveButton->setIcon(icon);
        RemoveButton->setIconSize(QSize(20, 20));
        RemoveButton->setFlat(true);
        AddButton = new QPushButton(widget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(34, 0, 61, 31));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(AddButton->sizePolicy().hasHeightForWidth());
        AddButton->setSizePolicy(sizePolicy2);
        AddButton->setMaximumSize(QSize(83, 16777215));
        AddButton->setFocusPolicy(Qt::StrongFocus);
        AddButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/B9Edit/icons/new4.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/B9Edit/icons/delete3.jpg"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/B9Edit/icons/delete2.png"), QSize(), QIcon::Disabled, QIcon::Off);
        AddButton->setIcon(icon1);
        AddButton->setIconSize(QSize(20, 20));
        AddButton->setFlat(true);
        duplicateButton = new QPushButton(widget);
        duplicateButton->setObjectName(QString::fromUtf8("duplicateButton"));
        duplicateButton->setGeometry(QRect(107, 0, 91, 31));
        duplicateButton->setMaximumSize(QSize(100, 16777215));
        duplicateButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/B9Edit/icons/new3.png"), QSize(), QIcon::Normal, QIcon::Off);
        duplicateButton->setIcon(icon2);
        duplicateButton->setIconSize(QSize(20, 20));
        duplicateButton->setFlat(true);

        retranslateUi(ModelList);

        QMetaObject::connectSlotsByName(ModelList);
    } // setupUi

    void retranslateUi(QWidget *ModelList)
    {
        ModelList->setWindowTitle(QApplication::translate("ModelList", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        widget->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        ApplyButton->setToolTip(QApplication::translate("ModelList", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ApplyButton->setText(QApplication::translate("ModelList", "Apply", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("ModelList", "\345\210\207\347\211\207\345\216\232\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("ModelList", " Thickness(\316\274m)\357\274\232", 0, QApplication::UnicodeUTF8));
        thicknesscombo->clear();
        thicknesscombo->insertItems(0, QStringList()
         << QApplication::translate("ModelList", "200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModelList", "180", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModelList", "160", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModelList", "150", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModelList", "130", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModelList", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModelList", "80", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModelList", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModelList", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModelList", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModelList", "\345\210\207\347\211\207\344\270\255", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("ModelList", "     X", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ModelList", "     Y", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ModelList", "     Z", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("ModelList", "\345\260\272\345\257\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("ModelList", "Size(mm):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("ModelList", "\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("ModelList", "Position(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("ModelList", "\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("ModelList", "Rotation\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("ModelList", "\347\274\251\346\224\276", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("ModelList", "Scaling\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        RemoveButton->setToolTip(QApplication::translate("ModelList", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        RemoveButton->setText(QApplication::translate("ModelList", "Delete", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        AddButton->setToolTip(QApplication::translate("ModelList", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        AddButton->setStatusTip(QApplication::translate("ModelList", "789", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        AddButton->setWhatsThis(QApplication::translate("ModelList", "123", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        AddButton->setText(QApplication::translate("ModelList", "Add", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        duplicateButton->setToolTip(QApplication::translate("ModelList", "\345\244\215\345\210\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        duplicateButton->setText(QApplication::translate("ModelList", "Duplicate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ModelList: public Ui_ModelList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELLIST_H
