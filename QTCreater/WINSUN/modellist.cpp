#include "modellist.h"
#include "ui_modellist.h"
#include "layout/modelinstance.h"

ModelList::ModelList(MainWindow *main,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelList)
{
    ui->setupUi(this);
    pMain = main;

    connect(ui->AddButton,SIGNAL(clicked()),pMain,SLOT(AddModel()));
    connect(ui->RemoveButton,SIGNAL(clicked()),pMain,SLOT(DeleteSelection()));
    connect(ui->duplicateButton,SIGNAL(clicked()),pMain,SLOT(DuplicateSelection()));

    connect(ui->posx,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
    connect(ui->posy,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
    connect(ui->posz,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
    connect(ui->rotx,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
    connect(ui->roty,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
    connect(ui->rotz,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
    connect(ui->scalex,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
    connect(ui->scaley,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
    connect(ui->scalez,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
    connect(ui->ApplyButton,SIGNAL(clicked()),this,SLOT(PushTranslations()));

    connect(ui->ModelList_2,SIGNAL(itemSelectionChanged()),this,SLOT(RefreshSelectionsFromList()));

}

ModelList::~ModelList()
{
    delete ui;
}

void ModelList::UpdateInterface()
{
    if(ui->ModelList_2->selectedItems().size() <= 0){//no items selected.
        ui->duplicateButton->setEnabled(false);
        ui->RemoveButton->setEnabled(false);
    }
    else{
        ui->duplicateButton->setEnabled(true);
        ui->RemoveButton->setEnabled(true);
    }
    if(!(ui->ModelList_2->selectedItems().size() <= 0 || ui->ModelList_2->selectedItems().size() > 1))
    {
        B9ModelInstance* inst = pMain->FindInstance(GetSelectedItem()[0]);
        ui->posx->setText(QString().number(inst->GetPos().x(),'f',2));
        ui->posy->setText(QString().number(inst->GetPos().y(),'f',2));
        ui->posz->setText(QString().number(inst->GetMinBound().z(),'f',2));

        ui->rotz->setText(QString().number(inst->GetRot().z()));
        ui->rotx->setText(QString().number(inst->GetRot().x()));
        ui->roty->setText(QString().number(inst->GetRot().y()));

        ui->scalex->setText(QString().number(inst->GetScale().x()));
        ui->scaley->setText(QString().number(inst->GetScale().y()));
        ui->scalez->setText(QString().number(inst->GetScale().z()));

        ui->modelsizex->setText(QString().number(inst->GetMaxBound().x() - inst->GetMinBound().x()));
        ui->modelsizey->setText(QString().number(inst->GetMaxBound().y() - inst->GetMinBound().y()));
        ui->modelsizez->setText(QString().number(inst->GetMaxBound().z() - inst->GetMinBound().z()));
    }
}

void ModelList::AddTagToModelList(QListWidgetItem* item)
{
    ui->ModelList_2->addItem(item);
}

std::vector<B9ModelInstance*> ModelList::GetSelectedInstances()
{
    std::vector<B9ModelInstance*> insts;
    int i;
    for(i=0;i<ui->ModelList_2->selectedItems().size();i++)
    {
        insts.push_back(pMain->FindInstance(ui->ModelList_2->selectedItems()[i]));
    }
    return insts;
}

//selection
void ModelList::RefreshSelectionsFromList()
{
    int i;
    for(i=0;i<ui->ModelList_2->count();i++)
    {
        B9ModelInstance* inst = pMain->FindInstance(ui->ModelList_2->item(i));
        if(inst == NULL)
            return;

        if(!ui->ModelList_2->item(i)->isSelected())
        {
            pMain->DeSelect(pMain->FindInstance(ui->ModelList_2->item(i)));
        }
        else if(ui->ModelList_2->item(i)->isSelected())
        {
            pMain->Select(pMain->FindInstance(ui->ModelList_2->item(i)));
        }
    }
}

void ModelList::PushTranslations()
{
    QString scalex;
        QString scaley;
        QString scalez;
        if(true)//Í¬²½Ëõ·Å
        {
            scalex = ui->scalex->text();
            scaley = ui->scalex->text();
            scalez = ui->scalex->text();
            ui->scaley->blockSignals(true);
                ui->scaley->setText(scalex);
            ui->scaley->blockSignals(false);
            ui->scalez->blockSignals(true);
                ui->scalez->setText(scalex);
            ui->scalez->blockSignals(true);
        }
        else
        {
            scalex = ui->scalex->text();
            scaley = ui->scaley->text();
            scalez = ui->scalez->text();
        }

        pMain->SetSelectionPos(ui->posx->text().toDouble(),0,0,1);
        pMain->SetSelectionPos(0,ui->posy->text().toDouble(),0,2);
        pMain->SetSelectionPos(0,0,ui->posz->text().toDouble(),3);

        pMain->SetSelectionRot(QVector3D(ui->rotx->text().toDouble(),
                                  ui->roty->text().toDouble(),
                                  ui->rotz->text().toDouble()));

        pMain->SetSelectionScale(scalex.toDouble(),0,0,1);
        pMain->SetSelectionScale(0,scaley.toDouble(),0,2);
        pMain->SetSelectionScale(0,0,scalez.toDouble(),3);

        for(unsigned int i = 0; i < GetSelectedInstances().size(); i++)
        {
            GetSelectedInstances()[i]->UpdateBounds();
        }
}

QList<QListWidgetItem*> ModelList::GetSelectedItem()
{
    return ui->ModelList_2->selectedItems();
}

double ModelList::getThickness()
{
    return (ui->thicknesscombo->currentText().toDouble());
}
