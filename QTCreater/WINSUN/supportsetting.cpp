#include "supportsetting.h"
#include "ui_supportsetting.h"

SupportSetting::SupportSetting(PSupportSettings *pSettings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupportSetting)
{
    ui->setupUi(this);
    m_pSettings = pSettings;
    m_pSettings->loadSettings(); // load from system
    updateDialog();
}

SupportSetting::~SupportSetting()
{
    delete ui;
}

void SupportSetting::updateDialog()
{//Support_Base_Radius_doubleSpinBox
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

    for(size_t i = 0; i < B9SupportStructure::AttachmentDataList.size(); i++)
    {
        ui->Support_Top_AttachType_comboBox->addItem(B9SupportStructure::AttachmentDataList[i].GetName());
        ui->Support_Mid_AttachType_comboBox->addItem(B9SupportStructure::AttachmentDataList[i].GetName());
        ui->Support_Bottom_AttachType_comboBox->addItem(B9SupportStructure::AttachmentDataList[i].GetName());
        ui->Support_Base_AttachType_comboBox->addItem(B9SupportStructure::AttachmentDataList[i].GetName());
    }

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
}

void SupportSetting::stuffSettings()
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

}

void SupportSetting::on_pushButtonRestoreDefaults_clicked()
{
    m_pSettings->setFactorySettings();
    updateDialog();
}

void SupportSetting::on_pushButtonOK_clicked()
{
    stuffSettings();
    m_pSettings->saveSettings();
    close();
}

void SupportSetting::on_Support_Top_Penetration_horizontalSlider_valueChanged(int value)
{
    ui->Support_Top_Penetration_label->setText(QString::number(ui->Support_Top_Penetration_horizontalSlider->value()*0.01));
}

void SupportSetting::on_Support_Top_AngleFactor_horizontalSlider_valueChanged(int value)
{
    ui->Support_Top_AngleFactor_label->setText(QString::number(ui->Support_Top_AngleFactor_horizontalSlider->value()*0.01));

}

void SupportSetting::on_Support_Bottom_Penetration_horizontalSlider_valueChanged(int value)
{
    ui->Support_Bottom_Penetration_label->setText(QString::number(ui->Support_Bottom_Penetration_horizontalSlider->value()*0.01));

}

void SupportSetting::on_Support_Bottom_AngleFactor_horizontalSlider_valueChanged(int value)
{
    ui->Support_Bottom_AngleFactor_label->setText(QString::number(ui->Support_Bottom_AngleFactor_horizontalSlider->value()*0.01));

}
