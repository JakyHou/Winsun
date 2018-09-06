#include "slicedialog.h"
#include "ui_slicedialog.h"

SliceDialog::SliceDialog(MainWindow *main,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SliceDialog)
{
    ui->setupUi(this);
    pMain = main;

    QSettings appSettings;
    appSettings.beginGroup("USERSET");
    int index = ui->thicknesscombo->findText(appSettings.value("Thickness",100).toString());
    if(index<0) index = 0;
    ui->thicknesscombo->setCurrentIndex(index);
    language=appSettings.value("Language").toString();
    appSettings.endGroup();
    if(language!=""){
        UpdateByLanguage();
    }
}

SliceDialog::~SliceDialog()
{
//    //记住最后一次选择
//    QSettings appSettings;
//    appSettings.beginGroup("USERSET");
//    appSettings.setValue("Thickness",ui->thicknesscombo->currentText());
//    appSettings.endGroup();

    delete ui;
}

void SliceDialog::on_BrowseButton_clicked()
{
    QSettings settings("Dir");

    QString filename = CROSS_OS_GetSaveFileName(this, tr("Export Slices"),
                    settings.value("WorkingDir").toString(),
                                                tr("Nepho3d_Studio Slice File  (*.n3d)"),QStringList("n3d"));

    if(filename.isEmpty())//cancell button
    {
        return;
    }
    settings.setValue("WorkingDir",QFileInfo(filename).absolutePath());
    ui->lineEditPath->setText(filename);
}

void SliceDialog::on_SliceButton_clicked()
{
    if(ui->lineEditPath->text() == ""){
        if(language=="Chinese"){
            QMessageBox::warning(this, tr("提示"), tr("保存地址为空"),QMessageBox::Ok);
        }else{
            QMessageBox::warning(this, tr("Hint"), tr("Save Path is Empty"),QMessageBox::Ok);
        }

        return;
    }

    pMain->SetZLayerThickness(ui->thicknesscombo->currentText());
    if(pMain->SliceWorldToJob(ui->lineEditPath->text()))
        QMessageBoxByLanguage("完成","切片完成\n\n所有切片数据已保存.","Finished","Slicing Completed\n\nAll layers sliced and job file saved.");
    else{
        QMessageBoxByLanguage("取消","切片已取消\n\n保存失败.","Canceled","Slicing Canceled\n\nnothing was saved.");
    }
    close();
    return;
}

void SliceDialog::UpdateByLanguage(){
    if(language=="Chinese"){
        this->setWindowTitle("切片");
        ui->label->setText("保存路径:");
        ui->BrowseButton->setText("浏览");
        ui->label_4->setText("层厚(μm):");
        ui->SliceButton->setText("切片...");
    }else{
        this->setWindowTitle("Slice");
        ui->label->setText("Save Path:");
        ui->BrowseButton->setText("Browse");
        ui->label_4->setText("Thickness (μm):");
        ui->SliceButton->setText("Slice...");
    }
}

void SliceDialog::QMessageBoxByLanguage(QString c1,QString c2,QString e1,QString e2){
    if(language=="Chinese"){
        QMessageBox::information(0,c1,c2);
    }else{
        QMessageBox::information(0,e1,e2);
    }
}
