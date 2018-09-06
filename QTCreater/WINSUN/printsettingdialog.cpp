#include "printsettingdialog.h"
#include "ui_printsettingdialog.h"
#include <QtGui>

PrintSettingDialog::PrintSettingDialog(MainWindow *main,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintSettingDialog)
{
    ui->setupUi(this);
    pMain = main;
    bShowMore = false;

    QSettings appSettings;
    appSettings.beginGroup("USERSET");
    if(appSettings.value("AppearDLG","YES") == "YES"){
        ui->checkBoxAppears->setChecked(false);
    }
    else
        ui->checkBoxAppears->setChecked(true);
    language=appSettings.value("Language").toString();
    appSettings.endGroup();
    if(language!=""){
        UpdateByLanguage();
    }
//    ui->groupBox_BuildSpace->setVisible(false);
    UpdateExtentsUI();
//    connect(this,SIGNAL(show()),this,SLOT(UpdateExtentsUI()));
    on_pushButtonOK_clicked();

//    ui->printercombo->activated(1);
}

PrintSettingDialog::~PrintSettingDialog()
{
    delete ui;
}

void PrintSettingDialog::closeEvent(QCloseEvent *e)
{
    UpdateExtentsUI();
    close();
}

void PrintSettingDialog::showIt()
{
    UpdateExtentsUI();
    exec();
}

void PrintSettingDialog::UpdateExtentsUI()
{
    int index;
    QSettings appSettings;

//    //materials
//    appSettings.beginGroup("MATERIALPARAMS");
//    int count = appSettings.value("MATERIALCOUNT",0).toInt();
//    ui->materialcombo->clear();
//    for(int i=0;i<count;i++){
//        ui->materialcombo->addItem(appSettings.value("NO"+QString::number(i),"").toString());
//    }
//    appSettings.endGroup();
//    appSettings.beginGroup("USERSET");
//    if(appSettings.value("Material").toString() != "")//寻找上次选择的材料
//        index = ui->materialcombo->findText(appSettings.value("Material").toString());
//    else//找不到，默选第一个
//        index = 0;
//    ui->materialcombo->setCurrentIndex(index);
//    appSettings.endGroup();
    appSettings.beginGroup("USERSET");
    //printer
    index = ui->printercombo->findText(appSettings.value("Printer","M50").toString());
    if(index < 0) index = 0;
    on_printercombo_currentIndexChanged(index);

//    //thickness
//    index = ui->thicknesscombo->findText(appSettings.value("Thickness",100).toString());
//    ui->thicknesscombo->setCurrentIndex(index);

    appSettings.endGroup();


}

void PrintSettingDialog::on_pushButtonOK_clicked()
{
    QSettings appSettings;
    appSettings.beginGroup("USERSET");
    if(ui->checkBoxAppears->isChecked()){
        appSettings.setValue("AppearDLG","NO");//cyp
    }
    else
        appSettings.setValue("AppearDLG","YES");//cyp


//        appSettings.setValue("Thickness",ui->thicknesscombo->currentText().toInt());
        appSettings.setValue("Printer",ui->printercombo->currentText());
//        appSettings.setValue("Material",ui->materialcombo->currentText());
    appSettings.endGroup();

//    pMain->t->setPrinter(ui->printercombo->currentIndex());

//    pMain->pw->setMaterial(ui->materialcombo->currentIndex());
//    pMain->project->SetPixelThickness(ui->thicknesscombo->currentText().toDouble());
//    emit setPrinter(ui->printercombo->currentIndex());
//    emit setMaterial(ui->materialcombo->currentIndex());
//    emit setThickness(ui->thicknesscombo->currentIndex());
    pMain->SetXYPixelSizePreset(ui->lineEdit_pixelsize->text());
    close();
}

void PrintSettingDialog::on_toolButtonMore_clicked()
{
//    bShowMore = !bShowMore;
//    ui->groupBox_BuildSpace->setVisible(bShowMore);
//    if(bShowMore){
//        ui->toolButtonMore->setArrowType(Qt::DownArrow);
//    }
//    else{
//        ui->toolButtonMore->setArrowType(Qt::RightArrow);
//    }
}

void PrintSettingDialog::on_printercombo_currentIndexChanged(int index)
{
    ui->printercombo->setCurrentIndex(index);
    if(index == 0){
        ui->lineEdit_pixelsize->setText("50");
//        ui->lineEdit_projector->setText("(LCR4500)1280x800");
        ui->Print_Extents_X->setText("64");
        ui->Print_Extents_Y->setText("40");
    }
    else{// if(index == 1){
        ui->lineEdit_pixelsize->setText("100");
//        ui->lineEdit_projector->setText("(LCR4500)1280x800");
        ui->Print_Extents_X->setText("128");
        ui->Print_Extents_Y->setText("80");
    }

}
void PrintSettingDialog::UpdateByLanguage(){
    if(language=="Chinese"){
        this->setWindowTitle("选择打印机");
        ui->label->setText("打印机:");
        ui->groupBox_BuildSpace->setTitle("构建空间:");
        ui->label_4->setText("像素精度:");
        ui->label_35->setText("构图区间(mm):");
        ui->label_36->setText("最大高度(mm)");
        ui->checkBoxAppears->setText("不再显示");
    }else{
        this->setWindowTitle("Select Printer");
        ui->label->setText("Printer:");
        ui->groupBox_BuildSpace->setTitle("Build Space:");
        ui->label_4->setText("Pixel Size(μm):");
        ui->label_35->setText("Build Table Area(mm):");
        ui->label_36->setText("Max Height(mm):");
        ui->checkBoxAppears->setText("Did'n show it again.");
    }
}
