#include "viewwidget.h"
#include "ui_viewwidget.h"

viewWidget::viewWidget(MainWindow *main,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewWidget)
{
    ui->setupUi(this);
    pMain = main;

    this->setStyleSheet("background-color: rgba(225, 225 ,225, 100%);color: rgba(208, 219, 230, 100%);");//208, 219, 230

    QObject::connect(ui->pushButtonTop,SIGNAL(clicked()),pMain->pWorldView,SLOT(TopView()));//pMain->pWorldView
    QObject::connect(ui->pushButtonBottom,SIGNAL(clicked()),pMain->pWorldView,SLOT(BottomView()));
    QObject::connect(ui->pushButtonLeft,SIGNAL(clicked()),pMain->pWorldView,SLOT(LeftView()));
    QObject::connect(ui->pushButtonRight,SIGNAL(clicked()),pMain->pWorldView,SLOT(RightView()));
    QObject::connect(ui->pushButtonFront,SIGNAL(clicked()),pMain->pWorldView,SLOT(FrontView()));
    QObject::connect(ui->pushButtonBack,SIGNAL(clicked()),pMain->pWorldView,SLOT(BackView()));

    QSettings appSettings;
    appSettings.beginGroup("USERSET");
    language=appSettings.value("Language").toString();
    appSettings.endGroup();
    if(language!=""){
        UpdateByLanguage();
    }
}

viewWidget::~viewWidget()
{
    delete ui;
}
void viewWidget::UpdateByLanguage(){
    if(language=="Chinese"){
        ui->pushButtonBack->setText("后");
        ui->pushButtonBottom->setText("下");
        ui->pushButtonFront->setText("前");
        ui->pushButtonLeft->setText("左");
        ui->pushButtonRight->setText("右");
        ui->pushButtonTop->setText("上");
    }else{
        ui->pushButtonBack->setText("Back");
        ui->pushButtonBottom->setText("Btm");
        ui->pushButtonFront->setText("Front");
        ui->pushButtonLeft->setText("Left");
        ui->pushButtonRight->setText("Right");
        ui->pushButtonTop->setText("Top");
    }
}
