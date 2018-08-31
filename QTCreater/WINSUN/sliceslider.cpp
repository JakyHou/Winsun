#include "sliceslider.h"
#include "ui_sliceslider.h"

SliceSlider::SliceSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SliceSlider)
{
    ui->setupUi(this);
}

SliceSlider::~SliceSlider()
{
    delete ui;
}

void SliceSlider::on_curNumOfLayersSlider_valueChanged(int value)
{
    ui->lineEditCurNumOfLayers->setText(QString::number(value));
    if(value==ui->curNumOfLayersSlider->maximum()) value--;
    emit curNumOfLayers(value);
//    ui->spinBoxCurNumOfLayers->setValue(value);
}

void SliceSlider::on_spinBoxCurNumOfLayers_valueChanged(int arg1)
{
//    emit curNumOfLayers(arg1);
//    ui->curNumOfLayersSlider->setValue(arg1);
}

void SliceSlider::setNumOfLayers(int num)
{
    ui->labelTotalLayers->setText(QString::number(num+1));
//    ui->lineEditCurNumOfLayers->setText(QString::number(num+1));
//    ui->spinBoxCurNumOfLayers->setMaximum(num);
    ui->curNumOfLayersSlider->setMaximum(num+1);
//    ui->curNumOfLayersSlider->setMinimum(0);
    ui->curNumOfLayersSlider->setValue(num+1);
    on_curNumOfLayersSlider_valueChanged(num+1);
}

void SliceSlider::on_lineEditCurNumOfLayers_returnPressed()
{
    int num = ui->lineEditCurNumOfLayers->text().toInt();
    if(num>ui->curNumOfLayersSlider->maximum())
        ui->lineEditCurNumOfLayers->setText("InValid");
    else
        ui->curNumOfLayersSlider->setValue(num);
}
