#include "printwindow.h"
#include "ui_printwindow.h"
#include <QPushButton>
#include <QSettings>
#include <QMessageBox>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hidapi.h"

#include "dlpc350_common.h"
#include "dlpc350_error.h"
#include "dlpc350_usb.h"
#include "dlpc350_api.h"
#include "dlpc350_flashDevice.h"
#include "dlpc350_BMPParser.h"
#include "dlpc350_firmware.h"
#include "dlpc350_version.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QtGlobal>
#include <QThread>
#include <QTextStream>
#include <QListWidgetItem>
#include <QItemSelectionModel>
#include <QMenu>
#include <QPainter>
#include <QTimer>
#include <QTime>

#ifndef DEBUG_LOG_EN
//Enable MACRO to see debug logs
//#define DEBUG_LOG_EN
#include <QDebug>
#endif

#define MAX_NUM_RETRIES 5
#define TattachMS 8.0
#define TbaseMS 1.0
#define BlueLED 100


#include "Helper.h"

ComboBoxMaterialItemDelegate::ComboBoxMaterialItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

ComboBoxMaterialItemDelegate::~ComboBoxMaterialItemDelegate()
{
}

QWidget* ComboBoxMaterialItemDelegate::createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
    if(index.column() > 2 || index.column() < 0)
        return QStyledItemDelegate::createEditor(parent, option, index);

    // Create the label
    QLabel *lb = new QLabel(parent);
    lb->setEnabled(false);
    return lb;
}
void ComboBoxMaterialItemDelegate::setModelData ( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const
{
    if(QComboBox *cb = qobject_cast<QComboBox *>(editor))
        // save the current text of the combo box as the current value of the item
        model->setData(index, cb->currentText(), Qt::EditRole);
    else
        QStyledItemDelegate::setModelData(editor, model, index);
}

PrintWindow::PrintWindow(MainWindow* main,Terminal* pTerminal,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrintWindow)
{
    ui->setupUi(this);

    pMain = main;

    m_pCPJ = NULL;
    newCPJ = NULL;
    pSliceView = NULL;
    m_pTerminal = pTerminal;
    m_iTattachMS=10000;//cyp
    m_iNumAttach = 3;
    m_iTbaseMS=3000;
    m_iToverMS=0;
    m_bDryRun = true;//false;
    m_bMirrored = false;
    m_iLastLayer = 0;

    QSettings appSettings;
    appSettings.beginGroup("USERSET");
    language=appSettings.value("Language").toString();
    appSettings.endGroup();
    if(language!=""){
        UpdateByLanguage();
    }
    QObject::connect(m_pTerminal, SIGNAL(updateConnectionStatus(QString)), ui->commStatus, SLOT(showMessage(QString)));

    connect(m_pTerminal->pPrinterComm,SIGNAL(BC_CurrentZPosInPU(int)), this, SLOT(onBC_CurrentZPosInPU()));//ui->lineEditTgtPos setText(QString::number(int))
    connect(m_pTerminal->pPrinterComm,SIGNAL(BC_ConnectionStatusDetailed(QString)),this, SLOT(onBC_ConnectionStatusDetailed(QString)));
//    connect(m_pTerminal->pPrinterComm,SIGNAL(setProjStatus(QString)),ui->projectorStatus, SLOT(setText(QString)));
    QObject::connect(m_pTerminal, SIGNAL(setProjStatus(QString)), this, SLOT(onSetProjStatus(QString)));

//Dan Begin...
/*    QSettings settings;
    settings.beginGroup("cycsettings");
    settings.setValue("RSpd1",ui->spinBoxRaiseSpd1->value());
    settings.setValue("LSpd1",ui->spinBoxLowerSpd1->value());
    settings.setValue("OverLift1",ui->doubleSpinBoxOverlift1->value());
    settings.setValue("BreatheClosed1",ui->doubleSpinBoxBreathe1->value());
    settings.endGroup();
*/
    QSettings settings;//("cycsettings");
    settings.beginGroup("cycsettings");
    ui->spinBoxRaiseSpd1->setValue(settings.value("RSpd1",480).toInt());
    ui->spinBoxLowerSpd1->setValue(settings.value("LSpd1",480).toInt());
    ui->doubleSpinBoxBreathe1->setValue(settings.value("SettleOpen1",1).toDouble());
    ui->doubleSpinBoxOverlift1->setValue(settings.value("OverLift1",4).toDouble());
    settings.endGroup();
//Dan End...

//    m_pTerminal->pSettings->loadSettings();
//    ui->spinBoxRaiseSpd1->setValue(m_pTerminal->pSettings->m_iRSpd1);
//    ui->spinBoxLowerSpd1->setValue(m_pTerminal->pSettings->m_iLSpd1);
//    ui->doubleSpinBoxBreathe1->setValue(m_pTerminal->pSettings->m_dBreatheClosed1);
//    ui->doubleSpinBoxOverlift1->setValue(m_pTerminal->pSettings->m_dOverLift1);

    connect(m_pTerminal,SIGNAL(BC_ConnectionStatusDetailed(QString)), ui->commStatus, SLOT(setText(QString)));

//    QSettings settings;
    settings.beginGroup("MATERIALPARAMS");
        int count = settings.value("MATERIALCOUNT",0).toInt();
        settings.beginGroup("MATERIALNAMES");
            ui->comboBoxMaterial->clear();
            for(int i=0;i<count;i++){
                ui->comboBoxMaterial->addItem(settings.value("NO"+QString::number(i),"").toString());
            }
        settings.endGroup();
    settings.endGroup();
//    settings.beginGroup("MATERIALPARAMS");
//    int count = settings.value("MATERIALCOUNT",0).toInt();
//    ui->comboBoxMaterial->clear();
//    for(int i=0;i<count;i++){
//        ui->comboBoxMaterial->addItem(settings.value("NO"+QString::number(i),"").toString());
//    }
//    settings.endGroup();
    int index;
//    QSettings appSettings;
    settings.beginGroup("USERSET");
    if(settings.value("Material").toString() != "")//寻找上次选择的材料
        index = ui->comboBoxMaterial->findText(settings.value("Material").toString());
    else//找不到，默选第一个
        index = 0;
    settings.endGroup();
    ui->comboBoxMaterial->setCurrentIndex(index);

//    QObject::connect(ui->projectorStatus, SIGNAL(textChanged(QString)), pMain->pw, SLOT(onSetProjStatus(QString)));
//    QObject::connect(ui->commStatus, SIGNAL(textChanged(QString)), pMain->pw, SLOT(onSetCommStatus(QString)));

    bShowAdvanced = false;

    setFixedSize(this->width(),this->height());
}

PrintWindow::~PrintWindow()
{
    m_pTerminal->on_pushButtonProjPowerOFF_clicked();
    if(pSliceView)
        delete pSliceView;
    m_pCPJ = NULL;
    if(newCPJ){
        delete newCPJ;
        newCPJ =NULL;
    }
    delete ui;
}

void PrintWindow::closeEvent(QCloseEvent * event )
{
    if(m_pTerminal->pProjector)
        m_pTerminal->pProjector->hide();
    event->accept();
}

void PrintWindow::setCPJ(CrushedPrintJob* pCPJ)
{
    if(pCPJ == NULL){
        return;
    }
    //模型信息
    QString strPrinter = pCPJ->getPrinter();
    QSettings appSettings;
    appSettings.beginGroup("USERSET");
    if(appSettings.value("Printer").toString()!=strPrinter){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Hint");//提示
        msgBox.setText("\nThe printer of this file is different from the current printer\n\tThe file printer:"+strPrinter+
                       "\n\tthe current printer:"+appSettings.value("Printer").toString()+
                       "\nAre you sure you want to load it?\n");
        msgBox.setToolTip("\n该文件的打印机与当前的打印机不同\n\t该文件打印机："+strPrinter+
                          "\n\t当前打印机："+appSettings.value("Printer").toString()+
                          "\n确定要加载该文件吗？\n");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret = msgBox.exec();

        if(ret == QMessageBox::No)
            return;
    }

//    if(m_pCPJ){
//        m_pCPJ->clearAll();
//        delete m_pCPJ;
//        m_pCPJ = NULL;
//        pMain->m_pCPJ = NULL;
//    }
    m_pCPJ = pCPJ;
    pMain->m_pCPJ =  pCPJ;
//    m_pTerminal->setPrinter(m_pTerminal->m_iCPJModel);
    ui->lineEditName->setText(m_pCPJ->getName());
    this->setWindowTitle("Print-"+m_pCPJ->getName());
    this->setToolTip("Print-"+m_pCPJ->getName());
    ui->lineEditInfo->setText(strPrinter+" "+QString::number(1000*m_pCPJ->getZLayermm())+"μm");
    ui->lineEditXYPixelSizeMicrons->setText(QString::number(1000*m_pCPJ->getXYPixelmm()));
    ui->lineEditNumOfLayers->setText(QString::number(m_pCPJ->getTotalLayers()));
    ui->lineEditZSizeMicrons->setText(QString::number(1000*m_pCPJ->getZLayermm()));
    ui->lineEditZHeight->setText(QString::number(m_pCPJ->getZLayermm()*m_pCPJ->getTotalLayers()));

    ui->pushButtonSelectAll->setEnabled(false);
    ui->spinBoxLayersToPrint->setMinimum(1);
    ui->spinBoxLayersToPrint->setMaximum(m_pCPJ->getTotalLayers());
    ui->spinBoxLayersToPrint->setValue(m_pCPJ->getTotalLayers());
    ui->doubleSpinBoxZHeightToPrint->setValue(m_pCPJ->getZLayermm()*ui->spinBoxLayersToPrint->value());

//    int index;
//    QSettings appSettings;
//    appSettings.beginGroup("USERSET");
//    if(appSettings.value("Material").toString() != "")//寻找上次选择的材料
//        index = ui->comboBoxMaterial->findText(appSettings.value("Material").toString());
//    else//找不到，默选第一个
//        index = 0;
//    appSettings.endGroup();
//    ui->comboBoxMaterial->setCurrentIndex(index);

//    ui->doubleSpinBoxTattachMS->setValue(10);
//    ui->spinBoxNumAttach->setValue(3);
//    ui->doubleSpinBoxTbaseMS->setValue(3);
//    ui->doubleSpinBoxToverMS->setValue(0);

    m_pTerminal->getMatCat()->setCurXYIndex(((ui->lineEditXYPixelSizeMicrons->text().toInt()-25)/25)-1);

    onBC_UpdateMaterialsCatalog();
//    on_comboBoxMaterial_currentIndexChanged(ui->comboBoxMaterial->currentText());

    updateTimes();

}

int PrintWindow::getProjectorBlueLED()
{
    return ui->spinBox_BlueLEDExposure->value();
}

void PrintWindow::updateTimes()
{
    if(m_pCPJ != NULL){
        QTime vTimeRemains, t;
        int iTime = m_pTerminal->getEstCompleteTimeMS(0,m_iLastLayer,m_pCPJ->getZLayermm(),m_iTbaseMS+m_iToverMS);
        int iM = iTime/60000;
        int iH = iM/60;
        iM = (int)((double)iM+0.5) - iH*60;
        QString sLZ = ":0"; if(iM>9)sLZ = ":";
        QString sTimeRemaining = QString::number(iH)+sLZ+QString::number(iM);
        t.setHMS(0,0,0);
        vTimeRemains = t.addMSecs(iTime);
        ui->lineEditTimeRequired->setText(vTimeRemains.toString("hh:mm"));
        //ui->lcdNumberTimeRequired->display(vTimeRemains.toString("hh:mm"));
    }

}

void PrintWindow::onBC_ConnectionStatusDetailed(QString sText)
{
    ui->commStatus->setText(sText);
    if(m_pTerminal->pPrinterComm->isConnected()){
        ui->pushButtonPrint->setEnabled(true);
//        ui->pushButtonCmdReset->setEnabled(true);
        ui->lineEditTgtPos->setEnabled(true);
        ui->pushButtonStop->setEnabled(true);
        ui->pushButtonFindHomePos->setEnabled(true);
//        ui->pushButtonProjPowerON->setEnabled(true);
//        ui->pushButtonProjPowerOFF->setEnabled(true);
        ui->pushButtonBoardON->setEnabled(true);
        ui->pushButtonBoardOFF->setEnabled(true);
        ui->checkBox->setEnabled(true);
    }
    else{
        ui->pushButtonPrint->setEnabled(false);
//        ui->pushButtonCmdReset->setEnabled(false);
        ui->lineEditTgtPos->setEnabled(false);
        ui->pushButtonStop->setEnabled(false);
        ui->pushButtonFindHomePos->setEnabled(false);
//        ui->pushButtonProjPowerON->setEnabled(false);
//        ui->pushButtonProjPowerOFF->setEnabled(false);
        ui->pushButtonBoardON->setEnabled(false);
        ui->pushButtonBoardOFF->setEnabled(false);
        ui->checkBox->setEnabled(false);
    }
}

void PrintWindow::on_pushButtonMaterialCatalog_clicked()
{
//    QSettings settings;
//    settings.setValue("CurrentMaterialLabel",ui->comboBoxMaterial->currentText());
////    settings.setValue("CurrentXYLabel",ui->lineEditXYPixelSizeMicrons->text()+" (祄)");
////    m_pTerminal->dlgEditMatCat();

//    m_bInitializing = true;
//    int t = ui->comboBoxMaterial->count();
//    for(int i=0; i<m_pTerminal->getMatCat()->getMaterialCount(); i++){
//        ui->comboBoxMaterial->addItem(m_pTerminal->getMatCat()->getMaterialLabel(i));
//    }
//    for(int i=0; i<t; i++)ui->comboBoxMaterial->removeItem(0);
//    int index = ui->comboBoxMaterial->findText(settings.value("CurrentMaterialLabel","100").toString());
//    if(index<0)index=0;
//    ui->comboBoxMaterial->setCurrentIndex(index);
//    m_bInitializing = false;
}

void PrintWindow::on_pushButtonCycSetting_clicked()
{
    m_pTerminal->updateCycleValues();
    updateTimes();
}

void PrintWindow::on_pushButtonPrint_clicked()
{
    if(ui->lineEditInfo->text()==NULL){
        QMessageBox msg;
        if(language=="Chinese"){
            msg.setWindowTitle("提示");//提示
            msg.setText("\n请\n\t添加模型\n");
            //msg.setToolTip("\n请\n\t添加模型\n");
        }else{
            msg.setWindowTitle("Hint");//提示
            msg.setText("\nPlease\n\tadd a Model\n");
            //msg.setToolTip("\n请\n\t添加模型\n");
        }
        msg.setStandardButtons(QMessageBox::Yes);
        msg.exec();
        return;
    }
    QMessageBox msgBox;
    if(language=="Chinese"){
         msgBox.setWindowTitle("提示");//提示
         msgBox.setText("\n请确认:\n\t树脂是否备好\n");
         msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
         msgBox.setButtonText(QMessageBox::Yes,QString("是"));
         msgBox.setButtonText(QMessageBox::No,QString("否"));
    }else{
        msgBox.setWindowTitle("Hint");//提示
        msgBox.setText("\nPlease Sure:\n\tThe material has fallen in\n");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    }

//    msgBox.setWindowTitle("Hint");//提示
//    msgBox.setIcon(QMessageBox::Warning);
//    msgBox.setText("\n请确认:\n\t树脂是否备好\n");
//    msgBox.setText("\nPlease Sure:\n\tThe material has fallen in\n");
//    msgBox.setToolTip("\n请确认:\n\t树脂是否备好\n");
//    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//    msgBox.setButtonText(QMessageBox::Yes,QString("是"));
//    msgBox.setButtonText(QMessageBox::No,QString("否"));
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if(ret == QMessageBox::No)
        return;
    else{
//        emit accepted();
        ui->pushButtonPrint->setEnabled(false);
        if(!m_pTerminal->on_pushButtonProjPowerON_clicked()){
            if(language=="Chinese"){
                QMessageBox::information(this, tr("投影仪断开"),
                                               tr("请确认一下投影仪是否有连接.\n"),
                                               QMessageBox::Ok);
            }else{
                QMessageBox::information(this, tr("Projector Disconnect"),
                                               tr("Please confirm if the projector is connected.\n"),
                                               QMessageBox::Ok);
            }
        }
        QObject::connect(m_pTerminal, SIGNAL(HomeFound()), pMain, SLOT(doPrint()));
//        int iTimeoutEstimate = 30000; // 80 seconds (should never take longer than 75 secs from upper limit)

//        this->setEnabled(false);
//        // Remote activation of Reset (Find Home) Motion
//        m_pResetTimer->start(iTimeoutEstimate);
//        pPrinterComm->SendCmd("R");
//        resetLastSentCycleSettings();
        m_pTerminal->rcGotoFillAfterReset(-1);
        m_pTerminal->on_pushButtonCmdReset_clicked();
        //m_pTerminal->SetCycleParametersFromPrint(ui->spinBoxRaiseSpd1->value(),ui->spinBoxLowerSpd1->value(),ui->doubleSpinBoxOverlift1->value(),ui->doubleSpinBoxBreathe1->value());
    }
}

void PrintWindow::on_lineEditTgtPos_returnPressed()
{
    int iValue=ui->lineEditTgtPos->text().toInt();
    if(QString::number(iValue)!=ui->lineEditTgtPos->text()|| iValue<0 || iValue >15000){
        // Bad Value, just return
        ui->lineEditTgtPos->setText("Bad Value");
        return;
    }
    m_pTerminal->rcSendCmd("G"+QString::number(iValue));
}

void PrintWindow::on_pushButtonSelectAll_clicked()
{
    if(m_pCPJ){
        ui->spinBoxLayersToPrint->setValue(m_pCPJ->getTotalLayers());
        ui->doubleSpinBoxZHeightToPrint->setValue(m_pCPJ->getZLayermm()*ui->spinBoxLayersToPrint->value());
    }
}

void PrintWindow::on_spinBoxLayersToPrint_valueChanged(int arg1)
{
    if(m_pCPJ){
        m_iLastLayer = arg1;
        ui->pushButtonSelectAll->setEnabled(m_pCPJ->getTotalLayers()!=m_iLastLayer);
        ui->doubleSpinBoxZHeightToPrint->setValue(m_pCPJ->getZLayermm()*ui->spinBoxLayersToPrint->value());

        updateTimes();

    }
    else
        ui->spinBoxLayersToPrint->setValue(0);
}

void PrintWindow::on_doubleSpinBoxTattachMS_valueChanged(double arg1)
{
    m_iTattachMS = arg1 * 1000;
    updateTimes();
}

void PrintWindow::on_spinBoxNumAttach_valueChanged(int arg1)
{
    m_iNumAttach = arg1;
    updateTimes();
}

void PrintWindow::on_doubleSpinBoxTbaseMS_valueChanged(double arg1)
{
    m_iTbaseMS = arg1 * 1000;
    updateTimes();
}

void PrintWindow::on_doubleSpinBoxToverMS_valueChanged(double arg1)
{
    m_iToverMS = arg1 * 1000;
    updateTimes();
}

void PrintWindow::on_comboBoxMaterial_currentIndexChanged(const QString &arg1)
{
//    QSettings appSettings;
//    appSettings.beginGroup("USERSET");
//        appSettings.setValue("Material",ui->comboBoxMaterial->currentText());
//    appSettings.endGroup();

    if(!m_pCPJ) return;
    int thickness = 1000*m_pCPJ->getZLayermm();
    int iBlueLED;

    QSettings settings;
    settings.beginGroup("MATERIALPARAMS");
        settings.beginGroup(ui->comboBoxMaterial->currentText());
        settings.beginGroup(QString::number(1000*m_pCPJ->getZLayermm())+"μm");
            m_iTattachMS = settings.value("AttachExposure",TattachMS).toDouble() * 1000;
            m_iTbaseMS = settings.value("TimeOfExposure",TbaseMS).toDouble() * 1000;
            iBlueLED = settings.value("IntensityOfExposure",BlueLED).toInt();
//        if(thickness == 20){
//            settings.beginGroup("20μm");
//                m_iTattachMS = settings.value("AttachExposure",TattachMS).toDouble() * 1000;
//                m_iTbaseMS = settings.value("TimeOfExposure",TbaseMS).toDouble() * 1000;
//                iBlueLED = settings.value("IntensityOfExposure",BlueLED).toInt();
//        }
//        if(thickness == 50){
//            settings.beginGroup("50μm");
//                m_iTattachMS = settings.value("AttachExposure",TattachMS).toDouble() * 1000;
//                m_iTbaseMS = settings.value("TimeOfExposure",TbaseMS).toDouble() * 1000;
//                iBlueLED = settings.value("IntensityOfExposure",BlueLED).toInt();
//        }
//        if(thickness == 100){
//            settings.beginGroup("100μm");
//                m_iTattachMS = settings.value("AttachExposure",TattachMS).toDouble() * 1000;
//                m_iTbaseMS = settings.value("TimeOfExposure",TbaseMS).toDouble() * 1000;
//                iBlueLED = settings.value("IntensityOfExposure",BlueLED).toInt();
//        }
            settings.endGroup();
        settings.endGroup();
    settings.endGroup();

    m_pTerminal->onSetBlueLED(iBlueLED);//设置光强

    updateTimes();
//    ui->doubleSpinBoxTattachMS->setValue(dTattachMS);
//    ui->doubleSpinBoxTbaseMS->setValue(dTbaseMS);
}

void PrintWindow::on_pushButtonCmdReset_clicked()
{
    QMessageBox msgBox;
    if(language=="Chinese"){
        msgBox.setWindowTitle("提示");//提示
        msgBox.setText("\n请先确认打印机位置\n确定要复位打印机并打开投影仪吗？");//
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setButtonText(QMessageBox::Yes,QString("是"));
        msgBox.setButtonText(QMessageBox::No,QString("否"));
    }else{
        msgBox.setWindowTitle("Hint");//提示
        msgBox.setText("\nPlease confirm the printer location\nAre you sure to reset the printer and turn on the projector?");//
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    }
//    msgBox.setWindowTitle("Hint");//提示
//    msgBox.setIcon(QMessageBox::Warning);
//    msgBox.setText("\nPlease confirm the printer location\nAre you sure to reset the printer and turn on the projector?");//
//    msgBox.setToolTip("请先确认打印机位置\n确定要复位打印机并打开投影仪吗？");
//    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//    msgBox.setButtonText(QMessageBox::Yes,QString("是"));
//    msgBox.setButtonText(QMessageBox::No,QString("否"));
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if(ret == QMessageBox::No)
        return;
    else{
        m_pTerminal->on_pushButtonProjPowerON_clicked();
//        if(m_pTerminal->isM50){
            ui->pushButtonPrint->setEnabled(true);
//        }
//        else{//M100

//        }

        m_pTerminal->on_pushButtonCmdReset_clicked();
    }
}

void PrintWindow::on_pushButtonShowSlice_clicked()
{
    if(m_pCPJ){
        pSliceView = new ShowSlices(pMain,NULL);
        pSliceView->pCPJ = m_pCPJ;
        pSliceView->GoToSlice(0);
        pSliceView->UpdateWidgets();

        pSliceView->show();
    }
    else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Hint");//提示
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("\n Please select (.n3d) file\n");//
        msgBox.setToolTip("请选择切片文件！");
        msgBox.exec();
    }

}

void PrintWindow::on_pushButtonBrowse_clicked()
{
    QFileDialog dialog(0);
    QSettings settings("Dir");
    QString openFile = dialog.getOpenFileName(this,"Select Nepho3d_Studio File", settings.value("WorkingDir").toString(), tr("Nepho3d_Studio (*.n3d)"));//cyp .b9j
    if(openFile.isEmpty()) return;
    settings.setValue("WorkingDir", QFileInfo(openFile).absolutePath());


//    m_pCPJ->clearAll();

//    m_pCPJ = new CrushedPrintJob;
    QFile file(openFile);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("Error Loading File.  Unknown Version?");//"");
        msgBox.setToolTip("文件加载错误。未知版本？");
        msgBox.exec();
        return;
    }
    QDataStream in(&file);
//    newCPJ = new CrushedPrintJob;
    CrushedPrintJob *tempCPJ = new CrushedPrintJob();
    if(!tempCPJ->loadCPJ(in)) {
        tempCPJ->clearAll();
        delete tempCPJ;
        newCPJ = NULL;
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("Error Loading File.  Unknown Version?");//"");
        msgBox.setToolTip("文件加载错误。未知版本？");
        msgBox.exec();
        return;
    }
    if(newCPJ){
        newCPJ->clearAll();
        delete newCPJ;
    }
    newCPJ = tempCPJ;
//    if(!newCPJ->loadCPJ(&file)) {
//        QMessageBox msgBox;
//        msgBox.setWindowTitle("Nepho3D_Studio");//
//        msgBox.setText("Error Loading File.  Unknown Version?");//"");
//        msgBox.setToolTip("文件加载错误。未知版本？");
//        msgBox.exec();
//        delete newCPJ;
//        newCPJ = NULL;
//        return;
//    }
//    if(m_pCPJ){//释放之前的m_pCPJ内存空间
//        delete m_pCPJ;
//        m_pCPJ = NULL;
//        pMain->m_pCPJ = NULL;
//    }
    ui->checkBox->setChecked(false);
    newCPJ->showSupports(true);
    newCPJ->setName(openFile);//cyp
    setCPJ(newCPJ);
}

void PrintWindow::setMaterial(int index)
{
    ui->comboBoxMaterial->setCurrentIndex(index);

}

void PrintWindow::OnSetProjectorPowerOff()
{
//    ui->pushButtonPrint->setEnabled(false);
//    m_pTerminal->on_pushButtonBoardOFF_clicked();
    m_pTerminal->on_pushButtonProjPowerOFF_clicked();

//    if(m_pTerminal->pProjector)
//        m_pTerminal->pProjector->hide();
}

void PrintWindow::onSetCommStatus(QString text)
{
    ui->commStatus->setText(text);
}

void PrintWindow::onSetProjStatus(QString text)
{
    if(ui->projectorStatus->text()==text) return;
    ui->projectorStatus->setText(text);
//    if(text == "ON" && !m_pTerminal->isM50)
//        QTimer::singleShot(40000,this,SLOT(setPrintEnable()));
}

void PrintWindow::setPrintEnable()
{
    ui->pushButtonPrint->setEnabled(true);
}

void PrintWindow::on_pushButtonRestoreDefaults_clicked()
{
    ui->spinBoxRaiseSpd1->setValue(480);
    ui->spinBoxLowerSpd1->setValue(480);
    ui->doubleSpinBoxOverlift1->setValue(4);
    ui->doubleSpinBoxBreathe1->setValue(1.0);
}

void PrintWindow::on_spinBoxRaiseSpd1_valueChanged(int arg1)
{
    QSettings settings;//("cycsettings");
    settings.beginGroup("cycsettings");
    settings.setValue("RSpd1",arg1);
    settings.endGroup();
    m_pTerminal->pSettings->loadSettings();
    updateTimes();
}

void PrintWindow::on_spinBoxLowerSpd1_valueChanged(int arg1)
{
    QSettings settings;//("cycsettings");
    settings.beginGroup("cycsettings");
    settings.setValue("LSpd1",arg1);
    settings.endGroup();
    m_pTerminal->pSettings->loadSettings();
    updateTimes();
}

void PrintWindow::on_doubleSpinBoxOverlift1_valueChanged(double arg1)
{
    QSettings settings;//("cycsettings");
    settings.beginGroup("cycsettings");
    settings.setValue("OverLift1",arg1);
    settings.endGroup();
    m_pTerminal->pSettings->loadSettings();
    updateTimes();
}

void PrintWindow::on_doubleSpinBoxBreathe1_valueChanged(double arg1)
{
    QSettings settings;//("cycsettings");
    settings.beginGroup("cycsettings");
    settings.setValue("BreatheClosed1",arg1);
    settings.setValue("SettleOpen1",arg1);
    settings.endGroup();
    m_pTerminal->pSettings->loadSettings();
    updateTimes();
}

void PrintWindow::on_pushButtonTerminal_clicked()
{
    pMain->t->exec();
}

void PrintWindow::on_spinBox_BlueLEDExposure_valueChanged(int arg1)
{
    m_pTerminal->onSetBlueLED(arg1);
}

void PrintWindow::on_pushButton_MaterialsEdit_clicked()
{
    QSettings appSettings;
    appSettings.beginGroup("USERSET");
        appSettings.setValue("Material",ui->comboBoxMaterial->currentText());
    appSettings.endGroup();
    MaterialsCatalog dlg;
    dlg.exec();

    onBC_UpdateMaterialsCatalog();
}

void PrintWindow::onBC_UpdateMaterialsCatalog()
{
    QString strMatName;
    QSettings settings;
    settings.beginGroup("MATERIALPARAMS");
        int count = settings.value("MATERIALCOUNT",0).toInt();
            ui->comboBoxMaterial->clear();
            if(!m_pCPJ){
                settings.beginGroup("MATERIALNAMES");
                for(int i=0;i<count;i++){
                    ui->comboBoxMaterial->addItem(settings.value("NO"+QString::number(i),"").toString());
                }
                settings.endGroup();
            }
            else{//match job'pixel
                for(int i=0;i<count;i++){
                    settings.beginGroup("MATERIALNAMES");
                    strMatName = settings.value("NO"+QString::number(i),"").toString();
                    settings.endGroup();
                    settings.beginGroup(strMatName);
                    if(settings.value(QString::number(1000*m_pCPJ->getZLayermm())+"_isValuid").toBool())
                        ui->comboBoxMaterial->addItem(strMatName);
                    settings.endGroup();
                }
            }
    settings.endGroup();

    int index = 0;
    QSettings appSettings;
    appSettings.beginGroup("USERSET");
    if(appSettings.value("Material").toString() != "")//寻找上次选择的材料
        index = ui->comboBoxMaterial->findText(appSettings.value("Material").toString());
    if(index<0)//找不到，默选第一个
        index = 0;
    appSettings.endGroup();
    ui->comboBoxMaterial->setCurrentIndex(index);
    on_comboBoxMaterial_currentIndexChanged(ui->comboBoxMaterial->currentText());
}

void PrintWindow::on_toolButtonAdvanced_clicked()
{
//    QRect screenGeometry = this->geometry();

    bShowAdvanced = !bShowAdvanced;
    if(bShowAdvanced){
        setFixedSize(this->width(),578);
//        screenGeometry.setHeight(556);
//        this->setGeometry(screenGeometry);//0,0,357,556
        ui->toolButtonAdvanced->setArrowType(Qt::DownArrow);
    }
    else{
        setFixedSize(this->width(),289);
//        screenGeometry.setHeight(293);
//        this->setGeometry(screenGeometry);
        ui->toolButtonAdvanced->setArrowType(Qt::RightArrow);
    }

//m_pTerminal->dlgEditPrinterCycleSettings();
}
void PrintWindow::UpdateByLanguage(){
    if(language=="Chinese"){
        this->setWindowTitle("打印");
        ui->labelPrinter->setText("打印状态：");
        ui->groupBox->setTitle("参数");
        ui->label_12->setText("模型");
        ui->pushButtonBrowse->setText("浏览");
        ui->label_5->setText("材料：");
        ui->pushButton_MaterialsEdit->setText("编辑");
        ui->label_7->setText("剩余时间(hh:mm)：");
        ui->pushButtonPrint->setText("打印");
        ui->toolButtonAdvanced->setText("         高级选项");
        ui->groupBox_2->setTitle("设置");
        ui->label_16->setText("上升速度(mm/min)(120~800)");
        ui->label_14->setText("下降速度(mm/min)(120~800)");
        ui->label_15->setText("上升高度(mm)");
        ui->label_21->setText("缓冲时间(秒)");
        ui->pushButtonRestoreDefaults->setText("默认");
    }else{
        this->setWindowTitle("Print");
        ui->labelPrinter->setText("Printer Status：");
        ui->groupBox->setTitle("Parameters");
        ui->label_12->setText("model：");
        ui->pushButtonBrowse->setText("Browse");
        ui->label_5->setText("Material：");
        ui->pushButton_MaterialsEdit->setText("Edit");
        ui->label_7->setText("Time(hh:mm)：");
        ui->pushButtonPrint->setText("Print");
        ui->toolButtonAdvanced->setText("         Advanced Options");
        ui->groupBox_2->setTitle("setting");
        ui->label_16->setText("Raise Speed(mm/min)(120~800)");
        ui->label_14->setText("Lower Speed(mm/min)(120~800)");
        ui->label_15->setText("Raise Height(mm)");
        ui->label_21->setText("Wait for Exposure(sec)");
        ui->pushButtonRestoreDefaults->setText("Default");
    }
}
