/********************************************************************************
** Form generated from reading UI file 'supportsetting.ui'
**
** Created: Fri Aug 31 18:03:01 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPORTSETTING_H
#define UI_SUPPORTSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SupportSetting
{
public:
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QLabel *label_16;
    QComboBox *Support_Base_AttachType_comboBox;
    QLabel *label_14;
    QDoubleSpinBox *Support_Base_Radius_doubleSpinBox;
    QLabel *label_15;
    QDoubleSpinBox *Support_Base_Length_doubleSpinBox;
    QWidget *top_support;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QComboBox *Support_Top_AttachType_comboBox;
    QLabel *label_2;
    QDoubleSpinBox *Support_Top_Length_doubleSpinBox;
    QLabel *label_3;
    QDoubleSpinBox *Support_Top_Radius_doubleSpinBox;
    QLabel *label_4;
    QSlider *Support_Top_Penetration_horizontalSlider;
    QLabel *Support_Top_Penetration_label;
    QLabel *label_5;
    QSlider *Support_Top_AngleFactor_horizontalSlider;
    QLabel *Support_Top_AngleFactor_label;
    QWidget *mid_support;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QComboBox *Support_Mid_AttachType_comboBox;
    QLabel *label_7;
    QDoubleSpinBox *Support_Mid_Radius_doubleSpinBox;
    QWidget *bottom_support;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QComboBox *Support_Bottom_AttachType_comboBox;
    QLabel *label_9;
    QDoubleSpinBox *Support_Bottom_Length_doubleSpinBox;
    QLabel *label_11;
    QDoubleSpinBox *Support_Bottom_Radius_doubleSpinBox;
    QLabel *label_12;
    QSlider *Support_Bottom_Penetration_horizontalSlider;
    QLabel *Support_Bottom_Penetration_label;
    QLabel *label_13;
    QSlider *Support_Bottom_AngleFactor_horizontalSlider;
    QLabel *Support_Bottom_AngleFactor_label;
    QPushButton *pushButtonRestoreDefaults;
    QPushButton *pushButtonOK;

    void setupUi(QWidget *SupportSetting)
    {
        if (SupportSetting->objectName().isEmpty())
            SupportSetting->setObjectName(QString::fromUtf8("SupportSetting"));
        SupportSetting->resize(362, 275);
        gridLayout_5 = new QGridLayout(SupportSetting);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tabWidget = new QTabWidget(SupportSetting);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 0, 0, 1, 1);

        Support_Base_AttachType_comboBox = new QComboBox(tab);
        Support_Base_AttachType_comboBox->setObjectName(QString::fromUtf8("Support_Base_AttachType_comboBox"));
        Support_Base_AttachType_comboBox->setMinimumSize(QSize(218, 0));

        gridLayout->addWidget(Support_Base_AttachType_comboBox, 0, 1, 1, 1);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 1, 0, 1, 1);

        Support_Base_Radius_doubleSpinBox = new QDoubleSpinBox(tab);
        Support_Base_Radius_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Base_Radius_doubleSpinBox"));
        Support_Base_Radius_doubleSpinBox->setMaximum(18);
        Support_Base_Radius_doubleSpinBox->setSingleStep(0.18);

        gridLayout->addWidget(Support_Base_Radius_doubleSpinBox, 1, 1, 1, 1);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 2, 0, 1, 1);

        Support_Base_Length_doubleSpinBox = new QDoubleSpinBox(tab);
        Support_Base_Length_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Base_Length_doubleSpinBox"));
        Support_Base_Length_doubleSpinBox->setMaximum(5);

        gridLayout->addWidget(Support_Base_Length_doubleSpinBox, 2, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        top_support = new QWidget();
        top_support->setObjectName(QString::fromUtf8("top_support"));
        gridLayout_2 = new QGridLayout(top_support);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(top_support);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        Support_Top_AttachType_comboBox = new QComboBox(top_support);
        Support_Top_AttachType_comboBox->setObjectName(QString::fromUtf8("Support_Top_AttachType_comboBox"));

        gridLayout_2->addWidget(Support_Top_AttachType_comboBox, 0, 1, 1, 1);

        label_2 = new QLabel(top_support);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        Support_Top_Length_doubleSpinBox = new QDoubleSpinBox(top_support);
        Support_Top_Length_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Top_Length_doubleSpinBox"));
        Support_Top_Length_doubleSpinBox->setMaximum(10);

        gridLayout_2->addWidget(Support_Top_Length_doubleSpinBox, 1, 1, 1, 1);

        label_3 = new QLabel(top_support);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        Support_Top_Radius_doubleSpinBox = new QDoubleSpinBox(top_support);
        Support_Top_Radius_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Top_Radius_doubleSpinBox"));
        Support_Top_Radius_doubleSpinBox->setMaximum(10);

        gridLayout_2->addWidget(Support_Top_Radius_doubleSpinBox, 2, 1, 1, 1);

        label_4 = new QLabel(top_support);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        Support_Top_Penetration_horizontalSlider = new QSlider(top_support);
        Support_Top_Penetration_horizontalSlider->setObjectName(QString::fromUtf8("Support_Top_Penetration_horizontalSlider"));
        Support_Top_Penetration_horizontalSlider->setMaximum(100);
        Support_Top_Penetration_horizontalSlider->setSingleStep(0);
        Support_Top_Penetration_horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(Support_Top_Penetration_horizontalSlider, 3, 1, 1, 1);

        Support_Top_Penetration_label = new QLabel(top_support);
        Support_Top_Penetration_label->setObjectName(QString::fromUtf8("Support_Top_Penetration_label"));
        Support_Top_Penetration_label->setMinimumSize(QSize(30, 0));

        gridLayout_2->addWidget(Support_Top_Penetration_label, 3, 2, 1, 1);

        label_5 = new QLabel(top_support);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        Support_Top_AngleFactor_horizontalSlider = new QSlider(top_support);
        Support_Top_AngleFactor_horizontalSlider->setObjectName(QString::fromUtf8("Support_Top_AngleFactor_horizontalSlider"));
        Support_Top_AngleFactor_horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(Support_Top_AngleFactor_horizontalSlider, 4, 1, 1, 1);

        Support_Top_AngleFactor_label = new QLabel(top_support);
        Support_Top_AngleFactor_label->setObjectName(QString::fromUtf8("Support_Top_AngleFactor_label"));
        Support_Top_AngleFactor_label->setMinimumSize(QSize(30, 0));

        gridLayout_2->addWidget(Support_Top_AngleFactor_label, 4, 2, 1, 1);

        tabWidget->addTab(top_support, QString());
        mid_support = new QWidget();
        mid_support->setObjectName(QString::fromUtf8("mid_support"));
        gridLayout_3 = new QGridLayout(mid_support);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(mid_support);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        Support_Mid_AttachType_comboBox = new QComboBox(mid_support);
        Support_Mid_AttachType_comboBox->setObjectName(QString::fromUtf8("Support_Mid_AttachType_comboBox"));
        Support_Mid_AttachType_comboBox->setMinimumSize(QSize(218, 0));

        gridLayout_3->addWidget(Support_Mid_AttachType_comboBox, 0, 1, 1, 1);

        label_7 = new QLabel(mid_support);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        Support_Mid_Radius_doubleSpinBox = new QDoubleSpinBox(mid_support);
        Support_Mid_Radius_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Mid_Radius_doubleSpinBox"));
        Support_Mid_Radius_doubleSpinBox->setMaximum(5);

        gridLayout_3->addWidget(Support_Mid_Radius_doubleSpinBox, 1, 1, 1, 1);

        tabWidget->addTab(mid_support, QString());
        bottom_support = new QWidget();
        bottom_support->setObjectName(QString::fromUtf8("bottom_support"));
        gridLayout_4 = new QGridLayout(bottom_support);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_10 = new QLabel(bottom_support);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 0, 0, 1, 1);

        Support_Bottom_AttachType_comboBox = new QComboBox(bottom_support);
        Support_Bottom_AttachType_comboBox->setObjectName(QString::fromUtf8("Support_Bottom_AttachType_comboBox"));

        gridLayout_4->addWidget(Support_Bottom_AttachType_comboBox, 0, 1, 1, 1);

        label_9 = new QLabel(bottom_support);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 1, 0, 1, 1);

        Support_Bottom_Length_doubleSpinBox = new QDoubleSpinBox(bottom_support);
        Support_Bottom_Length_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Bottom_Length_doubleSpinBox"));
        Support_Bottom_Length_doubleSpinBox->setMaximum(5);

        gridLayout_4->addWidget(Support_Bottom_Length_doubleSpinBox, 1, 1, 1, 1);

        label_11 = new QLabel(bottom_support);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 2, 0, 1, 1);

        Support_Bottom_Radius_doubleSpinBox = new QDoubleSpinBox(bottom_support);
        Support_Bottom_Radius_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Bottom_Radius_doubleSpinBox"));
        Support_Bottom_Radius_doubleSpinBox->setMaximum(10);

        gridLayout_4->addWidget(Support_Bottom_Radius_doubleSpinBox, 2, 1, 1, 1);

        label_12 = new QLabel(bottom_support);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 3, 0, 1, 1);

        Support_Bottom_Penetration_horizontalSlider = new QSlider(bottom_support);
        Support_Bottom_Penetration_horizontalSlider->setObjectName(QString::fromUtf8("Support_Bottom_Penetration_horizontalSlider"));
        Support_Bottom_Penetration_horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(Support_Bottom_Penetration_horizontalSlider, 3, 1, 1, 1);

        Support_Bottom_Penetration_label = new QLabel(bottom_support);
        Support_Bottom_Penetration_label->setObjectName(QString::fromUtf8("Support_Bottom_Penetration_label"));
        Support_Bottom_Penetration_label->setMinimumSize(QSize(30, 0));

        gridLayout_4->addWidget(Support_Bottom_Penetration_label, 3, 2, 1, 1);

        label_13 = new QLabel(bottom_support);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 4, 0, 1, 1);

        Support_Bottom_AngleFactor_horizontalSlider = new QSlider(bottom_support);
        Support_Bottom_AngleFactor_horizontalSlider->setObjectName(QString::fromUtf8("Support_Bottom_AngleFactor_horizontalSlider"));
        Support_Bottom_AngleFactor_horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(Support_Bottom_AngleFactor_horizontalSlider, 4, 1, 1, 1);

        Support_Bottom_AngleFactor_label = new QLabel(bottom_support);
        Support_Bottom_AngleFactor_label->setObjectName(QString::fromUtf8("Support_Bottom_AngleFactor_label"));
        Support_Bottom_AngleFactor_label->setMinimumSize(QSize(30, 0));

        gridLayout_4->addWidget(Support_Bottom_AngleFactor_label, 4, 2, 1, 1);

        tabWidget->addTab(bottom_support, QString());

        gridLayout_5->addWidget(tabWidget, 0, 0, 1, 2);

        pushButtonRestoreDefaults = new QPushButton(SupportSetting);
        pushButtonRestoreDefaults->setObjectName(QString::fromUtf8("pushButtonRestoreDefaults"));

        gridLayout_5->addWidget(pushButtonRestoreDefaults, 1, 0, 1, 1);

        pushButtonOK = new QPushButton(SupportSetting);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));

        gridLayout_5->addWidget(pushButtonOK, 1, 1, 1, 1);


        retranslateUi(SupportSetting);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(SupportSetting);
    } // setupUi

    void retranslateUi(QWidget *SupportSetting)
    {
        SupportSetting->setWindowTitle(QApplication::translate("SupportSetting", "Form", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("SupportSetting", "\345\275\242\347\212\266:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("SupportSetting", "\345\215\212\345\276\204(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("SupportSetting", "\345\216\232\345\272\246(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SupportSetting", "Base", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SupportSetting", "\345\275\242\347\212\266\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SupportSetting", "\351\225\277\345\272\246(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SupportSetting", "\345\215\212\345\276\204(mm):", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SupportSetting", "\346\270\227\351\200\217\347\216\207:", 0, QApplication::UnicodeUTF8));
        Support_Top_Penetration_label->setText(QApplication::translate("SupportSetting", "0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SupportSetting", "\351\273\230\350\256\244\350\247\222\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        Support_Top_AngleFactor_label->setText(QApplication::translate("SupportSetting", "0", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(top_support), QApplication::translate("SupportSetting", "Top", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SupportSetting", "\345\275\242\347\212\266\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SupportSetting", "\345\215\212\345\276\204(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(mid_support), QApplication::translate("SupportSetting", "mid", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SupportSetting", "\345\275\242\347\212\266\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SupportSetting", "\351\225\277\345\272\246(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SupportSetting", "\345\215\212\345\276\204(mm):", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SupportSetting", "\346\270\227\351\200\217\347\216\207:", 0, QApplication::UnicodeUTF8));
        Support_Bottom_Penetration_label->setText(QApplication::translate("SupportSetting", "0", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("SupportSetting", "\351\273\230\350\256\244\350\247\222\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        Support_Bottom_AngleFactor_label->setText(QApplication::translate("SupportSetting", "0", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(bottom_support), QApplication::translate("SupportSetting", "bottom", 0, QApplication::UnicodeUTF8));
        pushButtonRestoreDefaults->setText(QApplication::translate("SupportSetting", "\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButtonOK->setText(QApplication::translate("SupportSetting", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SupportSetting: public Ui_SupportSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPORTSETTING_H
