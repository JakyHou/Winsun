#include "supportparameter.h"
#include "layout/modelinstance.h"
#include "ui_supportparameter.h"

SupportParameter::SupportParameter(QWidget *parent, MainWindow *main) :
    QWidget(parent),
    ui(new Ui::SupportParameter)
{
    ui->setupUi(this);
    pMain = main;
    m_pSettings = pMain->pSettings;
//    m_pSettings->loadSettings(); // load from system
//    updateDialog();
    for(size_t i = 0; i < B9SupportStructure::AttachmentDataList.size(); i++)
    {
        ui->Support_Top_AttachType_comboBox->addItem(B9SupportStructure::AttachmentDataList[i].GetName());
        ui->Support_Mid_AttachType_comboBox->addItem(B9SupportStructure::AttachmentDataList[i].GetName());
        ui->Support_Bottom_AttachType_comboBox->addItem(B9SupportStructure::AttachmentDataList[i].GetName());
        ui->Support_Base_AttachType_comboBox->addItem(B9SupportStructure::AttachmentDataList[i].GetName());
    }
    connect(pMain->pWorldView,SIGNAL(ComputeComplete(bool)), ui->pushButtonAutoSupport, SLOT(setEnabled(bool)));

    bShowAdvanced = false;
//    ui->pushButtonAutoSupport->hide();
}

SupportParameter::~SupportParameter()
{
    delete ui;
}

void SupportParameter::updateDialog()
{//Support_Base_Radius_doubleSpinBox

    ui->pushButtonAutoSupport->setEnabled(false);

    ui->doubleSpinBoxDensity->setValue(m_pSettings->m_autoDistance);

    ui->Support_Base_Coverage_horizontalSlider->setValue(m_pSettings->m_dBaseRadius/30*100);
    ui->Support_Base_Length_doubleSpinBox->setValue(m_pSettings->m_dBaseLength);
    ui->Support_Base_Radius_doubleSpinBox->setValue(m_pSettings->m_dBaseRadius);

    ui->Support_Top_Radius_doubleSpinBox->setValue(m_pSettings->m_dTopRadius);
    ui->Support_Top_Length_doubleSpinBox->setValue(m_pSettings->m_dTopLength);
    ui->Support_Top_Penetration_horizontalSlider->setValue(m_pSettings->m_dTopPenetration*100);
    ui->Support_Top_AngleFactor_horizontalSlider->setValue(m_pSettings->m_dTopAngleFactor*100);

    ui->Support_Mid_Radius_doubleSpinBox->setValue(m_pSettings->m_dMidRadius);

    ui->Support_Bottom_Radius_doubleSpinBox->setValue(m_pSettings->m_dBottomRadius);
    ui->Support_Bottom_Length_doubleSpinBox->setValue(m_pSettings->m_dBottomLength);
    ui->Support_Bottom_Penetration_horizontalSlider->setValue(m_pSettings->m_dBottomPenetration*100);
    ui->Support_Bottom_AngleFactor_horizontalSlider->setValue(m_pSettings->m_dBottomAngleFactor*100);


    int indx;
    indx = ui->Support_Base_AttachType_comboBox->findText(m_pSettings->m_baseAttachShape);
    ui->Support_Base_AttachType_comboBox->blockSignals(true);
        ui->Support_Base_AttachType_comboBox->setCurrentIndex(indx);
    ui->Support_Base_AttachType_comboBox->blockSignals(false);

    indx = ui->Support_Top_AttachType_comboBox->findText(m_pSettings->m_topAttachShape);
    ui->Support_Top_AttachType_comboBox->blockSignals(true);
     ui->Support_Top_AttachType_comboBox->setCurrentIndex(indx);
    ui->Support_Top_AttachType_comboBox->blockSignals(false);

    indx = ui->Support_Mid_AttachType_comboBox->findText(m_pSettings->m_midAttachShape);
    ui->Support_Mid_AttachType_comboBox->blockSignals(true);
     ui->Support_Mid_AttachType_comboBox->setCurrentIndex(indx);
    ui->Support_Mid_AttachType_comboBox->blockSignals(false);

    indx = ui->Support_Bottom_AttachType_comboBox->findText(m_pSettings->m_bottomAttachShape);
    ui->Support_Bottom_AttachType_comboBox->blockSignals(true);
     ui->Support_Bottom_AttachType_comboBox->setCurrentIndex(indx);
    ui->Support_Bottom_AttachType_comboBox->blockSignals(false);

    ui->radioButtonAdd->setChecked(true);

    B9SupportStructure* basePlate = pMain->SupportModeInst()->GetBasePlate();
//    int indx;

    if(basePlate == NULL)
    {
        ui->checkBoxBase->setChecked(false);
    }
    else
    {
        ui->checkBoxBase->setChecked(true);
        indx = ui->Support_Base_AttachType_comboBox->findText(basePlate->GetBottomAttachShape());
        ui->Support_Base_AttachType_comboBox->setCurrentIndex(indx);
        ui->Support_Base_Radius_doubleSpinBox->setValue(basePlate->GetBottomRadius());
        ui->Support_Base_Length_doubleSpinBox->setValue(basePlate->GetBottomLength());
    }
}

void SupportParameter::stuffSettings()
{
    m_pSettings->m_baseAttachShape = ui->Support_Base_AttachType_comboBox->currentText();
    m_pSettings->m_dBaseLength = ui->Support_Base_Length_doubleSpinBox->value();
    m_pSettings->m_dBaseRadius = ui->Support_Base_Radius_doubleSpinBox->value();

    m_pSettings->m_topAttachShape = ui->Support_Top_AttachType_comboBox->currentText();
    m_pSettings->m_dTopRadius = ui->Support_Top_Radius_doubleSpinBox->value();
    m_pSettings->m_dTopLength = ui->Support_Top_Length_doubleSpinBox->value();
    m_pSettings->m_dTopPenetration = ui->Support_Top_Penetration_horizontalSlider->value()*0.01;
    m_pSettings->m_dTopAngleFactor = ui->Support_Top_AngleFactor_horizontalSlider->value()*0.01;

    m_pSettings->m_midAttachShape = ui->Support_Mid_AttachType_comboBox->currentText();
    m_pSettings->m_dMidRadius = ui->Support_Mid_Radius_doubleSpinBox->value();

    m_pSettings->m_bottomAttachShape = ui->Support_Bottom_AttachType_comboBox->currentText();
    m_pSettings->m_dBottomRadius  = ui->Support_Bottom_Radius_doubleSpinBox->value();
    m_pSettings->m_dBottomLength = ui->Support_Bottom_Length_doubleSpinBox->value();
    m_pSettings->m_dBottomPenetration = ui->Support_Bottom_Penetration_horizontalSlider->value()*0.01;
    m_pSettings->m_dBottomAngleFactor = ui->Support_Bottom_AngleFactor_horizontalSlider->value()*0.01;

    m_pSettings->m_autoDistance = ui->doubleSpinBoxDensity->value();

    ui->Support_Base_Coverage_horizontalSlider->setValue(m_pSettings->m_dBaseRadius/30*100);

    m_pSettings->saveSettings();
}

void SupportParameter::on_pushButtonSave_clicked()
{
    stuffSettings();
}

void SupportParameter::on_radioButtonAdd_toggled(bool checked)
{
    if(checked){
        pMain->SetToolSupportAdd();
    }
}

void SupportParameter::on_radioButtonDelete_toggled(bool checked)
{
    if(checked){
        pMain->SetToolSupportDelete();
    }
}

void SupportParameter::on_pushButtonCleanAll_clicked()
{
    pMain->RemoveAllSupports();
}

void SupportParameter::on_pushButtonRestoreDefaults_clicked()
{
    m_pSettings->setFactorySettings();
    updateDialog();
    on_pushButtonSave_clicked();
    ui->pushButtonAutoSupport->setEnabled(true);
}

void SupportParameter::on_checkBoxBase_toggled(bool checked)
{
    pMain->OnBasePlatePropertiesChanged();
}

bool SupportParameter::getBaseIsChecked()
{
    return ui->checkBoxBase->isChecked();
}


void SupportParameter::on_Support_Base_Coverage_horizontalSlider_valueChanged(int value)
{
    m_pSettings->m_dBaseRadius = 30*value*0.01;
    ui->Support_Base_Radius_doubleSpinBox->setValue(m_pSettings->m_dBaseRadius);
//    QSettings appSettings("supportsettings");
    QSettings appSettings;
    appSettings.beginGroup("USERSUPPORTPARAMS");
    appSettings.setValue("BaseRadius",m_pSettings->m_dBaseRadius);//cyp
    appSettings.endGroup();
    if(ui->checkBoxBase->isChecked()){
        pMain->OnBasePlatePropertiesChanged();
    }
}

void SupportParameter::on_Support_Top_Penetration_horizontalSlider_valueChanged(int value)
{
    ui->Support_Top_Penetration_label->setText(QString::number(ui->Support_Top_Penetration_horizontalSlider->value()*0.01));

}

void SupportParameter::on_Support_Top_AngleFactor_horizontalSlider_valueChanged(int value)
{
    ui->Support_Top_AngleFactor_label->setText(QString::number(ui->Support_Top_AngleFactor_horizontalSlider->value()*0.01));

}

void SupportParameter::on_Support_Bottom_Penetration_horizontalSlider_valueChanged(int value)
{
    ui->Support_Bottom_Penetration_label->setText(QString::number(ui->Support_Bottom_Penetration_horizontalSlider->value()*0.01));

}

void SupportParameter::on_Support_Bottom_AngleFactor_horizontalSlider_valueChanged(int value)
{
    ui->Support_Bottom_AngleFactor_label->setText(QString::number(ui->Support_Bottom_AngleFactor_horizontalSlider->value()*0.01));

}


void SupportParameter::on_pushButtonAutoSupport_clicked()
{
    pMain->setButtonEnable(false);
//    pMain->pButtonSupport->setEnabled(false);
    B9SupportStructure temp;//必须有，否则可能显示不了支撑
    //断开定时更新view，否则支撑会一个个添加
//    pMain->pWorldView->progress->show();//来回滚动条，避免等待时间过长
    disconnect(pMain->pWorldView->pDrawTimer, SIGNAL(timeout()), pMain->pWorldView, SLOT(UpdateTick()));
    pMain->pWorldView->m_autoSupport->start();
//    pMain->pWorldView->OnToolAutoAddSupport();
}

void SupportParameter::on_toolButtonAdvanced_clicked()
{
    bShowAdvanced = !bShowAdvanced;
    if(bShowAdvanced){
        emit setSupportWidget(518);
        ui->toolButtonAdvanced->setArrowType(Qt::DownArrow);
    }
    else{
        emit setSupportWidget(195);
        ui->toolButtonAdvanced->setArrowType(Qt::RightArrow);
    }
//    ui->widget->setVisible(bShowAdvanced);
}

void SupportParameter::on_doubleSpinBoxDensity_editingFinished()
{
    m_pSettings->m_autoDistance = ui->doubleSpinBoxDensity->value();
    QSettings appSettings;
    appSettings.beginGroup("USERSUPPORTPARAMS");
        appSettings.setValue("AutoDistance",m_pSettings->m_autoDistance);
    appSettings.endGroup();
}
