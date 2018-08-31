#include "buildspace.h"
#include "ui_buildspace.h"

BuildSpace::BuildSpace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuildSpace)
{
    ui->setupUi(this);
}

BuildSpace::~BuildSpace()
{
    delete ui;
}
