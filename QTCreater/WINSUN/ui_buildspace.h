/********************************************************************************
** Form generated from reading UI file 'buildspace.ui'
**
** Created: Fri Aug 31 18:03:01 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUILDSPACE_H
#define UI_BUILDSPACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuildSpace
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QTableWidget *tableWidget;

    void setupUi(QWidget *BuildSpace)
    {
        if (BuildSpace->objectName().isEmpty())
            BuildSpace->setObjectName(QString::fromUtf8("BuildSpace"));
        BuildSpace->resize(625, 440);
        label = new QLabel(BuildSpace);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 71, 16));
        label_2 = new QLabel(BuildSpace);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 91, 16));
        label_3 = new QLabel(BuildSpace);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 90, 54, 12));
        comboBox = new QComboBox(BuildSpace);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(120, 30, 161, 22));
        comboBox_2 = new QComboBox(BuildSpace);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(120, 60, 161, 22));
        lineEdit = new QLineEdit(BuildSpace);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(120, 90, 161, 20));
        listWidget = new QListWidget(BuildSpace);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(40, 180, 256, 192));
        tableWidget = new QTableWidget(BuildSpace);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(320, 180, 256, 192));

        retranslateUi(BuildSpace);

        QMetaObject::connectSlotsByName(BuildSpace);
    } // setupUi

    void retranslateUi(QWidget *BuildSpace)
    {
        BuildSpace->setWindowTitle(QApplication::translate("BuildSpace", "\346\230\276\347\244\272\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BuildSpace", "\345\203\217\347\264\240\347\262\276\345\272\246(\316\274m)\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BuildSpace", "\346\212\225\345\275\261\344\273\252\345\210\206\350\276\250\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BuildSpace", "\345\214\272\345\237\237(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BuildSpace: public Ui_BuildSpace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUILDSPACE_H
