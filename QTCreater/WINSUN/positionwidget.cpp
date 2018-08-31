#include "positionwidget.h"
#include "ui_positionwidget.h"
#include "layout/modelinstance.h"

PositionWidget::PositionWidget(MainWindow *main,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PositionWidget)
{
    ui->setupUi(this);
    pMain = main;

    connect(ui->posx,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
    connect(ui->posy,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
    connect(ui->posz,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
}

PositionWidget::~PositionWidget()
{
    delete ui;
}

void PositionWidget::UpdateInterface()
{
    bool found = false;
    int i;
    for(i = 0; i < pMain->GetAllInstances().size();i++)
    {
        B9ModelInstance* inst = pMain->GetAllInstances()[i];

        if(inst->isselected)
        {
            ui->posx->setText(QString().number(inst->GetPos().x(),'f',2));
            ui->posy->setText(QString().number(inst->GetPos().y(),'f',2));
            ui->posz->setText(QString().number(inst->GetMinBound().z(),'f',2));
            found=true;
            break;
        }
    }
    if(!found)
    {
        ui->posz->setText("");
        ui->posx->setText("");
        ui->posy->setText("");
    }
}

void PositionWidget::PushTranslations()
{

    pMain->SetSelectionPos(ui->posx->text().toDouble(),0,0,1);
    pMain->SetSelectionPos(0,ui->posy->text().toDouble(),0,2);
    pMain->SetSelectionPos(0,0,ui->posz->text().toDouble(),3);

        for(unsigned int i = 0; i < pMain->GetSelectedInstances().size(); i++)
        {
            pMain->GetSelectedInstances()[i]->UpdateBounds();
        }
}
