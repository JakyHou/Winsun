/********************************************************************************
** Form generated from reading UI file 'slicedialog.ui'
**
** Created: Fri Aug 31 18:03:02 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLICEDIALOG_H
#define UI_SLICEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SliceDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditPath;
    QPushButton *BrowseButton;
    QComboBox *thicknesscombo;
    QPushButton *SliceButton;
    QLabel *label_4;

    void setupUi(QDialog *SliceDialog)
    {
        if (SliceDialog->objectName().isEmpty())
            SliceDialog->setObjectName(QString::fromUtf8("SliceDialog"));
        SliceDialog->resize(394, 179);
        gridLayout = new QGridLayout(SliceDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(SliceDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditPath = new QLineEdit(SliceDialog);
        lineEditPath->setObjectName(QString::fromUtf8("lineEditPath"));
        lineEditPath->setMinimumSize(QSize(0, 40));
        lineEditPath->setReadOnly(true);

        gridLayout->addWidget(lineEditPath, 0, 1, 1, 1);

        BrowseButton = new QPushButton(SliceDialog);
        BrowseButton->setObjectName(QString::fromUtf8("BrowseButton"));
        BrowseButton->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(BrowseButton, 0, 2, 1, 1);

        thicknesscombo = new QComboBox(SliceDialog);
        thicknesscombo->setObjectName(QString::fromUtf8("thicknesscombo"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(thicknesscombo->sizePolicy().hasHeightForWidth());
        thicknesscombo->setSizePolicy(sizePolicy);
        thicknesscombo->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(thicknesscombo, 1, 1, 1, 2);

        SliceButton = new QPushButton(SliceDialog);
        SliceButton->setObjectName(QString::fromUtf8("SliceButton"));
        SliceButton->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(SliceButton, 2, 0, 1, 3);

        label_4 = new QLabel(SliceDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(100, 40));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label->raise();
        lineEditPath->raise();
        BrowseButton->raise();
        thicknesscombo->raise();
        SliceButton->raise();
        label_4->raise();

        retranslateUi(SliceDialog);

        QMetaObject::connectSlotsByName(SliceDialog);
    } // setupUi

    void retranslateUi(QDialog *SliceDialog)
    {
        SliceDialog->setWindowTitle(QApplication::translate("SliceDialog", "Slice", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("SliceDialog", "\344\277\235\345\255\230\350\267\257\345\276\204", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("SliceDialog", "Save Path:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEditPath->setToolTip(QApplication::translate("SliceDialog", "\344\277\235\345\255\230\350\267\257\345\276\204", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        BrowseButton->setToolTip(QApplication::translate("SliceDialog", "\346\265\217\350\247\210", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        BrowseButton->setWhatsThis(QApplication::translate("SliceDialog", "Select Layout file to slice", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        BrowseButton->setText(QApplication::translate("SliceDialog", "Browse", 0, QApplication::UnicodeUTF8));
        thicknesscombo->clear();
        thicknesscombo->insertItems(0, QStringList()
         << QApplication::translate("SliceDialog", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SliceDialog", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SliceDialog", "20", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        thicknesscombo->setToolTip(QApplication::translate("SliceDialog", "\345\210\207\347\211\207\345\261\202\345\216\232\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        thicknesscombo->setWhatsThis(QApplication::translate("SliceDialog", "Select the slice thickness in microns", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        SliceButton->setToolTip(QApplication::translate("SliceDialog", "\345\210\207\347\211\207", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        SliceButton->setWhatsThis(QApplication::translate("SliceDialog", "Slice the layout", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        SliceButton->setText(QApplication::translate("SliceDialog", "Slice...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("SliceDialog", "\345\210\207\347\211\207\345\216\232\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("SliceDialog", "Thickness (\302\265m):", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SliceDialog: public Ui_SliceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLICEDIALOG_H
