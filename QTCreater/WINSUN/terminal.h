#ifndef TERMINAL_H
#define TERMINAL_H
/*Dan
  对打印机的控制页面,软件ui未使用
*/
#include <QWidget>
#include <QDesktopWidget>
#include <QtGui/QWidget>
#include <QHideEvent>
#include <QTimer>
#include <QTime>
#include "printercomm.h"
#include "logfilemanager.h"
#include "projector.h"
#include "matcat.h"

#include "dlpc350_common.h"
#include "dlpc350_firmware.h"

#include "mainwindow.h"

class MainWindow;

#define COUNTOF( array )    (sizeof(array) / sizeof((array)[0]))


class PCycleSettings {
public:
    PCycleSettings(){loadSettings();}
    ~PCycleSettings(){}
    void updateValues(); // Opens a dialog and allows user to change settings

    void loadSettings();
    void saveSettings();
    void setFactorySettings();
    int m_iRSpd1, m_iLSpd1, m_iRSpd2, m_iLSpd2;
    int m_iOpenSpd1, m_iCloseSpd1, m_iOpenSpd2, m_iCloseSpd2;
    double m_dBreatheClosed1, m_dSettleOpen1, m_dBreatheClosed2, m_dSettleOpen2;
    double m_dOverLift1, m_dOverLift2;
    double m_dBTClearInMM;
    double m_dHardZDownMM;
    double m_dZFlushMM;
};

namespace Ui {
class Terminal;
}

class Terminal : public QDialog
{
    Q_OBJECT
    
public:
    explicit Terminal(MainWindow *main,QWidget *parent = 0);
    ~Terminal();
    void closeEvent(QCloseEvent * event );
    void UpdateExtentsUI();

    int GetDLPC350Status();
    void SetDLPC350InVideoMode();
    bool isConnected(){return pPrinterComm->isConnected();}

    double getHardZDownMM(){return pSettings->m_dHardZDownMM;}
    double getZFlushMM(){return pSettings->m_dZFlushMM;}

    int getEstBaseCycleTime(int iCur, int iTgt);
    int getEstNextCycleTime(int iCur, int iTgt);
    int getEstFinalCycleTime(int iCur, int iTgt);

    QTime getEstCompleteTime(int iCurLayer, int iTotLayers, double dLayerThicknessMM, int iExposeMS);
    int getEstCompleteTimeMS(int iCurLayer, int iTotLayers, double dLayerThicknessMM, int iExposeMS);
    int getLampAdjustedExposureTime(int iBaseTimeMS);

    B9MatCat* getMatCat() {return m_pCatalog;}

    void setUsePrimaryMonitor(bool bFlag){m_bUsePrimaryMonitor=bFlag; }
    bool getUsePrimaryMonitor(){return m_bUsePrimaryMonitor;}
    void setPrintPreview(bool bFlag){m_bPrintPreview=bFlag; }
    bool getPrintPreview(){return m_bPrintPreview;}
    void createNormalizedMask(double XYPS=0.1, double dZ = 257.0, double dOhMM = 91.088){
        pProjector->createNormalizedMask(XYPS, dZ, dOhMM);}//call when we show or resize

    int getXYPixelSize(){return pPrinterComm->getXYPixelSize();}

    void setIsPrinting(bool bFlag){
        pPrinterComm->m_bIsPrinting = bFlag;}
    void SetCycleParametersFromPrint(int iE, int iJ, double iK, double iL);

public slots:
    void showIt();
    void dlgEditMatCat();
    void dlgEditPrinterCycleSettings();

    void rcResetHomePos(){ on_pushButtonCmdReset_clicked();}
    void rcSendCmd(QString sCmd){ pPrinterComm->SendCmd(sCmd); }
    void rcResetCurrentPositionPU(int iCurPos){
        pPrinterComm->SendCmd("O"+QString::number(iCurPos)); }
    void rcBasePrint(double dBaseMM); // Position for Base Layer Exposure.
    void rcNextPrint(double dNextMM,QString progressValue,int minu); // Position for Next Layer Exposure.
    void rcFinishPrint(double dDeltaMM); // Calculates a final Z position at current + dDelta, closes vat, raises z, turns off projector.
    void rcSTOP(){ on_pushButtonStop_clicked();}
    void rcCloseVat();
    void rcSetWarmUpDelay(int iDelayMS){ pPrinterComm->setWarmUpDelay(iDelayMS); }
    void rcIsMirrored(bool bIsMirrored){  pPrinterComm->setMirrored(bIsMirrored); }

    void rcProjectorPwr(bool bPwrOn){on_pushButtonProjPower_toggled(bPwrOn);}
    void rcSetCPJ(CrushedPrintJob *pCPJ){
//        if(pCPJ == NULL)//cyp
//            emit setProjectorBlueLED(0);
//        else
//            emit setProjectorBlueLED(222);
        emit sendCPJ(pCPJ);
    } // Set the pointer to the CMB to be displayed, NULL if blank
    void rcCreateToverMap(int iRadius){pProjector->createToverMap(iRadius);}
    bool rcClearTimedPixels(int iLevel){return pProjector->clearTimedPixels(iLevel);}
    void rcSetProjMessage(QString sMsg);
    void rcGotoFillAfterReset(int iFillLevel){m_iFillLevel = iFillLevel;}

    void onScreenCountChanged(int iCount = 0);  // Signal that the number of monitors has changed

    void updateCycleValues(){pSettings->updateValues();}

signals:
    void signalAbortPrint(QString sMessage);
    void pausePrint();
    void updateConnectionStatus(QString sText); // Connected or Searching
    void updateProjectorOutput(QString sText);  // Data on video to projector connection
    void updateProjectorStatus(QString sText);  // Projector Power Status Changes
    void updateProjector(B9PrinterStatus::ProjectorStatus eStatus);
    void ProjectorIsOn();
    void PrintReleaseCycleFinished();

    void sendStatusMsg(QString text);					// signal to the Projector window to change the status msg
    void sendGrid(bool bshow);							// signal to the Projector window to update the grid display
    void sendCPJ(CrushedPrintJob * pCPJ);				// signal to the Projector window to show a crushed bit map image
    void sendXoff(int xOff);							// signal to the Projector window to update the X offset
    void sendYoff(int yOff);							// signal to the Projector window to update the Y offset

    void BC_ConnectionStatusDetailed(QString);

    void eventHiding();
    void HomeFound(); // Done with Reset
    void ZMotionComplete();

    void setProjectorBlueLED(int);

    void setProjStatus(QString);

public slots:
    void onSetBlueLED(int arg1){m_iBlueLED = arg1;}
    void timerTimeout(void);
    unsigned char CheckUart();
    void on_pushButton_Connect_clicked();
    void on_radioButton_VideoMode_clicked();
    void on_setProjectorBlueLED(int arg1 = 222);

    void on_pushButton_GetLEDConfiguration_clicked();

    void on_pushButton_SetLEDConfiguration_clicked();

    void on_pushButtonCmdReset_clicked();

    void on_pushButtonStop_clicked();

    //
    void setPrinterToModel1();
    void setPrinterToModel2();
    void setPrinter(int index);

    void on_printercombo_currentIndexChanged(int index = 0);

    void on_pushButtonResetHomePos_clicked();

//    void on_pushButtonBoardON_clicked();

//    void on_pushButtonBoardOFF_clicked();

    bool on_pushButtonProjPowerON_clicked();

    void on_pushButtonProjPowerOFF_clicked();


private slots:
    void on_pixelsizecombo_currentIndexChanged(const QString &arg1);

    void on_projectorcombo_currentIndexChanged(int index);


    void on_pushButtonProjPower_clicked();

    void on_pushButtonBoard_clicked();

    void on_pushButtonCycleSettings_clicked();

    void on_pushButtonPrintBase_clicked();

    void on_pushButtonPrintNext_clicked();

    void on_pushButtonPrintFinal_clicked();



    void makeProjectorConnections();
    void getKey(int iKey);					    // Signal that we received a (released) key from the projector


//    void sendCommand();
    void setProjectorPowerCmd(bool bPwrFlag){
        pPrinterComm->setProjectorPowerCmd(bPwrFlag);
    } // call to send projector power on/off command
    void onUpdateConnectionStatus(QString sText){
        emit (updateConnectionStatus(sText));
    }
    void onBC_ConnectionStatusDetailed(QString sText);
    void onUpdatePrinterComm(QString sText);
    void onUpdateRAWPrinterComm(QString sText);
    void onBC_LostCOMM();
    void onBC_ProjStatusChanged();
    void onBC_ProjStatusFAIL();

    void onMotionResetTimeout();
    void onMotionResetComplete();

    void onMotionVatTimeout();

    void onBC_ModelInfo(QString sModel);
    void onBC_FirmVersion(QString sVersion);
    void onBC_ProjectorRemoteCapable(bool bCapable);
    void onBC_HasShutter(bool bHS);
    void onBC_PU(int iPU);
    void onBC_UpperZLimPU(int iUpZLimPU);
    void onBC_CurrentZPosInPU(int iCZ);
    void onBC_CurrentVatPercentOpen(int iPO);
    void onBC_HalfLife(int iHL);
    void onBC_NativeX(int iNX);
    void onBC_NativeY(int iNY);
    void onBC_XYPixelSize(int iPS);

    void setTgtAltitudePU(int iTgtPU);
    void setTgtAltitudeMM(double iTgtMM);
    void setTgtAltitudeIN(double iTgtIN);

    void onBC_PrintReleaseCycleFinished();
    void onReleaseCycleTimeout();
    void SetCycleParameters();

    void on_lineEditCommand_returnPressed();

    void on_lineEditCurZPosInPU_returnPressed();

    void on_lineEditCurZPosInMM_returnPressed();

    void on_lineEditTgtZPU_editingFinished();

    void on_lineEditTgtZMM_editingFinished();

    void on_pushButtonProjPower_toggled(bool checked);

    void on_pushButtonFindHomePos_clicked();

    void on_checkBox_toggled(bool checked);

    void on_spinBox_BlueLEDCurrent_editingFinished();


    void on_projectorStatus_textChanged(const QString &arg1);

    void on_commStatus_editingFinished();

    void on_commStatus_textChanged(const QString &arg1);

    void on_toolButtonUp_clicked();

    void on_toolButtonDown_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonSubtract_clicked();

    void on_pushButtonCalibration_clicked();

public:
    B9PrinterComm *pPrinterComm;
    PCycleSettings *pSettings;
    B9Projector *pProjector;
    int  m_cx;//屏幕分辨率（长）

    int m_iCPJModel;

    bool BlueEnable;
//    bool isM50;

    int   iRadioButton;

    QSettings m_settings;
    QString m_firmwarePath;
    QString m_ptnImagePath;
    QString m_outFileName;
    QString m_csvFileName;
    QFileInfo m_patternFile;
    QTimer *m_usbPollTimer;
    QString m_addedSplashImages[MAX_SPLASH_IMAGES];
    bool m_isPrevModeStandBy;
    int m_splashImageAddIndex;
    int m_splashImageCount;
    int m_splashImageAdded;
    int m_splashImageRemoved;
    int m_numExtraSplashLutEntries;
    int m_extraSplashLutEntries[64];
    unsigned int m_numImgInFlash;
    QString m_progressValue;
    int m_minute;

private:
    Ui::Terminal *ui;
    MainWindow *pMain;
    void hideEvent(QHideEvent *event);

    int getZMoveTime(int iDelta, int iSpd);
    int getVatMoveTime(int iSpeed);


    B9MatCat* m_pCatalog;
    QString m_sModelName;
    int m_iD, m_iE, m_iJ, m_iK, m_iL, m_iW, m_iX;
    void resetLastSentCycleSettings(){m_iD=m_iE=m_iJ=m_iK=m_iL=m_iW=m_iX = -1;}

    LogFileManager *pLogManager;
    QDesktopWidget* m_pDesktop;
    bool m_bPrimaryScreen;
    bool m_bPrintPreview;
    bool m_bUsePrimaryMonitor;

    QTimer *m_pResetTimer;
    QTimer *m_pPReleaseCycleTimer;
    QTimer *m_pVatTimer;

    int m_iFillLevel;
    int m_UpperZLimPU;

    void setEnabledWarned(); // Set the enabled status based on connection and user response
    void warnSingleMonitor();
    bool m_bWaiverPresented;
    bool m_bWaiverAccepted;
    bool m_bWavierActive;
    bool m_bNeedsWarned;

    int m_iBlueLED;

    int m_iCurZPosInPU;
    int m_iTgtZPosInPU;
    double m_dCurZPosInMM;
    double m_dTgtZPosInMM;

};

#endif // TERMINAL_H
