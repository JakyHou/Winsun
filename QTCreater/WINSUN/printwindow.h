#ifndef PRINTWINDOW_H
#define PRINTWINDOW_H
/*Dan
  打印前数据设定,包括切片模型选择,连接的打印机串口号,材料设定,需要打印的时间显示灯
*/
#include <QWidget>
#include <cycleprintsetting.h>
#include <print.h>
#include <crushbitmap.h>
#include <terminal.h>
#include <showslices.h>
#include "mainwindow.h"

#include <QSettings>
#ifdef Q_OS_WIN32
#include <qt_windows.h>
#endif
#include <QListWidgetItem>
#include <QFileInfo>
#include <QThread>

#include "dlpc350_common.h"
#include "dlpc350_firmware.h"

//class CrushedPrintJob;
class Terminal;
class ShowSlices;

class ComboBoxMaterialItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    ComboBoxMaterialItemDelegate(QObject *parent = 0);
    ~ComboBoxMaterialItemDelegate();

    virtual QWidget *createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const;
    virtual void setModelData ( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const;
};

class SleeperThread : public QThread
{
public:
    static void msleep(unsigned long msecs)
    {
        QThread::msleep(msecs);
    }
};

namespace Ui {
class PrintWindow;
}

class MainWindow;
class PrintWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PrintWindow(MainWindow* main,Terminal* pTerminal,QWidget *parent = 0);
    ~PrintWindow();
    void updateTimes();
    void setCPJ(CrushedPrintJob* pCPJ);
    void closeEvent(QCloseEvent * event );

    int getProjectorBlueLED();

signals:
    void accepted();


public slots:
    void setPrintEnable();

    void OnSetProjectorPowerOff();

    void onSetCommStatus(QString text);

    void onSetProjStatus(QString text);

    void setMaterial(int index);

private slots:
    void onBC_ConnectionStatusDetailed(QString sText);

    void on_pushButtonMaterialCatalog_clicked();

    void on_pushButtonCycSetting_clicked();

    void on_pushButtonPrint_clicked();

    void on_lineEditTgtPos_returnPressed();

    void on_pushButtonSelectAll_clicked();

    void on_spinBoxLayersToPrint_valueChanged(int arg1);

    void on_doubleSpinBoxTattachMS_valueChanged(double arg1);

    void on_spinBoxNumAttach_valueChanged(int arg1);

    void on_doubleSpinBoxTbaseMS_valueChanged(double arg1);

    void on_doubleSpinBoxToverMS_valueChanged(double arg1);

    void on_comboBoxMaterial_currentIndexChanged(const QString &arg1);

    void on_pushButtonCmdReset_clicked();

    void on_pushButtonShowSlice_clicked();

    void on_pushButtonBrowse_clicked();

    void on_pushButtonRestoreDefaults_clicked();

    void on_spinBoxRaiseSpd1_valueChanged(int arg1);

    void on_spinBoxLowerSpd1_valueChanged(int arg1);

    void on_doubleSpinBoxOverlift1_valueChanged(double arg1);

    void on_doubleSpinBoxBreathe1_valueChanged(double arg1);

    void on_pushButtonTerminal_clicked();

    void on_spinBox_BlueLEDExposure_valueChanged(int arg1);

    void on_pushButton_MaterialsEdit_clicked();

    void onBC_UpdateMaterialsCatalog();

    void on_toolButtonAdvanced_clicked();

public:
    int m_iTattachMS;
    int m_iNumAttach;
    int m_iTbaseMS;
    int m_iToverMS;
    bool m_bMirrored;
    bool m_bDryRun;
    int m_iLastLayer;
    CrushedPrintJob *newCPJ;
    MainWindow* pMain;

    bool BlueEnable;
    QString language;
//    bool isM50;

//    QSettings m_settings;
//    QString m_firmwarePath;
//    QString m_ptnImagePath;
//    QString m_outFileName;
//    QString m_csvFileName;
//    QFileInfo m_patternFile;
//    QTimer *m_usbPollTimer;
//    QString m_addedSplashImages[MAX_SPLASH_IMAGES];
//    bool m_isPrevModeStandBy;
//    int m_splashImageAddIndex;
//    int m_splashImageCount;
//    int m_splashImageAdded;
//    int m_splashImageRemoved;
//    int m_numExtraSplashLutEntries;
//    int m_extraSplashLutEntries[64];
//    unsigned int m_numImgInFlash;


    void UpdateByLanguage();
private:
    Ui::PrintWindow *ui;
    CrushedPrintJob *m_pCPJ;
    ShowSlices *pSliceView;
    Terminal *m_pTerminal;
    bool m_bInitializing;
    bool bShowAdvanced;

};

#endif // PRINTWINDOW_H
