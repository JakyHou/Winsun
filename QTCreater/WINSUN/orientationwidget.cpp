#include "orientationwidget.h"
#include "ui_orientationwidget.h"
#include "layout/modelinstance.h"

OrientationWidget::OrientationWidget(MainWindow *main,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrientationWidget)
{
    ui->setupUi(this);
    pMain = main;

    connect(ui->rotx,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
    connect(ui->roty,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
    connect(ui->rotz,SIGNAL(returnPressed()),this,SLOT(PushTranslations()));
//    connect(ui->doubleSpinBox_rotx,SIGNAL(editingFinished()),this,SLOT(PushTranslations()));
//    connect(ui->doubleSpinBox_roty,SIGNAL(editingFinished()),this,SLOT(PushTranslations()));
//    connect(ui->doubleSpinBox_rotz,SIGNAL(editingFinished()),this,SLOT(PushTranslations()));
}

OrientationWidget::~OrientationWidget()
{
    delete ui;
}

void OrientationWidget::UpdateInterface()
{
    bool found = false;
    int i;
    for(i = 0; i < pMain->GetAllInstances().size();i++)
    {
        B9ModelInstance* inst = pMain->GetAllInstances()[i];

        if(inst->isselected)
        {
            ui->rotz->setText(QString().number(inst->GetRot().z()));
            ui->rotx->setText(QString().number(inst->GetRot().x()));
            ui->roty->setText(QString().number(inst->GetRot().y()));
            found=true;
            break;
        }
    }
    if(!found)
    {
        ui->rotz->setText("");
        ui->rotx->setText("");
        ui->roty->setText("");
    }
}

void OrientationWidget::PushTranslations()
{
    pMain->SetSelectionRot(QVector3D(ui->rotx->text().toDouble(),
                              ui->roty->text().toDouble(),
                              ui->rotz->text().toDouble()));

        for(unsigned int i = 0; i < pMain->GetSelectedInstances().size(); i++)
        {
            pMain->GetSelectedInstances()[i]->UpdateBounds();
        }

        on_pushButtonDrop_To_Floor_clicked();
}

void OrientationWidget::on_pushButtonDrop_To_Floor_clicked()
{
    pMain->DropSelectionToFloor();
}
