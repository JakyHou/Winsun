#include "showslices.h"
#include "ui_showslices.h"

ShowSlices::ShowSlices(MainWindow* main, QWidget *parent = 0) :
    QWidget(parent),
    ui(new Ui::ShowSlices)
{
    ui->setupUi(this);
    pMain = main;
//    pCPJ = cPJ;
    bGrid = false;
    supportMode = false;
    pCPJ = NULL;
    backupIndx = 0;
    m_xOffset = 0;
    m_yOffset = 0;
    currSlice = 0;

//    pDrawingContext = new DrawingContext(this);
//    pDrawingContext->pEditView = this;

//    SetSupportTool("circle");
//    SetDrawTool("penfill");

    pDrawingContext = new DrawingContext(this);
//    pDrawingContext->pEditView = this;
    ui->scrollArea->setWidget(pDrawingContext);

//    pWorldView = new WorldView(NULL,pMain);
//    ui->scrollArea->setWidget(pWorldView);//pMain->
//    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
}

ShowSlices::~ShowSlices()
{
//    if(pWorldView)
//        delete pWorldView;
    delete ui;
}

void ShowSlices::UpdateWidgets()
{
    setWindowTitle("Show Slices - Preview");
    //slider
    ui->curNumOfLayersSlider->setMinimum(0);
    ui->curNumOfLayersSlider->setMaximum(pCPJ->getTotalLayers() - 1);
    ui->curNumOfLayersSlider->setValue(currSlice);

    ui->spinBoxCurNumOfLayers->setMaximum(pCPJ->getTotalLayers());
    ui->spinBoxCurNumOfLayers->setMinimum(1);
    ui->spinBoxCurNumOfLayers->setValue(currSlice+1);

    ui->labelTotalLayers->setText(QString("/").append(QString::number(pCPJ->getTotalLayers())));
    ui->lineEditThickness->setText(QString::number(1000*pCPJ->getZLayermm()));
    connect(ui->curNumOfLayersSlider,SIGNAL(valueChanged(int)),this,SLOT(setCurNumOfLayers(int)));

}

void ShowSlices::setCurNumOfLayers(int iValue)
{
    ui->spinBoxCurNumOfLayers->setValue(iValue+1);
    GoToSlice(iValue);
}

void ShowSlices::on_spinBoxCurNumOfLayers_valueChanged(int arg1)
{
    ui->curNumOfLayersSlider->setValue(arg1-1);

}

void ShowSlices::GoToSlice(int slicenumber)
{
    //make sure the suggested slice is in range...
    if(slicenumber > pCPJ->getTotalLayers() - 1 || slicenumber < 0)
    {
        return;
    }
    currSlice = slicenumber;
    DeCompressIntoContext();

    if(supportMode)
    {
        RefreshContext(0);
    }
    else
    {
        RefreshContext(1);
    }
}

void ShowSlices::DeCompressIntoContext()
{
    pCPJ->setCurrentSlice(currSlice);
    if(supportMode)
        pCPJ->showSupports(1);
    else
        pCPJ->showSupports(0);

    //double check if the top image is 0x0, we want to resize it to fix the "grey window"
    //problem when first opening an image.
    //because
    if(topImg.size().width() == 0)
    {//cyp
        topImg = QImage(1280,800,QImage::Format_ARGB32_Premultiplied) ;//1024,768
    }



    pCPJ->inflateCurrentSlice(&topImg, m_xOffset, m_yOffset, true);
    pDrawingContext->SetUpperImg(&topImg);

    if(currSlice <= 0)//make "base" image
    {
        botImg = QImage(topImg.width(),topImg.height(),QImage::Format_RGB16);
        botImg.fill(QColor(255,255,255));
    }
    else
    {
        pCPJ->setCurrentSlice(currSlice - 1);
        pCPJ->inflateCurrentSlice(&botImg, m_xOffset, m_yOffset, true);
    }

    pDrawingContext->SetLowerImg(&botImg);
}

void ShowSlices::RefreshContext(bool alreadywhite)
{
    if(!alreadywhite)
        pDrawingContext->GenerateLogicImage();
    pDrawingContext->repaint();

}


////////////////////////////////
//Protected
////////////////////////////////
void ShowSlices::keyPressEvent(QKeyEvent * pEvent)
{

    QWidget::keyPressEvent(pEvent);
}
void ShowSlices::keyReleaseEvent(QKeyEvent * pEvent)
{
    QWidget::keyPressEvent(pEvent);
}

void ShowSlices::mouseReleaseEvent(QMouseEvent * pEvent)
{
    QWidget::mouseReleaseEvent(pEvent);
}
