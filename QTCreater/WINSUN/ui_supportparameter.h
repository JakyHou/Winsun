/********************************************************************************
** Form generated from reading UI file 'supportparameter.ui'
**
** Created: Fri Aug 31 18:03:02 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPORTPARAMETER_H
#define UI_SUPPORTPARAMETER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SupportParameter
{
public:
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
    QPushButton *pushButtonSave;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_5;
    QCheckBox *checkBoxBase;
    QSlider *Support_Base_Coverage_horizontalSlider;
    QRadioButton *radioButtonAdd;
    QRadioButton *radioButtonDelete;
    QPushButton *pushButtonCleanAll;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBoxDensity;
    QPushButton *pushButtonAutoSupport;
    QToolButton *toolButtonAdvanced;

    void setupUi(QWidget *SupportParameter)
    {
        if (SupportParameter->objectName().isEmpty())
            SupportParameter->setObjectName(QString::fromUtf8("SupportParameter"));
        SupportParameter->resize(345, 516);
        SupportParameter->setMinimumSize(QSize(337, 516));
        SupportParameter->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tabWidget = new QTabWidget(SupportParameter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(9, 200, 321, 261));
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(70, 40));
        label_16->setMaximumSize(QSize(800, 16777215));

        gridLayout->addWidget(label_16, 0, 0, 1, 1);

        Support_Base_AttachType_comboBox = new QComboBox(tab);
        Support_Base_AttachType_comboBox->setObjectName(QString::fromUtf8("Support_Base_AttachType_comboBox"));
        Support_Base_AttachType_comboBox->setMinimumSize(QSize(0, 40));
        Support_Base_AttachType_comboBox->setMaximumSize(QSize(1400, 16777215));
        Support_Base_AttachType_comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));

        gridLayout->addWidget(Support_Base_AttachType_comboBox, 0, 1, 1, 1);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(70, 40));
        label_14->setMaximumSize(QSize(800, 16777215));

        gridLayout->addWidget(label_14, 1, 0, 1, 1);

        Support_Base_Radius_doubleSpinBox = new QDoubleSpinBox(tab);
        Support_Base_Radius_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Base_Radius_doubleSpinBox"));
        Support_Base_Radius_doubleSpinBox->setMinimumSize(QSize(0, 40));
        Support_Base_Radius_doubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        Support_Base_Radius_doubleSpinBox->setMaximum(30);
        Support_Base_Radius_doubleSpinBox->setSingleStep(0.18);

        gridLayout->addWidget(Support_Base_Radius_doubleSpinBox, 1, 1, 1, 1);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(70, 40));
        label_15->setMaximumSize(QSize(800, 16777215));

        gridLayout->addWidget(label_15, 2, 0, 1, 1);

        Support_Base_Length_doubleSpinBox = new QDoubleSpinBox(tab);
        Support_Base_Length_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Base_Length_doubleSpinBox"));
        Support_Base_Length_doubleSpinBox->setMinimumSize(QSize(0, 40));
        Support_Base_Length_doubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        Support_Base_Length_doubleSpinBox->setMaximum(5);

        gridLayout->addWidget(Support_Base_Length_doubleSpinBox, 2, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        top_support = new QWidget();
        top_support->setObjectName(QString::fromUtf8("top_support"));
        gridLayout_2 = new QGridLayout(top_support);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(top_support);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(90, 40));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        Support_Top_AttachType_comboBox = new QComboBox(top_support);
        Support_Top_AttachType_comboBox->setObjectName(QString::fromUtf8("Support_Top_AttachType_comboBox"));
        Support_Top_AttachType_comboBox->setMinimumSize(QSize(120, 40));
        Support_Top_AttachType_comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));

        gridLayout_2->addWidget(Support_Top_AttachType_comboBox, 0, 1, 1, 1);

        label_2 = new QLabel(top_support);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(90, 40));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        Support_Top_Length_doubleSpinBox = new QDoubleSpinBox(top_support);
        Support_Top_Length_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Top_Length_doubleSpinBox"));
        Support_Top_Length_doubleSpinBox->setMinimumSize(QSize(120, 40));
        Support_Top_Length_doubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        Support_Top_Length_doubleSpinBox->setMaximum(10);

        gridLayout_2->addWidget(Support_Top_Length_doubleSpinBox, 1, 1, 1, 1);

        label_3 = new QLabel(top_support);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(90, 40));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        Support_Top_Radius_doubleSpinBox = new QDoubleSpinBox(top_support);
        Support_Top_Radius_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Top_Radius_doubleSpinBox"));
        Support_Top_Radius_doubleSpinBox->setMinimumSize(QSize(120, 40));
        Support_Top_Radius_doubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        Support_Top_Radius_doubleSpinBox->setMaximum(10);

        gridLayout_2->addWidget(Support_Top_Radius_doubleSpinBox, 2, 1, 1, 1);

        label_4 = new QLabel(top_support);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(90, 40));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        Support_Top_Penetration_horizontalSlider = new QSlider(top_support);
        Support_Top_Penetration_horizontalSlider->setObjectName(QString::fromUtf8("Support_Top_Penetration_horizontalSlider"));
        Support_Top_Penetration_horizontalSlider->setMinimumSize(QSize(115, 40));
        Support_Top_Penetration_horizontalSlider->setMaximumSize(QSize(1200, 16777215));
        Support_Top_Penetration_horizontalSlider->setMaximum(100);
        Support_Top_Penetration_horizontalSlider->setSingleStep(0);
        Support_Top_Penetration_horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(Support_Top_Penetration_horizontalSlider, 3, 1, 1, 1);

        Support_Top_Penetration_label = new QLabel(top_support);
        Support_Top_Penetration_label->setObjectName(QString::fromUtf8("Support_Top_Penetration_label"));
        Support_Top_Penetration_label->setMinimumSize(QSize(30, 40));

        gridLayout_2->addWidget(Support_Top_Penetration_label, 3, 2, 1, 1);

        label_5 = new QLabel(top_support);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(90, 40));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        Support_Top_AngleFactor_horizontalSlider = new QSlider(top_support);
        Support_Top_AngleFactor_horizontalSlider->setObjectName(QString::fromUtf8("Support_Top_AngleFactor_horizontalSlider"));
        Support_Top_AngleFactor_horizontalSlider->setMinimumSize(QSize(115, 40));
        Support_Top_AngleFactor_horizontalSlider->setMaximumSize(QSize(1200, 16777215));
        Support_Top_AngleFactor_horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(Support_Top_AngleFactor_horizontalSlider, 4, 1, 1, 1);

        Support_Top_AngleFactor_label = new QLabel(top_support);
        Support_Top_AngleFactor_label->setObjectName(QString::fromUtf8("Support_Top_AngleFactor_label"));
        Support_Top_AngleFactor_label->setMinimumSize(QSize(30, 40));

        gridLayout_2->addWidget(Support_Top_AngleFactor_label, 4, 2, 1, 1);

        tabWidget->addTab(top_support, QString());
        mid_support = new QWidget();
        mid_support->setObjectName(QString::fromUtf8("mid_support"));
        gridLayout_3 = new QGridLayout(mid_support);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(mid_support);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(90, 40));
        label_6->setMaximumSize(QSize(1000, 16777215));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        Support_Mid_AttachType_comboBox = new QComboBox(mid_support);
        Support_Mid_AttachType_comboBox->setObjectName(QString::fromUtf8("Support_Mid_AttachType_comboBox"));
        Support_Mid_AttachType_comboBox->setMinimumSize(QSize(0, 40));
        Support_Mid_AttachType_comboBox->setMaximumSize(QSize(1200, 16777215));
        Support_Mid_AttachType_comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));

        gridLayout_3->addWidget(Support_Mid_AttachType_comboBox, 0, 1, 1, 1);

        label_7 = new QLabel(mid_support);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(90, 40));
        label_7->setMaximumSize(QSize(1000, 16777215));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        Support_Mid_Radius_doubleSpinBox = new QDoubleSpinBox(mid_support);
        Support_Mid_Radius_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Mid_Radius_doubleSpinBox"));
        Support_Mid_Radius_doubleSpinBox->setMinimumSize(QSize(0, 40));
        Support_Mid_Radius_doubleSpinBox->setMaximumSize(QSize(1200, 16777215));
        Support_Mid_Radius_doubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        Support_Mid_Radius_doubleSpinBox->setMaximum(5);

        gridLayout_3->addWidget(Support_Mid_Radius_doubleSpinBox, 1, 1, 1, 1);

        tabWidget->addTab(mid_support, QString());
        bottom_support = new QWidget();
        bottom_support->setObjectName(QString::fromUtf8("bottom_support"));
        gridLayout_4 = new QGridLayout(bottom_support);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_10 = new QLabel(bottom_support);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(90, 40));

        gridLayout_4->addWidget(label_10, 0, 0, 1, 1);

        Support_Bottom_AttachType_comboBox = new QComboBox(bottom_support);
        Support_Bottom_AttachType_comboBox->setObjectName(QString::fromUtf8("Support_Bottom_AttachType_comboBox"));
        Support_Bottom_AttachType_comboBox->setMinimumSize(QSize(120, 40));
        Support_Bottom_AttachType_comboBox->setMaximumSize(QSize(1200, 16777215));
        Support_Bottom_AttachType_comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));

        gridLayout_4->addWidget(Support_Bottom_AttachType_comboBox, 0, 1, 1, 1);

        label_9 = new QLabel(bottom_support);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(90, 40));

        gridLayout_4->addWidget(label_9, 1, 0, 1, 1);

        Support_Bottom_Length_doubleSpinBox = new QDoubleSpinBox(bottom_support);
        Support_Bottom_Length_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Bottom_Length_doubleSpinBox"));
        Support_Bottom_Length_doubleSpinBox->setMinimumSize(QSize(120, 40));
        Support_Bottom_Length_doubleSpinBox->setMaximumSize(QSize(1200, 16777215));
        Support_Bottom_Length_doubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        Support_Bottom_Length_doubleSpinBox->setMaximum(5);

        gridLayout_4->addWidget(Support_Bottom_Length_doubleSpinBox, 1, 1, 1, 1);

        label_11 = new QLabel(bottom_support);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(90, 40));

        gridLayout_4->addWidget(label_11, 2, 0, 1, 1);

        Support_Bottom_Radius_doubleSpinBox = new QDoubleSpinBox(bottom_support);
        Support_Bottom_Radius_doubleSpinBox->setObjectName(QString::fromUtf8("Support_Bottom_Radius_doubleSpinBox"));
        Support_Bottom_Radius_doubleSpinBox->setMinimumSize(QSize(120, 40));
        Support_Bottom_Radius_doubleSpinBox->setMaximumSize(QSize(1200, 16777215));
        Support_Bottom_Radius_doubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        Support_Bottom_Radius_doubleSpinBox->setMaximum(10);

        gridLayout_4->addWidget(Support_Bottom_Radius_doubleSpinBox, 2, 1, 1, 1);

        label_12 = new QLabel(bottom_support);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(90, 40));

        gridLayout_4->addWidget(label_12, 3, 0, 1, 1);

        Support_Bottom_Penetration_horizontalSlider = new QSlider(bottom_support);
        Support_Bottom_Penetration_horizontalSlider->setObjectName(QString::fromUtf8("Support_Bottom_Penetration_horizontalSlider"));
        Support_Bottom_Penetration_horizontalSlider->setMinimumSize(QSize(115, 40));
        Support_Bottom_Penetration_horizontalSlider->setMaximumSize(QSize(1200, 16777215));
        Support_Bottom_Penetration_horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(Support_Bottom_Penetration_horizontalSlider, 3, 1, 1, 1);

        Support_Bottom_Penetration_label = new QLabel(bottom_support);
        Support_Bottom_Penetration_label->setObjectName(QString::fromUtf8("Support_Bottom_Penetration_label"));
        Support_Bottom_Penetration_label->setMinimumSize(QSize(30, 40));

        gridLayout_4->addWidget(Support_Bottom_Penetration_label, 3, 2, 1, 1);

        label_13 = new QLabel(bottom_support);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(90, 40));

        gridLayout_4->addWidget(label_13, 4, 0, 1, 1);

        Support_Bottom_AngleFactor_horizontalSlider = new QSlider(bottom_support);
        Support_Bottom_AngleFactor_horizontalSlider->setObjectName(QString::fromUtf8("Support_Bottom_AngleFactor_horizontalSlider"));
        Support_Bottom_AngleFactor_horizontalSlider->setMinimumSize(QSize(115, 40));
        Support_Bottom_AngleFactor_horizontalSlider->setMaximumSize(QSize(1200, 16777215));
        Support_Bottom_AngleFactor_horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(Support_Bottom_AngleFactor_horizontalSlider, 4, 1, 1, 1);

        Support_Bottom_AngleFactor_label = new QLabel(bottom_support);
        Support_Bottom_AngleFactor_label->setObjectName(QString::fromUtf8("Support_Bottom_AngleFactor_label"));
        Support_Bottom_AngleFactor_label->setMinimumSize(QSize(30, 40));

        gridLayout_4->addWidget(Support_Bottom_AngleFactor_label, 4, 2, 1, 1);

        tabWidget->addTab(bottom_support, QString());
        pushButtonRestoreDefaults = new QPushButton(SupportParameter);
        pushButtonRestoreDefaults->setObjectName(QString::fromUtf8("pushButtonRestoreDefaults"));
        pushButtonRestoreDefaults->setGeometry(QRect(93, 467, 111, 40));
        pushButtonRestoreDefaults->setMinimumSize(QSize(0, 40));
        pushButtonRestoreDefaults->setMaximumSize(QSize(800, 16777215));
        pushButtonRestoreDefaults->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        pushButtonSave = new QPushButton(SupportParameter);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(213, 467, 111, 40));
        pushButtonSave->setMinimumSize(QSize(0, 40));
        pushButtonSave->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        layoutWidget = new QWidget(SupportParameter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 322, 180));
        gridLayout_5 = new QGridLayout(layoutWidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        checkBoxBase = new QCheckBox(layoutWidget);
        checkBoxBase->setObjectName(QString::fromUtf8("checkBoxBase"));
        checkBoxBase->setMinimumSize(QSize(0, 40));

        gridLayout_5->addWidget(checkBoxBase, 0, 0, 1, 1);

        Support_Base_Coverage_horizontalSlider = new QSlider(layoutWidget);
        Support_Base_Coverage_horizontalSlider->setObjectName(QString::fromUtf8("Support_Base_Coverage_horizontalSlider"));
        Support_Base_Coverage_horizontalSlider->setEnabled(false);
        Support_Base_Coverage_horizontalSlider->setMinimumSize(QSize(193, 40));
        Support_Base_Coverage_horizontalSlider->setMaximum(199);
        Support_Base_Coverage_horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(Support_Base_Coverage_horizontalSlider, 0, 1, 1, 2);

        radioButtonAdd = new QRadioButton(layoutWidget);
        radioButtonAdd->setObjectName(QString::fromUtf8("radioButtonAdd"));
        radioButtonAdd->setMinimumSize(QSize(0, 40));
        radioButtonAdd->setMaximumSize(QSize(78, 16777215));
        radioButtonAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_5->addWidget(radioButtonAdd, 1, 0, 1, 1);

        radioButtonDelete = new QRadioButton(layoutWidget);
        radioButtonDelete->setObjectName(QString::fromUtf8("radioButtonDelete"));
        radioButtonDelete->setMinimumSize(QSize(80, 40));
        radioButtonDelete->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_5->addWidget(radioButtonDelete, 1, 1, 1, 1);

        pushButtonCleanAll = new QPushButton(layoutWidget);
        pushButtonCleanAll->setObjectName(QString::fromUtf8("pushButtonCleanAll"));
        pushButtonCleanAll->setMinimumSize(QSize(0, 40));
        pushButtonCleanAll->setMaximumSize(QSize(5000, 16777215));
        pushButtonCleanAll->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));

        gridLayout_5->addWidget(pushButtonCleanAll, 1, 2, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 40));

        gridLayout_5->addWidget(label_8, 2, 0, 1, 1);

        doubleSpinBoxDensity = new QDoubleSpinBox(layoutWidget);
        doubleSpinBoxDensity->setObjectName(QString::fromUtf8("doubleSpinBoxDensity"));
        doubleSpinBoxDensity->setMinimumSize(QSize(0, 40));
        doubleSpinBoxDensity->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        doubleSpinBoxDensity->setSingleStep(0.2);

        gridLayout_5->addWidget(doubleSpinBoxDensity, 2, 1, 1, 1);

        pushButtonAutoSupport = new QPushButton(layoutWidget);
        pushButtonAutoSupport->setObjectName(QString::fromUtf8("pushButtonAutoSupport"));
        pushButtonAutoSupport->setEnabled(true);
        pushButtonAutoSupport->setMinimumSize(QSize(0, 40));
        pushButtonAutoSupport->setMaximumSize(QSize(5000, 16777215));
        pushButtonAutoSupport->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));

        gridLayout_5->addWidget(pushButtonAutoSupport, 2, 2, 1, 1);

        toolButtonAdvanced = new QToolButton(layoutWidget);
        toolButtonAdvanced->setObjectName(QString::fromUtf8("toolButtonAdvanced"));
        toolButtonAdvanced->setMinimumSize(QSize(320, 40));
        toolButtonAdvanced->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248,248);"));
        toolButtonAdvanced->setPopupMode(QToolButton::InstantPopup);
        toolButtonAdvanced->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButtonAdvanced->setArrowType(Qt::RightArrow);

        gridLayout_5->addWidget(toolButtonAdvanced, 3, 0, 1, 3);

        layoutWidget->raise();
        tabWidget->raise();
        pushButtonRestoreDefaults->raise();
        pushButtonSave->raise();

        retranslateUi(SupportParameter);
        QObject::connect(checkBoxBase, SIGNAL(toggled(bool)), Support_Base_Coverage_horizontalSlider, SLOT(setEnabled(bool)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SupportParameter);
    } // setupUi

    void retranslateUi(QWidget *SupportParameter)
    {
        SupportParameter->setWindowTitle(QApplication::translate("SupportParameter", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tab->setToolTip(QApplication::translate("SupportParameter", "\345\272\225\347\233\230\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_16->setToolTip(QApplication::translate("SupportParameter", "\345\275\242\347\212\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_16->setText(QApplication::translate("SupportParameter", "Shape:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Support_Base_AttachType_comboBox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_14->setToolTip(QApplication::translate("SupportParameter", "\345\215\212\345\276\204", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_14->setText(QApplication::translate("SupportParameter", "Radius(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_15->setToolTip(QApplication::translate("SupportParameter", "\351\253\230\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_15->setText(QApplication::translate("SupportParameter", "Height(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SupportParameter", "Base", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        top_support->setToolTip(QApplication::translate("SupportParameter", "\346\224\257\346\222\221\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("SupportParameter", "\345\275\242\347\212\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("SupportParameter", "Shape\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Support_Top_AttachType_comboBox->setToolTip(QApplication::translate("SupportParameter", "\345\275\242\347\212\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("SupportParameter", "\351\253\230\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("SupportParameter", "Height(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("SupportParameter", "\345\215\212\345\276\204", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("SupportParameter", "Radius(mm):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("SupportParameter", "\346\270\227\351\200\217\347\216\207", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("SupportParameter", "Penetration:", 0, QApplication::UnicodeUTF8));
        Support_Top_Penetration_label->setText(QApplication::translate("SupportParameter", "0", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("SupportParameter", "\350\247\222\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("SupportParameter", "Angle\357\274\232", 0, QApplication::UnicodeUTF8));
        Support_Top_AngleFactor_label->setText(QApplication::translate("SupportParameter", "0", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(top_support), QApplication::translate("SupportParameter", "Top", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        mid_support->setToolTip(QApplication::translate("SupportParameter", "\346\224\257\346\222\221\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("SupportParameter", "\345\275\242\347\212\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("SupportParameter", "Shape\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Support_Mid_AttachType_comboBox->setToolTip(QApplication::translate("SupportParameter", "\345\275\242\347\212\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("SupportParameter", "\345\215\212\345\276\204", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("SupportParameter", "Radius(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(mid_support), QApplication::translate("SupportParameter", "mid", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        bottom_support->setToolTip(QApplication::translate("SupportParameter", "\346\224\257\346\222\221\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_10->setToolTip(QApplication::translate("SupportParameter", "\345\275\242\347\212\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("SupportParameter", "Shape\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_9->setToolTip(QApplication::translate("SupportParameter", "\351\253\230\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_9->setText(QApplication::translate("SupportParameter", "Height(mm)\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_11->setToolTip(QApplication::translate("SupportParameter", "\345\215\212\345\276\204", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_11->setText(QApplication::translate("SupportParameter", "Radius(mm):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_12->setToolTip(QApplication::translate("SupportParameter", "\346\270\227\351\200\217\347\216\207", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_12->setText(QApplication::translate("SupportParameter", "Penetration:", 0, QApplication::UnicodeUTF8));
        Support_Bottom_Penetration_label->setText(QApplication::translate("SupportParameter", "0", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_13->setToolTip(QApplication::translate("SupportParameter", "\350\247\222\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_13->setText(QApplication::translate("SupportParameter", "Angle\357\274\232", 0, QApplication::UnicodeUTF8));
        Support_Bottom_AngleFactor_label->setText(QApplication::translate("SupportParameter", "0", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(bottom_support), QApplication::translate("SupportParameter", "bottom", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonRestoreDefaults->setToolTip(QApplication::translate("SupportParameter", "\350\256\276\347\275\256\351\273\230\350\256\244\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonRestoreDefaults->setText(QApplication::translate("SupportParameter", "Default", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonSave->setToolTip(QApplication::translate("SupportParameter", "\344\277\235\345\255\230\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonSave->setText(QApplication::translate("SupportParameter", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBoxBase->setToolTip(QApplication::translate("SupportParameter", "\345\272\225\347\233\230", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBoxBase->setText(QApplication::translate("SupportParameter", "Base", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Support_Base_Coverage_horizontalSlider->setToolTip(QApplication::translate("SupportParameter", "\345\272\225\347\233\230\345\215\212\345\276\204", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        radioButtonAdd->setToolTip(QApplication::translate("SupportParameter", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        radioButtonAdd->setText(QApplication::translate("SupportParameter", "Add", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButtonDelete->setToolTip(QApplication::translate("SupportParameter", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        radioButtonDelete->setText(QApplication::translate("SupportParameter", "Delete", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonCleanAll->setToolTip(QApplication::translate("SupportParameter", "\346\270\205\347\251\272\346\211\200\346\234\211\346\224\257\346\222\221", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonCleanAll->setText(QApplication::translate("SupportParameter", "Clean All", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("SupportParameter", "\350\207\252\345\212\250\346\224\257\346\222\221\345\257\206\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("SupportParameter", "  Density:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonAutoSupport->setToolTip(QApplication::translate("SupportParameter", "\350\207\252\345\212\250\346\267\273\345\212\240\346\224\257\346\222\221", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonAutoSupport->setText(QApplication::translate("SupportParameter", "Auto Support", 0, QApplication::UnicodeUTF8));
        toolButtonAdvanced->setText(QApplication::translate("SupportParameter", "         Advanced Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SupportParameter: public Ui_SupportParameter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPORTPARAMETER_H
