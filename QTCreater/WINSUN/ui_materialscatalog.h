/********************************************************************************
** Form generated from reading UI file 'materialscatalog.ui'
**
** Created: Fri Aug 31 18:03:01 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALSCATALOG_H
#define UI_MATERIALSCATALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaterialsCatalog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QComboBox *comboBoxMaterial;
    QTableWidget *tableWidgetParameters;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *MaterialsCatalog)
    {
        if (MaterialsCatalog->objectName().isEmpty())
            MaterialsCatalog->setObjectName(QString::fromUtf8("MaterialsCatalog"));
        MaterialsCatalog->resize(680, 296);
        MaterialsCatalog->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(MaterialsCatalog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_2 = new QGroupBox(MaterialsCatalog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        comboBoxMaterial = new QComboBox(groupBox_2);
        comboBoxMaterial->setObjectName(QString::fromUtf8("comboBoxMaterial"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxMaterial->sizePolicy().hasHeightForWidth());
        comboBoxMaterial->setSizePolicy(sizePolicy1);
        comboBoxMaterial->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(comboBoxMaterial, 0, 1, 1, 4);

        tableWidgetParameters = new QTableWidget(groupBox_2);
        if (tableWidgetParameters->columnCount() < 3)
            tableWidgetParameters->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetParameters->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetParameters->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetParameters->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidgetParameters->rowCount() < 3)
            tableWidgetParameters->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetParameters->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetParameters->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetParameters->setVerticalHeaderItem(2, __qtablewidgetitem5);
        tableWidgetParameters->setObjectName(QString::fromUtf8("tableWidgetParameters"));
        tableWidgetParameters->setFrameShape(QFrame::StyledPanel);
        tableWidgetParameters->setLineWidth(1);
        tableWidgetParameters->setMidLineWidth(0);
        tableWidgetParameters->setTextElideMode(Qt::ElideMiddle);
        tableWidgetParameters->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidgetParameters->setShowGrid(true);
        tableWidgetParameters->setGridStyle(Qt::SolidLine);
        tableWidgetParameters->setWordWrap(true);
        tableWidgetParameters->setCornerButtonEnabled(true);
        tableWidgetParameters->horizontalHeader()->setVisible(true);
        tableWidgetParameters->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidgetParameters->horizontalHeader()->setDefaultSectionSize(180);
        tableWidgetParameters->horizontalHeader()->setHighlightSections(true);
        tableWidgetParameters->horizontalHeader()->setMinimumSectionSize(180);
        tableWidgetParameters->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidgetParameters->horizontalHeader()->setStretchLastSection(true);
        tableWidgetParameters->verticalHeader()->setVisible(true);
        tableWidgetParameters->verticalHeader()->setCascadingSectionResizes(false);
        tableWidgetParameters->verticalHeader()->setDefaultSectionSize(40);
        tableWidgetParameters->verticalHeader()->setMinimumSectionSize(40);
        tableWidgetParameters->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidgetParameters->verticalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(tableWidgetParameters, 1, 0, 1, 5);

        pushButtonAdd = new QPushButton(groupBox_2);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pushButtonAdd, 2, 1, 1, 1);

        pushButtonDelete = new QPushButton(groupBox_2);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));
        sizePolicy1.setHeightForWidth(pushButtonDelete->sizePolicy().hasHeightForWidth());
        pushButtonDelete->setSizePolicy(sizePolicy1);
        pushButtonDelete->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pushButtonDelete, 2, 2, 1, 1);

        pushButtonSave = new QPushButton(groupBox_2);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pushButtonSave, 2, 3, 1, 1);

        pushButtonCancel = new QPushButton(groupBox_2);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pushButtonCancel, 2, 4, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);


        retranslateUi(MaterialsCatalog);
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), MaterialsCatalog, SLOT(close()));

        QMetaObject::connectSlotsByName(MaterialsCatalog);
    } // setupUi

    void retranslateUi(QWidget *MaterialsCatalog)
    {
        MaterialsCatalog->setWindowTitle(QApplication::translate("MaterialsCatalog", "Materials Setting", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        MaterialsCatalog->setToolTip(QApplication::translate("MaterialsCatalog", "\346\235\220\346\226\231\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QApplication::translate("MaterialsCatalog", "Materials Setting", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("MaterialsCatalog", "\346\235\220\346\226\231", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("MaterialsCatalog", "Material\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        comboBoxMaterial->setToolTip(QApplication::translate("MaterialsCatalog", "Select a Material from the Catalog", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        comboBoxMaterial->setWhatsThis(QApplication::translate("MaterialsCatalog", "Select a Material from the Catalog to view/edit exposure timing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        QTableWidgetItem *___qtablewidgetitem = tableWidgetParameters->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MaterialsCatalog", "Attach Exposure(sec)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetParameters->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MaterialsCatalog", "Time of Exposure(sec)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetParameters->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MaterialsCatalog", "Intensity of Exposure(0-255)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetParameters->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MaterialsCatalog", "20\316\274m", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetParameters->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MaterialsCatalog", "50\316\274m", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetParameters->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MaterialsCatalog", "100\316\274m", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidgetParameters->setToolTip(QApplication::translate("MaterialsCatalog", "\346\235\220\346\226\231\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tableWidgetParameters->setWhatsThis(QApplication::translate("MaterialsCatalog", "Exposure settings for a given material and xy pixel size.  Each possible layer thickness and it's associated timing is shown.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButtonAdd->setToolTip(QApplication::translate("MaterialsCatalog", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButtonAdd->setWhatsThis(QApplication::translate("MaterialsCatalog", "Add a new Material to the Catalog", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButtonAdd->setText(QApplication::translate("MaterialsCatalog", "Add", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonDelete->setToolTip(QApplication::translate("MaterialsCatalog", "\347\247\273\351\231\244", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButtonDelete->setWhatsThis(QApplication::translate("MaterialsCatalog", "Remove the selected material from the Catalog.  Default entries can not be deleted.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButtonDelete->setText(QApplication::translate("MaterialsCatalog", "Delete", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonSave->setToolTip(QApplication::translate("MaterialsCatalog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonSave->setText(QApplication::translate("MaterialsCatalog", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButtonCancel->setToolTip(QApplication::translate("MaterialsCatalog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonCancel->setText(QApplication::translate("MaterialsCatalog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MaterialsCatalog: public Ui_MaterialsCatalog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALSCATALOG_H
