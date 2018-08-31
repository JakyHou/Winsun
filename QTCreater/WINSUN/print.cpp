#include "print.h"
#include "ui_print.h"

Print::Print(Terminal *pTerm,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Print)
{
    ui->setupUi(this);
    m_pTerminal = pTerm;
    if(m_pTerminal == NULL) qFatal("FATAL Call to B9Creator with null B9Terminal Pointer");

//    // Clear old messages
//    ui->lineEditSerialStatus->setText("");
//    ui->lineEditProjectorOutput->setText("");

    m_iTbase = m_iTover = 0;
    m_iTattach = 0;
    m_iNumAttach = 1;
    m_iXOff = m_iYOff =0;
    m_iPrintState = PRINT_NO;
    m_iPaused = PAUSE_NO;
    m_bAbort = false;
    m_sAbortMessage = "Unknown Abort";
    m_iCurLayerNumber = 0;
    m_dLayerThickness = 0.0;
    m_iLastLayer = 0;
    t1=clock();
    t2=clock();
    count=0;

//    connect(m_pTerminal, SIGNAL(updateConnectionStatus(QString)), this, SLOT(on_updateConnectionStatus(QString)));
    connect(m_pTerminal, SIGNAL(updateProjectorOutput(QString)), this, SLOT(on_updateProjectorOutput(QString)));
    connect(m_pTerminal, SIGNAL(updateProjectorStatus(QString)), this, SLOT(on_updateProjectorStatus(QString)));
    connect(m_pTerminal, SIGNAL(updateProjector(B9PrinterStatus::ProjectorStatus)), this, SLOT(on_updateProjector(B9PrinterStatus::ProjectorStatus)));
    connect(m_pTerminal, SIGNAL(signalAbortPrint(QString)), this, SLOT(on_pushButtonAbort_clicked(QString)));
    connect(m_pTerminal, SIGNAL(PrintReleaseCycleFinished()), this, SLOT(exposeTBaseLayer()));
    connect(m_pTerminal, SIGNAL(pausePrint()), this, SLOT(on_pushButtonPauseResume_clicked()));
    connect(m_pTerminal, SIGNAL(sendStatusMsg(QString)),this, SLOT(setProjMessage(QString)));

    QString sTime = QDateTime::currentDateTime().toString("hh:mm");
    ui->lcdNumberTime->setDigitCount(9);
    ui->lcdNumberTime->display(sTime);

}

Print::~Print()
{
    delete ui;
}

void Print::print3D(CrushedPrintJob* pCPJ, int iXOff, int iYOff, int iTbase, int iTover, int iTattach, int iNumAttach, int iLastLayer, bool bPrintPreview, bool bUsePrimaryMonitor, bool bIsMirrored)
{
    // Note if, iLastLayer < 1, print ALL layers.
    // if bPrintPreview, run without turning on the projector


    this->setWindowTitle("Printing-"+pCPJ->getName());

    m_iMinimumTintMS = m_vSettings.value("m_iMinimumTintMS",50).toInt(); // Grab the old value
    if(m_iMinimumTintMS>500)
        m_iMinimumTintMS=555; // Should never get this big, fix it.
    else if (m_iMinimumTintMS<50)
        m_iMinimumTintMS=56;  // Or this little
    m_vSettings.setValue("m_iMinimumTintMS",(int)((double)m_iMinimumTintMS*.9)); //Set it back to 90% of it last value, just to keep it close to the edge

    m_iPrintState = PRINT_NO;
    m_pTerminal->setEnabled(false);
    m_pCPJ = pCPJ;
    m_pTerminal->createNormalizedMask(m_pCPJ->getXYPixelmm());
    m_iTbase = iTbase; m_iTover = iTover; m_iTattach = iTattach; m_iNumAttach = iNumAttach;
    m_iXOff = iXOff; m_iYOff = iYOff;
    m_iCurLayerNumber = 0;
    m_iPaused = PAUSE_NO;
    m_bAbort = false;
    m_iLastLayer = iLastLayer;
    if(m_iLastLayer<1)m_iLastLayer = m_pCPJ->getTotalLayers();

    m_pTerminal->setUsePrimaryMonitor(bUsePrimaryMonitor);
    m_pTerminal->setPrintPreview(bPrintPreview);
    m_pTerminal->onScreenCountChanged();
//    emit m_pTerminal->setProjectorBlueLED(222);
//    m_pTerminal->rcSendCmd("#0");

//    ui->lineEditJobName->setText(m_pCPJ->getName());
//    ui->lineEditJobDescription->setText(m_pCPJ->getDescription());
    ui->progressBarPrintProgress->setMinimum(0);
    ui->progressBarPrintProgress->setMaximum(m_iLastLayer);
    ui->progressBarPrintProgress->setValue(0);
    ui->lineEditLayerCount->setText("Total Layers To Print: "+QString::number(m_iLastLayer)+"  Powering up the projector.");
//    ui->lineEditLayerCount->setText("共有: "+QString::number(m_iLastLayer)+"层  正在打开投影仪...");

    ui->lcdNumberTime->display(m_pTerminal->getEstCompleteTime(m_iCurLayerNumber,m_iLastLayer,m_pCPJ->getZLayermm(),m_iTbase+m_iTover).toString("hh:mm"));
    QString sTimeUpdate = updateTimes();
    setProjMessage("Total Layers to print: "+QString::number(m_iLastLayer)+"  "+sTimeUpdate);
//    setProjMessage("共有: "+QString::number(m_iLastLayer)+"层  "+sTimeUpdate);

    if(!bPrintPreview){
        // Turn on the projector and set the warm up time in ms
        ui->pushButtonPauseResume->setEnabled(false);
        ui->pushButtonAbort->setEnabled(false);
        m_pTerminal->rcIsMirrored(bIsMirrored);
        m_pTerminal->rcSetWarmUpDelay(20000);
        m_pTerminal->rcProjectorPwr(true);
    }
    else {
//        ui->lineEditProjectorStatus->setText("OFF:  'Print Preview' Mode");
        ui->pushButtonPauseResume->setEnabled(true);
        ui->pushButtonAbort->setEnabled(true);
        m_iPrintState = PRINT_SETUP1;
        m_dLayerThickness = m_pCPJ->getZLayer().toDouble();
        m_pTerminal->rcBasePrint(-m_pTerminal->getHardZDownMM()); // Dynamic Z Zero, overshoot zero until we are down hard and motor 'skips'
    }
}

void Print::setProjMessage(QString sText)
{
    m_pTerminal->rcSetProjMessage(sText);
}


QString Print::updateTimes()
{   
    qDebug()<<"Print::updateTimes";
    t1=clock();
    qDebug()<<count<<" timeChange:"<<t1-t2;
    count++;
    QTime vTimeFinished, vTimeRemains, t;
    int iTime = m_pTerminal->getEstCompleteTimeMS(m_iCurLayerNumber,m_iLastLayer,m_pCPJ->getZLayermm(),m_iTbase+m_iTover);
    qDebug()<<"TimeAll:"<<iTime;
    int iM = iTime/60000;
    m_minute=iM;
    int iH = iM/60;
    iM = (int)((double)iM+0.5) - iH*60;
    QString sLZ = ":0"; if(iM>9)sLZ = ":";
    QString sTimeRemaining = QString::number(iH)+sLZ+QString::number(iM);
    timeRemain=sTimeRemaining;
    t.setHMS(0,0,0); vTimeRemains = t.addMSecs(iTime);
    vTimeFinished = QTime::currentTime().addMSecs(iTime);
    ui->lineEditLayerTimeCompletion->setText(vTimeFinished.toString("hh:mm AP"));
    ui->lineEditLayerTimeRemaining->setText(sTimeRemaining);
//    ui->lcdNumberTime->display(vTimeFinished.toString("hh:mm AP"));
//    ui->lcdNumberTimeRemaining->display(sTimeRemaining);
//    return "预计剩余时间: "+sTimeRemaining+"  预计完成时间: "+vTimeFinished.toString("hh:mm AP");
    return "Estimated time remaining: "+sTimeRemaining+"  Estimated Completion Time: "+vTimeFinished.toString("hh:mm AP");
}

void Print::on_updateConnectionStatus(QString sText)
{
    if(sText!=MSG_CONNECTED){
        ui->pushButtonAbort->setEnabled(false);
        ui->pushButtonPauseResume->setEnabled(false);
        ui->lineEditLayerCount->setText("Lost Contact with Nepho3d_Studio Printer.  Searching...");
    }
}

void Print::on_updateProjector(B9PrinterStatus::ProjectorStatus eStatus)
{
    if(m_iPrintState==PRINT_NO && eStatus==B9PrinterStatus::PS_ON){
        // Projector is warmed up and on!
        ui->pushButtonPauseResume->setEnabled(true); // Enable pause/resume & abort now
        ui->pushButtonAbort->setEnabled(true);
        m_iPrintState = PRINT_SETUP1;
        m_dLayerThickness = m_pCPJ->getZLayer().toDouble();
        m_pTerminal->rcBasePrint(-m_pTerminal->getHardZDownMM()); // Dynamic Z Zero, overshoot zero until we are down hard and motor 'skips'
    }
}
void Print::on_signalAbortPrint()
{
    if(m_iPrintState!=PRINT_ABORT) return;
    m_iPrintState=PRINT_NO;

    // Handle Abort Signals Here
    if(m_sAbortMessage.contains("Jammed Mechanism"))
        m_pTerminal->rcProjectorPwr(false); // Don't try to release if possibly jammed!
    else
        m_pTerminal->rcFinishPrint(5); //Finish at current z position + 5 mm, turn Projector Off

    m_pTerminal->onScreenCountChanged(); // toggles off the screen if needed for primary monitor setups
    hide();
    m_pTerminal->setUsePrimaryMonitor(false);
    m_pTerminal->setPrintPreview(false);
    m_pTerminal->onScreenCountChanged();
    m_pTerminal->setEnabled(true);

//    QMessageBox::information(0,"打印停止!","打印已停止\n\n"+m_sAbortMessage);

    QMessageBox::information(0,"Printing Aborted!","PRINT ABORTED\n\n"+m_sAbortMessage);
}


void Print::exposeTBaseLayer(){
    //Release & reposition cycle completed, time to expose the new layer
    if(m_iPrintState==PRINT_NO || m_iPrintState == PRINT_ABORT)return;

    if(m_iPrintState==PRINT_SETUP1){
        //We've used -  getHardZDownMM()to overshoot and get to here,
        // now reset current position to 0 and move up to + getZFlushMM
        m_pTerminal->rcResetCurrentPositionPU(0);
        m_pTerminal->rcBasePrint(m_pTerminal->getZFlushMM());
        m_iPrintState = PRINT_SETUP2;
        return;
    }

    if(m_iPrintState==PRINT_SETUP2){
        //We should now be flush
        // reset current position 0 and continue
        m_pTerminal->rcResetCurrentPositionPU(0);
        m_iPrintState = PRINT_RELEASING;
    }

    if(m_iPrintState == PRINT_DONE){
        m_iPrintState=PRINT_NO;
        m_pTerminal->setEnabled(true);
        if(m_pTerminal->getPrintPreview()){
            m_pTerminal->setPrintPreview(false);
            m_pTerminal->setUsePrimaryMonitor(false);
        }
        m_pTerminal->onScreenCountChanged();
        hide();
        return;
    }

    if(m_bAbort){
        // We're done, release and raise
        m_pTerminal->rcSetCPJ(NULL); //blank
        ui->pushButtonAbort->setText("Abort");
         m_iPrintState = PRINT_ABORT;
        on_signalAbortPrint();
        return;
    }

    //Start Tbase Print exposure
    ui->progressBarPrintProgress->setValue(m_iCurLayerNumber+1);
//    ui->lineEditLayerCount->setText("正在打印切片 "+QString::number(m_iCurLayerNumber+1)+" / "+QString::number(m_iLastLayer)+",  "+QString::number(100.0*(double)(m_iCurLayerNumber+1)/(double)m_iLastLayer,'f',1)+"% 完成");
    ui->lineEditLayerCount->setText("Creating Layer "+QString::number(m_iCurLayerNumber+1)+" of "+QString::number(m_iLastLayer)+",  "+QString::number(100.0*(double)(m_iCurLayerNumber+1)/(double)m_iLastLayer,'f',1)+"% Complete");
    setSlice(m_iCurLayerNumber);
    m_vClock.start(); // image is out there, start the clock running!
    QString sTimeUpdate = updateTimes();
    if(m_iPaused==PAUSE_WAIT){
        ui->lineEditLayerCount->setText("Pausing...");
        setProjMessage("Pausing...");//暂停
    }
    else{
        setProjMessage("(Press'p' to pause, 'a' to ABORT)  " + sTimeUpdate+"  Creating Layer "+QString::number(m_iCurLayerNumber+1)+" of "+QString::number(m_iLastLayer));
//        setProjMessage("(按'p' 暂停, 'a' 终止)  " + sTimeUpdate+"  正在打印切片 "+QString::number(m_iCurLayerNumber+1)+" / "+QString::number(m_iLastLayer));
    }
    m_iPrintState = PRINT_EXPOSING;
    // set timer
    int iAdjExposure = m_pTerminal->getLampAdjustedExposureTime(m_iTbase);
    if(m_iCurLayerNumber<m_iNumAttach) iAdjExposure = m_pTerminal->getLampAdjustedExposureTime(m_iTattach);  //First layers may have different exposure timing
    if(iAdjExposure>0){
        QTimer::singleShot(iAdjExposure-m_vClock.elapsed(), this, SLOT(startExposeTOverLayers()));
        return;
    }
    else
    {
        startExposeTOverLayers(); // If this is getting called, we're taking too long!
        qDebug() << "EXPOSURE TIMING ERROR:  Tbase exposed for too long!, Tbase is set too small or computer too slow?" << iAdjExposure;
        return;
    }
}

void Print::startExposeTOverLayers(){
    if(m_iCurLayerNumber==0){exposureOfTOverLayersFinished(); return;} //Skip this on first layer (0)

    m_vClock.start();  //restart for Tover interval pace

    m_iMinimumTintMS = m_vSettings.value("m_iMinimumTintMS",50).toInt(); // We default to 50ms but adjust it upwards when it gets hit.
    m_iMinimumTintMSWorstCase=m_iMinimumTintMS;//50*0.9=45

    int iAdjTover = m_pTerminal->getLampAdjustedExposureTime(m_iTover);
    m_iTintNum = (int)((double)iAdjTover/(double)m_iMinimumTintMS);//cyp ???
    if(m_iTintNum > 255) m_iTintNum = 255; // maximum number of time intervals we chop Tover into is 256

    m_dTintMS = (double)iAdjTover/(double)m_iTintNum; //cyp ??? The time of each interval in fractional ms, will always be >= m_iMinimumTintMS
    m_iCurTintIndex = 0;
    exposureOfCurTintLayerFinished();
}

void Print::exposureOfCurTintLayerFinished(){
    // Turn off the pixels at the curent point cyp???
    if(m_pTerminal->rcClearTimedPixels((double)m_iCurTintIndex*255.0/(double)m_iTintNum) || m_iCurTintIndex>=m_iTintNum)
    {
        exposureOfTOverLayersFinished();  // We're done with Tover
        m_vSettings.setValue("m_iMinimumTintMS",m_iMinimumTintMSWorstCase);
        return;
    }

    m_iCurTintIndex ++;
    int iAdjustedInt = (int)(m_dTintMS * (double)m_iCurTintIndex)-m_vClock.elapsed();
    if(iAdjustedInt>0){
        QTimer::singleShot(iAdjustedInt, this, SLOT(exposureOfCurTintLayerFinished()));
        return;
    }
    else
    {
        if(m_iCurTintIndex==1)m_iMinimumTintMSWorstCase=m_iMinimumTintMS-iAdjustedInt;
        exposureOfCurTintLayerFinished(); // If this is getting called, we're taking too long!
        return;
    }
}

void Print::exposureOfTOverLayersFinished(){
    if(m_iPrintState==PRINT_NO)return;

    m_pTerminal->rcSetCPJ(NULL); //blank
    //Cycle to next layer or finish
    if(m_iPaused==PAUSE_WAIT){
        m_iPaused=PAUSE_YES;
        m_pTerminal->rcSTOP();
//        m_pTerminal->rcCloseVat();
        ui->pushButtonPauseResume->setText("Resume");//继续
        ui->pushButtonPauseResume->setToolTip("恢复");
        ui->pushButtonPauseResume->setEnabled(true);
        ui->pushButtonAbort->setEnabled(true);
//        ui->lineEditLayerCount->setText("暂停.");
//        m_pTerminal->rcSetProjMessage(" 暂停.  按 'p' 继续打印, 'a' 终止打印.");
        ui->lineEditLayerCount->setText("Paused.  Manual positioning toggle switches are enabled.");
        m_pTerminal->rcSetProjMessage(" Paused.  Manual toggle switches are enabled.  Press 'p' when to resume printing, 'A' to abort.");
        return;
    }

    if(m_bAbort){
        // We're done
        m_pTerminal->rcSetCPJ(NULL); //blank
        ui->pushButtonAbort->setText("Abort");//终止
        m_iPrintState = PRINT_ABORT;
        on_signalAbortPrint();
        return;
    }
    else if(m_iCurLayerNumber==m_iLastLayer-1){
        // We're done, release and raise
        emit setProjectorPowerOff();
        ui->pushButtonAbort->setEnabled(false);
        ui->pushButtonPauseResume->setEnabled(false);
        m_iPrintState=PRINT_DONE;
        m_pTerminal->rcFinishPrint(30); //Finish at current z position + 50.8 mm, turn Projector Off
        ui->lineEditLayerCount->setText("Finished!");//完成
        setProjMessage("Finished!");
        return;
    }
    else
    {
        // do next layer
        m_iCurLayerNumber++;  // set the next layer number
        m_pTerminal->rcNextPrint(curLayerIndexMM(),"C"+QString::number(m_iCurLayerNumber+1)+"/"+QString::number(m_iLastLayer)+"T"+timeRemain/*QString::number(m_minute)*/,m_minute);
        m_iPrintState = PRINT_RELEASING;
//        ui->lineEditLayerCount->setText("剥离切片 "+QString::number(m_iCurLayerNumber)+", 重新定位切片 "+QString::number(m_iCurLayerNumber+1));
//        QString sTimeUpdate = updateTimes();
//        setProjMessage("(按'p' 暂停, 'a' 终止)  " + sTimeUpdate+"  释放并循环到 "+QString::number(m_iCurLayerNumber+1)+"/"+QString::number(m_iLastLayer));
        ui->lineEditLayerCount->setText("Releasing Layer "+QString::number(m_iCurLayerNumber)+", repositioning to layer "+QString::number(m_iCurLayerNumber+1));
        QString sTimeUpdate = updateTimes();
        setProjMessage("(Press'p' to pause, 'a' to ABORT)  " + sTimeUpdate+"  Release and cycle to Layer "+QString::number(m_iCurLayerNumber+1)+" of "+QString::number(m_iLastLayer));
     }
}

//void Print::keyPressEvent(QKeyEvent * pEvent){
//    QDialog::keyReleaseEvent(pEvent);}		// Handle key press events
//void Print::hideEvent(QHideEvent *event){
//    emit eventHiding();
//    event->accept();
//}
//void Print::closeEvent ( QCloseEvent * event ){
//    event->ignore();
//    on_pushButtonAbort_clicked();
//}

void Print::setSlice(int iSlice)
{
    if(m_iLastLayer<1)
        m_pTerminal->rcSetCPJ(NULL);
    else {
        m_pCPJ->setCurrentSlice(iSlice);
        m_pTerminal->rcSetCPJ(m_pCPJ);
    }
}


void Print::on_pushButtonPauseResume_clicked()
{
//    ui->pushButtonPauseResume->setEnabled(false);
    if(m_iPrintState == PRINT_NO) return; // not printing yet.

    if(m_iPaused==PAUSE_YES){
        // Time to Resume...
        m_iPaused = PAUSE_NO;
        ui->pushButtonPauseResume->setText("Pause");
        ui->pushButtonPauseResume->setToolTip("暂停");
//        ui->pushButtonPauseResume->setEnabled(true);//cyp0928 多次暂停
        ui->pushButtonAbort->setEnabled(true);
        exposureOfTOverLayersFinished();
    }
    else if(m_iPaused==PAUSE_NO){
        // Time to Pause....
        m_iPaused = PAUSE_WAIT;
        ui->pushButtonPauseResume->setText("Pause...");
        ui->pushButtonPauseResume->setToolTip("暂停...");
        ui->pushButtonPauseResume->setEnabled(false);
        ui->pushButtonAbort->setEnabled(false);
        setProjMessage("Pause...");
    }
}

void Print::on_pushButtonAbort_clicked(QString sAbortText)
{
    emit setProjectorPowerOff();
    //Prompt the User To Make Sure they want to abort.
    //only if the USER was the reason for abort...
//    if(sAbortText == "User Directed Abort.")
//    {
//        QMessageBox msgBox;
//        msgBox.setWindowTitle("Nepho3D_Studio");
//        msgBox.setText("确定要终止吗？");//Are you sure you want to abort?
//        msgBox.setIcon(QMessageBox::Warning);
//        msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
//        msgBox.setButtonText(QMessageBox::Yes,"是");
//        msgBox.setButtonText(QMessageBox::No,"否");
//        msgBox.setDefaultButton(QMessageBox::No);
//        int ret = msgBox.exec();

//        if(ret == QMessageBox::No)
//            return;
//    }

    m_sAbortMessage = sAbortText;
    if(m_sAbortMessage.contains("Jammed Mechanism")||m_sAbortMessage.contains("Lost Printer Connection")||
       (m_sAbortMessage.contains("Projector"))){
        // Special cases, always handle it asap.
        m_pTerminal->rcSetCPJ(NULL); //blank
        ui->pushButtonAbort->setText("Abort");
        m_iPrintState = PRINT_ABORT;
        on_signalAbortPrint();
        return;
    }

    if(m_iPrintState == PRINT_NO||m_iPrintState == PRINT_ABORT||m_iPaused==PAUSE_WAIT) return; // no abort if pausing, not printing or already aborting
    ui->pushButtonAbort->setText("Aborting...");//终止
    ui->lineEditLayerCount->setText("Aborting...");
    ui->pushButtonPauseResume->setEnabled(false);
    ui->pushButtonAbort->setEnabled(false);
    setProjMessage("Aborting...");
    m_bAbort = true;
    if(m_iPaused==PAUSE_YES) on_pushButtonPauseResume_clicked();
}
