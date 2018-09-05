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
    appSettings.endGroup();
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
        QMessageBox::warning(this, tr("Hint"), tr("Save Path is Empty"),QMessageBox::Ok);
        return;
    }

    pMain->SetZLayerThickness(ui->thicknesscombo->currentText());
    if(pMain->SliceWorldToJob(ui->lineEditPath->text()))
        QMessageBox::information(0,"Finished","Slicing Completed\n\nAll layers sliced and job file saved.");
    else
        QMessageBox::information(0,"Canceled","Slicing Canceled\n\nnothing was saved.");
    close();
    return;
}
