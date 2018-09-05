#include "statuswidget.h"
#include "ui_statuswidget.h"

statusWidget::statusWidget(MainWindow *main,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statusWidget)
{
    ui->setupUi(this);
    pMain = main;
    UpdateExtentsUI();
}

statusWidget::~statusWidget()
{
    delete ui;
}

void statusWidget::setPrintModel(bool isPrint)
{
    ui->printercombo->setEnabled(!isPrint);
    ui->thicknesscombo->setEnabled(!isPrint);
    ui->pushButtonPrint->setVisible(isPrint);
    connect(ui->pushButtonPrint,SIGNAL(clicked()),pMain,SLOT(showPrintWindow()));
}

void statusWidget::on_thicknesscombo_currentIndexChanged(int index)
{
    pMain->project->SetPixelThickness(ui->thicknesscombo->currentText().toInt());
}

double statusWidget::getThickness()
{
    return (ui->thicknesscombo->currentText().toDouble());
}

void statusWidget::setPrinter(int index)
{
    ui->printercombo->setCurrentIndex(index);
}

void statusWidget::setThickness(int index)
{
    ui->thicknesscombo->setCurrentIndex(index);
}

void statusWidget::setThickness(QString s)
{
    ui->thicknesscombo->setCurrentIndex(ui->thicknesscombo->findText(s));
}

QString statusWidget::getPrinter()
{
    return ui->printercombo->currentText();
}

void statusWidget::on_printercombo_currentIndexChanged(int index)
{
//    pMain->t->setPrinter(index);
//    switch(index)
//    {
//        case 0:
//            pMain->pOptions->setPrinterToModel1();
//            break;
//        case 1:
//            pMain->pOptions->setPrinterToModel2();
//            break;
//        case 2:
//            pMain->pOptions->setPrinterToModel3();
//            break;

//        default:break;

//    }
}

void statusWidget::UpdateExtentsUI()
{
//    int pixi;
//    int proi;

//    //pixel sizes
//    if(pMain->project->GetPixelSize() == 50)
//        pixi=0;
//    else if(pMain->project->GetPixelSize() == 52.2)
//        pixi=1;
//    else if(pMain->project->GetPixelSize() == 60)
//        pixi=2;
//    //projector resolutions
//    if(pMain->project->GetResolution() == QVector2D(1024,768))
//        proi=0;
//    else if(pMain->project->GetResolution() == QVector2D(1280,800))
//        proi=1;

//    if(pixi == 0 && proi == 0)
//        setPrinter(0);
//    else if(pixi == 1 && proi == 0)
//        setPrinter(1);
//    else if(pixi == 0 && proi == 1)
//        setPrinter(2);

//    //pixel sizes
//    if(pMain->project->GetPixelSize() == 50)
//        setPrinter(0);
//    else if(pMain->project->GetPixelSize() == 100)
//        setPrinter(1);

    int indx = ui->thicknesscombo->findText(QString::number(pMain->project->GetPixelThickness()));
    ui->thicknesscombo->setCurrentIndex(indx);
}
