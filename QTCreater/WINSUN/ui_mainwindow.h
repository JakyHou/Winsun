/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Sep 3 13:38:15 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Project;
    QAction *actionOpen_Project;
    QAction *actionSave;
    QAction *actionAdd_Model;
    QAction *actionDelete;
    QAction *actionDuplicate;
    QAction *actionCenter_View;
    QAction *actionTop_View;
    QAction *actionBottom_View;
    QAction *actionLeft_View;
    QAction *actionRight_View;
    QAction *actionFront_View;
    QAction *actionBack_View;
    QAction *actionRotate;
    QAction *actionMove;
    QAction *actionScale;
    QAction *Support_Add_Supports_action;
    QAction *Support_Delete_Supports_action;
    QAction *slice;
    QAction *materialCatalog;
    QAction *cyclePrintSetting;
    QAction *terminal;
    QAction *openProjector;
    QAction *buildSpace;
    QAction *Foundation_action;
    QAction *SupportSettings_action;
    QAction *Support_Reset_Light_button;
    QAction *Support_Reset_Medium_button;
    QAction *Support_Reset_Heavy_button;
    QAction *otherSupport;
    QAction *showSlices;
    QAction *actionSave_As;
    QAction *actionExport;
    QAction *actionDrop_To_Floor;
    QAction *RemoveAllSupports_action;
    QAction *actionPrint;
    QAction *actionTerminal;
    QAction *actionModel_1;
    QAction *actionModel_2;
    QAction *actionSupport;
    QAction *actionExportSlice;
    QAction *actionOption;
    QAction *actionExport_stl;
    QAction *actionShow_3D_Model;
    QAction *actionEnglish;
    QAction *actionChinese;
    QWidget *WINSUN;
    QGridLayout *gridLayout;
    QHBoxLayout *WorldViewContext;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuPrinter;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuSlice;
    QMenu *menuTools;
    QMenu *menuLanguage;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1214, 902);
        MainWindow->setMinimumSize(QSize(500, 500));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionNew_Project = new QAction(MainWindow);
        actionNew_Project->setObjectName(QString::fromUtf8("actionNew_Project"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/B9Edit/icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Project->setIcon(icon);
        actionOpen_Project = new QAction(MainWindow);
        actionOpen_Project->setObjectName(QString::fromUtf8("actionOpen_Project"));
        actionOpen_Project->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/B9Edit/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Project->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/B9Edit/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionAdd_Model = new QAction(MainWindow);
        actionAdd_Model->setObjectName(QString::fromUtf8("actionAdd_Model"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/B9Edit/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Model->setIcon(icon3);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/B9Edit/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon4);
        actionDuplicate = new QAction(MainWindow);
        actionDuplicate->setObjectName(QString::fromUtf8("actionDuplicate"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/B9Edit/icons/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDuplicate->setIcon(icon5);
        actionCenter_View = new QAction(MainWindow);
        actionCenter_View->setObjectName(QString::fromUtf8("actionCenter_View"));
        actionTop_View = new QAction(MainWindow);
        actionTop_View->setObjectName(QString::fromUtf8("actionTop_View"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/B9Edit/icons/top.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTop_View->setIcon(icon6);
        actionBottom_View = new QAction(MainWindow);
        actionBottom_View->setObjectName(QString::fromUtf8("actionBottom_View"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/B9Edit/icons/bottom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBottom_View->setIcon(icon7);
        actionLeft_View = new QAction(MainWindow);
        actionLeft_View->setObjectName(QString::fromUtf8("actionLeft_View"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/B9Edit/icons/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLeft_View->setIcon(icon8);
        actionRight_View = new QAction(MainWindow);
        actionRight_View->setObjectName(QString::fromUtf8("actionRight_View"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/B9Edit/icons/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRight_View->setIcon(icon9);
        actionFront_View = new QAction(MainWindow);
        actionFront_View->setObjectName(QString::fromUtf8("actionFront_View"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/B9Edit/icons/front.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFront_View->setIcon(icon10);
        actionBack_View = new QAction(MainWindow);
        actionBack_View->setObjectName(QString::fromUtf8("actionBack_View"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/B9Edit/icons/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBack_View->setIcon(icon11);
        actionRotate = new QAction(MainWindow);
        actionRotate->setObjectName(QString::fromUtf8("actionRotate"));
        actionRotate->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/B9Edit/icons/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate->setIcon(icon12);
        actionMove = new QAction(MainWindow);
        actionMove->setObjectName(QString::fromUtf8("actionMove"));
        actionMove->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/B9Edit/icons/move.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove->setIcon(icon13);
        actionScale = new QAction(MainWindow);
        actionScale->setObjectName(QString::fromUtf8("actionScale"));
        actionScale->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/B9Edit/icons/scale.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScale->setIcon(icon14);
        Support_Add_Supports_action = new QAction(MainWindow);
        Support_Add_Supports_action->setObjectName(QString::fromUtf8("Support_Add_Supports_action"));
        Support_Add_Supports_action->setCheckable(true);
        Support_Add_Supports_action->setEnabled(false);
        Support_Add_Supports_action->setIcon(icon3);
        Support_Delete_Supports_action = new QAction(MainWindow);
        Support_Delete_Supports_action->setObjectName(QString::fromUtf8("Support_Delete_Supports_action"));
        Support_Delete_Supports_action->setCheckable(true);
        Support_Delete_Supports_action->setEnabled(true);
        Support_Delete_Supports_action->setIcon(icon4);
        slice = new QAction(MainWindow);
        slice->setObjectName(QString::fromUtf8("slice"));
        slice->setEnabled(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/B9Edit/icons/preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        slice->setIcon(icon15);
        materialCatalog = new QAction(MainWindow);
        materialCatalog->setObjectName(QString::fromUtf8("materialCatalog"));
        materialCatalog->setEnabled(false);
        cyclePrintSetting = new QAction(MainWindow);
        cyclePrintSetting->setObjectName(QString::fromUtf8("cyclePrintSetting"));
        terminal = new QAction(MainWindow);
        terminal->setObjectName(QString::fromUtf8("terminal"));
        openProjector = new QAction(MainWindow);
        openProjector->setObjectName(QString::fromUtf8("openProjector"));
        openProjector->setEnabled(false);
        buildSpace = new QAction(MainWindow);
        buildSpace->setObjectName(QString::fromUtf8("buildSpace"));
        buildSpace->setEnabled(false);
        Foundation_action = new QAction(MainWindow);
        Foundation_action->setObjectName(QString::fromUtf8("Foundation_action"));
        Foundation_action->setCheckable(true);
        Foundation_action->setChecked(false);
        Foundation_action->setEnabled(true);
        SupportSettings_action = new QAction(MainWindow);
        SupportSettings_action->setObjectName(QString::fromUtf8("SupportSettings_action"));
        SupportSettings_action->setEnabled(true);
        Support_Reset_Light_button = new QAction(MainWindow);
        Support_Reset_Light_button->setObjectName(QString::fromUtf8("Support_Reset_Light_button"));
        Support_Reset_Medium_button = new QAction(MainWindow);
        Support_Reset_Medium_button->setObjectName(QString::fromUtf8("Support_Reset_Medium_button"));
        Support_Reset_Heavy_button = new QAction(MainWindow);
        Support_Reset_Heavy_button->setObjectName(QString::fromUtf8("Support_Reset_Heavy_button"));
        otherSupport = new QAction(MainWindow);
        otherSupport->setObjectName(QString::fromUtf8("otherSupport"));
        showSlices = new QAction(MainWindow);
        showSlices->setObjectName(QString::fromUtf8("showSlices"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/B9Edit/icons/slice.png"), QSize(), QIcon::Normal, QIcon::Off);
        showSlices->setIcon(icon16);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QString::fromUtf8("actionExport"));
        actionDrop_To_Floor = new QAction(MainWindow);
        actionDrop_To_Floor->setObjectName(QString::fromUtf8("actionDrop_To_Floor"));
        actionDrop_To_Floor->setCheckable(false);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/B9Edit/icons/drop.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        actionDrop_To_Floor->setIcon(icon17);
        RemoveAllSupports_action = new QAction(MainWindow);
        RemoveAllSupports_action->setObjectName(QString::fromUtf8("RemoveAllSupports_action"));
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/B9Edit/icons/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon18);
        actionTerminal = new QAction(MainWindow);
        actionTerminal->setObjectName(QString::fromUtf8("actionTerminal"));
        actionModel_1 = new QAction(MainWindow);
        actionModel_1->setObjectName(QString::fromUtf8("actionModel_1"));
        actionModel_2 = new QAction(MainWindow);
        actionModel_2->setObjectName(QString::fromUtf8("actionModel_2"));
        actionSupport = new QAction(MainWindow);
        actionSupport->setObjectName(QString::fromUtf8("actionSupport"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/B9Edit/icons/support.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSupport->setIcon(icon19);
        actionExportSlice = new QAction(MainWindow);
        actionExportSlice->setObjectName(QString::fromUtf8("actionExportSlice"));
        actionOption = new QAction(MainWindow);
        actionOption->setObjectName(QString::fromUtf8("actionOption"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/B9Edit/icons/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOption->setIcon(icon20);
        actionExport_stl = new QAction(MainWindow);
        actionExport_stl->setObjectName(QString::fromUtf8("actionExport_stl"));
        actionShow_3D_Model = new QAction(MainWindow);
        actionShow_3D_Model->setObjectName(QString::fromUtf8("actionShow_3D_Model"));
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QString::fromUtf8("actionEnglish"));
        actionChinese = new QAction(MainWindow);
        actionChinese->setObjectName(QString::fromUtf8("actionChinese"));
        WINSUN = new QWidget(MainWindow);
        WINSUN->setObjectName(QString::fromUtf8("WINSUN"));
        gridLayout = new QGridLayout(WINSUN);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        WorldViewContext = new QHBoxLayout();
        WorldViewContext->setSpacing(6);
        WorldViewContext->setObjectName(QString::fromUtf8("WorldViewContext"));

        gridLayout->addLayout(WorldViewContext, 0, 0, 1, 1);

        MainWindow->setCentralWidget(WINSUN);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1214, 23));
        menuBar->setStyleSheet(QString::fromUtf8(""));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuPrinter = new QMenu(menuFile);
        menuPrinter->setObjectName(QString::fromUtf8("menuPrinter"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuSlice = new QMenu(menuBar);
        menuSlice->setObjectName(QString::fromUtf8("menuSlice"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuLanguage = new QMenu(menuTools);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuSlice->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuFile->addAction(actionNew_Project);
        menuFile->addAction(actionOpen_Project);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionPrint);
        menuFile->addAction(menuPrinter->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExportSlice);
        menuFile->addAction(actionExport_stl);
        menuPrinter->addAction(actionModel_1);
        menuPrinter->addAction(actionModel_2);
        menuEdit->addAction(actionAdd_Model);
        menuEdit->addAction(actionDelete);
        menuEdit->addAction(actionDuplicate);
        menuEdit->addSeparator();
        menuEdit->addAction(actionRotate);
        menuEdit->addAction(actionMove);
        menuEdit->addAction(actionScale);
        menuEdit->addAction(actionDrop_To_Floor);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSupport);
        menuView->addAction(actionTop_View);
        menuView->addAction(actionBottom_View);
        menuView->addAction(actionLeft_View);
        menuView->addAction(actionRight_View);
        menuView->addAction(actionFront_View);
        menuView->addAction(actionBack_View);
        menuSlice->addAction(slice);
        menuSlice->addAction(showSlices);
        menuTools->addAction(actionTerminal);
        menuTools->addAction(actionOption);
        menuTools->addSeparator();
        menuTools->addAction(menuLanguage->menuAction());
        menuLanguage->addSeparator();
        menuLanguage->addAction(actionEnglish);
        menuLanguage->addAction(actionChinese);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Nepho3d_Studio", 0, QApplication::UnicodeUTF8));
        actionNew_Project->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNew_Project->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNew_Project->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionOpen_Project->setText(QApplication::translate("MainWindow", "Open(.nstl)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen_Project->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpen_Project->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save(.nstl)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionAdd_Model->setText(QApplication::translate("MainWindow", "Add Model(.stl)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAdd_Model->setToolTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\250\241\345\236\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionDelete->setText(QApplication::translate("MainWindow", "Delete Model", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionDelete->setToolTip(QApplication::translate("MainWindow", "\345\210\240\351\231\244\346\250\241\345\236\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionDelete->setShortcut(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        actionDuplicate->setText(QApplication::translate("MainWindow", "Duplicate Model", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionDuplicate->setToolTip(QApplication::translate("MainWindow", "\345\244\215\345\210\266\346\250\241\345\236\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionDuplicate->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionCenter_View->setText(QApplication::translate("MainWindow", "Center", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCenter_View->setToolTip(QApplication::translate("MainWindow", "\344\270\255\345\244\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionTop_View->setText(QApplication::translate("MainWindow", "Top", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionTop_View->setToolTip(QApplication::translate("MainWindow", "\351\241\266\351\203\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionBottom_View->setText(QApplication::translate("MainWindow", "Bottom", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionBottom_View->setToolTip(QApplication::translate("MainWindow", "\345\272\225\351\203\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionLeft_View->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLeft_View->setToolTip(QApplication::translate("MainWindow", "\345\267\246\344\276\247", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRight_View->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRight_View->setToolTip(QApplication::translate("MainWindow", "\345\217\263\344\276\247", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionFront_View->setText(QApplication::translate("MainWindow", "Front", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionFront_View->setToolTip(QApplication::translate("MainWindow", "\345\211\215\351\235\242", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionBack_View->setText(QApplication::translate("MainWindow", "Back", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionBack_View->setToolTip(QApplication::translate("MainWindow", "\345\220\216\351\235\242", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRotate->setText(QApplication::translate("MainWindow", "Ratate", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRotate->setToolTip(QApplication::translate("MainWindow", "\346\227\213\350\275\254", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionMove->setText(QApplication::translate("MainWindow", "Move", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionMove->setToolTip(QApplication::translate("MainWindow", "\345\271\263\347\247\273", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionScale->setText(QApplication::translate("MainWindow", "Scale", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionScale->setToolTip(QApplication::translate("MainWindow", "\347\274\251\346\224\276", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        Support_Add_Supports_action->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\224\257\346\222\221", 0, QApplication::UnicodeUTF8));
        Support_Delete_Supports_action->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\346\224\257\346\222\221", 0, QApplication::UnicodeUTF8));
        slice->setText(QApplication::translate("MainWindow", "Slice", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slice->setToolTip(QApplication::translate("MainWindow", "\346\237\245\347\234\213\345\210\207\347\211\207", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        materialCatalog->setText(QApplication::translate("MainWindow", "\346\235\220\346\226\231\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        cyclePrintSetting->setText(QApplication::translate("MainWindow", "\345\276\252\347\216\257\346\211\223\345\215\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        terminal->setText(QApplication::translate("MainWindow", "\347\273\210\347\253\257\346\223\215\344\275\234", 0, QApplication::UnicodeUTF8));
        openProjector->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\212\225\345\275\261\344\273\252", 0, QApplication::UnicodeUTF8));
        buildSpace->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\231\250\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        Foundation_action->setText(QApplication::translate("MainWindow", "\345\234\260\345\237\272", 0, QApplication::UnicodeUTF8));
        SupportSettings_action->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        Support_Reset_Light_button->setText(QApplication::translate("MainWindow", "\345\260\217\345\217\267", 0, QApplication::UnicodeUTF8));
        Support_Reset_Medium_button->setText(QApplication::translate("MainWindow", "\344\270\255\345\217\267", 0, QApplication::UnicodeUTF8));
        Support_Reset_Heavy_button->setText(QApplication::translate("MainWindow", "\345\244\247\345\217\267", 0, QApplication::UnicodeUTF8));
        otherSupport->setText(QApplication::translate("MainWindow", "\345\205\266\344\273\226\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
        showSlices->setText(QApplication::translate("MainWindow", "Show Slice", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        showSlices->setToolTip(QApplication::translate("MainWindow", "\345\210\207\347\211\207", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As(.nstl)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave_As->setToolTip(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionExport->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272", 0, QApplication::UnicodeUTF8));
        actionDrop_To_Floor->setText(QApplication::translate("MainWindow", "Drop to Floor", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionDrop_To_Floor->setToolTip(QApplication::translate("MainWindow", "\350\220\275\345\272\225", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        RemoveAllSupports_action->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\224\257\346\222\221", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPrint->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionTerminal->setText(QApplication::translate("MainWindow", "Terminal", 0, QApplication::UnicodeUTF8));
        actionModel_1->setText(QApplication::translate("MainWindow", "M50", 0, QApplication::UnicodeUTF8));
        actionModel_2->setText(QApplication::translate("MainWindow", "M100", 0, QApplication::UnicodeUTF8));
        actionModel_2->setIconText(QApplication::translate("MainWindow", "M100\357\274\210128x80\357\274\211", 0, QApplication::UnicodeUTF8));
        actionSupport->setText(QApplication::translate("MainWindow", "Support", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSupport->setToolTip(QApplication::translate("MainWindow", "\346\224\257\346\222\221", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionExportSlice->setText(QApplication::translate("MainWindow", "Export(.n3d)", 0, QApplication::UnicodeUTF8));
        actionOption->setText(QApplication::translate("MainWindow", "Printer Option", 0, QApplication::UnicodeUTF8));
        actionExport_stl->setText(QApplication::translate("MainWindow", "Export(.stl)", 0, QApplication::UnicodeUTF8));
        actionShow_3D_Model->setText(QApplication::translate("MainWindow", "Show 3D Model", 0, QApplication::UnicodeUTF8));
        actionEnglish->setText(QApplication::translate("MainWindow", "English", 0, QApplication::UnicodeUTF8));
        actionChinese->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\207", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        menuFile->setToolTip(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuPrinter->setTitle(QApplication::translate("MainWindow", "Printer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        menuEdit->setToolTip(QApplication::translate("MainWindow", "\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        menuView->setToolTip(QApplication::translate("MainWindow", "\350\247\206\345\233\276", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        menuSlice->setToolTip(QApplication::translate("MainWindow", "\345\210\207\347\211\207", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        menuSlice->setTitle(QApplication::translate("MainWindow", "Slice", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        menuLanguage->setTitle(QApplication::translate("MainWindow", "Language", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
