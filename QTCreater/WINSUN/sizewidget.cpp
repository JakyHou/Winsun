#include "sizewidget.h"
#include "ui_sizewidget.h"
#include "layout/modelinstance.h"

sizeWidget::sizeWidget(MainWindow *main,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sizeWidget)
{
    ui->setupUi(this);
    pMain = main;

}

sizeWidget::~sizeWidget()
{
    delete ui;
}

void sizeWidget::UpdateInterface()
{
    bool found = false;
    int i;
    for(i = 0; i < pMain->GetAllInstances().size();i++)
    {
        B9ModelInstance* inst = pMain->GetAllInstances()[i];

        if(inst->isselected)
        {
            ui->doubleSpinBox_scale->setValue(inst->GetScale().x());
            ui->modelsizex->setText(QString().number(inst->GetMaxBound().x() - inst->GetMinBound().x()));
            ui->modelsizey->setText(QString().number(inst->GetMaxBound().y() - inst->GetMinBound().y()));
            ui->modelsizez->setText(QString().number(inst->GetMaxBound().z() - inst->GetMinBound().z()));
            found=true;
            break;
        }
    }
    if(!found)
    {
        ui->doubleSpinBox_scale->setValue(0);
        ui->modelsizex->setText("");
        ui->modelsizey->setText("");
        ui->modelsizez->setText("");
    }
}

void sizeWidget::PushTranslations()
{
    double scale;
    scale = ui->doubleSpinBox_scale->value();
        pMain->SetSelectionScale(scale,0,0,1);
        pMain->SetSelectionScale(0,scale,0,2);
        pMain->SetSelectionScale(0,0,scale,3);

        for(unsigned int i = 0; i < pMain->GetSelectedInstances().size(); i++)
        {
            pMain->GetSelectedInstances()[i]->UpdateBounds();
        }
}

void sizeWidget::on_doubleSpinBox_scale_valueChanged(double arg1)
{
//    PushTranslations();
}

void sizeWidget::on_pushButtonDrop_To_Floor_clicked()
{
    pMain->DropSelectionToFloor();
}

void sizeWidget::on_doubleSpinBox_scale_editingFinished()
{
    PushTranslations();
    on_pushButtonDrop_To_Floor_clicked();
}
