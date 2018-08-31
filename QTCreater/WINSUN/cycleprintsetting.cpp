#include "cycleprintsetting.h"
#include "ui_cycleprintsetting.h"
#include <QDesktopWidget>
#include <QtGui/QWidget>
#include <QHideEvent>
#include <QTimer>
#include <QTime>

CyclePrintSetting::CyclePrintSetting(PCycleSettings *pSettings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CyclePrintSetting)
{
    ui->setupUi(this);
    m_pSettings = pSettings;
    m_pSettings->loadSettings(); // load from system
    updateDialog();
}

CyclePrintSetting::~CyclePrintSetting()
{
    delete ui;
}

void CyclePrintSetting::updateDialog()
{
    ui->spinBoxRaiseSpd1->setValue(m_pSettings->m_iRSpd1);
    ui->spinBoxLowerSpd1->setValue(m_pSettings->m_iLSpd1);

    ui->doubleSpinBoxOverlift1->setValue(m_pSettings->m_dOverLift1);
    ui->doubleSpinBoxBreathe1->setValue(m_pSettings->m_dBreatheClosed1);
    ui->doubleSpinBoxSettle1->setValue(m_pSettings->m_dSettleOpen1);


}

void CyclePrintSetting::stuffSettings()
{
    m_pSettings->m_iRSpd1 = ui->spinBoxRaiseSpd1->value();
    m_pSettings->m_iLSpd1 = ui->spinBoxLowerSpd1->value();
    m_pSettings->m_dOverLift1 = ui->doubleSpinBoxOverlift1->value();
    m_pSettings->m_dBreatheClosed1 = ui->doubleSpinBoxBreathe1->value();
    m_pSettings->m_dSettleOpen1 = ui->doubleSpinBoxSettle1->value();
}

void CyclePrintSetting::on_pushButtonRestoreDefaults_clicked()
{
    m_pSettings->setFactorySettings();
    updateDialog();
}

void CyclePrintSetting::on_buttonBox_clicked()
{

}

void CyclePrintSetting::on_pushButtonOK_clicked()
{
    stuffSettings();
    m_pSettings->saveSettings();
    close();
}

void CyclePrintSetting::on_buttonBox_accepted()
{
    stuffSettings();
    m_pSettings->saveSettings();
    close();
}

void CyclePrintSetting::on_buttonBox_rejected()
{
    close();
}
