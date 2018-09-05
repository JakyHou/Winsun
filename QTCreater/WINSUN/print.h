#ifndef PRINT_H
#define PRINT_H
/*Dan
  打印状态显示,包括剩余时间,完成时间,已完成切点数量,切片总数量等
*/
#include <QDialog>
#include <QWidget>
#include <QDateTime>
#include <QHideEvent>
#include <QSettings>
#include <QMessageBox>
#include <QTimer>
#include "helpsystem.h"
#include "terminal.h"
#include <time.h>

class Terminal;
//class CrushedPrintJob;

namespace Ui {
class Print;
}

class Print : public QDialog
{
    Q_OBJECT
    
public:
    explicit Print(Terminal *pTerm,QWidget *parent = 0);
    ~Print();
    void print3D(CrushedPrintJob *pCPJ, int iXOff, int iYOff, int iTbase, int iTover, int iTattach, int iNumAttach = 1, int iLastLayer = 0, bool bPrintPreview = false, bool bUsePrimaryMonitor = false, bool bIsMirrored = false);

signals:
    void eventHiding();
    void updateProjectorStatus(QString);
    void updateConnectionStatus(QString);
    void updateProjectorOutput(QString);
    void updateProjector(B9PrinterStatus::ProjectorStatus);
    void signalAbortPrint(QString);
    void PrintReleaseCycleFinished();
    void pausePrint();
    void sendStatusMsg(QString);
    void setProjectorPowerOff();

public slots:
    void setProjMessage(QString sText);//{m_pTerminal->rcSetProjMessage(sText);}
    QString updateTimes();

private slots:
    void showHelp(){}
    void on_updateConnectionStatus(QString sText);
    void on_updateProjectorOutput(QString sText){}
    void on_updateProjectorStatus(QString sText){}
    void on_updateProjector(B9PrinterStatus::ProjectorStatus eStatus);
    void on_signalAbortPrint();

    void exposeTBaseLayer();
    void startExposeTOverLayers();
    void exposureOfCurTintLayerFinished();
    void exposureOfTOverLayersFinished();

    void on_pushButtonPauseResume_clicked();

    void on_pushButtonAbort_clicked(QString sAbortText="User Directed Abort.");

//    void on_pushButtonAbort_clicked();

public:
    Ui::Print *ui;

    enum {PRINT_NO, PRINT_SETUP1, PRINT_SETUP2, PRINT_RELEASING, PRINT_EXPOSING, PRINT_ABORT, PRINT_DONE};
    enum {PAUSE_NO, PAUSE_WAIT, PAUSE_YES};

    void keyPressEvent(QKeyEvent * pEvent){
        QDialog::keyReleaseEvent(pEvent);}		// Handle key press events
    void hideEvent(QHideEvent *event){
        emit eventHiding();
        event->accept();
    }
    void closeEvent ( QCloseEvent * event ){
        event->ignore();
        on_pushButtonAbort_clicked();
    }

    double curLayerIndexMM(){// layer "0" has zero thickness
        return (double)m_iCurLayerNumber * m_dLayerThickness + 0.00001;
    }
    void setSlice(int iSlice);

    HelpSystem m_HelpSystem;

    Terminal* m_pTerminal;
    CrushedPrintJob* m_pCPJ;
    int m_iTbase,  m_iTover, m_iTattach, m_iNumAttach;
    int m_iXOff, m_iYOff;
    int m_iPrintState;
    int m_iCurLayerNumber;
    int m_iLastLayer;
    double m_dLayerThickness;
    int m_iPaused;
    bool m_bAbort;
    QString m_sAbortMessage;
    double m_dTintMS;
    int m_iTintNum, m_iCurTintIndex, m_iMinimumTintMS,m_iMinimumTintMSWorstCase;
    QTime m_vClock;
    QSettings m_vSettings;
    int m_minute;
    QString timeRemain;
    clock_t t1;
    clock_t t2;
    int count;
};

#endif // PRINT_H
