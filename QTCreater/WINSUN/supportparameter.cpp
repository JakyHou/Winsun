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

    QSettings appSettings;
    appSettings.beginGroup("USERSET");
    language=appSettings.value("Language").toString();
    appSettings.endGroup();
    if(language!=""){
        UpdateByLanguage();
    }
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
    B9SupportStructure temp;//�����У����������ʾ����֧��
    //�Ͽ���ʱ����view������֧�Ż�һ�������
//    pMain->pWorldView->progress->show();//���ع�����������ȴ�ʱ�����
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
void SupportParameter::UpdateByLanguage(){
    if(language=="Chinese"){
        ui->checkBoxBase->setText("����");
        ui->radioButtonAdd->setText("���");
        ui->radioButtonDelete->setText("ɾ��");
        ui->pushButtonCleanAll->setText("ȫ��ɾ��");
        ui->label_8->setText("�ܶ�:");
        ui->pushButtonAutoSupport->setText("�Զ�֧��");
        ui->toolButtonAdvanced->setText("�߼�ѡ��");
//        QStringList headers;
//        headers<<"����"<<"�ϲ�"<<"�в�"<<"�²�";
//        ui->tabWidget->setHorizontalHeaderLabels(headers);
        ui->tabWidget->setTabText(0,"����");
        ui->tabWidget->setTabText(1,"�ϲ�");
        ui->tabWidget->setTabText(2,"�в�");
        ui->tabWidget->setTabText(3,"�²�");
        ui->label_16->setText("��״:");
        ui->label_14->setText("�뾶(mm)��");
        ui->label_15->setText("��(mm)��");
        ui->label->setText("��״:");
        ui->label_2->setText("��(mm)��");
        ui->label_3->setText("�뾶(mm):");
        ui->label_4->setText("��͸��:");
        ui->label_5->setText("�Ƕȣ�");
        ui->label_6->setText("��״:");
        ui->label_7->setText("�뾶(mm)��");
        ui->label_10->setText("��״:");
        ui->label_9->setText("��(mm)��");
        ui->label_11->setText("�뾶(mm):");
        ui->label_12->setText("��͸��:");
        ui->label_13->setText("�Ƕ�:");
        ui->pushButtonRestoreDefaults->setText("Ĭ��");
        ui->pushButtonSave->setText("����");
    }else{
        ui->checkBoxBase->setText("Base");
        ui->radioButtonAdd->setText("Add");
        ui->radioButtonDelete->setText("Delete");
        ui->pushButtonCleanAll->setText("Clean All");
        ui->label_8->setText("Density:");
        ui->pushButtonAutoSupport->setText("Auto Support");
        ui->toolButtonAdvanced->setText("Advanced Options");
//        QStringList headers;
//        headers<<"Base"<<"Top"<<"Mid"<<"Bottom";
//        ui->tabWidget->setHorizontalHeaderLabels(headers);
        ui->tabWidget->setTabText(0,"Base");
        ui->tabWidget->setTabText(1,"Top");
        ui->tabWidget->setTabText(2,"Mid");
        ui->tabWidget->setTabText(3,"Bottom");
        ui->label_16->setText("Shape:");
        ui->label_14->setText("Radius(mm)��");
        ui->label_15->setText("Height(mm)��");
        ui->label->setText("Shape��");
        ui->label_2->setText("Height(mm)��");
        ui->label_3->setText("Radius(mm):");
        ui->label_4->setText("Penetration:");
        ui->label_5->setText("Angle��");
        ui->label_6->setText("Shape��");
        ui->label_7->setText("Radius(mm)��");
        ui->label_10->setText("Shape��");
        ui->label_9->setText("Height(mm)��");
        ui->label_11->setText("Radius(mm):");
        ui->label_12->setText("Penetration:");
        ui->label_13->setText("Angle��");
        ui->pushButtonRestoreDefaults->setText("Default");
        ui->pushButtonSave->setText("Save");
    }
}
