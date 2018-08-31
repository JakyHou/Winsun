#include "materialscatalog.h"
#include "ui_materialscatalog.h"
#include <QSettings>
#include <QMessageBox>
#include <QInputDialog>
#include <QSpinBox>

#define TattachMS 0.0
#define TbaseMS 0.0
#define BlueLED 0

MaterialsTableItemDelegate::MaterialsTableItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

MaterialsTableItemDelegate::~MaterialsTableItemDelegate()
{
}

QWidget* MaterialsTableItemDelegate::createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
    if(index.column() > 2 || index.column() < 0)
        return QStyledItemDelegate::createEditor(parent, option, index);

    // Create the spinBox
    QDoubleSpinBox *sb = new QDoubleSpinBox(parent);
    sb->setDecimals(2);
    sb->setMaximum(255);
    sb->setMinimum(0);
    sb->setSingleStep(1);
    return sb;
}
void MaterialsTableItemDelegate::setModelData ( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const
{
    if(QComboBox *cb = qobject_cast<QComboBox *>(editor))
        // save the current text of the combo box as the current value of the item
        model->setData(index, cb->currentText(), Qt::EditRole);
    else
        QStyledItemDelegate::setModelData(editor, model, index);
}

MaterialsCatalog::MaterialsCatalog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MaterialsCatalog)
{
    ui->setupUi(this);

    MaterialsTableItemDelegate *mtid = new MaterialsTableItemDelegate(0);
    ui->tableWidgetParameters->setItemDelegate(mtid);
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++)
            ui->tableWidgetParameters->setItem(r,c,new QTableWidgetItem());
    }
    vecName.clear();
    QSettings settings;
    settings.beginGroup("MATERIALPARAMS");
        int count = settings.value("MATERIALCOUNT",0).toInt();
        settings.beginGroup("MATERIALNAMES");
            ui->comboBoxMaterial->clear();
            for(int i=0;i<count;i++){
                vecName.push_back(settings.value("NO"+QString::number(i),"").toString());
                ui->comboBoxMaterial->addItem(vecName[i]);
            }
        settings.endGroup();
    settings.endGroup();
    int index;
    QSettings appSettings;
    appSettings.beginGroup("USERSET");
    if(appSettings.value("Material").toString() != "")//寻找上次选择的材料
        index = ui->comboBoxMaterial->findText(appSettings.value("Material").toString());
    else//找不到，默选第一个
        index = 0;
    language=appSettings.value("Language").toString();
    appSettings.endGroup();
    if(language!=""){
        UpdateByLanguage();
    }
    ui->comboBoxMaterial->setCurrentIndex(index);

    setFixedSize(this->width(), this->height());//固定窗口大
}

MaterialsCatalog::~MaterialsCatalog()
{
//    on_pushButtonCancel_clicked();
    delete ui;
}

void MaterialsCatalog::closeEvent(QCloseEvent * event )
{
    QSettings settings;
    settings.beginGroup("MATERIALPARAMS");
        settings.setValue("MATERIALCOUNT",vecName.size());
        settings.remove("MATERIALNAMES");
        settings.beginGroup("MATERIALNAMES");
            ui->comboBoxMaterial->clear();
            for(int i=0;i<vecName.size();i++){
                settings.setValue("NO"+QString::number(i),vecName[i]);
            }
        settings.endGroup();
    settings.endGroup();
    close();
}

void MaterialsCatalog::on_comboBoxMaterial_currentIndexChanged(const QString &arg1)
{
    QSettings settings;
    settings.beginGroup("MATERIALPARAMS");
        settings.beginGroup(ui->comboBoxMaterial->currentText());
            settings.beginGroup("20μm");
                ui->tableWidgetParameters->item(0,0)->setText(settings.value("AttachExposure",TattachMS).toString());
                ui->tableWidgetParameters->item(0,1)->setText(settings.value("TimeOfExposure",TbaseMS).toString());
                ui->tableWidgetParameters->item(0,2)->setText(settings.value("IntensityOfExposure",BlueLED).toString());
            settings.endGroup();
            settings.beginGroup("50μm");
                ui->tableWidgetParameters->item(1,0)->setText(settings.value("AttachExposure",TattachMS).toString());
                ui->tableWidgetParameters->item(1,1)->setText(settings.value("TimeOfExposure",TbaseMS).toString());
                ui->tableWidgetParameters->item(1,2)->setText(settings.value("IntensityOfExposure",BlueLED).toString());
            settings.endGroup();
            settings.beginGroup("100μm");
                ui->tableWidgetParameters->item(2,0)->setText(settings.value("AttachExposure",TattachMS).toString());
                ui->tableWidgetParameters->item(2,1)->setText(settings.value("TimeOfExposure",TbaseMS).toString());
                ui->tableWidgetParameters->item(2,2)->setText(settings.value("IntensityOfExposure",BlueLED).toString());
            settings.endGroup();
        settings.endGroup();
    settings.endGroup();
}

void MaterialsCatalog::on_pushButtonAdd_clicked()
{
    bool ok;
    QString sMatName = QInputDialog::getText(this, tr("Material ID"),
                                         tr("Enter a short unique Identifier for this Material:"), QLineEdit::Normal,
                                         "MaterialID", &ok);
    if (!(ok && !sMatName.isEmpty())) return;
    if(ui->comboBoxMaterial->findText(sMatName,Qt::MatchFixedString)!=-1){
        QMessageBox::warning(this,tr("Duplicate Material ID!"),sMatName+" already exists in the Catalog.  Please enter a unique ID.",QMessageBox::Ok);
        return;
    }
    if (!ok) return;

    ui->comboBoxMaterial->addItem(sMatName);
    ui->comboBoxMaterial->setCurrentIndex(ui->comboBoxMaterial->count()-1);
}

void MaterialsCatalog::on_pushButtonDelete_clicked()
{
    if(vecName.size()<=0) return;
    QSettings settings;
    settings.beginGroup("MATERIALPARAMS");
    settings.remove(ui->comboBoxMaterial->currentText());
    int idx;
    for(idx=0;idx<vecName.size();idx++){
        if(vecName[idx]==ui->comboBoxMaterial->currentText())
            break;
    }
    vecName.erase(vecName.begin()+idx);
    ui->comboBoxMaterial->removeItem(ui->comboBoxMaterial->currentIndex());
    settings.endGroup();

}

void MaterialsCatalog::on_pushButtonSave_clicked()
{
    QSettings settings;
    settings.beginGroup("MATERIALPARAMS");
        settings.beginGroup(ui->comboBoxMaterial->currentText());
            //20
            settings.beginGroup("20μm");
                settings.setValue("AttachExposure",ui->tableWidgetParameters->item(0,0)->text());
                settings.setValue("TimeOfExposure",ui->tableWidgetParameters->item(0,1)->text());
                settings.setValue("IntensityOfExposure",ui->tableWidgetParameters->item(0,2)->text());
            settings.endGroup();
            if(ui->tableWidgetParameters->item(0,0)->text() == "0" ||
                    ui->tableWidgetParameters->item(0,1)->text() == "0" ||
                    ui->tableWidgetParameters->item(0,2)->text() == "0")
                settings.setValue("20_isValuid",0);
            else
                settings.setValue("20_isValuid",1);
            //50
            settings.beginGroup("50μm");
                settings.setValue("AttachExposure",ui->tableWidgetParameters->item(1,0)->text());
                settings.setValue("TimeOfExposure",ui->tableWidgetParameters->item(1,1)->text());
                settings.setValue("IntensityOfExposure",ui->tableWidgetParameters->item(1,2)->text());
            settings.endGroup();
            if(ui->tableWidgetParameters->item(1,0)->text() == "0" ||
                    ui->tableWidgetParameters->item(1,1)->text() == "0" ||
                    ui->tableWidgetParameters->item(1,2)->text() == "0")
                settings.setValue("50_isValuid",0);
            else
                settings.setValue("50_isValuid",1);
            //100
            settings.beginGroup("100μm");
                settings.setValue("AttachExposure",ui->tableWidgetParameters->item(2,0)->text());
                settings.setValue("TimeOfExposure",ui->tableWidgetParameters->item(2,1)->text());
                settings.setValue("IntensityOfExposure",ui->tableWidgetParameters->item(2,2)->text());
            settings.endGroup();
            if(ui->tableWidgetParameters->item(2,0)->text() == "0" ||
                    ui->tableWidgetParameters->item(2,1)->text() == "0" ||
                    ui->tableWidgetParameters->item(2,2)->text() == "0")
                settings.setValue("100_isValuid",0);
            else
                settings.setValue("100_isValuid",1);
        settings.endGroup();
    settings.endGroup();
    int idx;
    bool found = false;
    for(idx=0;idx<vecName.size();idx++){
        if(vecName[idx]==ui->comboBoxMaterial->currentText()){
            found = true;
            break;
        }
    }
    if(!found)
        vecName.push_back(ui->comboBoxMaterial->currentText());
}

void MaterialsCatalog::UpdateByLanguage(){
    if(language=="Chinese"){
        ui->groupBox_2->setWindowTitle("材料设定");
        ui->groupBox_2->setTitle("材料设定");
        ui->label_6->setText("材料:");
        QStringList headers;
        headers<<"基底曝光时间(秒)"<<"循环曝光时间(秒)"<<"曝光强度(0-255)";
        ui->tableWidgetParameters->setHorizontalHeaderLabels(headers);
        ui->pushButtonAdd->setText("添加");
        ui->pushButtonDelete->setText("删除");
        ui->pushButtonSave->setText("保存");
        ui->pushButtonCancel->setText("取消");
    }else if(language=="English"){
        ui->groupBox_2->setWindowTitle("Materials Setting");
        ui->groupBox_2->setTitle("Materials Setting");
        ui->label_6->setText("Material：");
        QStringList headers;
        headers<<"Attach Exposure(sec)"<<"Time of Exposure(sec)"<<"Intensity of Exposure(0-255)";
        ui->tableWidgetParameters->setHorizontalHeaderLabels(headers);
        ui->pushButtonAdd->setText("Add");
        ui->pushButtonDelete->setText("Delete");
        ui->pushButtonSave->setText("Save");
        ui->pushButtonCancel->setText("Cancel");
    }
}
