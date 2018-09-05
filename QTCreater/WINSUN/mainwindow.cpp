#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "layout/layoutprojectdata.h"
#include "crushbitmap.h"
#include "layout/slicecontext.h"
#include "layout/sliceset.h"
#include "layout/slice.h"
#include "loadingbar.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QVector3D>
#include <QGLWidget>
#include <QDebug>
#include "layout/SlcExporter.h"
#include "layout/modeldata.h"
#include "layout/modelinstance.h"
#include "supportstructure.h"
#include "OS_Wrapper_Functions.h"
#include "modelwriter.h"

#include <QBitmap>
#include <QPainter>

#define btnbkgcolor "QPushButton{background-color: rgba(70, 130, 180, 100%);}"\
                    "QPushButton:hover{background-color:rgba(0, 170, 255, 100%);}"\
                    "QPushButton:pressed{background-color:rgb(100, 100, 100);}"
#define bkgcolor "background-color: rgba( 233, 233 ,233, 100%);"
#define BASERADIUS 6.0 //240, 240, 240 208, 219, 230
#define TOPRADIUS 0.5
#define MIDRADIUS 0.5
#define BOTTOMRADIUS 3.0
#define BASELENGTH 1.0
#define TOPLENGTH 1.0
//#define MIDLENGTH
#define BOTTOMLENGTH 0.5
#define BASESHAP "Cylinder"
#define TOPSHAPE "Cone 25%"
#define MIDHAPE "Cylinder"
#define BOTTOMSHAPE "Cylinder"
#define TOPPENETRATION 0
#define BOTTOMPENETRATION 0
#define TOPANGLE 0.2
#define BOTTOMANGLE 0.2

void PSupportSettings::updateValues()
{
    SupportSetting dlg(this);
    dlg.exec();
}

void PSupportSettings::loadSettings()
{
    QSettings appSettings;
    appSettings.beginGroup("USERSUPPORTPARAMS");

    m_dBaseRadius = appSettings.value("BaseRadius",BASERADIUS).toDouble();
    m_dBaseLength = appSettings.value("BaseLength",BASELENGTH).toDouble();
    m_baseAttachShape = appSettings.value("BaseAttachShape",BASESHAP).toString();

    m_topAttachShape = appSettings.value("TopAttachShape",TOPSHAPE).toString();
    m_dTopRadius = appSettings.value("TopRadius",TOPRADIUS).toDouble();
    m_dTopLength = appSettings.value("TopLength",TOPLENGTH).toDouble();
    m_dTopPenetration = appSettings.value("TopPenetration",TOPPENETRATION).toDouble();
    m_dTopAngleFactor = appSettings.value("TopAngleFactor",TOPANGLE).toDouble();

    m_midAttachShape = appSettings.value("MidAttachShape",MIDHAPE).toString();
    m_dMidRadius = appSettings.value("MidRadius",MIDRADIUS).toDouble();

    m_bottomAttachShape = appSettings.value("BottomAttachShape",BOTTOMSHAPE).toString();
    m_dBottomLength = appSettings.value("BottomLength",BOTTOMLENGTH).toDouble();
    m_dBottomPenetration = appSettings.value("BottomPenetration",BOTTOMPENETRATION).toDouble();
    m_dBottomAngleFactor = appSettings.value("BottomAngleFactor",BOTTOMANGLE).toDouble();
    m_dBottomRadius = appSettings.value("BottomRadius",BOTTOMRADIUS).toDouble();

    m_autoDistance = appSettings.value("AutoDistance",2).toDouble();

    appSettings.endGroup();

}

void PSupportSettings::saveSettings()
{
    QSettings appSettings;
    appSettings.beginGroup("USERSUPPORTPARAMS");
            appSettings.setValue("BaseRadius",m_dBaseRadius);
            appSettings.setValue("BaseLength",m_dBaseLength);

        appSettings.setValue("TopLength",m_dTopLength);
        appSettings.setValue("TopRadius",m_dTopRadius);
        appSettings.setValue("TopPenetration",m_dTopPenetration);
        appSettings.setValue("TopAngleFactor", m_dTopAngleFactor);

        appSettings.setValue("MidRadius",m_dMidRadius);

        appSettings.setValue("BottomLength",m_dBottomLength);
        appSettings.setValue("BottomRadius",m_dBottomRadius);
        appSettings.setValue("BottomPenetration",m_dBottomPenetration);
        appSettings.setValue("BottomAngleFactor", m_dBottomAngleFactor);


        appSettings.setValue("BaseAttachShape",m_baseAttachShape);
        appSettings.setValue("TopAttachShape",m_topAttachShape);
        appSettings.setValue("MidAttachShape",m_midAttachShape);
        appSettings.setValue("BottomAttachShape",m_bottomAttachShape);


        appSettings.setValue("AutoDistance",m_autoDistance);

        appSettings.endGroup();
}

void PSupportSettings::setFactorySettings()
{
    m_baseAttachShape = "Cylinder";
    m_dBaseRadius = BASERADIUS;
    m_dBaseLength = BASELENGTH;

    m_topAttachShape = "Cone 25%";
    m_dTopLength = TOPLENGTH;
    m_dTopRadius = TOPRADIUS;
    m_dTopPenetration = TOPPENETRATION;
    m_dTopAngleFactor = TOPANGLE;

    m_midAttachShape = "Cylinder";
    m_dMidRadius = MIDRADIUS;

    m_bottomAttachShape = "Cylinder";
    m_dBottomRadius = BOTTOMRADIUS;
    m_dBottomLength = BOTTOMLENGTH;
    m_dBottomPenetration = BOTTOMPENETRATION;
    m_dBottomAngleFactor = BOTTOMANGLE;

    m_autoDistance = 2;
}


MainWindow::MainWindow(int width,int height,QWidget *parent) :
    QMainWindow(parent)/*,
    ui(new Ui::MainWindow)*/
{
    ui.setupUi(this);

    m_width = width;
    m_height = height;

    pSettings = new PSupportSettings;
    //Initialize project data
    project = new B9LayoutProjectData();
    project->pMain = this;

    //子窗口
    t = new Terminal(this);
    pPrint = new Print(t);
    pSliceView=NULL;
    pw = new PrintWindow(this,t);

//    status = new statusWidget(this/*,statusBar()*/);
//    status->setGeometry(m_width/2-200,0,660,30);

    pPriSetDlg = new PrintSettingDialog(this);
    pPriSetDlg->setGeometry(width/2-200,height/2-200,400,310);


    bModel=true;
    bView=bSize=bPos=bRot=bSup=false;

    //Create the worldview and attach it to the window    pixmap = new QPixmap(100,100);
    pWorldView = new WorldView(NULL,this);
    ui.WorldViewContext->addWidget(pWorldView);


    pMBW_ModelList = new MyBallonWidget(pWorldView);
    pMBW_ModelList->setGeometry(0,0,420,380);
    pModelList = new ModelList(this,pMBW_ModelList);
    pModelList->setGeometry(60,20,337,335);
    pMBW_ModelList->hide();


    SetToolModelSelect();//start off with pointer tool

    //support B9Editing
    currInstanceInSupportMode = NULL;
    hideSupports = true;

    //slicing
    cancelslicing = false;

    //import premade stls for support structures
    B9SupportStructure::ImportAttachmentDataFromStls();
//        B9SupportStructure::FillRegistryDefaults();//if needed

    //build the interface initially - different than update interface..

    m_pCPJ = NULL;
    newCPJ = NULL;
//    m_pCPJ = new CrushedPrintJob;
//    newCPJ = new CrushedPrintJob;

    this->geometry();

    connect (pw, SIGNAL(accepted()),this,SLOT(doPrint()));
//    connect(pPrint,SIGNAL(setProjectorPowerOff()),pw,SLOT(on_pushButtonProjPowerOFF_clicked()/*on_setProjectorBlueLED(int)*/));
    connect(pPrint,SIGNAL(setProjectorPowerOff()),pw,SLOT(OnSetProjectorPowerOff()/*on_setProjectorBlueLED(int)*/));
//    connect(t,SIGNAL(setProjectorBlueLED(int)),pw,SLOT(on_setProjectorBlueLED(int)));
//    connect(t->pProjector,SIGNAL(setProjectorBlueLED(int)),pw,SLOT(on_setProjectorBlueLED(int)));
    current_language="English";
    QSettings appSettings;
    appSettings.beginGroup("USERSET");
    language=appSettings.value("Language").toString();
    qDebug()<<"Setting language:"<<language;
    appSettings.endGroup();
    if(language!=""){
        UpdateByLanguage();
    }
    InitInterface();

    New();

//    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
//    setFixedSize(m_width, m_height);//固定窗口大小

}

MainWindow::~MainWindow()
{
    delete pPriSetDlg;

    delete pModelList;
    delete pMBW_ModelList;

    delete size;
    delete pMBW_Size;
//    delete pButtonScale;

    delete position;
    delete pMBW_Position;

    delete orientation;
    delete pMBW_Rotate;

    if(pw)
        delete pw;
    if(t)
        delete t;
    if(pPrint)
        delete pPrint;
    if(pSliceView)
        delete pSliceView;

//    delete bakground;

    if(pWorldView)
        delete pWorldView;
    if(project)
        delete project;
//    if(m_pCPJ)
//        delete m_pCPJ;

    if(newCPJ){
        delete newCPJ;
        newCPJ =NULL;
    }
    if(pSettings)
        delete pSettings;
    if(currInstanceInSupportMode)
        delete currInstanceInSupportMode;

//    if(pActionSupport)
//        delete pActionSupport;

}

void MainWindow::InitInterface()
{
    ui.WINSUN->setStyleSheet(bkgcolor);
//    ui.statusBar->setStyleSheet(bkgcolor);
    //===========================界面快捷方式======================================

    //-------------------------------view-------------------------------------
    //按钮背景色
    bakground = new QWidget(pWorldView);
    bakground->setGeometry(m_width-70,0,70, m_height);//300
    bakground->setStyleSheet(bkgcolor);//"background-color: rgba(240, 240, 240, 100%);"

//    pMBW_View = new MyBallonWidget(pWorldView);
//    pMBW_View->setGeometry(70,30,115,165);
//    view = new viewWidget(this,pMBW_View);
//    view->setGeometry(10,10,105,150);
//    pMBW_View->setVisible(false);

//    pButtonView = new QPushButton(pWorldView);
//    pButtonView->setGeometry(10,30,50,50);
//    pButtonView->setText("View");
//    pButtonView->setStyleSheet(bkgcolor);
//    pButtonView->setToolTip("View");
//    connect(pButtonView,SIGNAL(clicked()),this,SLOT(on_ButtonView_clicked()));

    QIcon iconTop;
    iconTop.addFile(QString::fromUtf8(":/B9Edit/icons/top.png"), QSize(), QIcon::Normal, QIcon::Off);//
    pButtonTop = new QPushButton(bakground);
    pButtonTop->setIcon(iconTop);
    pButtonTop->setIconSize(QSize(40, 40));
    pButtonTop->setFlat(true);
    pButtonTop->setGeometry(0,10,40,40);
    pButtonTop->setStyleSheet(bkgcolor);
    pButtonTop->setToolTip("Top");
    connect(pButtonTop,SIGNAL(clicked()),pWorldView,SLOT(TopView()));

    QIcon iconBottom;
    iconBottom.addFile(QString::fromUtf8(":/B9Edit/icons/bottom.png"), QSize(), QIcon::Normal, QIcon::Off);//
    pButtonBottom = new QPushButton(bakground);
    pButtonBottom->setIcon(iconBottom);
    pButtonBottom->setIconSize(QSize(40, 40));
    pButtonBottom->setFlat(true);
    pButtonBottom->setGeometry(0,60,40,40);
    pButtonBottom->setStyleSheet(bkgcolor);
    pButtonBottom->setToolTip("Bottom");
    connect(pButtonBottom,SIGNAL(clicked()),pWorldView,SLOT(BottomView()));

    QIcon iconLeft;
    iconLeft.addFile(QString::fromUtf8(":/B9Edit/icons/left.png"), QSize(), QIcon::Normal, QIcon::Off);//
    pButtonLeft = new QPushButton(bakground);
    pButtonLeft->setIcon(iconLeft);
    pButtonLeft->setIconSize(QSize(40, 40));
    pButtonLeft->setFlat(true);
    pButtonLeft->setGeometry(0,110,40,40);
    pButtonLeft->setStyleSheet(bkgcolor);
    pButtonLeft->setToolTip("Left");
    connect(pButtonLeft,SIGNAL(clicked()),pWorldView,SLOT(LeftView()));

    QIcon iconRight;
    iconRight.addFile(QString::fromUtf8(":/B9Edit/icons/right.png"), QSize(), QIcon::Normal, QIcon::Off);//
    pButtonRight = new QPushButton(bakground);
    pButtonRight->setIcon(iconRight);
    pButtonRight->setIconSize(QSize(40, 40));
    pButtonRight->setFlat(true);
    pButtonRight->setGeometry(0,160,40,40);//230,350,100,100 border-image: url(:/B9Edit/icons/scale3.png);
    pButtonRight->setStyleSheet(bkgcolor);
    pButtonRight->setToolTip("Right");
    connect(pButtonRight,SIGNAL(clicked()),pWorldView,SLOT(RightView()));

    QIcon iconFront;
    iconFront.addFile(QString::fromUtf8(":/B9Edit/icons/front.png"), QSize(), QIcon::Normal, QIcon::Off);//
    pButtonFront = new QPushButton(bakground);
    pButtonFront->setIcon(iconFront);
    pButtonFront->setIconSize(QSize(40, 40));
    pButtonFront->setFlat(true);
    pButtonFront->setGeometry(0,210,40,40);
    pButtonFront->setStyleSheet(bkgcolor);
    pButtonFront->setToolTip("Front");
    connect(pButtonFront,SIGNAL(clicked()),pWorldView,SLOT(FrontView()));

    QIcon iconBack;
    iconBack.addFile(QString::fromUtf8(":/B9Edit/icons/back.png"), QSize(), QIcon::Normal, QIcon::Off);//
    pButtonBack = new QPushButton(bakground);
    pButtonBack->setIcon(iconBack);
    pButtonBack->setIconSize(QSize(40, 40));
    pButtonBack->setFlat(true);
    pButtonBack->setGeometry(0,260,40,40);
    pButtonBack->setStyleSheet(bkgcolor);
    pButtonBack->setToolTip("Back");
    connect(pButtonBack,SIGNAL(clicked()),pWorldView,SLOT(BackView()));

//    curNumOfLayersSlider = new SliceSlider(bakground);
//    curNumOfLayersSlider->setGeometry(0,350,50,m_height-500);
//    curNumOfLayersSlider->setMaximum(100);
//    curNumOfLayersSlider->setValue(50);
//    connect(curNumOfLayersSlider,SIGNAL(curNumOfLayers(int)),this,SLOT(on_curNumOfLayers(int)));

    QBitmap bmp(50,50);
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),5,5);
    int height = 20;
    //--------------------------------add model------------------------------------
    bakgroundAdd = new QWidget(pWorldView);
    bakgroundAdd->setGeometry(10,height+10,50, 50);
    bakgroundAdd->setMask(bmp);
//    bakgroundAdd->setStyleSheet("background-color:gray;");
//    bakgroundAdd->setStyleSheet("QWidget{border-radius:15px;background-color: rgba(255, 255, 255, 50%);}");
    QIcon iconAdd;
    iconAdd.addFile(QString::fromUtf8(":/B9Edit/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);//
    pButtonAdd = new QPushButton(bakgroundAdd);
    pButtonAdd->setIcon(iconAdd);
    pButtonAdd->setIconSize(QSize(50, 50));
    pButtonAdd->setGeometry(-5,-5,60,60);
    pButtonAdd->setStyleSheet(btnbkgcolor);//(bkgcolor);
//    pButtonAdd->setStyleSheet("QPushButton{background-color:gray;border-radius:15px;}");
    pButtonAdd->setToolTip("Add");
    connect(pButtonAdd,SIGNAL(clicked()),ui.actionAdd_Model,SLOT(trigger()));


    //--------------------------------B9Edit/Layout------------------------------------
    //scale
    bakgroundScale = new QWidget(pWorldView);
    bakgroundScale->setGeometry(10,height+80,50, 50);
    bakgroundScale->setMask(bmp);
//    bakgroundScale->setStyleSheet("background-color: rgba(208, 219, 230, 0%);");
    pMBW_Size = new MyBallonWidget(pWorldView);
    pMBW_Size->setGeometry(70,height+80,220,250);//70,200,150,155
    size = new sizeWidget(this,pMBW_Size);
    size->setGeometry(10,5,207,240);
    pMBW_Size->setVisible(false);
    QIcon iconScale;
    iconScale.addFile(QString::fromUtf8(":/B9Edit/icons/scale.png"), QSize(), QIcon::Normal, QIcon::Off);//
    pButtonScale = new QPushButton(bakgroundScale);
    pButtonScale->setIcon(iconScale);
    pButtonScale->setIconSize(QSize(50, 50));
    pButtonScale->setGeometry(-10,-10,70,70);//230,350,100,100 border-image: url(:/B9Edit/icons/scale3.png);
    pButtonScale->setStyleSheet(btnbkgcolor);//(bkgcolor);
    pButtonScale->setToolTip("Scale");
    connect(pButtonScale,SIGNAL(clicked()),this,SLOT(on_ButtonScale_clicked()));

    //Rotate
    bakgroundRotate = new QWidget(pWorldView);
    bakgroundRotate->setGeometry(10,height+132,50, 50);
    bakgroundRotate->setMask(bmp);
//    bakgroundRotate->setStyleSheet("background-color: rgba(208, 219, 230, 0%);");
    pMBW_Rotate = new MyBallonWidget(pWorldView);
    pMBW_Rotate->setGeometry(70,height+130,200,210);
    orientation = new OrientationWidget(this,pMBW_Rotate);
    orientation->setGeometry(10,5,190,200);
    pMBW_Rotate->setVisible(false);
    QIcon iconRotate;
    iconRotate.addFile(QString::fromUtf8(":/B9Edit/icons/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
    pButtonRotate = new QPushButton(bakgroundRotate);
    pButtonRotate->setIcon(iconRotate);
    pButtonRotate->setIconSize(QSize(50, 50));
    pButtonRotate->setGeometry(-5,-5,60,60);//10,350,100,100 -10,60,70,70
    pButtonRotate->setStyleSheet(btnbkgcolor);//(bkgcolor);
    pButtonRotate->setToolTip("Rotate");
    connect(pButtonRotate,SIGNAL(clicked()),this,SLOT(on_ButtonRotate_clicked()));

    //Move
    bakgroundMove = new QWidget(pWorldView);
    bakgroundMove->setGeometry(10,height+184,50, 50);
    bakgroundMove->setMask(bmp);
//    bakgroundMove->setStyleSheet("background-color: rgba(208, 219, 230, 0%);");
    pMBW_Position = new MyBallonWidget(pWorldView);
    pMBW_Position->setGeometry(70,height+180,200,170);
    position = new PositionWidget(this,pMBW_Position);
    position->setGeometry(10,5,190,160);
    pMBW_Position->setVisible(false);
    QIcon iconMove;
    iconMove.addFile(QString::fromUtf8(":/B9Edit/icons/move.png"), QSize(), QIcon::Normal, QIcon::Off);
    pButtonMove = new QPushButton(bakgroundMove);
    pButtonMove->setIcon(iconMove);
    pButtonMove->setIconSize(QSize(50, 50));
    pButtonMove->setGeometry(-5,-5,60,60);//-10,130,70,70 120,350,100,100
    pButtonMove->setStyleSheet(btnbkgcolor);//(bkgcolor);
    pButtonMove->setToolTip("Move");
    connect(pButtonMove,SIGNAL(clicked()),this,SLOT(on_ButtonMove_clicked()));

    //--------------------------------support---------------------------------------
    bakgroundSupport = new QWidget(pWorldView);
    bakgroundSupport->setGeometry(10,height+250,50,50);
    bakgroundSupport->setMask(bmp);
//    bakgroundSupport->setStyleSheet(bkgcolor);
    QIcon iconSupOption;
    iconSupOption.addFile(QString::fromUtf8(":/B9Edit/icons/support.png"), QSize(), QIcon::Normal, QIcon::Off);
    pButtonSupport = new QPushButton(bakgroundSupport);
    pButtonSupport->setIcon(iconSupOption);
    pButtonSupport->setIconSize(QSize(50, 50));
    pButtonSupport->setGeometry(-5,-5,60,60);
    pButtonSupport->setStyleSheet(bkgcolor);
    pButtonSupport->setToolTip("Support");
    //option
    //支撑参数设置窗口 pWorldView->geometry().width()
    pMBW_Support = new MyBallonWidget(pWorldView);
    pMBW_Support->setGeometry(70,height+250,355,200);
    pMBW_Support->setVisible(false);
    pSupport = new SupportParameter(pMBW_Support,this);
    pSupport->setGeometry(10,5,345,190);

    connect(pButtonSupport,SIGNAL(clicked()),this,SLOT(on_ButtonSupport_clicked()));
//    connect(pButtonSupport,SIGNAL(enable(bool)),ui.actionSupport,SLOT(setEnabled(bool)));
//    connect(pWorldView,SIGNAL(getGLSize(int,int)),this,SLOT(setViewButton(int,int)));
    connect(pSupport,SIGNAL(setSupportWidget(int)),this,SLOT(OnSetSupprotWidget(int)));


    //-----------------------------------slice-------------------------------
    bakgroundSlice = new QWidget(pWorldView);
    bakgroundSlice->setGeometry(10,height+320,50,50);
    bakgroundSlice->setMask(bmp);
//    bakgroundSlice->setStyleSheet(bkgcolor);
    QIcon iconSlice;
    iconSlice.addFile(QString::fromUtf8(":/B9Edit/icons/slice.png"), QSize(), QIcon::Normal, QIcon::Off);//
    pButtonSlice = new QPushButton(bakgroundSlice);
    pButtonSlice->setIcon(iconSlice);
    pButtonSlice->setIconSize(QSize(50, 50));
    pButtonSlice->setGeometry(-5,-5,60,60);
    pButtonSlice->setStyleSheet(btnbkgcolor);//"background-color: rgba(70,130,180, 100%);"
    pButtonSlice->setToolTip("Slice");
    connect(pButtonSlice,SIGNAL(clicked()),this,SLOT(doSlice()));

    //-----------------------------------print--------------------------------
    bakgroundPrint = new QWidget(pWorldView);
    bakgroundPrint->setGeometry(10,height+390,50,50);
    bakgroundPrint->setMask(bmp);
//    bakgroundPrint->setStyleSheet(bkgcolor);
    QIcon iconPrint;
    iconPrint.addFile(QString::fromUtf8(":/B9Edit/icons/print.png"), QSize(), QIcon::Normal, QIcon::Off);//
    pButtonPrint = new QPushButton(bakgroundPrint);
    pButtonPrint->setIcon(iconPrint);
    pButtonPrint->setIconSize(QSize(50, 50));
    pButtonPrint->setGeometry(-5,-5,60,60);
    pButtonPrint->setStyleSheet(btnbkgcolor);//"background-color: rgba(70,130,180, 100%);"
    pButtonPrint->setToolTip("Print");
    connect(pButtonPrint,SIGNAL(clicked()),this,SLOT(showPrintWindow()));

    //信号和槽
    //    connect(pWorldView,SIGNAL(ComputeComplete(bool)), pButtonModel, SLOT(setEnabled(bool)));
    //    connect(pWorldView,SIGNAL(ComputeComplete(bool)), pButtonLayout, SLOT(setEnabled(bool)));
//        connect(pWorldView,SIGNAL(ComputeComplete(bool)), this, SLOT(setButtonStyleSheet(pButtonSupport,bool)));
//        connect(pWorldView,SIGNAL(ComputeComplete(bool)), pButtonPrint, SLOT(setEnabled(bool)));
//        connect(pWorldView,SIGNAL(ComputeComplete(bool)), pButtonAdd, SLOT(setEnabled(bool)));
//        connect(pWorldView,SIGNAL(ComputeComplete(bool)), pButtonScale, SLOT(setEnabled(bool)));
//        connect(pWorldView,SIGNAL(ComputeComplete(bool)), pButtonRotate, SLOT(setEnabled(bool)));
//        connect(pWorldView,SIGNAL(ComputeComplete(bool)), pButtonMove, SLOT(setEnabled(bool)));
        connect(pWorldView,SIGNAL(ComputeComplete(bool)), this, SLOT(setButtonEnable(bool)));

    //action
    connect(ui.actionNew_Project,SIGNAL(triggered()),this,SLOT(New()));
    connect(ui.actionOpen_Project,SIGNAL(triggered()),this,SLOT(Open()));
    connect(ui.actionSave,SIGNAL(triggered()),this,SLOT(Save()));
    connect(ui.actionSave_As,SIGNAL(triggered()),this,SLOT(SaveAs()));
    connect(ui.actionAdd_Model,SIGNAL(triggered()),this,SLOT(AddModel()));
    connect(ui.actionDelete,SIGNAL(triggered()),this,SLOT(DeleteSelection()));
    connect(ui.actionDuplicate,SIGNAL(triggered()),this,SLOT(DuplicateSelection()));
    connect(ui.actionPrint,SIGNAL(triggered()),this,SLOT(showPrintWindow()));
    connect(ui.actionExportSlice,SIGNAL(triggered()),this,SLOT(doSlice()));
    connect(ui.actionExport_stl,SIGNAL(triggered()),this,SLOT(PromptExportToSTL()));

    //printer
    connect(ui.actionModel_1,SIGNAL(triggered()),this,SLOT(setPrinterToModel1()));
    connect(ui.actionModel_2,SIGNAL(triggered()),this,SLOT(setPrinterToModel2()));

    //B9Edit
    connect(ui.actionMove,SIGNAL(triggered()),this,SLOT(on_ButtonMove_clicked()));
    connect(ui.actionRotate,SIGNAL(triggered()),this,SLOT(on_ButtonRotate_clicked()));
    connect(ui.actionScale,SIGNAL(triggered()),this,SLOT(on_ButtonScale_clicked()));
    connect(ui.actionDrop_To_Floor,SIGNAL(triggered()),this,SLOT(DropSelectionToFloor()));
    connect(ui.actionSupport,SIGNAL(triggered()),this,SLOT(on_ButtonSupport_clicked()));

    //append
    connect(ui.slice,SIGNAL(triggered()),this,SLOT(doSlice()));
    connect(ui.showSlices,SIGNAL(triggered()),this,SLOT(showSliceWindow()));
    connect(ui.actionShow_3D_Model,SIGNAL(triggered()),this,SLOT(showWSfile()));
//    connect(ui.materialCatalog,SIGNAL(triggered()),this,SLOT(showCatalog()));
    connect(ui.actionTerminal,SIGNAL(triggered()),t,SLOT(showIt()));
    connect(ui.actionOption,SIGNAL(triggered()),pPriSetDlg,SLOT(showIt()));


    //view
//    QObject::connect(ui.actionCenter_View,SIGNAL(activated()),pWorldView,SLOT(CenterView()));
    QObject::connect(ui.actionTop_View,SIGNAL(activated()),pWorldView,SLOT(TopView()));
    QObject::connect(ui.actionRight_View,SIGNAL(activated()),pWorldView,SLOT(RightView()));
    QObject::connect(ui.actionFront_View,SIGNAL(activated()),pWorldView,SLOT(FrontView()));
    QObject::connect(ui.actionBack_View,SIGNAL(activated()),pWorldView,SLOT(BackView()));
    QObject::connect(ui.actionLeft_View,SIGNAL(activated()),pWorldView,SLOT(LeftView()));
    QObject::connect(ui.actionBottom_View,SIGNAL(activated()),pWorldView,SLOT(BottomView()));
//Language
    //LanguageInit();
    QObject::connect(ui.actionEnglish,SIGNAL(activated()),this,SLOT(ChangeToEnglish()));
    QObject::connect(ui.actionChinese,SIGNAL(activated()),this,SLOT(ChangeToChinese()));

}

void MainWindow::on_ButtonScale_clicked()
{
    if(bPos) on_ButtonMove_clicked();
    if(bRot) on_ButtonRotate_clicked();
    if(bSup) on_ButtonSupport_clicked();
    bSize = !bSize;
    pMBW_Size->setVisible(bSize);
    if(bSize)
        SetToolModelScale();
    else
        SetToolModelSelect();
}

void MainWindow::on_ButtonRotate_clicked()
{
//    if(bView) on_ButtonView_clicked();
    if(bSize) on_ButtonScale_clicked();
    if(bPos) on_ButtonMove_clicked();
    if(bSup) on_ButtonSupport_clicked();
    bRot = !bRot;
    pMBW_Rotate->setVisible(bRot);
    if(bRot)
        SetToolModelOrientate();
    else
        SetToolModelSelect();
}

void MainWindow::on_ButtonMove_clicked()
{
//    if(bView) on_ButtonView_clicked();
    if(bSize) on_ButtonScale_clicked();
    if(bRot) on_ButtonRotate_clicked();
    if(bSup) on_ButtonSupport_clicked();
    bPos = !bPos;
    pMBW_Position->setVisible(bPos);
    SetToolModelMove();
    if(bPos)
        SetToolModelMove();
    else
        SetToolModelSelect();
}

void MainWindow::on_ButtonAuto_clicked()
{
    setButtonEnable(false);
    B9SupportStructure temp;//必须有，否则可能显示不了支撑
    disconnect(pWorldView->pDrawTimer, SIGNAL(timeout()), pWorldView, SLOT(UpdateTick()));
    pWorldView->m_autoSupport->start();

}

void MainWindow::on_ButtonSupport_clicked(bool isSupport)
{
//    if(bView) on_ButtonView_clicked();
    if(bSize) on_ButtonScale_clicked();
    if(bRot) on_ButtonRotate_clicked();
    if(bPos) on_ButtonMove_clicked();
//    bSup = !bSup;
//    SetSupportMode(bSup);
//    pMBW_Support->setVisible(bSup);
//    if(!bSup)
//        setButtonEnable(false);
//    setButtonStyle(false,false,true);
    bSup = !bSup;
    SetSupportMode(bSup);
    if(!bSup){
        SetToolModelSelect();
    }
    pMBW_Support->setVisible(bSup);
    setButtonStyleSheet(pButtonAdd,!bSup);
}


void MainWindow::setButtonEnable(bool enable)
{
//    pButtonModel->setEnabled(enable);
//    pButtonLayout->setEnabled(enable);
//    pButtonSupport->setEnabled(enable);
//    pButtonSlice->setEnabled(enable);
//    pButtonPrint->setEnabled(enable);
//    setButtonStyleSheet(pButtonModel,enable);
    setButtonStyleSheet(pButtonScale,enable);
    setButtonStyleSheet(pButtonRotate,enable);
    setButtonStyleSheet(pButtonMove,enable);
    setButtonStyleSheet(pButtonSupport,enable);
//    setButtonStyleSheet(pButtonSlice,enable);
    setButtonStyleSheet(pButtonPrint,enable);
    ui.actionSupport->setEnabled(enable);
}

void MainWindow::setWidgetVisible(bool enable)
{
    bakgroundAdd->setVisible(enable);
    bakgroundScale->setVisible(enable);
    bakgroundRotate->setVisible(enable);
    bakgroundMove->setVisible(enable);
    bakgroundSupport->setVisible(enable);
    bakgroundSlice->setVisible(enable);
    bakgroundPrint->setVisible(enable);
    pMBW_Size->setVisible(false);
    pMBW_Rotate->setVisible(false);
    pMBW_Position->setVisible(false);
    pMBW_Support->setVisible(false);

//    setButtonStyleSheet(pButtonAdd,enable);
//    setButtonStyleSheet(pButtonScale,enable);
//    setButtonStyleSheet(pButtonRotate,enable);
//    setButtonStyleSheet(pButtonMove,enable);
//    setButtonStyleSheet(pButtonSupport,enable);
//    setButtonStyleSheet(pButtonSlice,enable);
//    setButtonStyleSheet(pButtonPrint,!enable);

//    curNumOfLayersSlider->setVisible(!enable);
    ui.menuEdit->setEnabled(enable);
    ui.menuSlice->setEnabled(enable);
    ui.menuTools->setEnabled(enable);
    ui.actionExport->setEnabled(enable);
//    ui.actionExport_stl->setEnabled(enable);
    ui.actionExportSlice->setEnabled(enable);
    ui.actionSave->setEnabled(enable);
    ui.actionSave_As->setEnabled(enable);
    ui.actionOpen_Project->setEnabled(enable);
//    ui.actionPrint->setEnabled(!enable);
    ui.menuPrinter->setEnabled(enable);

//    status->setPrintModel(!enable);
}

void MainWindow::setButtonStyleSheet(QPushButton *btn, bool enable)
{
    btn->setEnabled(enable);
    if(enable){
        btn->setStyleSheet(btnbkgcolor);//"background-color: rgba(70,130,180, 100%);"
    }
    else{
        btn->setStyleSheet("background-color: rgba(100,100,100, 100%);");
    }
}

void MainWindow::RemoveAllSupports()
{
    currInstanceInSupportMode->RemoveAllSupports();
}


void MainWindow::doSlice()
{
//    project->SetPixelThickness(pModelList->getThickness());
//    project->SetPixelThickness(status->getThickness());
//    SliceWorld();
    SliceDialog dlg(this);
    dlg.exec();

}



void MainWindow::showSliceWindow()
{
    QFileDialog dialog(0);
    QSettings settings("Dir");
    QString openFile = dialog.getOpenFileName(this,"Select Nepho3d_Studio Slice File", settings.value("WorkingDir").toString(), tr("Nepho3d File (*.n3d)"));//cyp .b9j
    if(openFile.isEmpty()) return;
    settings.setValue("WorkingDir", QFileInfo(openFile).absolutePath());


    cPJ.clearAll();

    QFile file(openFile);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("Error Loading File.  Unknown Version?");//"");
        msgBox.setToolTip("文件加载错误。未知版本？");
        msgBox.exec();
        return;
    }
    QDataStream in(&file);
    if(!cPJ.loadCPJ(in)) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("Error Loading File.  Unknown Version?");//"");
        msgBox.setToolTip("文件加载错误。未知版本？");
        msgBox.exec();
        return;
    }
    pSliceView = new ShowSlices(this,NULL);
    pSliceView->pCPJ = &cPJ;
    pSliceView->GoToSlice(0);
    pSliceView->UpdateWidgets();

    pSliceView->show();
}

bool matchLine(std::vector<_Line > &vecLine, _Line l)//QVector2D p1, QVector2D p2
{
//    bool isFound=false;
    for(unsigned int i=0;i<vecLine.size();i++){
//        if((vecLine[i].p1==p1&&vecLine[i].p2==p2) || (vecLine[i].p1==p2&&vecLine[i].p2==p1)){
        if(vecLine[i]==l){
            vecLine[i].isSingle = false;
//            isFound = true;
            return true;
        }
    }
    vecLine.push_back(l);//_Line(p1,p2)
    return false;
}

void MainWindow::showPrintWindow()
{//show .n3d
//    m_pCPJ = newCPJ;
    pw->setCPJ(newCPJ);
    pw->show();
    return;

}

void MainWindow::showPrintWindow1()
{//show .ws
    //first check if the user needs to save what hes working on first.
    if(project->IsDirtied())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("This will clear all the models.");//The current layout has been modified.
         msgBox.setInformativeText("Do you want to save your changes before opening?");//
         msgBox.setToolTip("将清空所有模型\n打开之前要保存吗？");//当前布局已被修改
         msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
//         msgBox.setButtonText(QMessageBox::Save, "保存");
//         msgBox.setButtonText(QMessageBox::Discard, "不保存");
//         msgBox.setButtonText(QMessageBox::Cancel, "取消");
         msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret)
        {
          case QMessageBox::Save:
                SaveAs();
              break;
          case QMessageBox::Discard:
                //do nothing
              break;
          case QMessageBox::Cancel:
            return ;
              break;
          default:
              break;
        }
    }
    New();

    QFileDialog dialog(0);
    QSettings settings("Dir");
    QString openFile = dialog.getOpenFileName(this,"Select nepho3d File", settings.value("WorkingDir").toString(), tr("nepho3d File (*.n3d)"));//cyp .b9j
    if(openFile.isEmpty()) return;
    settings.setValue("WorkingDir", QFileInfo(openFile).absolutePath());

    m_pCPJ->clearAll();

//    CrushedPrintJob *newPCJ = new CrushedPrintJob;
    QFile file(openFile);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("Error Loading File.  Unknown Version?");//"");
        msgBox.setToolTip("文件加载错误。未知版本？");
        msgBox.exec();
        return;
    }
    QDataStream in(&file);
    if(!m_pCPJ->loadCPJ(in)) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("Error Loading File.  Unknown Version?");//"");
        msgBox.setToolTip("文件加载错误。未知版本？");
        msgBox.exec();
        return;
    }

    ModelData* pNewModel = new ModelData(this, false);
    Triangle3D newtri;
    float xp, yp, zp;
    float nx,ny,nz;
    float x0,y0,z0;
    float x1,y1,z1;
    float x2,y2,z2;
    int cnt = 0;
    QString buff;
    in>>buff;//beginSTL
    in>>buff;//mesh
    while(buff == "mesh"){
        in >> nx >> ny >> nz;
        in >> x0 >> y0 >> z0;
        in >> x1 >> y1 >> z1;
        in >> x2 >> y2 >> z2;
        newtri.normal.setX(nx);
        newtri.normal.setY(ny);
        newtri.normal.setZ(nz);
        newtri.vertex[0].setX(x0);
        newtri.vertex[0].setY(y0);
        newtri.vertex[0].setZ(z0);
        newtri.vertex[1].setX(x1);
        newtri.vertex[1].setY(y1);
        newtri.vertex[1].setZ(z1);
        newtri.vertex[2].setX(x2);
        newtri.vertex[2].setY(y2);
        newtri.vertex[2].setZ(z2);
        //use right hand rule for importing normals - ignore file normals..
        newtri.UpdateNormalFromGeom();
        newtri.UpdateBounds();
        pNewModel->triList.push_back(newtri);
        in>>buff;
        cnt++;
    }
    in >> xp >> yp >> zp;

    int numSlice,numLoop,numTriangles;
    double thickness = m_pCPJ->getZLayermm();
    pNewModel->ZLayermm = thickness;
    unsigned int i,j,k;
    in>>buff;//beginData
    in>>numSlice;
    for(i=0;i<numSlice;i++){
        std::vector<std::vector<QVector2D> > vecLoop;
        in>>buff;//beginSlice
        in>>numLoop;
        for(j=0;j<numLoop;j++){
            std::vector<QVector2D> vecTriangels;
            in>>buff;//beginLoop
            in>>numTriangles;
            for(k=0;k<numTriangles;){
                in >> x0 >> y0;
                in >> x1 >> y1;
                in >> x2 >> y2;
                k += 3;
                vecTriangels.push_back(QVector2D(x0,y0));
                vecTriangels.push_back(QVector2D(x1,y1));
                vecTriangels.push_back(QVector2D(x2,y2));
            }
            vecLoop.push_back(vecTriangels);
//            pNewModel->mapSlice[i].push_back(vecLoop);
        }
//        mapSlice[i]=vecLoop;
//        break;
    }

    file.close();

//    return;
//    pNewModel->CenterModel();
//    int displaySuccess = pNewModel->FormSliceDisplayLists2();
//    if(!displaySuccess)
//        return;
    ModelDataList.push_back(pNewModel);
    B9ModelInstance* pNewInst = pNewModel->AddInstance();
    if(pNewInst != NULL)
    {
//        pNewInst->SetPos(QVector3D(xp,yp,zp));//
        pNewInst->UpdateBounds();//in order that zhieght is good and all.
        SelectOnly(pNewInst);
//        DropSelectionToFloor();
    }

    m_pCPJ->showSupports(true);
    m_pCPJ->setName(openFile);//cyp

    pw->setCPJ(m_pCPJ);
//    pw = new PrintWindow(m_pCPJ,t);
//    connect (pw, SIGNAL(accepted()),this,SLOT(doPrint()));
//    pw->show();
}


void MainWindow::on_curNumOfLayers(int num)
{
    ModelData* pModel = ModelDataList[0];
//    pModel->FormSliceDisplayLists(num);
    B9ModelInstance* pInst = pModel->instList[0];
    pInst->num = num;
}

//returns a list of the currently selected instances
std::vector<B9ModelInstance*> MainWindow::GetSelectedInstances()
{
    std::vector<B9ModelInstance*> insts;
    int i;
    for(i = 0; i < GetAllInstances().size();i++)
    {
        B9ModelInstance* inst = GetAllInstances()[i];

        if(inst->isselected)
        {
            insts.push_back(inst);
        }
    }
    return insts;
//    return pModelList->GetSelectedInstances();
}
std::vector<B9ModelInstance*> MainWindow::GetAllInstances()
{
    unsigned int d, i;
    std::vector<B9ModelInstance*> allInsts;

    for(d = 0; d < ModelDataList.size(); d++)
    {
        for(i = 0; i < ModelDataList[d]->instList.size(); i++)
        {
            allInsts.push_back(ModelDataList[d]->instList[i]);
        }
    }

    return allInsts;


}




//////////////////////////////////////////////////////
//Public Slots
//////////////////////////////////////////////////////

//Base Plate creation and destruction is handled here in addition to other base plate properties.
void MainWindow::OnBasePlatePropertiesChanged()
{
    B9SupportStructure* basePlate;

    if(SupportModeInst() == NULL)
        return;


    basePlate = SupportModeInst()->GetBasePlate();

    //cyp checkBoxSupportBase
    //Creation/Destruction
    if(/*ui.Foundation_action->isChecked()*/pSupport->getBaseIsChecked() && (basePlate == NULL))
    {
        SupportModeInst()->EnableBasePlate();
    }

    if(/*!ui.Foundation_action->isChecked()*/!pSupport->getBaseIsChecked() && (basePlate != NULL))
    {
        SupportModeInst()->DisableBasePlate();
    }

    //check again
    basePlate = SupportModeInst()->GetBasePlate();

    if(basePlate != NULL)
    {
        basePlate->SetBottomAttachShape(pSettings->m_baseAttachShape);//cyp"Cylinder"

        basePlate->SetBottomRadius(pSettings->m_dBaseRadius);//actualRad

        basePlate->SetBottomLength(pSettings->m_dBaseLength/*0.5ui.Support_Base_Length_lineB9Edit->text().toDouble()*/);
    }

    UpdateInterface();
}



void MainWindow::ResetSupportLight()//connected to push button will always use hardcoded values!
{
    B9SupportStructure::FillRegistryDefaults(true,"LIGHT");
    if(pWorldView->GetTool() == "SUPPORTADD")
    {
        FillSupportParamsWithDefaults();

        ui.Support_Reset_Heavy_button->setChecked(false);
        ui.Support_Reset_Medium_button->setChecked(false);
    }
    UpdateInterface();
}
void MainWindow::ResetSupportMedium()//connected to push button will always use hardcoded values!
{
    B9SupportStructure::FillRegistryDefaults(true,"MEDIUM");
    if(pWorldView->GetTool() == "SUPPORTADD")
    {
        FillSupportParamsWithDefaults();

        ui.Support_Reset_Heavy_button->setChecked(false);
        ui.Support_Reset_Light_button->setChecked(false);
    }
    UpdateInterface();
}
void MainWindow::ResetSupportHeavy()//connected to push button will always use hardcoded values!
{
    B9SupportStructure::FillRegistryDefaults(true,"HEAVY");
    if(pWorldView->GetTool() == "SUPPORTADD")
    {
        FillSupportParamsWithDefaults();

        ui.Support_Reset_Light_button->setChecked(false);
        ui.Support_Reset_Medium_button->setChecked(false);
    }
    UpdateInterface();
}

//fill the support parameter box will default params.
void MainWindow::FillSupportParamsWithDefaults()
{
//    int indx;

    QSettings appSettings;
    appSettings.beginGroup("USERSUPPORTPARAMS");

        pSettings->m_dTopRadius = appSettings.value("TopRadius").toDouble();
        pSettings->m_dTopLength = appSettings.value("TopLength").toDouble();
        pSettings->m_dTopPenetration = appSettings.value("TopPenetration").toDouble();
        pSettings->m_dTopAngleFactor = appSettings.value("TopAngleFactor").toDouble();

        pSettings->m_dMidRadius = appSettings.value("MidRadius").toDouble();

        pSettings->m_dBottomRadius = appSettings.value("BottomRadius").toDouble();
        pSettings->m_dBottomLength = appSettings.value("BottomLength").toDouble();
        pSettings->m_dBottomPenetration = appSettings.value("BottomPenetration").toDouble();
        pSettings->m_dBottomAngleFactor = appSettings.value("BottomAngleFactor").toDouble();
    appSettings.endGroup();
}


//file
void MainWindow::New()
{
    this->setWindowTitle(QString("Nepho3D_Studio"));
    setWidgetVisible(true);
    if(bSize) on_ButtonScale_clicked();
    if(bPos) on_ButtonMove_clicked();
    if(bRot) on_ButtonRotate_clicked();
    if(bSup) on_ButtonSupport_clicked();
//    SetSupportMode(false);
    RemoveAllInstances(); //remove instances.
    project->New();
    project->SetDirtied(false);//because UpdatingBuildSpaceUI dirties things in a round about way.
    pWorldView->CenterView();
//    pButtonSupport->setEnabled(false);
//    pButtonSlice->setEnabled(false);
    setButtonStyleSheet(pButtonSupport,false);
    setButtonStyleSheet(pButtonSlice,false);
    ui.actionSupport->setEnabled(false);
    ui.slice->setEnabled(false);
    ui.actionSupport->setEnabled(false);
    ui.actionExportSlice->setEnabled(false);
    ui.actionSave->setEnabled(false);
    ui.actionSave_As->setEnabled(false);
//    ui.Foundation_action->setEnabled(false);
    UpdateInterface();

}
QString MainWindow::Open(bool withoutVisuals)
{
    bool success;

    QSettings settings("Dir");


    //first check if the user needs to save what hes working on first.
    if(project->IsDirtied())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("The current layout has been modified.");//
         msgBox.setInformativeText("Do you want to save your changes before opening?");//
         msgBox.setToolTip("当前布局已被修改\n打开之前要保存吗？");
         msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
//         msgBox.setButtonText(QMessageBox::Save, "保存");
//         msgBox.setButtonText(QMessageBox::Discard, "不保存");
//         msgBox.setButtonText(QMessageBox::Cancel, "取消");
         msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret)
        {
          case QMessageBox::Save:
                SaveAs();
              break;
          case QMessageBox::Discard:
                //do nothing
              break;
          case QMessageBox::Cancel:
            return "";
              break;
          default:
              break;
        }
    }


//    QString filename = QFileDialog::getOpenFileName(this,WINSUN stl File (*.wstl);;WINSUN Slice File (*.ws)
//             tr("选择布局文件"), appSettings.value("WorkingDir").toString(), tr("WINSUN 布局文件 (*.wstl)"));
//    QString filename = QFileDialog::getOpenFileName(this,
//             tr("Select .wstl / .ws"), settings.value("WorkingDir").toString(), tr("*.wstl *.ws;;WINSUN stl File (*.wstl);;WINSUN Slice File (*.ws)"));
    QString filename = QFileDialog::getOpenFileName(this,
             tr("Select .nstl"), settings.value("WorkingDir").toString(), tr("*.nstl;"));


    if(filename.isEmpty())
    {return "";}

    showWSTLfile(filename);

    return filename;

}

void MainWindow::showWSTLfile(QString filepath)
{
    pWorldView->pDrawTimer->stop();
    QApplication::setOverrideCursor(Qt::WaitCursor);

    SetSupportMode(false);
//    bSup = true;
//    on_ButtonSupport_clicked();
    RemoveAllInstances(); //remove instances.

    bool success = project->Open(filepath,false);

    //lets update some of the UI stuff to match what we just loaded.
    pWorldView->UpdatePlasmaFence();

    QApplication::restoreOverrideCursor();
    if(!success)
    {
        QMessageBox::warning(this, tr("MainWindow"), tr("Open Failed"),QMessageBox::Ok);//打开失败

        return;
    }
    project->UpdateZSpace();

    CleanModelData();// now delete unneeded model data

    //set recent directory.
    QSettings settings("Dir");
    settings.setValue("WorkingDir", QFileInfo(filepath).absolutePath());

    ui.actionExportSlice->setEnabled(true);
    ui.slice->setEnabled(true);
    setButtonStyleSheet(pButtonSlice,true);
//    pButtonSlice->setEnabled(true);
    ui.actionSave->setEnabled(true);
    ui.actionSave_As->setEnabled(true);
//    pButtonSupport->setEnabled(false);

    SetToolModelSelect();
    this->setWindowTitle(QString("Nepho3d_Studio-"+filepath));

    pWorldView->pDrawTimer->start();
}

void MainWindow::showWSfile(/*QString filepath*/)
{
//    pWorldView->pDrawTimer->stop();
    New();
    QSettings settings("Dir");


    //first check if the user needs to save what hes working on first.
    if(project->IsDirtied())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("The current layout has been modified.");//
         msgBox.setInformativeText("Do you want to save your changes before opening?");//
         msgBox.setToolTip("当前布局已被修改\n打开之前要保存吗？");
         msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
//         msgBox.setButtonText(QMessageBox::Save, "保存");
//         msgBox.setButtonText(QMessageBox::Discard, "不保存");
//         msgBox.setButtonText(QMessageBox::Cancel, "取消");
         msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret)
        {
          case QMessageBox::Save:
                SaveAs();
              break;
          case QMessageBox::Discard:
                //do nothing
              break;
          case QMessageBox::Cancel:
            return ;
              break;
          default:
              break;
        }
    }


    QString filename = QFileDialog::getOpenFileName(this,
             tr("Select .n3d"), settings.value("WorkingDir").toString(), tr("*.n3d;"));


    if(filename.isEmpty())
    {return ;}

    RemoveAllInstances();

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("Error Loading File.  Unknown Version?");//"");
        msgBox.setToolTip("文件加载错误。未知版本？");
        msgBox.exec();
        return;
    }
    QDataStream in(&file);
//    newCPJ = new CrushedPrintJob;
    CrushedPrintJob *tempCPJ = new CrushedPrintJob();
    if(!tempCPJ->loadCPJ(in)) {
        tempCPJ->clearAll();
        delete tempCPJ;
        tempCPJ = NULL;
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("Error Loading File.  Unknown Version?");//"");
        msgBox.setToolTip("文件加载错误。未知版本？");
        msgBox.exec();
        return;
    }
    if(newCPJ){
        newCPJ->clearAll();
        delete newCPJ;
    }
    newCPJ = tempCPJ;
    if(newCPJ->getPrinter()=="M50")
        setPrinterToModel1();
    else
        setPrinterToModel2();
    ModelData* pNewModel = new ModelData(this, false);
    Triangle3D newtri;
    float xp, yp, zp;
    float nx,ny,nz;
    float x0,y0,z0;
    float x1,y1,z1;
    float x2,y2,z2;
    int cnt = 0;
    QString buff;
    in>>buff;//beginSTL
    in>>buff;//mesh
    while(buff == "mesh"){
        in >> nx >> ny >> nz;
        in >> x0 >> y0 >> z0;
        in >> x1 >> y1 >> z1;
        in >> x2 >> y2 >> z2;
        newtri.normal.setX(nx);
        newtri.normal.setY(ny);
        newtri.normal.setZ(nz);
        newtri.vertex[0].setX(x0);
        newtri.vertex[0].setY(y0);
        newtri.vertex[0].setZ(z0);
        newtri.vertex[1].setX(x1);
        newtri.vertex[1].setY(y1);
        newtri.vertex[1].setZ(z1);
        newtri.vertex[2].setX(x2);
        newtri.vertex[2].setY(y2);
        newtri.vertex[2].setZ(z2);
        //use right hand rule for importing normals - ignore file normals..
        newtri.UpdateNormalFromGeom();
        newtri.UpdateBounds();
        pNewModel->triList.push_back(newtri);
        in>>buff;
        cnt++;
    }
    in >> xp >> yp >> zp;
    pNewModel->CenterModel();
    int displaySuccess = pNewModel->FormNormalDisplayLists();
    if(!displaySuccess)
        return;
    ModelDataList.push_back(pNewModel);
    B9ModelInstance* pNewInst = pNewModel->AddInstance();
    if(pNewInst != NULL)
    {
        pNewInst->SetPos(QVector3D(xp,yp,zp));//
        pNewInst->UpdateBounds();//in order that zhieght is good and all.
        SelectOnly(pNewInst);
//        DropSelectionToFloor();
    }

    setWidgetVisible(false);

    newCPJ->showSupports(true);
    newCPJ->setName(filename);//cyp

    this->setWindowTitle(QString("Nepho3d_Studio-"+filename));

//    pWorldView->pDrawTimer->start();

    return;

}

void MainWindow::Save()
{
    if(project->GetFileName() == "untitled")
    {
        SaveAs();
    }
    else
    {
        project->Save(project->GetFileName());
    }
}
void MainWindow::SaveAs()
{
    bool success;

    QSettings settings("Dir");

    QString filename = CROSS_OS_GetSaveFileName(this, tr("Save"),
                    settings.value("WorkingDir").toString(),
                                                tr("Nepho3d_Studio stl (*.nstl)"),QStringList("nstl"));
    if(filename.isEmpty())
    {
        return;
    }

    success = project->Save(filename);
    if(!success)
    {
        QMessageBox::warning(this, tr("MainWindow"), tr("保存失败"),QMessageBox::Ok);
        return;
    }

    settings.setValue("WorkingDir",QFileInfo(filename).absolutePath());
}

//interface
void MainWindow::SetXYPixelSizePreset(QString size)
{
    project->SetPixelSize(size.toDouble());
    project->CalculateBuildArea();
//    UpdateExtentsUI();
}

void MainWindow::SetZLayerThickness(QString thick)
{
    project->SetPixelThickness(thick.toDouble());
//    project->CalculateBuildArea();
//    UpdateExtentsUI();
}

void MainWindow::SetProjectorX(QString x)
{
    project->SetResolution(QVector2D(x.toInt(),project->GetResolution().y()));
    project->CalculateBuildArea();
}
void MainWindow::SetProjectorY(QString y)
{
    project->SetResolution(QVector2D(project->GetResolution().x(),y.toInt()));
    project->CalculateBuildArea();
}
void MainWindow::SetProjectorPreset(int index)
{
    switch(index)
    {
        case 0://家用投影仪
            SetProjectorX(QString().number(1024));
            SetProjectorY(QString().number(768));

            break;
        case 1://LCR4500
            SetProjectorX(QString().number(1280));
            SetProjectorY(QString().number(800));

            break;
        default:
            break;

    }
//    UpdateExtentsUI();

}

void MainWindow::SetZHeight(QString z)
{
    project->SetBuildSpaceSize(QVector3D(project->GetBuildSpace().x(),project->GetBuildSpace().x(), z.toDouble()));

}

void MainWindow::SetAttachmentSurfaceThickness(QString num)
{
    project->SetAttachmentSurfaceThickness(num.toDouble());
}

void MainWindow::UpdateInterface()
{
    pModelList->UpdateInterface();
    size->UpdateInterface();
    orientation->UpdateInterface();
    position->UpdateInterface();

    if(pModelList->GetSelectedItem().size() <= 0 )//no items selected.
    {
        ui.actionDuplicate->setEnabled(false);
        ui.actionDelete->setEnabled(false);
    }
    else if(pWorldView->GetTool() != "SUPPORTADD")//1 or more items selected
    {
        SupportModeInst();
        ui.actionDuplicate->setEnabled(true);
        ui.actionDelete->setEnabled(true);
    }
    if(pModelList->GetSelectedItem().size() <= 0 || pModelList->GetSelectedItem().size() > 1)
        //no or multiple items selected.
    {
//        pButtonSupport->setEnabled(false);
        ui.actionSupport->setEnabled(false);
        setButtonStyleSheet(pButtonSupport,false);
//        setButtonStyleSheet(pButtonSlice,false);
//        ui.menuSupport->setEnabled(false);

    }
    else if(pWorldView->GetTool() != "SUPPORTADD") //exactly ONE object selected
    {
//        pButtonSupport->setEnabled(true);
        ui.actionSupport->setEnabled(true);
        setButtonStyleSheet(pButtonSupport,true);
        setButtonStyleSheet(pButtonSlice,true);
    }

    //refresh support structure tab as well.
    if(SupportModeInst() != NULL)//in support mode
    {
        if(pWorldView->GetTool() == "SUPPORTADD")
        {
            //start off with the right button checked
            QSettings appSettings;
            appSettings.beginGroup("USERSUPPORTPARAMS");
            QString weight = appSettings.value("ADDPRESETWEIGHT","LIGHT").toString();
            if(weight == "LIGHT") ui.Support_Reset_Light_button->setChecked(true);
            if(weight == "MEDIUM") ui.Support_Reset_Medium_button->setChecked(true);
            if(weight == "HEAVY") ui.Support_Reset_Heavy_button->setChecked(true);
        }
    }
    else//out of support mode
    {
//        UpdateExtentsUI();

    }

}

void MainWindow::OnModelSpinSliderReleased()
{
    for(unsigned int i = 0; i < GetSelectedInstances().size(); i++)
    {
        GetSelectedInstances()[i]->UpdateBounds();
    }
    UpdateInterface();
}

//tools interface
void MainWindow::SetTool(QString toolname)
{
    if(toolname == "MODELSELECT")
        SetToolModelSelect();
    else if(toolname == "MODELMOVE")
        SetToolModelMove();
    else if(toolname == "MODELSPIN")
        SetToolModelSpin();
    else if(toolname == "MODELORIENTATE")
        SetToolModelOrientate();
    else if(toolname == "MODELSCALE")
        SetToolModelScale();
    else if(toolname == "SUPPORTADD")
        SetToolSupportAdd();
    else if(toolname == "SUPPORTDELETE")
        SetToolSupportDelete();
}

void MainWindow::SetToolModelSelect()
{
    pWorldView->SetTool("MODELSELECT");
    ui.actionMove->setChecked(false);
    ui.actionRotate->setChecked(false);
    ui.actionScale->setChecked(false);
}
void MainWindow::SetToolModelMove()
{
    pWorldView->SetTool("MODELMOVE");
    ui.actionMove->setChecked(true);
    ui.actionRotate->setChecked(false);
    ui.actionScale->setChecked(false);
}
void MainWindow::SetToolModelSpin()
{
    pWorldView->SetTool("MODELSPIN");
//    ui.actionOrientate->setChecked(false);
    ui.actionRotate->setChecked(true);
    ui.actionMove->setChecked(false);
//    ui.actionSelection->setChecked(false);
    ui.actionScale->setChecked(false);
}
void MainWindow::SetToolModelOrientate()
{
    pWorldView->SetTool("MODELORIENTATE");
//    ui.actionOrientate->setChecked(true);
    ui.actionRotate->setChecked(true);
    ui.actionMove->setChecked(false);
//    ui.actionSelection->setChecked(false);
    ui.actionScale->setChecked(false);
}

void MainWindow::SetToolModelScale()
{
    pWorldView->SetTool("MODELSCALE");
    ui.actionScale->setChecked(true);
    ui.actionMove->setChecked(false);
//    ui.actionSelection->setChecked(false);
//    ui.actionOrientate->setChecked(false);
    ui.actionRotate->setChecked(false);
}




void MainWindow::ExitToolAction()
{
    pWorldView->ExitToolAction();
}


//support hiding
bool MainWindow::HidingSupports()
{
    return hideSupports;
}

void MainWindow::OnToggleSupportHiding(bool tog)
{
    hideSupports = tog;
}





//model
B9ModelInstance* MainWindow::AddModel(QString filepath, bool bypassVisuals)
{
    QSettings settings("Dir");

    if(filepath.isEmpty())
    {
        filepath = QFileDialog::getOpenFileName(this,
            tr("Open Model"), settings.value("WorkingDir").toString(), tr("Models (*.stl)"));

        //cancel button
        if(filepath.isEmpty())
            return NULL;
    }
    //by this point we should have a valid file path, if we dont - abort.
    if(!QFileInfo(filepath).exists())
    {
        return NULL;
    }

    //if the file has already been opened and is in the project, we dont want to load in another! instead we want to make a new instance
    for(unsigned int i = 0; i < ModelDataList.size(); i++)
    {
        if(ModelDataList[i]->GetFilePath() == filepath)
        {
            return ModelDataList[i]->AddInstance();//make a new instance
        }
    }

    ModelData* pNewModel = new ModelData(this, bypassVisuals);

    bool success = pNewModel->LoadIn(filepath);
    if(!success)
    {
        delete pNewModel;
        return NULL;
    }

    //update registry
    settings.setValue("WorkingDir",QFileInfo(filepath).absolutePath());

    //add to the list
    ModelDataList.push_back(pNewModel);

    //make an Instance of the model!
    B9ModelInstance* pNewInst = pNewModel->AddInstance();
    project->UpdateZSpace();

    //select it too
    SelectOnly(pNewInst);

    ui.slice->setEnabled(true);
    setButtonStyleSheet(pButtonSlice,true);
//    pButtonSlice->setEnabled(true);
    ui.actionExportSlice->setEnabled(true);
    ui.actionSave->setEnabled(true);
    ui.actionSave_As->setEnabled(true);

    return pNewInst;
}

void MainWindow::RemoveAllInstances()
{
    unsigned int m;
    unsigned int i;
    std::vector<B9ModelInstance*> allinstlist;
    for(m=0;m<this->ModelDataList.size();m++)
    {
        ModelDataList[m]->loadedcount = 0;//also reset the index counter for instances!
        for(i=0;i<ModelDataList[m]->instList.size();i++)
        {
            allinstlist.push_back(ModelDataList[m]->instList[i]);
        }
    }
    for(i=0;i<allinstlist.size();i++)
    {
        delete allinstlist[i];
    }

    CleanModelData();

}
void MainWindow::CleanModelData()
{
    unsigned int m;
    std::vector<ModelData*> templist;
    for(m=0;m<ModelDataList.size();m++)
    {
        if(ModelDataList[m]->instList.size() > 0)
        {
            templist.push_back(ModelDataList[m]);
        }
        else
        {
            delete ModelDataList[m];
        }
    }
    ModelDataList.clear();
//    return;
    ModelDataList = templist;
    if(ModelDataList.size() <= 0){
        ui.slice->setEnabled(false);
        setButtonStyleSheet(pButtonSlice,false);
        pButtonSlice->setEnabled(false);
        ui.actionExportSlice->setEnabled(false);
        ui.actionSave->setEnabled(false);
        ui.actionSave_As->setEnabled(false);
    }
}

void MainWindow::AddTagToModelList(QListWidgetItem* item)
{
    //    ui.ModelList->addItem(item);
        pModelList->AddTagToModelList(item);
}

B9ModelInstance* MainWindow::FindInstance(QListWidgetItem* item)
{
    unsigned int d;
    unsigned int i;
    for(d=0;d<ModelDataList.size();d++)
    {
        for(i=0;i<ModelDataList[d]->instList.size();i++)
        {
            if(ModelDataList[d]->instList[i]->listItem == item)
            {
                return ModelDataList[d]->instList[i];
            }
        }
    }
    return NULL;
}


//selection
void MainWindow::RefreshSelectionsFromList()
{
//    int i;
//    for(i=0;i<ui.ModelList->count();i++)
//    {
//        B9ModelInstance* inst = FindInstance(ui.ModelList->item(i));
//        if(inst == NULL)
//            return;

//        if(!ui.ModelList->item(i)->isSelected())
//        {
//            DeSelect(FindInstance(ui.ModelList->item(i)));
//        }
//        else if(ui.ModelList->item(i)->isSelected())
//        {
//            Select(FindInstance(ui.ModelList->item(i)));
//        }
//    }
}
void MainWindow::Select(B9ModelInstance* inst)
{
    //qDebug() << inst << "added to selection";
    inst->SetSelected(true);
    UpdateInterface();
}
void MainWindow::DeSelect(B9ModelInstance* inst)
{
    //qDebug() << inst << "removed from selection";
    inst->SetSelected(false);
    UpdateInterface();
}
void MainWindow::SelectOnly(B9ModelInstance* inst)
{
    DeSelectAll();
    Select(inst);
}

void MainWindow::DeSelectAll()
{
    unsigned int m;
    unsigned int i;
    for(m=0;m<ModelDataList.size();m++)
    {
        for(i=0;i<ModelDataList[m]->instList.size();i++)
        {
            DeSelect(ModelDataList[m]->instList[i]);
        }
    }
}

void MainWindow::SetSelectionPos(double x, double y, double z, int axis)
{
    int i;
    for(i=0;i<pModelList->GetSelectedItem().size();i++)
    {
        B9ModelInstance* inst = FindInstance(pModelList->GetSelectedItem()[i]);
        if(axis==0)
            inst->SetPos(QVector3D(x,y,z));
        else if(axis==1)
            inst->SetPos(QVector3D(x,inst->GetPos().y(),inst->GetPos().z()));
        else if(axis==2)
            inst->SetPos(QVector3D(inst->GetPos().x(),y,inst->GetPos().z()));
        else if(axis==3)
            inst->SetPos(QVector3D(inst->GetPos().x(),inst->GetPos().y(),z + inst->GetPos().z() - inst->GetMinBound().z()));
    }
}
void MainWindow::SetSelectionRot(QVector3D newRot)
{
    int i;
    for(i=0;i<pModelList->GetSelectedItem().size();i++)
    {
        B9ModelInstance* inst = FindInstance(pModelList->GetSelectedItem()[i]);

        inst->SetRot(newRot);
    }
}
void MainWindow::SetSelectionScale(double x, double y, double z, int axis)
{
    int i;
    for(i=0;i<pModelList->GetSelectedItem().size();i++)
    {
        B9ModelInstance* inst = FindInstance(pModelList->GetSelectedItem()[i]);
        if(axis==0)
            inst->SetScale(QVector3D(x,y,z));
        else if(axis==1)
            inst->SetScale(QVector3D(x,inst->GetScale().y(),inst->GetScale().z()));
        else if(axis==2)
            inst->SetScale(QVector3D(inst->GetScale().x(),y,inst->GetScale().z()));
        else if(axis==3)
            inst->SetScale(QVector3D(inst->GetScale().x(),inst->GetScale().y(),z));
    }
}
void MainWindow::SetSelectionFlipped(bool flipped)
{
    unsigned int i;
    std::vector<B9ModelInstance*> instList = GetSelectedInstances();

    for(i=0; i < instList.size(); i++)
    {
        instList[i]->SetFlipped(flipped);
    }

}


void MainWindow::DropSelectionToFloor()
{
    unsigned int i;
    for(i = 0; i < GetSelectedInstances().size(); i++)
    {
        GetSelectedInstances()[i]->RestOnBuildSpace();
    }
    UpdateInterface();
}
void MainWindow::ResetSelectionRotation()
{
    unsigned int i;
    for(i = 0; i < GetSelectedInstances().size(); i++)
    {
        GetSelectedInstances()[i]->SetRot(QVector3D(0,0,0));
        GetSelectedInstances()[i]->UpdateBounds();
    }
    UpdateInterface();
}


void MainWindow::DuplicateSelection()
{
    unsigned int i;
    B9ModelInstance* inst;
    B9ModelInstance* newinst;
    B9ModelInstance* compareinst;
    B9SupportStructure* newSup;
    bool good = true;
    double x;
    double y;
    double xkeep;
    double ykeep;
    std::vector<B9ModelInstance*> sellist = GetSelectedInstances();
    for(i=0;i<sellist.size();i++)
    {
        inst = sellist[i];

        double xsize = inst->GetMaxBound().x() - inst->GetMinBound().x();
        double ysize = inst->GetMaxBound().y() - inst->GetMinBound().y();

        xkeep = 0;
        ykeep = 0;
        for(x = -project->GetBuildSpace().x()*0.5 + xsize/2; x <= project->GetBuildSpace().x()*0.5 - xsize/2; x += xsize + 1)
        {
            for(y = -project->GetBuildSpace().y()*0.5 + ysize/2; y <= project->GetBuildSpace().y()*0.5 - ysize/2; y += ysize + 1)
            {
                good = true;
                for(unsigned int d=0;d<ModelDataList.size();d++)
                {
                    for(unsigned int n=0;n<ModelDataList[d]->instList.size();n++)
                    {
                        compareinst = ModelDataList[d]->instList[n];

                        if(((x - xsize/2) < compareinst->GetMaxBound().x()) && ((x + xsize/2) > compareinst->GetMinBound().x()) && ((y - ysize/2) < compareinst->GetMaxBound().y()) && ((y + ysize/2) > compareinst->GetMinBound().y()))
                        {
                            good = false;
                        }
                    }
                }
                if(good)
                {
                    xkeep = x;
                    ykeep = y;
                }

            }
        }

        newinst = inst->pData->AddInstance();
        newinst->SetPos(QVector3D(xkeep,ykeep,inst->GetPos().z()));
        newinst->SetRot(inst->GetRot());
        newinst->SetScale(inst->GetScale());
        newinst->SetFlipped(inst->GetFlipped());
        newinst->SetBounds(inst->GetMaxBound() + (newinst->GetPos() - inst->GetPos()),
                           inst->GetMinBound() + (newinst->GetPos() - inst->GetPos()));
        newinst->pData->pMain->ProjectData()->UpdateZSpace();//update build space size
        //dup supports
        for(i = 0; i < inst->GetSupports().size(); i++)
        {
            newSup = newinst->AddSupport();
            newSup->CopyFrom(inst->GetSupports()[i]);
            newSup->SetInstanceParent(newinst);

        }//and base plate
        if(inst->GetBasePlate())
        {
            newinst->EnableBasePlate();
            newinst->GetBasePlate()->CopyFrom(inst->GetBasePlate());
            newinst->GetBasePlate()->SetInstanceParent(newinst);
        }

        SelectOnly(newinst);
    }
}

//Upper level del action branching
void MainWindow::DeleteSelection()//delete whatever is selected - support or instance..
{
    if(SupportModeInst())
    {
        DeleteSelectedSupports();
    }
    else
    {
        DeleteSelectedInstances();
    }
}

void MainWindow::DeleteSelectedInstances()
{
    unsigned int i;
    std::vector<B9ModelInstance*> list = GetSelectedInstances();

    if(SupportModeInst())
        return;

    for(i=0;i < list.size();i++)
    {
        delete list[i];
    }
    //cleanup any unnessecary modeldata
    CleanModelData();
    UpdateInterface();
    project->UpdateZSpace();
}



//Support Mode/////////////////////////////////
void MainWindow::SetSupportMode(bool tog)
{
//    pModelList->setEnabled(!tog);
////    pButtonView->setEnabled(!tog);
//    pButtonScale->setEnabled(!tog);
//    pButtonRotate->setEnabled(!tog);
//    pButtonMove->setEnabled(!tog);
    ui.slice->setEnabled(!tog);
//    pButtonSlice->setEnabled(!tog);
    ui.actionExportSlice->setEnabled(!tog);
    ui.actionSave->setEnabled(!tog);
    ui.actionSave_As->setEnabled(!tog);
//    ui.menuB9Edit->setEnabled(!tog);
    ui.actionAdd_Model->setEnabled(!tog);
    ui.actionDelete->setEnabled(!tog);
    ui.actionDuplicate->setEnabled(!tog);
//    ui.actionScale->setEnabled(!tog);
//    ui.actionRotate->setEnabled(!tog);
//    ui.actionMove->setEnabled(!tog);
    ui.actionDrop_To_Floor->setEnabled(!tog);

    setButtonStyleSheet(pButtonSlice,!tog);
//    setButtonEnable(!tog);
//    pButtonModel->setEnabled(!tog);
//    pButtonLayout->setEnabled(!tog);
//    pButtonPrint->setEnabled(!tog);

//    ui.B9EditToolBar->setEnabled(!tog);

    if(tog && (currInstanceInSupportMode == NULL))//go into support mode
    {

        qDebug() << "Entering Support Mode";
//        //make sure weve selected somthing
        if(!GetSelectedInstances().size())
            return;

        //we can assume weve selected something...
        currInstanceInSupportMode = GetSelectedInstances()[0];

       // if the instance is on the ground, raise it so we dont get crunched supports.
        if(currInstanceInSupportMode->GetMinBound().z() < 0.01 && !currInstanceInSupportMode->GetSupports().size())
        {
            oldModelConstricted = true;
            currInstanceInSupportMode->Move(QVector3D(0,0,5));
        }else oldModelConstricted = false;

        currInstanceInSupportMode->SetInSupportMode(true);
        //bake the instance in a manner similar to slice preparation
        //but without support baking!
        currInstanceInSupportMode->BakeGeometry();
        currInstanceInSupportMode->SortBakedTriangles();
        currInstanceInSupportMode->AllocateTriContainers(0.1);
        currInstanceInSupportMode->FillTriContainers();
        currInstanceInSupportMode->FormTriPickDispLists();

        oldZoom = pWorldView->GetZoom();
        oldPan = pWorldView->GetPan();
        oldRot = pWorldView->GetRotation();
        oldTool = pWorldView->GetTool();

        pWorldView->SetRevolvePoint(currInstanceInSupportMode->GetPos());
        pWorldView->SetPan(QVector3D(0,0,0));
        pWorldView->SetZoom(100.0);


        //set tool to support addition
        SetToolSupportAdd();

        pSettings->loadSettings();
        pSettings->saveSettings();
        pSupport->updateDialog();
//        pSupport->show();//cyp 0822
//        pButtonSupport->setEnabled(false);
//        ui.actionSupport->setEnabled(false);
//        setButtonStyleSheet(pButtonSupport,false);
        setButtonStyleSheet(pButtonSlice,false);
        pWorldView->m_thread->start();
//        pWorldView->ComputeVertexNormal();

    }
    else if(!tog && (currInstanceInSupportMode != NULL))
    {
        qDebug() << "Exiting Support Mode";

        if(currInstanceInSupportMode != NULL)
        {
            currInstanceInSupportMode->SetInSupportMode(false);
            currInstanceInSupportMode->FreeTriPickDispLists();
            currInstanceInSupportMode->UnBakeGeometry();
            currInstanceInSupportMode->FreeTriContainers();

            if(oldModelConstricted && !currInstanceInSupportMode->GetSupports().size())
                currInstanceInSupportMode->Move(QVector3D(0,0,-5));
            else
                currInstanceInSupportMode->SetPos(currInstanceInSupportMode->GetPos());//nudge to fix supports

            currInstanceInSupportMode = NULL;
        }
        pWorldView->SetRevolvePoint(QVector3D(0,0,0));
        pWorldView->SetPan(oldPan);
        pWorldView->SetZoom(oldZoom);
        SetTool(oldTool);

//        pSupport->hide();//cyp 0822

    }
    //if entering or leaving we always deselect all supports
    DeSelectAllSupports();

    UpdateInterface();
}

void MainWindow::SetToolSupportAdd()
{
    pWorldView->SetTool("SUPPORTADD");
    //when were adding nothing should be selected
    DeSelectAllSupports();

    UpdateInterface();

    FillSupportParamsWithDefaults();


}

void MainWindow::SetToolSupportDelete()
{
    pWorldView->SetTool("SUPPORTDELETE");
    //when were deleteing nothing should be selected
    DeSelectAllSupports();

    UpdateInterface();
}


B9SupportStructure* MainWindow::FindSupportByName(QString name)
{
    unsigned int s;
    unsigned int searchNum = name.remove("Support ").toInt();
    std::vector<B9SupportStructure*> supList;

    if(!currInstanceInSupportMode)
    {
        qDebug() << "WARNING: finding support out of support mode";
         return NULL;
    }

    supList = currInstanceInSupportMode->GetSupports();

    for(s = 0; s < supList.size(); s++)
    {
        if(searchNum == supList[s]->SupportNumber)
        {
            return supList[s];
        }
    }
    return NULL;
}


B9ModelInstance* MainWindow::SupportModeInst()
{
    return currInstanceInSupportMode;
}


std::vector<B9SupportStructure*>* MainWindow::GetSelectedSupports()
{
    return &currSelectedSupports;
}


bool MainWindow::IsSupportSelected(B9SupportStructure* sup)
{
    unsigned int i;
    for(i = 0; i < currSelectedSupports.size(); i++)
    {
        if(currSelectedSupports[i] == sup)
            return true;
    }

    return false;
}

void MainWindow::DeSelectSupport(B9SupportStructure* sup)
{
    unsigned int s;
    std::vector<B9SupportStructure*> keepers;

    for(s = 0; s < currSelectedSupports.size(); s++)
    {
        if(currSelectedSupports[s] == sup)
        {
            //qDebug() << "Support: " << sup << " removed from selection";
            sup->SetSelected(false);
        }
        else
            keepers.push_back(currSelectedSupports[s]);
    }
    currSelectedSupports.clear();
    currSelectedSupports = keepers;

    UpdateInterface();

}


void MainWindow::DeSelectAllSupports()
{
    //qDebug() << "De-Selecting All Supports, selection list size: " << currSelectedSupports.size();
    while(currSelectedSupports.size())
    {
        DeSelectSupport(currSelectedSupports[0]);
    }
}

void MainWindow::DeleteSelectedSupports()//called from remove button.
{
    unsigned int s;
    if(!SupportModeInst())
        return;

    for(s = 0; s < currSelectedSupports.size(); s++)
    {
        SupportModeInst()->RemoveSupport(currSelectedSupports[s]);
    }
    currSelectedSupports.clear();

    UpdateInterface();
}

void MainWindow::DeleteSupport(B9SupportStructure* pSup)
{
    if(SupportModeInst() != NULL)
    {
        if(IsSupportSelected(pSup))
            DeSelectSupport(pSup);

        SupportModeInst()->RemoveSupport(pSup);
    }

    UpdateInterface();
}

void MainWindow::MakeSelectedSupportsVertical()
{
    unsigned int i;
    B9SupportStructure* pSup;

    if(SupportModeInst() == NULL)
        return;

    for(i = 0; i < currSelectedSupports.size(); i++)
    {
        pSup = currSelectedSupports[i];
        pSup->SetBottomPoint(QVector3D(pSup->GetTopPivot().x(),
                                       pSup->GetTopPivot().y(),
                                       pSup->GetBottomPoint().z()));
    }
}

void MainWindow::MakeSelectedSupportsStraight()
{
    unsigned int i;
    B9SupportStructure* pSup;
    QVector3D lenVec;
    QVector3D topNorm, bottomNorm;

    if(SupportModeInst() == NULL)
        return;


    for(i = 0; i < currSelectedSupports.size(); i++)
    {
        pSup = currSelectedSupports[i];

        lenVec = pSup->GetTopPoint() - pSup->GetBottomPoint();
        lenVec.normalize();

        topNorm = pSup->GetTopNormal();
        bottomNorm = pSup->GetBottomNormal();

        topNorm = lenVec;
        topNorm.normalize();

        bottomNorm = -lenVec;
        bottomNorm.normalize();


        pSup->SetTopNormal(topNorm);
        if(!pSup->GetIsGrounded())
            pSup->SetBottomNormal(bottomNorm);

        pSup->SetTopAngleFactor(1.0);
        if(!pSup->GetIsGrounded())
            pSup->SetBottomAngleFactor(1.0);

    }

    UpdateInterface();
}

//Support Properties changes
void MainWindow::OnSupport_Top_AttachType_Changed(bool updateInterface)
{
    unsigned int i;
    B9SupportStructure* selSup = NULL;
    for(i = 0; i < currSelectedSupports.size(); i++)
    {   selSup = currSelectedSupports[i];
        selSup->SetTopAttachShape(pSettings->m_topAttachShape);//cyp
    }

    if(updateInterface)
    UpdateInterface();

}
void MainWindow::OnSupport_Top_Radius_Changed(bool updateInterface)
{
    unsigned int i;
    B9SupportStructure* selSup = NULL;
    for(i = 0; i < currSelectedSupports.size(); i++)
    {   selSup = currSelectedSupports[i];
        selSup->SetTopRadius(pSettings->m_dTopRadius);//cyp
    }

    if(updateInterface)
    UpdateInterface();

}
void MainWindow::OnSupport_Top_Length_Changed(bool updateInterface)
{
    unsigned int i;
    B9SupportStructure* selSup = NULL;
    for(i = 0; i < currSelectedSupports.size(); i++)
    {   selSup = currSelectedSupports[i];
        selSup->SetTopLength(pSettings->m_dTopLength);//cyp
    }

    if(updateInterface)
    UpdateInterface();

}
void MainWindow::OnSupport_Top_Penetration_Changed(bool updateInterface)
{
    unsigned int i;
    B9SupportStructure* selSup = NULL;
    for(i = 0; i < currSelectedSupports.size(); i++)
    {   selSup = currSelectedSupports[i];
        selSup->SetTopPenetration(pSettings->m_dTopPenetration*0.01);//cyp
    }

    if(updateInterface)
    UpdateInterface();

}
void MainWindow::OnSupport_Top_AngleFactor_Changed(bool updateInterface)
{
    unsigned int i;
    B9SupportStructure* selSup = NULL;
    for(i = 0; i < currSelectedSupports.size(); i++)
    {   selSup = currSelectedSupports[i];
        selSup->SetTopAngleFactor(pSettings->m_dTopAngleFactor*0.01);//cyp
    }

    if(updateInterface)
    UpdateInterface();

}
void MainWindow::OnSupport_Mid_AttachType_Changed(bool updateInterface)
{
    unsigned int i;
    B9SupportStructure* selSup = NULL;
    for(i = 0; i < currSelectedSupports.size(); i++)
    {   selSup = currSelectedSupports[i];
        selSup->SetMidAttachShape(pSettings->m_midAttachShape);//cyp
    }

    if(updateInterface)
    UpdateInterface();
}
void MainWindow::OnSupport_Mid_Radius_Changed(bool updateInterface)
{
    unsigned int i;
    B9SupportStructure* selSup = NULL;
    for(i = 0; i < currSelectedSupports.size(); i++)
    {  selSup = currSelectedSupports[i];
       selSup->SetMidRadius(pSettings->m_dMidRadius);//cyp
    }

    if(updateInterface)
    UpdateInterface();
}
void MainWindow::OnSupport_Bottom_AttachType_Changed(bool updateInterface)
{
    unsigned int i;
    B9SupportStructure* selSup = NULL;
    for(i = 0; i < currSelectedSupports.size(); i++)
    {   selSup = currSelectedSupports[i];
        selSup->SetBottomAttachShape(pSettings->m_bottomAttachShape);
    }

    if(updateInterface)
    UpdateInterface();

}
void MainWindow::OnSupport_Bottom_Radius_Changed(bool updateInterface)
{
    unsigned int i;
    B9SupportStructure* selSup = NULL;
    for(i = 0; i < currSelectedSupports.size(); i++)
    {   selSup = currSelectedSupports[i];
        selSup->SetBottomRadius(pSettings->m_dBottomRadius);
    }

    if(updateInterface)
    UpdateInterface();

}
void MainWindow::OnSupport_Bottom_Length_Changed(bool updateInterface)
{
    unsigned int i;
    B9SupportStructure* selSup = NULL;
    for(i = 0; i < currSelectedSupports.size(); i++)
    {   selSup = currSelectedSupports[i];
        selSup->SetBottomLength(pSettings->m_dBottomLength);
    }

    if(updateInterface)
    UpdateInterface();

}
void MainWindow::OnSupport_Bottom_Penetration_Changed(bool updateInterface)
{
    unsigned int i;
    B9SupportStructure* selSup = NULL;
    for(i = 0; i < currSelectedSupports.size(); i++)
    {   selSup = currSelectedSupports[i];
        selSup->SetBottomPenetration(pSettings->m_dBottomPenetration*0.01);
    }

    if(updateInterface)
    UpdateInterface();

}
void MainWindow::OnSupport_Bottom_AngleFactor_Changed(bool updateInterface)
{
    unsigned int i;
    B9SupportStructure* selSup = NULL;
    for(i = 0; i < currSelectedSupports.size(); i++)
    {   selSup = currSelectedSupports[i];
        selSup->SetBottomAngleFactor(pSettings->m_dBottomAngleFactor*0.01);
    }

    if(updateInterface)
    UpdateInterface();

}



//overall slicing routine, returns success.
bool MainWindow::SliceWorld()
{//cyp
    QSettings settings("Dir");

    QString filename = CROSS_OS_GetSaveFileName(this, tr("Export Slices"),/*导出切片*/
                                                settings.value("WorkingDir").toString() + "/" + ProjectData()->GetJobName(),
                                                tr("Nepho3d_Studio Slice File (*.n3d)"));//cyp .b9j

    if(filename.isEmpty())//cancell button
    {
        return false;
    }

    QString Format = QFileInfo(filename).completeSuffix();
    settings.setValue("WorkingDir",QFileInfo(filename).absolutePath());

    if(Format.toLower() == "n3d")//j
    {
        if(SliceWorldToJob(filename))
        {
//             QMessageBox::information(0,"完成","切片完成\n\n所有切片数据已保存.");
             QMessageBox::information(0,"Finished","Slicing Completed\n\nAll layers sliced and job file saved.");
             return true;
        }
        else
        {
//            QMessageBox::information(0,"取消","切片已取消\n\n保存失败.");
            QMessageBox::information(0,"Canceled","Slicing Canceled\n\nnothing was saved.");
            return false;
        }
    }


    return false;
}

//slicing to a job file!
bool MainWindow::SliceWorldToJob(QString filename)
{
    unsigned int m,i,l,k;
    unsigned int totalSliceOps = 0;
    unsigned int globalLayers;
    int nummodels = 0;
    B9ModelInstance* pInst;
    double zhieght = project->GetBuildSpace().z();
    double thickness = project->GetPixelThickness()*0.001;
    QString jobname = project->GetJobName();
    QString jobdesc = project->GetJobDescription();
    CrushedPrintJob* pMasterJob = NULL;
    Slice* pSlice;
    bool moreSlicesToCome;
//    std::map<int,std::vector<_Line > > mapLine;
//    std::map<int,std::vector<std::vector<QVector2D> > > mapSlice;
//    mapTri.clear();
//    mapLine.clear();
    std::map<int,std::vector<QVector2D > > mapLine;
    std::map<int,std::vector<std::vector<QVector2D> > > mapTri;

    //calculate how many layers we need
    globalLayers = qCeil(zhieght/thickness);//CYP
//    for(i=0;i<globalLayers;i++){
//        mapSlice[i].clear();
//    }

    //calculate how many models there are
    for(m=0;m<ModelDataList.size();m++)
    {
        for(i=0;i<ModelDataList[m]->instList.size();i++)
        {
            pInst = ModelDataList[m]->instList[i];
            totalSliceOps += qCeil((pInst->GetMaxBound().z() - pInst->GetMinBound().z())/thickness);
        }
    }

    //make a loading bar
    LoadingBar progressbar(0, totalSliceOps);
    QObject::connect(&progressbar,SIGNAL(rejected()),this,SLOT(CancelSlicing()));
    progressbar.setDescription("Slicing...");//切片中
    progressbar.setValue(0);
    QApplication::processEvents();


    //make a master job file for use later
    pMasterJob = new CrushedPrintJob();
    QSettings appSettings;
    appSettings.beginGroup("USERSET");
    pMasterJob->setPrinter(appSettings.value("Printer").toString());//status->getPrinter()
    appSettings.endGroup();
    pMasterJob->setName(jobname);
    pMasterJob->setDescription(jobdesc);
    pMasterJob->setXYPixel(QString().number(project->GetPixelSize()/1000));
    pMasterJob->setZLayer(QString().number(project->GetPixelThickness()/1000));
    pMasterJob->clearAll(globalLayers);//fills the master job with the needed layers


    //FOR Each Model Instance
    for(m=0;m<ModelDataList.size();m++)
    {
        for(i=0;i<ModelDataList[m]->instList.size();i++)
        {
            B9ModelInstance* inst = ModelDataList[m]->instList[i];
            inst->PrepareForSlicing(thickness);

            //slice all layers and add to instance's job file
            for(l = 0; l < globalLayers; l++)
            {
                //if we are in the model's z - bounds
                if((double)l*thickness <= inst->GetMaxBound().z() && (double)l*thickness >= inst->GetMinBound().z()-0.5*thickness)
                {
                    inst->pSliceSet->QueNewSlice(l*thickness + thickness*0.5,l);
                }
            }
            if(nummodels == 1)
                inst->pSliceSet->SetSingleModelCompressHint(true);
            else
                inst->pSliceSet->SetSingleModelCompressHint(false);

            do
            {
                pSlice = inst->pSliceSet->ParallelCreateSlices(moreSlicesToCome,pMasterJob);
                if(pSlice != NULL)
                {
//                    if(pSlice->segmentList.size() == 0)
//                        k=0;
//                    for(k = 0;k<pSlice->loopList.size();k++){
//                        if(pSlice->loopList[k].isfill)//只保存填充区域
//                            mapTri[pSlice->layerIndx].push_back(pSlice->loopList[k].triangleStrip);
//                    }
//                    for(k = 0;k<pSlice->segmentList.size();k++){
//                        mapLine[pSlice->layerIndx].push_back(pSlice->segmentList[k]->p1);
//                        mapLine[pSlice->layerIndx].push_back(pSlice->segmentList[k]->p2);
//                    }
//                    mapSlice[pSlice->layerIndx] = pSlice->loopList;
//                    std::vector<Loop> tLoop = mapSlice[pSlice->layerIndx];
//                    std::vector<QVector2D> tTriangles = tLoop[0].triangleStrip;
                    delete pSlice;
                    progressbar.setValue(progressbar.GetValue() + 1);
                    QApplication::processEvents();
                }

                if(cancelslicing)
                {
                    cancelslicing = false;
                    inst->FreeFromSlicing();
                    return false;
                }

            }while(moreSlicesToCome);

            inst->FreeFromSlicing();

//            ExportToSlice(inst->pSliceSet->raster)
        }
    }

    QFile* pf = new QFile(filename);
    if (!pf->open(QIODevice::WriteOnly))
        return false;
    QDataStream out(pf);

    pMasterJob->saveCPJ(out);
    ExportToSTL(out);
//    ExportToSlice(out,mapTri,mapLine);

    pf->close();
    delete pf;
//    delete pMasterJob;
    if(newCPJ){
        newCPJ->clearAll();
        delete newCPJ;
    }
    newCPJ = pMasterJob;
    newCPJ->setName(filename);
    pw->setCPJ(newCPJ);


    pWorldView->makeCurrent();

    cancelslicing = false;

    return true;
}

//slicing to a slc file!
bool MainWindow::SliceWorldToSlc(QString filename)
{
    unsigned int m;
    unsigned int i;
    int l;
    int numlayers;
    int nummodels = 0;

    double zhieght = project->GetBuildSpace().z();
    double thickness = project->GetPixelThickness()*0.001;

    Slice* currSlice = NULL;
    bool moreSlicesToCome;

    //calculate how many layers we need
    numlayers = qCeil(zhieght/thickness);
    //calculate how many models there are
    for(m=0;m<ModelDataList.size();m++)
    {
        for(i=0;i<ModelDataList[m]->instList.size();i++)
        {
            nummodels++;
        }
    }

    //make a loading bar
        LoadingBar progressbar(0, numlayers*nummodels);
        QObject::connect(&progressbar,SIGNAL(rejected()),this,SLOT(CancelSlicing()));
        progressbar.setDescription("Exporting SLC..");
        progressbar.setValue(0);
        QApplication::processEvents();


    //create an slc exporter
    SlcExporter slc(filename.toStdString());
    if(!slc.SuccessOpen())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("Unable To Open Slc File!");//
        msgBox.setToolTip(".slc文件打不开");
        msgBox.exec();
    }
    //write the header
    slc.WriteHeader("heeeeelllllloooooo");
    slc.WriteReservedSpace();
    slc.WriteSampleTableSize(1);
    slc.WriteSampleTable(0.0,float(thickness),0.0f);



    //for each modelinstance
    for(m=0;m<ModelDataList.size();m++)
    {
        for(i=0;i<ModelDataList[m]->instList.size();i++)
        {
            B9ModelInstance* inst = ModelDataList[m]->instList[i];
            inst->PrepareForSlicing(thickness);

            //slice all layers and add to instance's job file
            for(l = 0; l < numlayers; l++)
            {
                //make sure we are in the model's z - bounds
                if(l*thickness <= inst->GetMaxBound().z() && l*thickness >= inst->GetMinBound().z())
                {
                    inst->pSliceSet->QueNewSlice(l*thickness + thickness*0.5,l);
                }
            }

            do
            {
                currSlice = inst->pSliceSet->ParallelCreateSlices(moreSlicesToCome,0);
                if(currSlice != NULL)
                {
                    progressbar.setValue(progressbar.GetValue() + 1);
                    QApplication::processEvents();
                    slc.WriteNewSlice(currSlice->realAltitude, currSlice->loopList.size());
                    currSlice->WriteToSlc(&slc);
                    delete currSlice;
                }


                if(cancelslicing)
                {
                    cancelslicing = false;
                    inst->FreeFromSlicing();
                    return false;
                }

            }while(moreSlicesToCome);



            inst->FreeFromSlicing();
        }
    }

    slc.WriteNewSlice(0.0,0xFFFFFFFF);
    return true;
}


void MainWindow::CancelSlicing()
{
    cancelslicing = true;
}


//exporting
void MainWindow::PromptExportToSTL()
{
    QString filename;
    QSettings settings("Dir");
    filename = CROSS_OS_GetSaveFileName(this, tr("Export To STL"),
                                        settings.value("WorkingDir").toString() + "/" + ProjectData()->GetFileName(),
                                        tr("stl (*.stl)"));

    if(filename.isEmpty())
        return;

    if(ExportToSTL(filename))
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("Stl Export Complete");//
        msgBox.setToolTip("stl导出完成");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Unable To Export stl File");//stl导出失败
        msgBox.setToolTip("stl导出失败");
        msgBox.exec();
    }
}

 bool MainWindow::ExportToSTL(QString filename)
 {
     unsigned int i;
     unsigned long int t;
     B9ModelInstance* pInst = NULL;
     Triangle3D* pTri = NULL;
     bool fileOpened;

     B9ModelWriter exporter(filename, fileOpened);


     if(!fileOpened)
         return false;

     SetSupportMode(false);

     for(i = 0; i < GetAllInstances().size(); i++)
     {
         pInst = GetAllInstances().at(i);
         pInst->BakeGeometry(true);

         for(t = 0; t < pInst->triList.size(); t++)
         {
             pTri = pInst->triList[t];
             exporter.WriteNextTri(pTri);
         }

         pInst->UnBakeGeometry();
     }

     exporter.Finalize();

     return true;
 }

 bool MainWindow::ExportToSTL(QDataStream & out)
 {
     unsigned int i;
     unsigned long int t;
     B9ModelInstance* pInst = NULL;
     Triangle3D* pTri = NULL;
     int triCount;
     int sumTriCount = 0;
     float sum_xp = 0;
     float sum_yp = 0;
     float sum_zp = 0;

     SetSupportMode(false);

     out << (QString)"beginSTL";
     int numInst = GetAllInstances().size();
     float Xmin,Ymin,Zmin,Xmax,Ymax,Zmax;
     Xmin=Ymin=Zmin=99999;
     Xmax=Ymax=Zmax=-99999;

     for(i = 0; i < numInst; i++)
     {
         pInst = GetAllInstances().at(i);
         pInst->BakeGeometry(true);
         if(pInst->GetMinBound().x()<Xmin)
             Xmin = pInst->GetMinBound().x();
         if(pInst->GetMinBound().y()<Ymin)
             Ymin = pInst->GetMinBound().y();
         if(pInst->GetMinBound().z()<Zmin)
             Zmin = pInst->GetMinBound().z();
         if(pInst->GetMaxBound().x()>Xmax)
             Xmax = pInst->GetMaxBound().x();
         if(pInst->GetMaxBound().y()>Ymax)
             Ymax = pInst->GetMaxBound().y();
         if(pInst->GetMaxBound().z()>Zmax)
             Zmax = pInst->GetMaxBound().z();

         triCount = pInst->triList.size();
         sumTriCount += triCount;

         for(t = 0; t < triCount; t++)
         {
             pTri = pInst->triList[t];
//                exporter.WriteNextTri(pTri);
             float nx = pTri->normal.x();
             float ny = pTri->normal.y();
             float nz = pTri->normal.z();

             float x0 = pTri->vertex[0].x();
             float y0 = pTri->vertex[0].y();
             float z0 = pTri->vertex[0].z();

             float x1 = pTri->vertex[1].x();
             float y1 = pTri->vertex[1].y();
             float z1 = pTri->vertex[1].z();

             float x2 = pTri->vertex[2].x();
             float y2 = pTri->vertex[2].y();
             float z2 = pTri->vertex[2].z();

             out<<(QString)"mesh";
             out << nx<<ny<<nz;
             out << x0 <<y0<<z0;
             out << x1 <<y1<<z1;
             out << x2 <<y2<<z2;//<< '\n';

//             loadbar.setProgress(t+1,triCount);
         }
         pInst->UnBakeGeometry();
     }
     out << (QString)"endSTL";
//     out << (float)sum_xp/(float)numInst  <<(float)sum_yp/(float)numInst  << (float)sum_zp/(float)numInst;
     out << (float)(Xmax+Xmin)/2  <<(float)(Ymax+Ymin)/2  << (float)(Zmax+Zmin)/2;

     return true;
 }

 void MainWindow::ExportToSlice(QDataStream & out,
                                std::map<int,std::vector< std::vector < QVector2D > > >& mapTri,
                                std::map<int,std::vector<QVector2D > >& mapLine)
 {
     if(mapTri.size() == 0) return;
     unsigned int i,j,k;
     std::vector<std::vector<QVector2D> > vecLoop;
//     Loop tLoop;
     std::vector<QVector2D> vecTriangles;
//     QVector2D tTriangles;
     int numSlice,numLoop,numTriangles;
     numSlice=mapTri.size();
     out << (QString)"beginData";
     out << numSlice;
     out << (QString)"beginTri";
     for(i=0;i<numSlice;i++){
         vecLoop = mapTri[i];
         numLoop=vecLoop.size();
         out << (QString)"beginSlice";
         out << numLoop;
         for(j=0;j<numLoop;j++){
//             Loop tLoop = vecLoop[j];
//             vecTriangles = tLoop.triangleStrip;
             vecTriangles = vecLoop[j];
             numTriangles=vecTriangles.size();
             out << (QString)"beginLoop";
             out << numTriangles;
             for(k=0;k<numTriangles;k++){
//                 tTriangles = vecTriangles[k];
                 out<<vecTriangles[k].x()<<vecTriangles[k].y();
             }
//             out<<(QString)"endLoop";
         }
//         out << (QString)"endSlice";

     }

     std::vector<QVector2D> vecLine;
     int numLine;
     out << (QString)"beginLine";
//     out << numSlice;
     for(i=0;i<numSlice;i++){
         vecLine = mapLine[i];
         numLine=vecLine.size();
         out << (QString)"beginSlice";
         out << numLine;
         for(k=0;k<numLine;k++){
             out<<vecLine[k].x()<<vecLine[k].y();
         }
//         out << (QString)"endSlice";

     }
     //move
     B9ModelInstance* pInst = NULL;
     int numInst = GetAllInstances().size();
     float Xmin,Ymin,Zmin,Xmax,Ymax,Zmax;
     Xmin=Ymin=Zmin=99999;
     Xmax=Ymax=Zmax=-99999;
     for(i = 0; i < numInst; i++)
     {
         pInst = GetAllInstances().at(i);
         pInst->BakeGeometry(true);
         if(pInst->GetMinBound().x()<Xmin)
             Xmin = pInst->GetMinBound().x();
         if(pInst->GetMinBound().y()<Ymin)
             Ymin = pInst->GetMinBound().y();
         if(pInst->GetMinBound().z()<Zmin)
             Zmin = pInst->GetMinBound().z();
         if(pInst->GetMaxBound().x()>Xmax)
             Xmax = pInst->GetMaxBound().x();
         if(pInst->GetMaxBound().y()>Ymax)
             Ymax = pInst->GetMaxBound().y();
         if(pInst->GetMaxBound().z()>Zmax)
             Zmax = pInst->GetMaxBound().z();
     }
     if(Zmin<0) Zmin=0;
     float height=Zmax;//+Zmin;
     double thickness =  project->GetPixelThickness();//m_pCPJ->getZLayermm();//cyp
     float zHeight=qCeil(height/thickness)*thickness;
     out << (float)(Xmax+Xmin)/2  <<(float)(Ymax+Ymin)/2 << (float)(zHeight)/2;

 }

//////////////////////////////////////////////////////
//Private
//////////////////////////////////////////////////////


///////////////////////////////////////////////////
//Events
///////////////////////////////////////////////////
void MainWindow::keyPressEvent(QKeyEvent * event )
{
    if(event->key() == Qt::Key_Escape)
    {
        SetSupportMode(false);
    }

    pWorldView->keyPressEvent(event);

}
void MainWindow::keyReleaseEvent(QKeyEvent * event )
{
    pWorldView->keyReleaseEvent(event);

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //pWorldView->mousePressEvent(event);
    event->accept();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    //pWorldView->mouseReleaseEvent(event);
    event->accept();
}

void MainWindow::hideEvent(QHideEvent *event)
{
    emit eventHiding();

    pWorldView->pDrawTimer->stop();


    event->accept();
}
void MainWindow::showEvent(QShowEvent *event)
{

    pWorldView->pDrawTimer->start();
    showMaximized();
    event->accept();
}

void MainWindow::closeEvent ( QCloseEvent * event )
{

    //if the layout is dirty - ask the user if they want to save.
    if(project->IsDirtied())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("The layout has been modified.");//布局已被修改
         msgBox.setInformativeText("Do you want to save your changes?");//保存修改吗？
         msgBox.setToolTip("布局已被修改\n要保存吗？");
         msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
//         msgBox.setButtonText(QMessageBox::Save,"保存");
//         msgBox.setButtonText(QMessageBox::Discard,"不保存");
//         msgBox.setButtonText(QMessageBox::Cancel,"取消");
         msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();


        switch (ret)
        {
          case QMessageBox::Save:
                Save();
              break;
          case QMessageBox::Discard:
                //nothing
              break;
          case QMessageBox::Cancel:
                event->ignore();
                return;
              break;
          default:
              break;
        }
    }

    //when we close the window - we want to make a new project.
    //because we might open the window again and we want a fresh start.
    New();
    event->accept();

}

void MainWindow::setPrinterToModel1()
{
    SetXYPixelSizePreset("50");
    QSettings appSettings;
    appSettings.beginGroup("USERSET");
        appSettings.setValue("Printer","M50");
    appSettings.endGroup();
}

void MainWindow::setPrinterToModel2()
{
    SetXYPixelSizePreset("100");
    QSettings appSettings;
    appSettings.beginGroup("USERSET");
        appSettings.setValue("Printer","M100");
    appSettings.endGroup();
}

void MainWindow::doPrint()
{

    // print using variables set by wizard...
    pPrint->show();
//    pLogManager->setPrinting(false); //cyp set to true to Stop logfile entries when printing
    t->setIsPrinting(true);
    CROSS_OS_DisableSleeps(true);//disable things like screen saver - and power options.

//    pw->on_setProjectorBlueLED(222);//cyp
    pPrint->print3D(m_pCPJ, 0, 0, pw->m_iTbaseMS, pw->m_iToverMS, pw->m_iTattachMS, pw->m_iNumAttach, pw->m_iLastLayer, pw->m_bDryRun, pw->m_bDryRun, pw->m_bMirrored);

    return;
}

void MainWindow::showCatalog()
{
    t->dlgEditMatCat();
}

void MainWindow::OnSetSupprotWidget(int iLength)
{
    pMBW_Support->setGeometry(70,pMBW_Support->geometry().y(),355,iLength+10);
    pSupport->setGeometry(10,5,345,iLength);
}

void MainWindow::getLanguage(int index){
    qDebug()<<"index:"<<index;
    switch (index) {
       case 0:
           QApplication::removeTranslator(tor);
           tor->load(":/trans/zh.qm");
           qApp->installTranslator(tor);
           this->ui.retranslateUi(this);
           //ui->comboBox_3->setCurrentIndex(0);
           current_language = "Chinese";
           break;
       case 1:
           QApplication::removeTranslator(tor);
           tor->load(":/trans/en.qm");
           qApp->installTranslator(tor);
           this->ui.retranslateUi(this);
           //ui->comboBox_3->setCurrentIndex(1);
           current_language = "English";
           break;
       default:
           QApplication::removeTranslator(tor);
           tor->load(":/trans/zh.qm");
           qApp->installTranslator(tor);
           this->ui.retranslateUi(this);
           //ui->comboBox_3->setCurrentIndex(0);
           current_language = "Chinese";
           break;
       }
       //set_default_Form_conf();
}
void MainWindow::ChangeToEnglish(){
    //getLanguage(1);
    language="English";
    UpdateByLanguage();
}

void MainWindow::ChangeToChinese(){
    //getLanguage(0);
    language="Chinese";
    UpdateByLanguage();
}

void MainWindow::LanguageInit(){
    tor = new QTranslator();
    if (current_language == "Chinese") {
       tor->load(":/trans/zh.qm");
    } else if (current_language == "English") {
        tor->load(":/trans/en.qm");
    }
    qApp->installTranslator(tor);
    this->ui.retranslateUi(this);

}
void MainWindow::UpdateByLanguage(){
    QSettings appSettings;
    appSettings.beginGroup("USERSET");
    appSettings.setValue("Language",language);
    appSettings.endGroup();
    if(language=="Chinese"){
        ui.menuFile->setTitle("文件");
        ui.menuEdit->setTitle("编辑");
        ui.menuView->setTitle("视图");
        ui.menuSlice->setTitle("切片");
        ui.menuTools->setTitle("工具");
        ui.menuLanguage->setTitle("语言");
        ui.actionNew_Project->setText("新建");
        ui.actionOpen_Project->setText("打开(.nstl)");
        ui.actionSave->setText("保存(.nstl)");
        ui.actionSave_As->setText("另存为(.nstl)");
        ui.actionPrint->setText("打印");
        ui.menuPrinter->setTitle("打印选择");
        ui.actionExportSlice->setText("导出(.n3d)");
        ui.actionExport_stl->setText("导出(.stl)");
        ui.actionAdd_Model->setText("添加模型");
        ui.actionDelete->setText("删除模型");
        ui.actionDuplicate->setText("重复添加模型");
        ui.actionRotate->setText("旋转");
        ui.actionMove->setText("移动");
        ui.actionScale->setText("缩放");
        ui.actionDrop_To_Floor->setText("落底");
        ui.actionSupport->setText("支撑");
        ui.actionTop_View->setText("上");
        ui.actionBottom_View->setText("下");
        ui.actionLeft_View->setText("左");
        ui.actionRight_View->setText("右");
        ui.actionFront_View->setText("前");
        ui.actionBack_View->setText("后");
        ui.slice->setText("切片");
        ui.showSlices->setText("切片展示");
        ui.actionTerminal->setText("终端");
        ui.actionOption->setText("打印机选项");

    }else if(language=="English"){
        ui.menuFile->setTitle("File");
        ui.menuEdit->setTitle("Edit");
        ui.menuView->setTitle("View");
        ui.menuSlice->setTitle("Slic");
        ui.menuTools->setTitle("Tools");
        ui.menuLanguage->setTitle("Language");
        ui.actionNew_Project->setText("New");
        ui.actionOpen_Project->setText("New(.nstl)");
        ui.actionSave->setText("Save(.nstl)");
        ui.actionSave_As->setText("Save As(.nstl)");
        ui.actionPrint->setText("Print");
        ui.menuPrinter->setTitle("Printer");
        ui.actionExportSlice->setText("Export(.n3d)");
        ui.actionExport_stl->setText("Export(.stl)");
        ui.actionAdd_Model->setText("Add Model(.stl)");
        ui.actionDelete->setText("Delete Model");
        ui.actionDuplicate->setText("Duplicate Model");
        ui.actionRotate->setText("Rotate");
        ui.actionMove->setText("Move");
        ui.actionScale->setText("Scale");
        ui.actionDrop_To_Floor->setText("Drop to Floor");
        ui.actionSupport->setText("Support");
        ui.actionTop_View->setText("Top");
        ui.actionBottom_View->setText("Bottom");
        ui.actionLeft_View->setText("Left");
        ui.actionRight_View->setText("Right");
        ui.actionFront_View->setText("Front");
        ui.actionBack_View->setText("Back");
        ui.slice->setText("Slice");
        ui.showSlices->setText("Show Slice");
        ui.actionTerminal->setText("Terminal");
        ui.actionOption->setText("Printer Option");
    }
}
