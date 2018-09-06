
#include <QtDebug>
#include <QMessageBox>
#include <QSettings>
#include "terminal.h"
#include "ui_terminal.h"
#include "cycleprintsetting.h"

#include "hidapi.h"

#include "dlpc350_common.h"
#include "dlpc350_error.h"
#include "dlpc350_usb.h"
#include "dlpc350_api.h"
#include "dlpc350_flashDevice.h"
#include "dlpc350_BMPParser.h"
#include "dlpc350_firmware.h"
#include "dlpc350_version.h"


#define RAISE1 100
#define LOWER1 200
#define CLOSE1 0
#define OPEN1 0
#define BREATHE1 0.1
#define SETTLE1 3.0
#define OVERLIFT1 4.0

#define MAX_NUM_RETRIES 5
#define TGT 300

#include "Helper.h"


#include "windows.h"
#include "resource.h"
#include "Command.h"
#include <QMessageBox>
#include "uart.h"
FlashDevice g_FlashDevice;
static int g_FrameIdx=0;
static int g_VarExpFrameIdx=0;
static unsigned char *g_pImageBuffer;
QString g_displayStr_splashImageCount = "# Original Images: ";
QString g_displayStr_splashImageAddedCount = "Images Added: ";
QString g_displayStr_splashImageRemovedCount = "Images Removed: ";
QString g_displayStr_splashImageTotalCount = "Total Images: ";
QStringList g_iniGUITokens;

extern INIPARAM_INFO g_iniParam_Info[];

unsigned char UART_Port=0;
unsigned char u_Serial[10]={0};
unsigned long BaudRate[]={9600,115200};

#define MAIN_DIALOG_TITLE1 "3D Printer"
unsigned int FirmwareVersion=0x0001000B;//1.0.11

bool f_LedOff = true;

typedef enum _qListDataRoles
{
    TrigType,
    PatNum,
    BitDepth,
    LEDSelect,
    InvertPat,
    InsertBlack,
    BufSwap,
    trigOutPrev,
    frameIndex,
    PatExposure,
    PatPeriod,
}qListDataRoles;

typedef enum _trigInType
{
    IntTrig,
    ExtPos,
    ExtNeg,
    NoTrig,
}trigInType;

quint32 BitPlanes[24][8] =
{
    { 0x01, 0x03, 0x07, 0x0F, 0x3E, 0x3F, 0xFE, 0xFF },  //G0 Bit-depth 1-8
    { 0x02, 0x03, 0x07, 0x0F, 0x3E, 0x3F, 0xFE, 0xFF },  //G1 Bit-depth 1-8
    { 0x04, 0x0C, 0x07, 0x0F, 0x3E, 0x3F, 0xFE, 0xFF },  //G2 Bit-depth 1-8
    { 0x08, 0x0C, 0x38, 0x0F, 0x3E, 0x3F, 0xFE, 0xFF },  //G3 Bit-depth 1-8
    { 0x10, 0x30, 0x38, 0xF0, 0x3E, 0x3F, 0xFE, 0xFF },  //G4 Bit-depth 1-8
    { 0x20, 0x30, 0x38, 0xF0, 0x3E, 0x3F, 0xFE, 0xFF },  //G5 Bit-depth 1-8
    { 0x40, 0xC0, 0x1C0, 0xF0, 0xF80, 0xFC0,0xFE, 0xFF },  //G6 Bit-depth 1-8
    { 0x80, 0xC0, 0x1C0, 0xF0, 0xF80, 0xFC0,0xFE, 0xFF }, //G7 Bit-depth 1-8


    { 0x0100, 0x0300, 0x1C0, 0xF00, 0xF80,     0xFC0,   0xFE00, 0xFF00 },  //R0 Bit-depth 1-8
    { 0x0200, 0x0300, 0xE00, 0xF00, 0xF80,     0xFC0,   0xFE00, 0xFF00 },  //R1 Bit-depth 1-8
    { 0x0400, 0x0C00, 0xE00, 0xF00, 0xF80,     0xFC0,   0xFE00, 0xFF00 },  //R2 Bit-depth 1-8
    { 0x0800, 0x0C00, 0xE00, 0xF00, 0xF80,     0xFC0,   0xFE00, 0xFF00 },  //R3 Bit-depth 1-8
    { 0x1000, 0x3000, 0x7000, 0xF000, 0x3E000,        0x3F000, 0xFE00, 0xFF00 },  //R4 Bit-depth 1-8
    { 0x2000, 0x3000, 0x7000, 0xF000, 0x3E000,  0x3F000, 0xFE00, 0xFF00 },  //R5 Bit-depth 1-8
    { 0x4000, 0xC000, 0x7000, 0xF000, 0x3E000, 0x3F000, 0xFE00, 0xFF00 },  //R6 Bit-depth 1-8
    { 0x8000, 0xC000, 0x38000, 0xF000, 0x3E000, 0x3F000, 0xFE00, 0xFF00 }, //R7 Bit-depth 1-8

    { 0x010000, 0x030000, 0x38000, 0xF0000,   0x3E000,  0x3F000,  0xFE0000, 0xFF0000 },  //B0 Bit-depth 1-8
    { 0x020000, 0x030000, 0x38000, 0xF0000,   0x3E000,  0x3F000,  0xFE0000, 0xFF0000 },  //B1 Bit-depth 1-8
    { 0x040000, 0x0C0000, 0x1C0000, 0xF0000,  0xF80000,   0xFC0000, 0xFE0000, 0xFF0000 },  //B2 Bit-depth 1-8
    { 0x080000, 0x0C0000, 0x1C0000, 0xF0000,  0xF80000, 0xFC0000, 0xFE0000, 0xFF0000 },  //B3 Bit-depth 1-8
    { 0x100000, 0x300000, 0x1C0000, 0xF00000, 0xF80000, 0xFC0000, 0xFE0000, 0xFF0000 },  //B4 Bit-depth 1-8
    { 0x200000, 0x300000, 0xE00000, 0xF00000, 0xF80000, 0xFC0000, 0xFE0000, 0xFF0000 },  //B5 Bit-depth 1-8
    { 0x400000, 0xC00000, 0xE00000, 0xF00000, 0xF80000, 0xFC0000, 0xFE0000, 0xFF0000 },  //B6 Bit-depth 1-8
    { 0x800000, 0xC00000, 0xE00000, 0xF00000, 0xF80000, 0xFC0000, 0xFE0000, 0xFF0000 },  //B7 Bit-depth 1-8
};

static int My_FileRead(void *Param, unsigned char *Data, unsigned int Size)
{
    QDataStream *pIn = (QDataStream *)Param;

    if(Data == NULL)
    {
        return 0;
    }
    else if(Size > 0)
    {
        if(pIn->readRawData((char *)Data, Size) <= 0)
            return -1;
    }

    return 0;
}

static int My_ImgeDraw(void *Param, unsigned int X, unsigned int Y, \
                       unsigned char *Pix, unsigned int Count)
{
    // LSB 5 bits represent where to place the pixel in stitched output image
    unsigned char bitPos = *(unsigned char *)Param & 0x1F;

    //MSB 3-bits represent bit depth of input image (zero based)
    unsigned char bitDepth = (*(unsigned char *)Param >> 5) + 1;

#ifdef DEBUG_LOG_EN
    qDebug() << "BitDepth = " << bitDepth << "BitPos = " << bitPos;
#endif

    if(bitPos > 23)
        return 0;

    if(X >= PTN_WIDTH || Y >= PTN_HEIGHT)
        return 0;

    if(X + Count > PTN_WIDTH)
    {
        Count = PTN_WIDTH - X;
    }

    unsigned mask = ((1 << bitDepth) - 1);
    unsigned char *pixPtr = (g_pImageBuffer + \
                             (X + Y * PTN_WIDTH)*BYTES_PER_PIXEL);
    unsigned inPix;

    for(unsigned i=0; i<Count; i++)
    {

        //GRB format as used in the splash - pixPtr[0] B[7:0], pixPtr[1] G[7:0], pixPtr[2] R[7:0]
        //inPix = pixPtr[0] | (pixPtr[1] << 8) | (pixPtr[2] << 16);

        //pixPtr[0] = B[7:0] = 7:0
        //pixPtr[1] = G[7:0] = 15:8
        //pixPtr[2] = R[7:0] = 23:16

        //Default is in RGB format, convert => to GRB format as used in DLPC350
        //G[7:0] - 7:0
        //R[7:0] - 15:8
        //B[7:0] - 23:16

        inPix = (pixPtr[0]<<16) | (pixPtr[1]) | (pixPtr[2] << 8);

        //Modify pixel value as passed in Pix[] 8-bit variable as given position
        inPix = ((inPix & ~(mask << bitPos)) | ((Pix[i]) << bitPos));

        //Revert back to RGB format before storing
        pixPtr[0] = (inPix >> 16) & 0xFF;
        pixPtr[1] = (inPix) & 0xFF;
        pixPtr[2] = (inPix >> 8) & 0xFF;
        pixPtr += 3;
    }
    return 0;
}

static int My_FileWrite(void *Param, unsigned char *Data, unsigned int Size)
{
    QFile *pOutFile = (QFile *)Param;

    if(Data == NULL)
    {
        if(pOutFile->seek(Size) != true)
            return -1;
    }
    else if(Size > 0)
    {
        if(pOutFile->write((char *)Data, Size) <= 0)
            return -1;
    }

    return 0;
}

static int My_ImgeGet(void *Param, unsigned int X, unsigned int Y, \
                      unsigned char *Pix, unsigned int Count)
{
    if(Param == NULL)
        Param = NULL;

    if(X >= PTN_WIDTH || Y >= PTN_HEIGHT)
        return 0;
    if(X + Count > PTN_WIDTH)
    {
        Count = PTN_WIDTH - X;
    }
    memcpy(Pix, g_pImageBuffer + (X + Y * PTN_WIDTH) * BYTES_PER_PIXEL,\
           Count * BYTES_PER_PIXEL);
    return 0;
}


void PCycleSettings::updateValues()
{
    CyclePrintSetting dlg(this);
    dlg.exec();
}

void PCycleSettings::loadSettings()
{

    QSettings settings;//("cycsettings");
    settings.beginGroup("cycsettings");
   m_iRSpd1 = int(settings.value("RSpd1",RAISE1).toInt()/4);//
   m_iLSpd1 = int(settings.value("LSpd1",LOWER1).toInt()/4);//
    m_iCloseSpd1 = 0;//settings.value("CloseSpd1",CLOSE1).toInt();
    m_iOpenSpd1 = 0;//settings.value("OpenSpd1",OPEN1).toInt();
    //m_dBreatheClosed1 = 0;//settings.value("BreatheClosed1",BREATHE1).toDouble();
    m_dBreatheClosed1 = settings.value("BreatheClosed1",BREATHE1).toDouble();
    m_dSettleOpen1 = settings.value("SettleOpen1",SETTLE1).toDouble();
    m_dOverLift1 = settings.value("OverLift1",OVERLIFT1).toDouble();

    settings.endGroup();
}

void PCycleSettings::saveSettings()
{
    QSettings settings;//("cycsettings");
    settings.beginGroup("cycsettings");
    settings.setValue("RSpd1",m_iRSpd1);

    settings.setValue("LSpd1",m_iLSpd1);
    settings.setValue("CloseSpd1",m_iCloseSpd1);
    settings.setValue("OpenSpd1",m_iOpenSpd1);
    settings.setValue("BreatheClosed1",m_dBreatheClosed1);
    settings.setValue("SettleOpen1",m_dSettleOpen1);
    settings.setValue("OverLift1",m_dOverLift1);
    settings.endGroup();

}

void PCycleSettings::setFactorySettings()
{
    m_iRSpd1 = RAISE1;
    qDebug()<<"m_iRSpd1 = RAISE1:"<<RAISE1;
    m_iLSpd1 = LOWER1;
    m_iOpenSpd1 = OPEN1;
    m_iCloseSpd1 = CLOSE1;
    m_dBreatheClosed1 = BREATHE1;
    m_dSettleOpen1 = SETTLE1;
    m_dOverLift1 = OVERLIFT1;
}



Terminal::Terminal(MainWindow *main,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Terminal)
{
    pMain = main;
    m_iCPJModel = 2;
    m_iBlueLED = 100;
    m_bWaiverPresented = false;
    m_bWaiverAccepted = false;
    m_bWavierActive = false;
    m_bNeedsWarned = true;
    m_iFillLevel = -1;

    iRadioButton=IDC_RADIO_B;

    ui->setupUi(this);

//    QObject::connect(ui->projectorStatus, SIGNAL(textChanged(QString)), pMain->pw, SLOT(onSetProjStatus(QString)));
//    QObject::connect(ui->commStatus, SIGNAL(textChanged(QString)), pMain->pw, SLOT(onSetCommStatus(QString)));

    ui->commStatus->setText("Searching for Nepho3d_Studio printer...");//B9Creator

    m_pCatalog = new B9MatCat;
    onBC_ModelInfo("B9C1");

    pSettings = new PCycleSettings;
    resetLastSentCycleSettings();

    pPrinterComm = new B9PrinterComm;
    pPrinterComm->enableBlankCloning(false/*true*/); // Allow for firmware update of suspected "blank" B9Creator Arduino's

    // Always set up the B9Projector in the Terminal constructor
    m_pDesktop = QApplication::desktop();
    pProjector = NULL;
    m_bPrimaryScreen = false;
    m_bPrintPreview = false;
    m_bUsePrimaryMonitor = false;

    connect(m_pDesktop, SIGNAL(screenCountChanged(int)),this, SLOT(onScreenCountChanged(int)));

    connect(pPrinterComm,SIGNAL(updateConnectionStatus(QString)), this, SLOT(onUpdateConnectionStatus(QString)));
    connect(pPrinterComm,SIGNAL(BC_ConnectionStatusDetailed(QString)), this, SLOT(onBC_ConnectionStatusDetailed(QString)));
    connect(pPrinterComm,SIGNAL(BC_LostCOMM()),this,SLOT(onBC_LostCOMM()));

    connect(pPrinterComm,SIGNAL(BC_RawData(QString)), this, SLOT(onUpdateRAWPrinterComm(QString)));
    connect(pPrinterComm,SIGNAL(BC_Comment(QString)), this, SLOT(onUpdatePrinterComm(QString)));

    connect(pPrinterComm,SIGNAL(BC_ModelInfo(QString)),this,SLOT(onBC_ModelInfo(QString)));
    connect(pPrinterComm,SIGNAL(BC_FirmVersion(QString)),this,SLOT(onBC_FirmVersion(QString)));
    connect(pPrinterComm,SIGNAL(BC_ProjectorRemoteCapable(bool)), this, SLOT(onBC_ProjectorRemoteCapable(bool)));
    connect(pPrinterComm,SIGNAL(BC_HasShutter(bool)), this, SLOT(onBC_HasShutter(bool)));
    connect(pPrinterComm,SIGNAL(BC_ProjectorStatusChanged()), this, SLOT(onBC_ProjStatusChanged()));
    connect(pPrinterComm,SIGNAL(BC_ProjectorFAIL()), this, SLOT(onBC_ProjStatusFAIL()));

    // Z Position Control
    connect(pPrinterComm, SIGNAL(BC_PU(int)), this, SLOT(onBC_PU(int)));
    connect(pPrinterComm, SIGNAL(BC_UpperZLimPU(int)), this, SLOT(onBC_UpperZLimPU(int)));
    m_pResetTimer = new QTimer(this);
    connect(m_pResetTimer, SIGNAL(timeout()), this, SLOT(onMotionResetTimeout()));
    connect(pPrinterComm, SIGNAL(BC_HomeFound()), this, SLOT(onMotionResetComplete()));
    connect(pPrinterComm, SIGNAL(BC_CurrentZPosInPU(int)), this, SLOT(onBC_CurrentZPosInPU(int)));
    connect(pPrinterComm, SIGNAL(BC_HalfLife(int)), this, SLOT(onBC_HalfLife(int)));
    connect(pPrinterComm, SIGNAL(BC_NativeX(int)), this, SLOT(onBC_NativeX(int)));
    connect(pPrinterComm, SIGNAL(BC_NativeY(int)), this, SLOT(onBC_NativeY(int)));
    connect(pPrinterComm, SIGNAL(BC_XYPixelSize(int)), this, SLOT(onBC_XYPixelSize(int)));

//    connect(ui->lineEditCommand, SIGNAL(returnPressed()), Terminal, SLOT(sendCommand()));

//    m_pVatTimer = new QTimer(this);
//    connect(m_pVatTimer, SIGNAL(timeout()), this, SLOT(onMotionVatTimeout()));
    connect(pPrinterComm, SIGNAL(BC_CurrentVatPercentOpen(int)), this, SLOT(onBC_CurrentVatPercentOpen(int)));

    m_pPReleaseCycleTimer = new QTimer(this);
    connect(m_pPReleaseCycleTimer, SIGNAL(timeout()), this, SLOT(onReleaseCycleTimeout()));
    //处理'F'信号
    connect(pPrinterComm, SIGNAL(BC_PrintReleaseCycleFinished()), this, SLOT(onBC_PrintReleaseCycleFinished()));

    onScreenCountChanged();
    pProjector->hide();

    m_isPrevModeStandBy = false;
    m_splashImageAddIndex = 0;
    m_splashImageCount = 0;
    m_splashImageAdded = 0;
    m_splashImageRemoved = 0;
    m_numExtraSplashLutEntries = 0;
    m_numImgInFlash = 0;
    m_minute=1;

    m_firmwarePath = m_settings.value("FirmwarePath", "").toString();
    m_ptnImagePath = m_settings.value("PtnImagePath", "").toString();
    m_outFileName = m_settings.value("outFileName", "").toString();
    m_csvFileName = m_settings.value("csvFileName", "").toString();


    g_pImageBuffer = (unsigned char *)malloc(PTN_WIDTH*PTN_HEIGHT*BYTES_PER_PIXEL);
    if(g_pImageBuffer == NULL)
        exit(-1);
    memset(g_pImageBuffer, 0, PTN_WIDTH*PTN_HEIGHT*BYTES_PER_PIXEL);

//    timerTimeout();
    DLPC350_USB_Init();
//    m_usbPollTimer = new QTimer(this);
//    m_usbPollTimer->setInterval(500);
//    connect(m_usbPollTimer, SIGNAL(timeout()), this, SLOT(timerTimeout()));//随时扫描投影仪状态
//    m_usbPollTimer->start();

    setFixedSize(this->width(), this->height());//固定窗口大小

    QSettings appSettings;
    appSettings.beginGroup("USERSET");
    language=appSettings.value("Language").toString();
    appSettings.endGroup();
    if(language!=""){
        UpdateByLanguage();
    }
}

Terminal::~Terminal()
{
    delete ui;
    delete pProjector;
    pProjector = NULL;
    delete pPrinterComm;
    qDebug() << "Terminal End";
}

void Terminal::closeEvent(QCloseEvent * event )
{
//    setPrinter(m_iCPJModel);

//    pPrinterComm->SendCmd("@"+QString::number(0));//关掉投影仪亮度
    ui->spinBox_BlueLEDCurrent->setValue(0);
    event->accept();
}

void Terminal::showIt()
{
    UpdateExtentsUI();
    exec();
}

void Terminal::timerTimeout(void)
{
    if(DLPC350_USB_IsConnected())
    {
        on_pushButton_GetLEDConfiguration_clicked();
    }
    else
    {
        if(DLPC350_USB_Open()==0)
        {
            emit on_pushButton_Connect_clicked();
//                ui->pushButtonProjPowerON->setEnabled(true);
        }
        else{
//                ui->pushButtonProjPowerON->setEnabled(false);
            ui->projectorStatus->setText("DISCONNECT");
        }
    }
    pMain->pw->onSetProjStatus(ui->projectorStatus->text());
}

unsigned char EnumSerialEx(unsigned char *m_Port)
{
//    return 0;
    HKEY hKey;
    QString str;
//    WINADVAPI LONG WINAPI RegOpenKeyExA(HKEY,LPCSTR,DWORD,REGSAM,PHKEY);
//    WINADVAPI LONG WINAPI RegOpenKeyExW(HKEY,LPCWSTR,DWORD,REGSAM,PHKEY);
    LPCSTR data_Set="HARDWARE\\DEVICEMAP\\SERIALCOMM\\";//LPCWSTR
    long ret0 = RegOpenKeyExA(HKEY_LOCAL_MACHINE, data_Set, 0, KEY_READ, &hKey);//RegOpenKeyEx
    if(ret0 != ERROR_SUCCESS)
    {
        return -1;
    }
    int i = 1;				//put the port index from 1;
    char Name[50];
    unsigned char szPortName[50];//UCHAR
    long Status;
    unsigned long dwIndex = 0;
    unsigned long dwName;
    unsigned long dwSizeofPortName;
    unsigned long Type;
    dwName = sizeof(Name);
    dwSizeofPortName = sizeof(szPortName);
    do
    {
//   WINADVAPI LONG WINAPI RegEnumValueA(HKEY,DWORD,LPSTR,PDWORD,PDWORD,PDWORD,LPBYTE,PDWORD);
//        WINADVAPI LONG WINAPI RegEnumValueW(HKEY,DWORD,LPWSTR,PDWORD,PDWORD,PDWORD,LPBYTE,PDWORD);

//        const size_t cSize = strlen(Name)+1;
//        wchar_t* wName = new wchar_t[cSize];
//        mbstowcs (wName, Name, cSize);
        Status = RegEnumValueA(hKey, dwIndex++, Name, &dwName, NULL, &Type,
            szPortName, &dwSizeofPortName);//RegEnumValue
        if((Status == ERROR_SUCCESS)||(Status == ERROR_MORE_DATA))
        {
//            str = CString(szPortName).Mid(3);;       // 串口字符串保存
            str = QString((char*)szPortName).mid(3);       // 串口字符串保存
            m_Port[i] = str.toInt();//atoi((const char *)str);
            i++;// 串口计数
        }
        dwName = sizeof(Name);
        dwSizeofPortName = sizeof(szPortName);
    } while((Status == ERROR_SUCCESS)||(Status == ERROR_MORE_DATA));
    RegCloseKey(hKey);
    return i;
}

unsigned char Terminal::CheckUart(/*MainWindow *pDlg*/)
{
    // TODO: Add your control notification handler code here
        BYTE i=0;
    unsigned char SerialPortNum=0;
    unsigned char j;

    if(UART_Port)
    {
        CloseUart(u_Serial[UART_Port]);
        UART_Port=0;
//        pDlg->SetDlgItemText(IDC_UART,_CS("Uart.Open"));
//        ui->pushButtonOpen->setText("Open");
        ui->projectorStatus->setText("Disconnect");
        return 1;
    }

    //DLG_PRINTF("正在连接...........");
    SerialPortNum=EnumSerialEx(u_Serial);

    for(i=0;i<COUNTOF(BaudRate);i++)
    {
        if (0< UART_Port && UART_Port < SerialPortNum)
        {
            if(OpenUart(u_Serial[UART_Port],BaudRate[i])==TRUE)
            {
                if(ShakeHands()==FALSE)
                {
                    CloseUart(u_Serial[UART_Port]);
                }
                else
                {
////                    pDlg->MessageBox(_CS("ConnectSuccess"),_CS("Title"),MB_OK);
//                    QMessageBox::information(this, tr("ConnectSuccess"),
//                                 tr("ConnectSuccess\n"),QMessageBox::Ok);

                    ui->projectorStatus->setText("Disconnect");
//                    pDlg->SetDlgItemText(IDC_UART,_CS("Uart.Close"));
                    if(CheckVersion(FirmwareVersion)==FALSE)
                        ui->projectorStatus->setText("FirmWareOld");
////                        pDlg->MessageBox(_CS("WarningGeneral.FirmWareOld"),_CS("Title"),MB_OK);
//                        QMessageBox::information(this, tr("Warning"),
//                                     tr("WarningGeneral.FirmWareOld\n"),QMessageBox::Ok);

                    return 1;
                }
            }
            else
                UART_Port=0;
        }
        else
            UART_Port=0;
    }

    UART_Port=0;
    //first connect MST
    if (SerialPortNum)
    {
        if(UART_Port == 0)
        {
            for (i=1; i<SerialPortNum; i++)
            {
                for(j=0;j<COUNTOF(BaudRate);j++)
                {
                    if(OpenUart(u_Serial[i],BaudRate[j])==TRUE)
                    {
                        if(ShakeHands()==TRUE)
                        {
                            UART_Port=i;

                            ui->projectorStatus->setText("ConnectSuccess");
//////                            pDlg->MessageBox(_CS("ConnectSuccess"),_CS("Title"),MB_OK);
////                            QMessageBox::information(this, tr("ConnectSuccess"),
////                                         tr("ConnectSuccess\n"),QMessageBox::Ok);

//                            ui->pushButtonOpen->setText("Close");
        //                    pDlg->SetDlgItemText(IDC_UART,_CS("Uart.Close"));
                            if(CheckVersion(FirmwareVersion)==FALSE)
                                ui->projectorStatus->setText("DISCONNECT");//FirmWareOld
//        //                        pDlg->MessageBox(_CS("WarningGeneral.FirmWareOld"),_CS("Title"),MB_OK);
//                                QMessageBox::information(this, tr("Warning"),
//                                             tr("WarningGeneral.FirmWareOld\n"),QMessageBox::Ok);

                            return 1;
                        }
                        CloseUart(u_Serial[i]);
                    }
                }
            }
        }
        if(UART_Port == 0)
        {
            ui->projectorStatus->setText("DISCONNECT");//ConnectFail
////            pDlg->MessageBox(_CS("ConnectFail"),_CS("Title"),MB_OK);
//            QMessageBox::information(this, tr("Warning"),
//                         tr("ConnectFail"),QMessageBox::Ok);

            return 0;
        }
    }
    else
    {
        ui->projectorStatus->setText("DISCONNECT");//NotFinded
////        pDlg->MessageBox(_CS("NotFinded"),_CS("Title"),MB_OK);
//        QMessageBox::information(this, tr("Warning"),
//                     tr("NotFinded"),QMessageBox::Ok);
        return 2;
    }
    return 1;
}

int Terminal::GetDLPC350Status()
{
    unsigned char HWStatus, SysStatus, MainStatus;

    if(DLPC350_GetStatus(&HWStatus, &SysStatus, &MainStatus) == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void Terminal::on_pushButton_Connect_clicked()
{
    char versionStr[255];
    unsigned int API_ver, App_ver, SWConfig_ver, SeqConfig_ver;
    int trigMode=0;
    bool SLmode=0;
    bool isExtPatDisplayMode=false;
    unsigned int numImgInFlash = 0;

    // Display GUI Version #
    sprintf(versionStr, "DLP LightCrafter 4500 Control Software - %d.%d.%d", \
            GUI_VERSION_MAJOR, GUI_VERSION_MINOR, GUI_VERSION_BUILD);

    ui->projectorStatus->setText(versionStr);//"CONNECTED"

    on_pushButton_GetLEDConfiguration_clicked();

    if(DLPC350_USB_IsConnected())
    {
        //Read System Status
        if(GetDLPC350Status() <0 )
            return ;

        if (DLPC350_GetVersion(&App_ver, &API_ver, &SWConfig_ver, &SeqConfig_ver) == 0)
        {
            sprintf(versionStr, "%d.%d.%d", (App_ver >> 24), ((App_ver << 8) >> 24), ((App_ver << 16) >> 16));
        }
        else
            return ;

        //Read firmware tag information
        unsigned char firmwareTag[33];
        if(DLPC350_GetFirmwareTagInfo(&firmwareTag[0]) == 0)
        {
            QString str((char *)firmwareTag);
        }
        else
            return;

        //Retrieve the total number of Images in the firmware info
        if(DLPC350_GetNumImagesInFlash(&numImgInFlash) == 0)
        {
            m_numImgInFlash = numImgInFlash;
        }
        else
            return ;

        // qDebug() << "Number of splash images in the flash = " << numImgInFlash;

        //Update UI content based on the mode
        bool standby;
        if(DLPC350_GetPowerMode(&standby) != 0)
        {
            ;//ShowError("PowerMode Read failed!!!");
        }

        //Read Display Mode & update UI elements
        if((DLPC350_GetMode(&SLmode) == 0) && (standby == false))
        {
            if(SLmode)
            {}
            else
            {
                emit on_radioButton_VideoMode_clicked();
            }
        }
        else
        {
            m_isPrevModeStandBy = true;
        }

//        //Update LED status
//        emit on_pushButton_GetLEDConfiguration_clicked();
//        emit on_pushButton_GetLEDDlyCtrlConfig_clicked();
//        emit on_pushButton_GetTrigConfig_clicked();
    }


}

void Terminal::on_radioButton_VideoMode_clicked()
{
    int i = 0;
    bool mode;

    if(m_isPrevModeStandBy)
    {
        m_isPrevModeStandBy = false;


        //Wakeup from standby
        //Bug? - Response fails for DLPC350_SetPowerMode command
        DLPC350_SetPowerMode(0);
        //Assuming it takes around 2.0 seconds
        SleeperThread::msleep(2000);

        while(1)
        {
            DLPC350_GetPowerMode(&mode);
            if(!mode)
                break;
            SleeperThread::msleep(100);
            if(i++ > (MAX_NUM_RETRIES*2))
                break;
        }
    }

    //Enter in Video Mode
    SetDLPC350InVideoMode();

}

void Terminal::on_setProjectorBlueLED(int arg1){
    if(!arg1)
        pPrinterComm->SendCmd("@0");
    else
        pPrinterComm->SendCmd("@"+QString::number(m_iBlueLED));
//    m_bWaiverPresented = !(!m_bWaiverPresented);
//    if(!BlueEnable) return;
////    if(isM50/* && BlueEnable*/){
//        if(!arg1)
//            DLPC350_SetLedCurrents(255, 255, 255);
//        else
//            DLPC350_SetLedCurrents(255, 255, 255-m_iBlueLED);

////    }
////    else if(UART_Port){
//////        unsigned short red,green,blue,Value;
//////        GetCurrent(&red,&green,&blue);
////        if(!arg1)
////            SetCurrent(0,0,0);
////        else
////            SetCurrent(0,m_iBlueLED,0);
////    }
////    emit setProjectorBlueLED(arg1);
}

void Terminal::SetDLPC350InVideoMode()
{
    int i = 0;
    bool mode;
    unsigned int patMode;

    //Check if it is in Pattern Mode
    DLPC350_GetMode(&mode);
    if(mode == true)
    {
       //First stop pattern sequence
        DLPC350_GetPatternDisplay(&patMode);
        //if it is in PAUSE or RUN mode
        if(patMode != 0)
        {
//            emit on_pushButton_PatSeqCtrlStop_clicked();
        }

        //Switch to Video Mode
        DLPC350_SetMode(false);
        SleeperThread::msleep(100);
        while(1)
        {
            DLPC350_GetMode(&mode);
            if(!mode)
                break;
            SleeperThread::msleep(100);
            if(i++ > MAX_NUM_RETRIES)
                break;
        }
    }

    return;
}

void Terminal::on_pushButton_GetLEDConfiguration_clicked()
{
    bool SeqCtrl, Red, Green, Blue;
//    unsigned char RedCurrent, GreenCurrent, BlueCurrent;
//    char currentStr[8];

    if (DLPC350_GetLedEnables(&SeqCtrl, &Red, &Green, &Blue) == 0)
        BlueEnable = Blue;
    if(!BlueEnable){
        ui->projectorStatus->setText("OFF");
    }
    else
        ui->projectorStatus->setText("ON");

//    if (DLPC350_GetLedCurrents(&RedCurrent, &GreenCurrent, &BlueCurrent) == 0)
//    {
//        sprintf(currentStr,"%d", 255-BlueCurrent);
//        ui->spinBox_BlueLEDCurrent->setValue(255-BlueCurrent);
////        ui->lineEdit_BlueLEDCurrent->setText(currentStr);
//    }
}

void Terminal::on_pushButton_SetLEDConfiguration_clicked()
{
    unsigned char RedCurrent, GreenCurrent, BlueCurrent;

    DLPC350_SetLedEnables(false, false, false, BlueEnable);

    DLPC350_SetLEDPWMInvert(false/*ui->checkBox_LedPwmInvert->isChecked()*/);

    RedCurrent      = 255;//-strToNum(ui->lineEdit_RedLEDCurrent->text());
    GreenCurrent    = 255;//-strToNum(ui->lineEdit_GreenLEDCurrent->text());
    BlueCurrent     = 255-ui->spinBox_BlueLEDCurrent->value();//strToNum(ui->lineEdit_BlueLEDCurrent->text());

    DLPC350_SetLedCurrents(RedCurrent, GreenCurrent, BlueCurrent);
}

void Terminal::setPrinterToModel1()
{
////    m_usbPollTimer->start();
//    QSettings appSettings;
//    appSettings.beginGroup("USERSET");
//        appSettings.setValue("Printer","M50");
//    appSettings.endGroup();
//    isM50=true;
//    pMain->pw->isM50=true;
//    ui->labelPrinter->setText("M50:");
////    ui->pushButtonBoardON->setEnabled(false);
////    ui->pushButtonBoardOFF->setEnabled(false);
//    ui->spinBox_BlueLEDCurrent->setEnabled(true);
//    pMain->SetXYPixelSizePreset("50");
//    pMain->SetProjectorPreset(1);
}
void Terminal::setPrinterToModel2()
{
////    m_usbPollTimer->stop();
//    QSettings appSettings;
//    appSettings.beginGroup("USERSET");
//        appSettings.setValue("Printer","M100");
//    appSettings.endGroup();
//    isM50=false;
//    pMain->pw->isM50=false;
//    ui->labelPrinter->setText("M100:");
////    ui->pushButtonBoardON->setEnabled(false);
////    ui->pushButtonBoardOFF->setEnabled(false);
//    ui->spinBox_BlueLEDCurrent->setEnabled(true);
//    pMain->SetXYPixelSizePreset("100");
//    pMain->SetProjectorPreset(1);
}


void Terminal::setPrinter(int index)
{
//    switch(index)
//    {
//        case 0:
//            setPrinterToModel1();
//            break;
//        case 1:
//            setPrinterToModel2();
//            break;

//        default:break;

//    }
//    ui->printercombo->setCurrentIndex(index);
//    pMain->status->setPrinter(index);
}

void Terminal::on_printercombo_currentIndexChanged(int index)
{
//    if(index == m_iCPJModel){
//        QObject::connect(ui->projectorStatus, SIGNAL(textChanged(QString)), pMain->pw, SLOT(onSetProjStatus(QString)));
//        QObject::connect(ui->commStatus, SIGNAL(textChanged(QString)), pMain->pw, SLOT(onSetCommStatus(QString)));
//    }
//    else{
//        QObject::disconnect(ui->projectorStatus, SIGNAL(textChanged(QString)), pMain->pw, SLOT(onSetProjStatus(QString)));
//        QObject::disconnect(ui->commStatus, SIGNAL(textChanged(QString)), pMain->pw, SLOT(onSetCommStatus(QString)));
//    }
//    switch(index)
//    {
//        case 0:
//            setPrinterToModel1();
//            break;
//        case 1:
//            setPrinterToModel2();
//            break;

//        default:break;

//    }
////    pMain->status->setPrinter(index);

}

void Terminal::on_pixelsizecombo_currentIndexChanged(const QString &arg1)
{
    pMain->SetXYPixelSizePreset(arg1);
    UpdateExtentsUI();
}

void Terminal::on_projectorcombo_currentIndexChanged(int index)
{
    pMain->SetProjectorPreset(index);
    UpdateExtentsUI();
}

void Terminal::UpdateExtentsUI()
{

//    QSettings appSettings;
//    appSettings.beginGroup("USERSET");
//    if(appSettings.value("Printer")=="M100(128x80)")
//        setPrinter(1);
//    else//M50(64x40)
//        setPrinter(0);
//    appSettings.endGroup();

}

int Terminal::getEstBaseCycleTime(int iCur, int iTgt){
    int iDelta = abs(iTgt - iCur);
    int iLowerSpd,iOpnSpd,iSettle;

        iLowerSpd = pSettings->m_iLSpd1;
//        iOpnSpd = pSettings->m_iOpenSpd1;
        iSettle = pSettings->m_dSettleOpen1*1000.0;

    // Time to move iDelta
    int iTimeReq = getZMoveTime(iDelta, iLowerSpd);
//    // Plus time to open vat
//    iTimeReq += getVatMoveTime(iOpnSpd);
    // Plus settle time;
    iTimeReq += iSettle;
    return iTimeReq;
}

int Terminal::getEstNextCycleTime(int iCur, int iTgt){
    int iDelta = abs(iTgt - iCur);
    int iRaiseSpd,iLowerSpd,iOpnSpd,iClsSpd,iGap,iBreathe,iSettle;

        iRaiseSpd = pSettings->m_iRSpd1;
        iLowerSpd = pSettings->m_iLSpd1;
//        iOpnSpd = pSettings->m_iOpenSpd1;
//        iClsSpd = pSettings->m_iCloseSpd1;
        iGap = (int)(pSettings->m_dOverLift1*100000.0/(double)pPrinterComm->getPU());
        iBreathe = pSettings->m_dBreatheClosed1*1000.0;
        iSettle = pSettings->m_dSettleOpen1*1000.0;

    // Time to move +iDelta + iGap, up and down
    int iTimeReq = getZMoveTime(iDelta+iGap, iRaiseSpd);
    iTimeReq += getZMoveTime(iDelta+iGap, iLowerSpd);
//    // Plus time to close + open the vat
//    iTimeReq += getVatMoveTime(iClsSpd)+getVatMoveTime(iOpnSpd);
    // Plus breathe & settle time;
    iTimeReq += iBreathe + iSettle;
    return iTimeReq;
}

int Terminal::getEstFinalCycleTime(int iCur, int iTgt){
    int iDelta = abs(iTgt - iCur);
    int iRaiseSpd;

        iRaiseSpd = pSettings->m_iRSpd1 / 130;

    // Time to move +iDelta up
    int iTimeReq = getZMoveTime(iDelta, iRaiseSpd);
    return iTimeReq;
}

QTime Terminal::getEstCompleteTime(int iCurLayer, int iTotLayers, double dLayerThicknessMM, int iExposeMS)
{
    return QTime::currentTime().addMSecs(getEstCompleteTimeMS(iCurLayer, iTotLayers, dLayerThicknessMM, iExposeMS));
}

int Terminal::getEstCompleteTimeMS(int iCurLayer, int iTotLayers, double dLayerThicknessMM, int iExposeMS)//当前打印层0/总打印层583/层厚0.1/等待时间900    //需要根据转速计算上升时间,下落时间等
{
    //return estimated completion time
  //  qDebug()<<"TimeTestBegin****";
      int  iLowerCount = iTotLayers-iCurLayer;
//    qDebug()<<"iLowerCount:"<<iLowerCount;
//    qDebug()<<"iExposeMS:"<<iExposeMS;
    int iTotalTimeMS = iExposeMS*iLowerCount;// + iExposeMS*iUpperCount;//等待时间*剩余层数
  // qDebug()<<"Time1:"<<iTotalTimeMS;
    iTotalTimeMS = getLampAdjustedExposureTime(iTotalTimeMS);
 //   qDebug()<<"Time1.2:"<<iTotalTimeMS;
    // Add Breathe and Settle
 //   qDebug()<<"pSettings->m_dBreatheClosed1:"<<pSettings->m_dBreatheClosed1<<"   pSettings->m_dSettleOpen1:"<<pSettings->m_dSettleOpen1;
    iTotalTimeMS += iLowerCount*(pSettings->m_dBreatheClosed1 + pSettings->m_dSettleOpen1)*1000;
 //   qDebug()<<"Time2:"<<iTotalTimeMS;
   // qDebug()<<"m_dBreatheClosed1:"<<pSettings->m_dBreatheClosed1<<"   m_dSettleOpen1:"<<pSettings->m_dSettleOpen1;

    // Z Travel Time
    int iGap1 = iLowerCount*(int)(pSettings->m_dOverLift1*100000.0/(double)pPrinterComm->getPU());
//   qDebug()<<"m_dOverLift1:"<<pSettings->m_dOverLift1;
//   qDebug()<<"PU:"<<pPrinterComm->getPU();
  //  qDebug()<<"iGap1:"<<iGap1;
//   qDebug()<<"dLayerThicknessMM:"<<dLayerThicknessMM;
    int iZRaiseDistance1 = iGap1 + iLowerCount*(int)(dLayerThicknessMM*100000.0/(double)pPrinterComm->getPU());
    int iZLowerDistance1 = iGap1;
    //qDebug()<<"iZRaiseDistance1:"<<iZRaiseDistance1;
    //qDebug()<<"iZLowerDistance1:"<<iZLowerDistance1;
    //cyp 百分比速率改成转速
    iTotalTimeMS += getZMoveTime(iZRaiseDistance1,pSettings->m_iRSpd1);
 //   qDebug()<<"Time3:"<<iTotalTimeMS;
    iTotalTimeMS += getZMoveTime(iZLowerDistance1,pSettings->m_iLSpd1);
 //   qDebug()<<"getZMoveTime1:"<<getZMoveTime(iZRaiseDistance1,pSettings->m_iRSpd1);
 //   qDebug()<<"Time4:"<<iTotalTimeMS;
 //   qDebug()<<"getZMoveTime2:"<<getZMoveTime(iZLowerDistance1,pSettings->m_iLSpd1);
    iTotalTimeMS+=550*iLowerCount;
    return iTotalTimeMS;
}

int Terminal::getLampAdjustedExposureTime(int iBaseTimeMS)
{
    if(pPrinterComm==NULL||pPrinterComm->getLampHrs()<0||pPrinterComm->getHalfLife()<0)
        return iBaseTimeMS;

    //  dLife = 0.0 at zero lamp hours and 1.0 at or above halflife hours.
    //  We multiply the base time by dLife and return the original amount + the product.
    //  So at Halflife, we've doubled the standard exposure time.
    double dLife = (double)pPrinterComm->getLampHrs()/(double)pPrinterComm->getHalfLife();
    if(dLife > 1.0)dLife = 1.0; // Limit to 100% the amount of applied bulb degradation (reached at HalfLife)
    return iBaseTimeMS + (double)iBaseTimeMS*dLife;
}


int Terminal::getZMoveTime(int iDelta, int iSpd){
    // returns time to travel iDelta PUs distance in milliseconds
    // Accurate but assumes that 100% is 130rpm and 0% is 50rpm
    // Also assumes 200 PU (Steps) per revolution
    // returns milliseconds required to move iDelta PU's
    if(iDelta==0)return 0;
    double dPUms; // printer units per millisecond
//    dPUms = ((double)iSpd/100.0)*80.0 + 50.0;
    dPUms = iSpd;//((double)iSpd/100.0)*130.0;
    dPUms *= 200.0; // PU per minute
    dPUms /= 60; // PU per second
    dPUms /= 1000; // PU per millisecond
    return (int)(double(iDelta)/dPUms);
}

int Terminal::getVatMoveTime(int iSpeed){
    double dPercent = (double)iSpeed/100.0;
//    return 999 - dPercent*229.0; // based on speed tests of B9C1 on 11/14/2012
    return 1500 - dPercent*229.0; // updated based on timeouts on pre-production model tests 11/18/2012
}

void Terminal::onScreenCountChanged(int iCount){
    QString sVideo = "Disconnected or Primary Monitor";
    if(pProjector) {
        delete pProjector;
        pProjector = NULL;
//        if(pPrinterComm->getProjectorStatus()==B9PrinterStatus::PS_ON)
//            if(!isEnabled())
//                emit signalAbortPrint("Print Aborted:  Connection to Projector Lost or Changed During Print Cycle");
    }
    pProjector = new B9Projector(true, 0,Qt::WindowStaysOnTopHint);
    connect(pProjector,SIGNAL(setProjectorBlueLED(int)),this,SLOT(on_setProjectorBlueLED(int)));

    makeProjectorConnections();
    int i=iCount;
    int screenCount = m_pDesktop->screenCount();
    QRect screenGeometry;

    if(m_bUsePrimaryMonitor)
    {
        screenGeometry = m_pDesktop->screenGeometry(0);
    }
    else{
        for(i=screenCount-1;i>= 0;i--) {
            screenGeometry = m_pDesktop->screenGeometry(i);
            if(screenGeometry.width() == pPrinterComm->getNativeX() && screenGeometry.height() == pPrinterComm->getNativeY()) {
                //Found the projector!
                sVideo = "Connected to Monitor: " + QString::number(i+1);
                m_bNeedsWarned = true;
                break;
            }
        }
    }
    if(i<=0||m_bUsePrimaryMonitor)m_bPrimaryScreen = true; else m_bPrimaryScreen = false;

    emit updateProjectorOutput(sVideo);

    pProjector->setShowGrid(true);
    pProjector->setCPJ(NULL);

    emit sendStatusMsg("Nepho3d_Studio - Idle");//cyp B9Creator
//    pProjector->setGeometry(screenGeometry);
    pProjector->setGeometry(1920,0,1280,800);
//    pProjector->showFullScreen();
    pProjector->show();
    if(!m_bPrimaryScreen){
//        pProjector->showFullScreen(); // Only show it if it is a secondary monitor
//        pProjector->hide();
        emit setProjectorBlueLED(0);
        activateWindow(); // if not using primary monitor, take focus back to here.
    }
    else if(m_bPrintPreview||(pPrinterComm->getProjectorStatus() != B9PrinterStatus::PS_OFF &&
            pPrinterComm->getProjectorStatus() != B9PrinterStatus::PS_COOLING &&
            pPrinterComm->getProjectorStatus() != B9PrinterStatus::PS_UNKNOWN)) {
//         //if the projector is not turned off, we better put up the blank screen now!
//        pProjector->showFullScreen();
//        emit setProjectorBlueLED(222);
    }
    //else warnSingleMonitor();

}

void Terminal::onBC_ConnectionStatusDetailed(QString sText)
{
    setEnabledWarned();

    ui->commStatus->setText(sText);

    if(pPrinterComm->isConnected()){//cyp
        this->setEnabled(true);
    }
    else{
        this->setEnabled(false);
    }
//    emit BC_ConnectionStatusDetailed(sText);
}

void Terminal::onBC_LostCOMM(){
    //Broadcast an alert
    if(!isEnabled())emit signalAbortPrint("ERROR: Lost Printer Connection.  Possible reasons: Power Loss, USB cord unplugged.");
    qDebug() << "BC_LostCOMM signal received.";
}

void Terminal::onUpdateRAWPrinterComm(QString sText)
{
//    QString html = "<font color=\"Blue\">" + sText + "</font><br>";
//    ui->textEditCommOut->insertHtml(html);
//    html = ui->textEditCommOut->toHtml();
//    ui->textEditCommOut->clear();
//    ui->textEditCommOut->insertHtml(html.right(2000));
//    ui->textEditCommOut->setAlignment(Qt::AlignBottom);
}

void Terminal::onUpdatePrinterComm(QString sText)
{
//    QString html = "<font color=\"Black\">" + sText + "</font><br>";
//    ui->textEditCommOut->insertHtml(html);
//    html = ui->textEditCommOut->toHtml();
//    ui->textEditCommOut->clear();
//    ui->textEditCommOut->insertHtml(html.right(2000));
//    ui->textEditCommOut->setAlignment(Qt::AlignBottom);
}

void Terminal::onBC_ModelInfo(QString sModel){
    m_sModelName = sModel;
    m_pCatalog->load(m_sModelName);
//    ui->lineEditModelInfo->setText(m_sModelName);
    resetLastSentCycleSettings();
}

void Terminal::onBC_FirmVersion(QString sVersion){
//    ui->lineEditFirmVersion->setText(sVersion);
}

void Terminal::onBC_ProjectorRemoteCapable(bool bCapable){
//    ui->groupBoxProjector->setEnabled(bCapable);
//    ui->pushButtonProjPower->setEnabled(bCapable);
//    ui->pushButtonProjPowerOFF->setEnabled(bCapable);
//    ui->pushButtonProjPowerON->setEnabled(bCapable);
}
void Terminal::onBC_HasShutter(bool bHS){
//    ui->groupBoxVAT->setEnabled(bHS);
}

void Terminal::onBC_ProjStatusChanged()
{//commercial projector
//    QString sText = "UNKNOWN";
//    bool isTurningOn = false;
//    switch (pPrinterComm->getProjectorStatus()){
//    case B9PrinterStatus::PS_OFF:
//        ui->pushButtonProjPower->setEnabled(true);
//        sText = "OFF";
//        break;
//    case B9PrinterStatus::PS_TURNINGON:
//        isTurningOn = true;
//        ui->pushButtonProjPower->setEnabled(false);
//        sText = "TURN ON";
//        break;
//    case B9PrinterStatus::PS_WARMING:
//        ui->pushButtonProjPower->setEnabled(true);
//        sText = "WARM UP";
//        break;
//    case B9PrinterStatus::PS_ON:
//        ui->pushButtonProjPower->setEnabled(true);
//        emit(ProjectorIsOn());
//        sText = "ON";
//        break;
//    case B9PrinterStatus::PS_COOLING:
//        ui->pushButtonProjPower->setEnabled(false);
//        sText = "COOL DN";
//        break;
//    case B9PrinterStatus::PS_TIMEOUT:
//        ui->pushButtonProjPower->setEnabled(false);
//        sText = "TIMEOUT";
//        if(!isEnabled())emit signalAbortPrint("Timed out while attempting to turn on projector.  Check Projector's Power Cord and RS-232 cable.");
//        break;
//    case B9PrinterStatus::PS_FAIL:
//        ui->pushButtonProjPower->setEnabled(false);
//        sText = "FAIL";
//        if(!isEnabled())emit signalAbortPrint("Lost Communications with Projector.  Possible Causes:  Manually powered off, Power Failure, Cord Disconnected or Projector Lamp Failure");
//        break;
//    case B9PrinterStatus::PS_UNKNOWN:
//        ui->pushButtonProjPower->setEnabled(true);
//    default:
//        sText = "UNKNOWN";
//        break;
//    }

//    // Update the power button state
//    if(isTurningOn){
//        pProjector->hide(); //cyp
//        activateWindow();
//        ui->pushButtonProjPower->setChecked(true);
//        ui->pushButtonProjPower->setText("OFF");
//    }
//    else if(pPrinterComm->isProjectorPowerCmdOn()){
//        if(!isTurningOn)
//            pProjector->show();//打开投影仪的时候不需要显示
//        activateWindow();
//        ui->pushButtonProjPower->setChecked(true);
//        ui->pushButtonProjPower->setText("OFF");
//    }
//    else{
//        if(pProjector)
//            pProjector->hide();
//        activateWindow();
//        ui->pushButtonProjPower->setChecked(false);
//        ui->pushButtonProjPower->setText("ON");
//    }

//    if(!isEnabled())emit sendStatusMsg("WINSUN - 投影仪 状态: "+sText);
//    if(!isEnabled())emit updateProjectorStatus(sText);
//    if(!isEnabled())emit updateProjector(pPrinterComm->getProjectorStatus());

//    ui->projectorStatus->setText(sText);

//    sText = "UNKNOWN";
//    int iLH = pPrinterComm->getLampHrs();
//    if(iLH >= 0 && (pPrinterComm->getProjectorStatus()==B9PrinterStatus::PS_ON||
//                    pPrinterComm->getProjectorStatus()==B9PrinterStatus::PS_WARMING||
//                    pPrinterComm->getProjectorStatus()==B9PrinterStatus::PS_COOLING))sText = QString::number(iLH);
////    ui->lineEditLampHrs->setText(sText);
}

void Terminal::on_projectorStatus_textChanged(const QString &arg1)
{
    emit setProjStatus(arg1);
}

void Terminal::onBC_ProjStatusFAIL()
{
    onBC_ProjStatusChanged();
    on_pushButtonProjPower_toggled(pPrinterComm->isProjectorPowerCmdOn());
}

void Terminal::onBC_PU(int iPU){
//    double dPU = (double)iPU/100000.0;
//    ui->lineEditPUinMicrons->setText(QString::number(dPU,'g',8));
}

void Terminal::onBC_UpperZLimPU(int iUpZLimPU){
//    double dZUpLimMM = (iUpZLimPU * pPrinterComm->getPU())/100000.0;
//    ui->lineEditUpperZLimMM->setText(QString::number(dZUpLimMM,'g',8));
//    ui->lineEditUpperZLimInches->setText(QString::number(dZUpLimMM/25.4,'g',8));
//    ui->lineEditUpperZLimPU->setText(QString::number(iUpZLimPU,'g',8));
    m_UpperZLimPU = iUpZLimPU;
}

void Terminal::onMotionResetTimeout(){
    this->setEnabled(true);
    m_pResetTimer->stop();
    QMessageBox msg;
    msg.setText("ERROR: TIMEOUT attempting to locate home position.  Check connections.");
    if(isEnabled())msg.exec();
}

void Terminal::onMotionResetComplete()
{
//    ui->groupBoxMain->setEnabled(true);
    this->setEnabled(true);
//    if(pPrinterComm->getHomeStatus()==B9PrinterStatus::HS_FOUND) ui->lineEditNeedsInit->setText("No");
//    else if(pPrinterComm->getHomeStatus()==B9PrinterStatus::HS_UNKNOWN) ui->lineEditNeedsInit->setText("Yes");
//    else ui->lineEditNeedsInit->setText("Seeking");
//    ui->lineEditZDiff->setText(QString::number(pPrinterComm->getLastHomeDiff()).toAscii());
    m_pResetTimer->stop();

//    pMain->pw->accepted();

    // Check for post reset go to fill command
    if(m_iFillLevel>=0){
//        pPrinterComm->SendCmd("G"+QString::number(m_iFillLevel));
        pPrinterComm->SendCmd("G2000");//移动到传感器向下5mm的位置,传感器位置3000
        m_iFillLevel=-1;
    }
    emit HomeFound();
}

void Terminal::onBC_CurrentZPosInPU(int iCurZPU){
//    double dZPosMM = (iCurZPU * pPrinterComm->getPU())/100000.0;
//    ui->lineEditCurZPosInMM->setText(QString::number(dZPosMM,'g',8));
//    ui->lineEditCurZPosInInches->setText(QString::number(dZPosMM/25.4,'g',8));
//    ui->lineEditCurZPosInPU->setText(QString::number(iCurZPU,'g',8));
//    emit ZMotionComplete();
    m_iCurZPosInPU = iCurZPU;
    m_dCurZPosInMM = (iCurZPU * pPrinterComm->getPU())/100000.0;
}

void Terminal::onBC_HalfLife(int iHL){
//    ui->lineEditHalfLife->setText(QString::number(iHL));
}

void Terminal::onBC_NativeX(int iNX){
//    ui->lineEditNativeX->setText(QString::number(iNX));
}

void Terminal::onBC_NativeY(int iNY){
//    ui->lineEditNativeY->setText(QString::number(iNY));
    if(pProjector == NULL)emit onScreenCountChanged();
}


void Terminal::onBC_XYPixelSize(int iPS){
//    int i=2;
//    if(iPS==50)i=0;
//    else if(iPS==75)i=1;
//    ui->comboBoxXPPixelSize->setCurrentIndex(i);
}


void Terminal::setTgtAltitudePU(int iTgtPU)
{
    m_iTgtZPosInPU = iTgtPU;
    m_dTgtZPosInMM = (iTgtPU * pPrinterComm->getPU())/100000.0;
//    double dTgtMM = (iTgtPU * pPrinterComm->getPU())/100000.0;
//    ui->lineEditTgtZPU->setText(QString::number(iTgtPU));
//    ui->lineEditTgtZMM->setText(QString::number(dTgtMM,'g',8));
//    ui->lineEditTgtZInches->setText(QString::number(dTgtMM/25.4,'g',8));
}

void Terminal::setTgtAltitudeMM(double dTgtMM){
    double dPU = (double)pPrinterComm->getPU()/100000.0;
    setTgtAltitudePU((int)(dTgtMM/dPU));
}

void Terminal::setTgtAltitudeIN(double dTgtIN){
    setTgtAltitudeMM(dTgtIN*25.4);
}

void Terminal::onMotionVatTimeout(){
//    m_pVatTimer->stop();
    on_pushButtonStop_clicked(); // STOP!
    QMessageBox msg;
    msg.setText("Vat Timed out");
    if(isEnabled())msg.exec();
//    ui->groupBoxVAT->setEnabled(true);
}

void Terminal::onBC_CurrentVatPercentOpen(int iPO){
//    m_pVatTimer->stop();
    int iVPO = iPO;
    if (iVPO>-3 && iVPO<4)iVPO=0;
    if (iVPO>97 && iVPO<104)iVPO=100;
//    ui->spinBoxVatPercentOpen->setValue(iVPO);
//    ui->groupBoxVAT->setEnabled(true);
}

void Terminal::onBC_PrintReleaseCycleFinished()
{//接收到‘F’信号，执行该函数
    m_pPReleaseCycleTimer->stop();
//    ui->lineEditCycleStatus->setText("Cycle Complete.");
//    ui->pushButtonPrintBase->setEnabled(true);
//    ui->pushButtonPrintNext->setEnabled(true);
//    ui->pushButtonPrintFinal->setEnabled(true);
    emit PrintReleaseCycleFinished();
}

void Terminal::onReleaseCycleTimeout()
{//接收不到‘F’信号，计时器时间到执行该函数。现默认不处理'F'信号，如果要处理，把该函数以下十行代码注释解掉，使其可执行
    m_pPReleaseCycleTimer->stop();
//    if(true){  // Set to true if we wish to abort due to the timeout.
//        qDebug()<<"Release Cycle Timeout.  Possible reasons: Power Loss, Jammed Mechanism.";
//        on_pushButtonStop_clicked(); // STOP!
//        if(!isEnabled())emit signalAbortPrint("ERROR: Cycle Timed Out.  Possible reasons: Power Loss, Jammed Mechanism.");
//        return;
//    }
//    else {
//        qDebug()<<"Release Cycle Timeout.  Possible reasons: Power Loss, Jammed Mechanism. IGNORED";
//        qDebug()<<"Serial Port Last Error:  "<<pPrinterComm->errorString();
//    }
}

void Terminal::SetCycleParameters(){//cyp
    int iD, iE, iJ, iK, iL, iW, iX;
//    if(pSettings->m_dBTClearInMM*100000/(double)pPrinterComm->getPU()>(double)ui->lineEditTgtZPU->text().toInt()){
//        iD = 100;//(int)(pSettings->m_dBreatheClosed1*1000.0); // Breathe delay time
        //iE = (int)(pSettings->m_dSettleOpen1*1000.0); // Settle delay time
        iE = (int)(pSettings->m_dSettleOpen1*1000.0);
        iJ = (int)(pSettings->m_dOverLift1*100000.0/(double)pPrinterComm->getPU()); // Overlift Raise Gap coverted to PU
        iK = pSettings->m_iRSpd1;  // Raise Speed
        iL = pSettings->m_iLSpd1;  // Lower Speed
        //qDebug()<<"iK:"<<iK<<"   iL:"<<iL;
 //       iW = pSettings->m_iOpenSpd1;  // Vat open speed
 //       iX = pSettings->m_iCloseSpd1; // Vat close speed
//    }
//    else{
//        iD = (int)(pSettings->m_dBreatheClosed2*1000.0); // Breathe delay time
//        iE = (int)(pSettings->m_dSettleOpen2*1000.0); // Settle delay time
//        iJ = (int)(pSettings->m_dOverLift2*100000.0/(double)pPrinterComm->getPU()); // Overlift Raise Gap coverted to PU
//        iK = pSettings->m_iRSpd2;  // Raise Speed
//        iL = pSettings->m_iLSpd2;  // Lower Speed
//        iW = pSettings->m_iOpenSpd2;  // Vat open speed
//        iX = pSettings->m_iCloseSpd2; // Vat close speed
//    }
    iD = (int)(pSettings->m_dBreatheClosed1*1000.0);
    iW=100;
    iX=100;
    if(iD!=m_iD){pPrinterComm->SendCmd("D"+QString::number(iD)); m_iD = iD;}
    if(iE!=m_iE){pPrinterComm->SendCmd("E"+QString::number(iE)); m_iE = iE;}
    if(iJ!=m_iJ){pPrinterComm->SendCmd("J"+QString::number(iJ)); m_iJ = iJ;}
    if(iK!=m_iK){pPrinterComm->SendCmd("K"+QString::number(iK)); m_iK = iK;}
    if(iL!=m_iL){pPrinterComm->SendCmd("L"+QString::number(iL)); m_iL = iL;}
    //if(iW!=m_iW){pPrinterComm->SendCmd("W"+QString::number(iW)); m_iW = iW;}
    //if(iX!=m_iX){pPrinterComm->SendCmd("X"+QString::number(iX)); m_iX = iX;}
}

void Terminal::SetCycleParametersFromPrint(int iK, int iL, double ij, double ie){//print
//    int iJ=(int)(ij*100000.0/(double)pPrinterComm->getPU());
//    qDebug()<<"pPrinterComm->getPU()"<<pPrinterComm->getPU();//1000
//    int iE=(int)ie*1000.0;
//    int iW = pSettings->m_iOpenSpd1;  // Vat open speed
//    int iX = pSettings->m_iCloseSpd1; // Vat close speed
//    int iD = (int)(pSettings->m_dBreatheClosed2*1000.0);
//    if(iD==0){
//        iD=1000;
//    }
//    iW=100;
//    iX=100;
//    if(iD!=m_iD){pPrinterComm->SendCmd("D"+QString::number(iD)); m_iD = iD;}
//    if(iE!=m_iE){pPrinterComm->SendCmd("E"+QString::number(iE)); m_iE = iE;}
//    if(iJ!=m_iJ){pPrinterComm->SendCmd("J"+QString::number(iJ)); m_iJ = iJ;}
//    if(iK!=m_iK){pPrinterComm->SendCmd("K"+QString::number(iK)); m_iK = iK;}
//    if(iL!=m_iL){pPrinterComm->SendCmd("L"+QString::number(iL)); m_iL = iL;}
//    if(iW!=m_iW){pPrinterComm->SendCmd("W"+QString::number(iW)); m_iW = iW;}
//    if(iX!=m_iX){pPrinterComm->SendCmd("X"+QString::number(iX)); m_iX = iX;}
//    pPrinterComm->SendCmd("B0");
//    pPrinterComm->SendCmd("O0");
//    pSettings->m_iRSpd1=m_iK;
//    pSettings->m_iLSpd1=m_iL;
//    pSettings->m_dSettleOpen1=(double)m_iE/1000.0;
//    pSettings->m_dOverLift1=(double)m_iJ*(double)pPrinterComm->getPU()/100000.0;
}


void Terminal::dlgEditMatCat()
{

}

void Terminal::dlgEditPrinterCycleSettings()
{
    CyclePrintSetting dlgPCycles(pSettings);
    dlgPCycles.exec();
}

void Terminal::rcBasePrint(double dBaseMM)
{
    pPrinterComm->m_bIsLog = true;//cyp
    setTgtAltitudeMM(dBaseMM);
    on_pushButtonPrintBase_clicked();
}

void Terminal::rcNextPrint(double dNextMM,QString progressValue,int minu)
{
    m_progressValue=progressValue;
    m_minute=minu;
    setTgtAltitudeMM(dNextMM);
    on_pushButtonPrintNext_clicked();
}

void Terminal::rcFinishPrint(double dDeltaMM)
{
    // Calculates final position based on current + dDeltaMM
    int newPos = dDeltaMM*100000.0/(double)pPrinterComm->getPU();
    newPos += m_iCurZPosInPU/*ui->lineEditCurZPosInPU->text().toInt()*/;
    int curPos = m_iCurZPosInPU/*ui->lineEditCurZPosInPU->text().toInt()*/;
    int upperLim = m_UpperZLimPU;//ui->lineEditUpperZLimPU->text().toInt();

    if(curPos >= upperLim)
        newPos = curPos;
    else if(newPos > upperLim)
        newPos = upperLim;

    setTgtAltitudePU(newPos);
    on_pushButtonPrintFinal_clicked();
    pPrinterComm->m_bIsLog = false;//cyp
}


void Terminal::rcCloseVat()
{
//    ui->groupBoxVAT->setEnabled(false);
    m_pVatTimer->start(3000); //should never take that long, even at slow speed
    pPrinterComm->SendCmd("V0");
}

void Terminal::rcSetProjMessage(QString sMsg)
{
    if(pProjector==NULL)return;
    // Pass along the message for the projector screen
    pProjector->setStatusMsg("Nepho3d_Studio  -  "+sMsg);
}

void Terminal::on_pushButtonCmdReset_clicked()
{
//    QObject::disconnect(this, SIGNAL(HomeFound()), pMain, SLOT(doPrint()));
    int iTimeoutEstimate = 30000; // 80 seconds (should never take longer than 75 secs from upper limit)

    this->setEnabled(false);
//    ui->lineEditNeedsInit->setText("Seeking");
    // Remote activation of Reset (Find Home) Motion
    m_pResetTimer->start(iTimeoutEstimate);
    //pPrinterComm->SendCmd("T1");
    pPrinterComm->SendCmd("R");
    resetLastSentCycleSettings();

}

void Terminal::on_pushButtonCalibration_clicked()
{
    QObject::disconnect(this, SIGNAL(HomeFound()), pMain, SLOT(doPrint()));
    rcGotoFillAfterReset(50);//go to Terminal::onMotionResetComplete() m_iFillLevel
    on_pushButtonCmdReset_clicked();
}

void Terminal::on_pushButtonProjPower_clicked()
{//commercial projector
//    if(ui->pushButtonProjPower->text() == "ON"){
//        rcSendCmd("P1");//open
//        ui->pushButtonProjPower->setText("OFF");
//    }
//    else{
//        rcSendCmd("P0");//close
//        ui->pushButtonProjPower->setText("ON");
//    }

}

void Terminal::on_pushButtonBoard_clicked()
{//commercial projector
//    if(ui->pushButtonBoard->text() == "ON"){
//        rcSendCmd("#0");//open
//        ui->pushButtonBoard->setText("OFF");
//    }
//    else{
//        rcSendCmd("#1");//close
//        ui->pushButtonBoard->setText("ON");
//    }
}

void Terminal::on_pushButtonCycleSettings_clicked()
{
    pSettings->updateValues();

}

void Terminal::on_pushButtonPrintBase_clicked()
{
//    ui->lineEditCycleStatus->setText("Moving to Base...");
//    ui->pushButtonPrintBase->setEnabled(false);
//    ui->pushButtonPrintNext->setEnabled(false);
//    ui->pushButtonPrintFinal->setEnabled(false);
    resetLastSentCycleSettings();
    SetCycleParameters();
    int iTimeout = getEstBaseCycleTime(m_iCurZPosInPU/*ui->lineEditCurZPosInPU->text().toInt()*/, m_iTgtZPosInPU/*ui->lineEditTgtZPU->text().toInt()*/);
    pPrinterComm->SendCmd("B"+QString::number(m_iTgtZPosInPU)/*ui->lineEditTgtZPU->text()*/);
    m_pPReleaseCycleTimer->start(iTimeout * 2.0); // Timeout after 200% of estimated time required

}

void Terminal::on_pushButtonPrintNext_clicked()
{
//    ui->lineEditCycleStatus->setText("Cycling to Next...");
//    ui->pushButtonPrintBase->setEnabled(false);
//    ui->pushButtonPrintNext->setEnabled(false);
//    ui->pushButtonPrintFinal->setEnabled(false);

    SetCycleParameters();
    int iTimeout = getEstNextCycleTime(m_iCurZPosInPU/*ui->lineEditCurZPosInPU->text().toInt()*/, m_iTgtZPosInPU/*ui->lineEditTgtZPU->text().toInt()*/);
    pPrinterComm->SendCmd("N"+QString::number(m_iTgtZPosInPU)+m_progressValue/*ui->lineEditTgtZPU->text()*/);
    m_pPReleaseCycleTimer->start(iTimeout * 2.0); // Timeout after 200% of estimated time required

}

void Terminal::on_pushButtonPrintFinal_clicked()
{
    rcProjectorPwr(false);  // command projector OFF
//    ui->lineEditCycleStatus->setText("Final Release...");
//    ui->pushButtonPrintBase->setEnabled(false);
//    ui->pushButtonPrintNext->setEnabled(false);
//    ui->pushButtonPrintFinal->setEnabled(false);
    SetCycleParameters();
    int iTimeout = getEstFinalCycleTime(m_iCurZPosInPU/*ui->lineEditCurZPosInPU->text().toInt()*/, m_iTgtZPosInPU/*ui->lineEditTgtZPU->text().toInt()*/);
    if(m_minute>0){
        pPrinterComm->SendCmd("F"+QString::number(m_iTgtZPosInPU)+"A"/*ui->lineEditTgtZPU->text()*/);
    }else{
        pPrinterComm->SendCmd("F"+QString::number(m_iTgtZPosInPU)+"F"/*ui->lineEditTgtZPU->text()*/);
    }
    //pPrinterComm->SendCmd("F"+QString::number(m_iTgtZPosInPU)/*ui->lineEditTgtZPU->text()*/);
    m_pPReleaseCycleTimer->start(iTimeout * 2.0); // Timeout after 200% of estimated time required

}

void Terminal::on_pushButtonStop_clicked()
{
    m_pPReleaseCycleTimer->stop();
//    m_pVatTimer->stop();
    pPrinterComm->SendCmd("S");
//    ui->lineEditCycleStatus->setText("停止");//Cycle Stopped.
//    ui->pushButtonPrintBase->setEnabled(true);
//    ui->pushButtonPrintNext->setEnabled(true);
//    ui->pushButtonPrintFinal->setEnabled(true);
//    ui->groupBoxVAT->setEnabled(true);
    resetLastSentCycleSettings();

}

void Terminal::on_pushButtonProjPower_toggled(bool checked)
{//commercial projector
//    ui->pushButtonProjPower->setChecked(checked);
//    if(checked)
//        ui->pushButtonProjPower->setText("ON");
//    else
//        ui->pushButtonProjPower->setText("OFF");
//    pPrinterComm->cmdProjectorPowerOn(checked);
//    emit(setProjectorPowerCmd(checked));

//    // if m_bPrimaryScreen is true, we need to show it before turning on projector!
////    if(m_bPrimaryScreen) onScreenCountChanged();//cyp
//    emit sendStatusMsg("B9Creator - Projector status: TURN ON");

//    // We always close the vat when powering up
//    if(checked){
//        emit onBC_CurrentVatPercentOpen(0);
////        emit on_spinBoxVatPercentOpen_editingFinished();
//    }

}


void Terminal::makeProjectorConnections()
{
    // should be called any time we create a new projector object
    if(pProjector==NULL)return;
    connect(pProjector, SIGNAL(keyReleased(int)),this, SLOT(getKey(int)));
    connect(this, SIGNAL(sendStatusMsg(QString)),pProjector, SLOT(setStatusMsg(QString)));
    connect(this, SIGNAL(sendGrid(bool)),pProjector, SLOT(setShowGrid(bool)));
    connect(this, SIGNAL(sendCPJ(CrushedPrintJob*)),pProjector, SLOT(setCPJ(CrushedPrintJob*)));
    connect(this, SIGNAL(sendXoff(int)),pProjector, SLOT(setXoff(int)));
    connect(this, SIGNAL(sendYoff(int)),pProjector, SLOT(setYoff(int)));
}

void Terminal::getKey(int iKey)
{
    if(!m_bPrimaryScreen)return; // Ignore keystrokes from the print window unless we're using the primary monitor
    if(isVisible()&&isEnabled())
    {
        // We must be "calibrating"  If we get any keypress we should close the projector window
        if(pProjector!=NULL) pProjector->hide();
    }
    switch(iKey){
    case 112:		// 'p' Pause/Resume
        emit pausePrint();
        break;
    case 97://cyp 65:        // Capital 'A' to abort
        if(!isEnabled()){
//            m_pPReleaseCycleTimer->stop();//cyp
            if(language=="Chinese"){
                emit signalAbortPrint("用户终止.");
            }else{
                emit signalAbortPrint("User Directed Abort.");
            }
//            emit signalAbortPrint("User Directed Abort.");
        }
        break;
    default:
        break;
    }
}
void Terminal::on_lineEditCommand_returnPressed()
{
//    pPrinterComm->SendCmd(ui->lineEditCommand->text());
//    ui->lineEditCommand->clear();
}

void Terminal::on_lineEditCurZPosInPU_returnPressed()
{
    int iValue=m_iCurZPosInPU/*ui->lineEditCurZPosInPU->text().toInt()*/;
    if(/*QString::number(iValue)!=ui->lineEditCurZPosInPU->text()|| */iValue<0 || iValue >13000){
        // Bad Value, just return
//        ui->lineEditCurZPosInPU->setText("Bad Value");
        return;
    }
    pPrinterComm->SendCmd("G"+QString::number(iValue));
//    ui->lineEditCurZPosInPU->setText("In Motion...");
//    ui->lineEditCurZPosInMM->setText("In Motion...");
//    ui->lineEditCurZPosInInches->setText("In Motion...");
}

void Terminal::on_lineEditCurZPosInMM_returnPressed()
{
    double dPU = (double)pPrinterComm->getPU()/100000.0;
    double dValue=m_dCurZPosInMM;//ui->lineEditCurZPosInMM->text().toDouble();
    if(/*(dValue==0 && ui->lineEditCurZPosInMM->text().length()>1 )||*/dValue<0 || dValue >130){
        // Bad Value, just return
//        ui->lineEditCurZPosInMM->setText("Bad Value");
        return;
    }

    pPrinterComm->SendCmd("G"+QString::number((int)(dValue/dPU)));
//    ui->lineEditCurZPosInPU->setText("In Motion...");
//    ui->lineEditCurZPosInMM->setText("In Motion...");
//    ui->lineEditCurZPosInInches->setText("In Motion...");
}

void Terminal::on_lineEditTgtZPU_editingFinished()
{
    int iValue=m_iTgtZPosInPU;//ui->lineEditTgtZPU->text().toInt();
    if(iValue<0 || iValue >13000){
        QMessageBoxByLanguage();
//        QMessageBox::information(this, tr("Target Level (Z high) Out of Range"),
//                                       tr("Please enter an integer value between 0-130.\n"
//                                          "This will be the altitude for the next layer.\n"),
//                                       QMessageBox::Ok);
        iValue = 0;
        m_iTgtZPosInPU = iValue;
//        ui->lineEditTgtZPU->setText(QString::number(iValue));
//        ui->lineEditTgtZPU->setFocus();
//        ui->lineEditTgtZPU->selectAll();
    }
    setTgtAltitudePU(iValue);
}

void Terminal::on_lineEditTgtZMM_editingFinished()
{
//    double dValue=m_dTgtZPosInMM;//ui->lineEditTgtZMM->text().toDouble();
//    double dTest = QString::number(dValue).toDouble();
//    if((dTest==0 && ui->lineEditTgtZMM->text().length()>2)|| dTest!=ui->lineEditTgtZMM->text().toDouble()||
//            dValue<0 || dValue >200.00595){
//        QMessageBox::information(this, tr("Target Level (Inches) Out of Range"),
//                     tr("Please enter an integer value between 0-130.\n"
//                     "This will be the altitude for the next layer.\n"),QMessageBox::Ok);
//        dValue = 0;
//        m_dTgtZPosInMM = dValue;
////        ui->lineEditTgtZMM->setText(QString::number(dValue));
////        ui->lineEditTgtZMM->setFocus();
////        ui->lineEditTgtZMM->selectAll();
//        return;
//    }
//    setTgtAltitudeMM(dValue);
}

void Terminal::warnSingleMonitor(){
    if(m_bPrimaryScreen && m_bNeedsWarned){
        m_bNeedsWarned = false;
        QMessageBox msg;
        msg.setWindowTitle("Projector Connection?");
        msg.setText("WARNING:  The printer's projector is not connected to a secondary video output.  Please check that all connections (VGA or HDMI) and system display settings are correct.  Disregard this message if your system has only one video output and will utilize a splitter to provide video output to both monitor and Projector.");
//        if(isEnabled())msg.exec();//cyp
    }
}

void Terminal::setEnabledWarned(){
    if(isHidden())return;
    if(!m_bWaiverPresented||m_bWaiverAccepted==false){
        // Present Waiver
        m_bWaiverPresented = true;
        m_bWaiverAccepted = false;
        if(!m_bWavierActive){
            m_bWavierActive = true;
//            int ret = QMessageBox::information(this, tr("Enable Terminal Control?"),
//                                           tr("Warning: Manual operation can damage the VAT coating.\n"
//                                              "If your VAT is installed and empty of resin care must be\n"
//                                              "taken to ensure it is not damaged.  Operation is only safe\n"
//                                              "with either the VAT removed, or the Sweeper and Build Table removed.\n"
//                                              "The purpose of this utility is to assist in troubleshooting.\n"
//                                              "Its use is not required during normal printing operations.\n"
//                                              "Do you want to enable manual control?"),
//                                           QMessageBox::Yes | QMessageBox::No
//                                           | QMessageBox::Cancel);

//            if(ret==QMessageBox::Cancel){m_bWavierActive = false;m_bWaiverPresented=false;hide();return;}
//            else if(ret==QMessageBox::Yes)m_bWaiverAccepted=true;

            m_bWaiverAccepted=true;//cyp
            warnSingleMonitor();
            m_bWavierActive = false;
        }
    }
//    ui->groupBoxMain->setEnabled(m_bWaiverAccepted&&pPrinterComm->isConnected()&&ui->lineEditNeedsInit->text()!="Seeking");
//    ui->groupBox_terminal->setEnabled(m_bWaiverAccepted&&pPrinterComm->isConnected()/*&&ui->lineEditNeedsInit->text()!="Seeking"*/);
//    this->setEnabled(m_bWaiverAccepted&&pPrinterComm->isConnected());
}

void Terminal::hideEvent(QHideEvent *event)
{
    emit eventHiding();
    event->accept();
}

//void Terminal::on_spinBoxVatPercentOpen_editingFinished()
//{
//    if(m_pVatTimer->isActive()) return;
//    m_pVatTimer->start(3000); //should never take that long, even at slow speed
//    int iValue = ui->spinBoxVatPercentOpen->value();
////    ui->groupBoxVAT->setEnabled(false);
//    pPrinterComm->SendCmd("V"+QString::number(iValue));
//}

void Terminal::on_pushButtonFindHomePos_clicked()
{
//    QMessageBox msgBox;
//    msgBox.setWindowTitle("Hint");//提示
////    msgBox.setIcon(QMessageBox::Warning);
//    msgBox.setText("\nThe motor is over the sensor\n");//
//    msgBox.setToolTip("请确认电机位置是否在传感器上方");
//    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
////    msgBox.setButtonText(QMessageBox::Yes,QString("是"));
////    msgBox.setButtonText(QMessageBox::No,QString("否"));
//    msgBox.setDefaultButton(QMessageBox::No);
//    int ret = msgBox.exec();

//    if(ret == QMessageBox::No)
//        return;
//    else{
//        QObject::disconnect(this, SIGNAL(HomeFound()), pMain, SLOT(doPrint()));
//        rcResetHomePos();//cyp
//        rcGotoFillAfterReset(50);
//    }
}

void Terminal::on_checkBox_toggled(bool checked)
{
    ui->lineEditHomePos->setEnabled(checked);
    ui->pushButtonResetHomePos->setEnabled(checked);

    if(!checked){
        ui->lineEditHomePos->setText("");
    }
}

void Terminal::on_pushButtonResetHomePos_clicked()
{
    int iValue=ui->lineEditHomePos->text().toInt();//感应器到零点的补偿值
    if(QString::number(iValue)!=ui->lineEditHomePos->text()|| iValue<0 || iValue >15000){
        // Bad Value, just return
        ui->lineEditHomePos->setText("Bad Value");
        return;
    }
    QMessageBox msgBox;
    msgBox.setWindowTitle("Hint");//提示
//    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Reset the home position");//
    msgBox.setToolTip("重设零点位置\n确定设置零点为传感器向下补偿"+ui->lineEditHomePos->text()+"步的位置吗？");//Are you sure you want to orientate?
    msgBox.setInformativeText("Are you sure you want to reset the zero is located "+ui->lineEditHomePos->text()+" steps below the sensor?");//Are you sure you want to orientate?
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//    msgBox.setButtonText(QMessageBox::Yes,QString("是"));
//    msgBox.setButtonText(QMessageBox::No,QString("否"));
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if(ret == QMessageBox::No)
        return;
    else{
        QString cmd = "Y" + ui->lineEditHomePos->text();
        rcSendCmd(cmd);
    }
}

//void Terminal::on_pushButtonBoardON_clicked()
//{
//    rcSendCmd("#0");//open
//}

//void Terminal::on_pushButtonBoardOFF_clicked()
//{
//    rcSendCmd("#1");//close
//}

bool Terminal::on_pushButtonProjPowerON_clicked()
{
    if(ui->projectorStatus->text() == "DISCONNECT")
        return false;
    BlueEnable = true;
//    if(isM50){
        DLPC350_SetLedEnables(false, false, false, BlueEnable);

        DLPC350_SetLEDPWMInvert(false);

        DLPC350_SetLedCurrents(255, 255, 255);

//    }
//    else{
//        HWND   hwnd;
//            int i=0;
//            bool flag;

//            if(f_LedOff)
//            {
//                GetDlgItem(hwnd,IDC_SLIDER_LED);
//                ::EnableWindow(hwnd,TRUE);
//                GetDlgItem(hwnd,IDC_EDIT_LED);
//                ::EnableWindow(hwnd,TRUE);
//                GetDlgItem(hwnd,IDC_BUTTON_LED_SET);
//                ::EnableWindow(hwnd,TRUE);
//                GetDlgItem(hwnd,IDC_BUTTON_LED_GET);
//                ::EnableWindow(hwnd,TRUE);
//                if(UART_Port)
//                {
//                    //Set_RGB_Current(RED_VAL,SliderPos,BLUE_VAL);
//                    for(i=0;i<4;i++)
//                    {
//                        flag=LedOnOff(1);
//                        if(flag)
//                            break;
//                        Sleep(50);
//                    }

//                    SetCurrent(0,0,0);
//                    f_LedOff=FALSE;
////                    ui->pushButtonOff->setText("Off");
//                }
//                else
//                    return false;
//            }
//    }
    ui->projectorStatus->setText("ON");
    return true;
}

void Terminal::on_pushButtonProjPowerOFF_clicked()
{
    BlueEnable = false;
//    if(isM50){
//        if(BlueEnable){//当前状态是开着的
            DLPC350_SetLedEnables(false, false, false, BlueEnable);
//            DLPC350_SetLEDPWMInvert(false);
//            DLPC350_SetLedCurrents(255, 255, 255);

//        }
//    }
//    else{
//        HWND   hwnd;
//            int i=0;
//            bool flag;
//        if(UART_Port==0)
//        {
//            return ;
//        }
//        SetCurrent(0,0,0);
//        GetDlgItem(hwnd,IDC_SLIDER_LED);
//        ::EnableWindow(hwnd,FALSE);
//        GetDlgItem(hwnd,IDC_EDIT_LED);
//        ::EnableWindow(hwnd,FALSE);
//        GetDlgItem(hwnd,IDC_BUTTON_LED_SET);
//        ::EnableWindow(hwnd,FALSE);
//        GetDlgItem(hwnd,IDC_BUTTON_LED_GET);
//        ::EnableWindow(hwnd,FALSE);

//        //Set_RGB_Current(RED_VAL,0,BLUE_VAL);
//        for(i=0;i<4;i++)
//        {
//            flag=LedOnOff(0);
//            if(flag)
//                break;
//            Sleep(50);
//        }
//        f_LedOff=TRUE;
////        ui->pushButtonOff->setText("On");
//////            SetDlgItemText(IDC_LED_CTRL,_CS("Led.On"));
//    }
    ui->projectorStatus->setText("OFF");
}

void Terminal::on_spinBox_BlueLEDCurrent_editingFinished()
{//调节投影仪亮度
////    if(!BlueEnable) return;
////    if(isM50/* && BlueEnable*/){
//        DLPC350_SetLedCurrents(255, 255, 255-ui->spinBox_BlueLEDCurrent->value());
////    }
////    else if(UART_Port){
////        unsigned short red,green,blue,Value;
////        Value = ui->spinBox_BlueLEDCurrent->value();
//////        GetCurrent(&red,&green,&blue);
////        SetCurrent(0,Value,0);
////    }
    pPrinterComm->SendCmd("@"+QString::number(ui->spinBox_BlueLEDCurrent->value()));
}

void Terminal::on_commStatus_editingFinished()
{
}

void Terminal::on_commStatus_textChanged(const QString &arg1)
{
    emit BC_ConnectionStatusDetailed(arg1);

}

void Terminal::on_toolButtonUp_clicked()
{
    double dPU = (double)pPrinterComm->getPU()/100000.0;
    m_iTgtZPosInPU = m_iCurZPosInPU +(int)(ui->doubleSpinBoxDistance->value()/dPU);
    if(m_iTgtZPosInPU<0 || m_iTgtZPosInPU >13000){
        QMessageBoxByLanguage();
//        QMessageBox::information(this, tr("Target Level (Z steps) Out of Range"),
//                                       tr("Please enter an integer value between 0-130.00.\n"
//                                          "This will be the altitude for the next layer.\n"),
//                                       QMessageBox::Ok);
        return;
    }
    pPrinterComm->SendCmd("G"+QString::number(m_iTgtZPosInPU));
}

void Terminal::on_toolButtonDown_clicked()
{
    double dPU = (double)pPrinterComm->getPU()/100000.0;
    m_iTgtZPosInPU = m_iCurZPosInPU -(int)(ui->doubleSpinBoxDistance->value()/dPU);
    if(m_iTgtZPosInPU<0 || m_iTgtZPosInPU >13000){
        QMessageBoxByLanguage();
//        QMessageBox::information(this, tr("Target Level (Z steps) Out of Range"),
//                                       tr("Please enter an integer value between 0-130.00.\n"
//                                          "This will be the altitude for the next layer.\n"),
//                                       QMessageBox::Ok);
        return;
    }
    pPrinterComm->SendCmd("G"+QString::number(m_iTgtZPosInPU));
}

void Terminal::on_pushButtonAdd_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Hint");//提示
//    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Reset the home position");//
    msgBox.setToolTip("重设零点位置\n确定将零点上调0.05mm吗？");//Are you sure you want to orientate?
    msgBox.setInformativeText("Are you sure you want to the zero up 0.05mm ?");//Are you sure you want to orientate?
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//    msgBox.setButtonText(QMessageBox::Yes,QString("是"));
//    msgBox.setButtonText(QMessageBox::No,QString("否"));
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if(ret == QMessageBox::No)
        return;
    else{
        rcSendCmd("ZU");
    }
}

void Terminal::on_pushButtonSubtract_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Hint");//提示
//    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Reset the home position");//
    msgBox.setToolTip("重设零点位置\n确定将零点下调0.05mm吗？");//Are you sure you want to orientate?
    msgBox.setInformativeText("Are you sure you want to the zero down 0.05mm ?");//Are you sure you want to orientate?
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//    msgBox.setButtonText(QMessageBox::Yes,QString("是"));
//    msgBox.setButtonText(QMessageBox::No,QString("否"));
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if(ret == QMessageBox::No)
        return;
    else{
        rcSendCmd("ZD");
    }
}

void Terminal::UpdateByLanguage(){
    if(language=="Chinese"){
        this->setWindowTitle("终端");
        ui->labelPrinter->setText("打印机状态：");
        ui->label_2->setText("手动调整(mm):");
        ui->label_4->setText("光强：");
        ui->pushButtonCalibration->setText("位置校准");
        ui->pushButton->setText("重设起点");
        ui->pushButton_2->setText("找到起点");
    }else{
        this->setWindowTitle("Terminal");
        ui->labelPrinter->setText("Printer Status：");
        ui->label_2->setText("Manual Move(mm):");
        ui->label_4->setText("Light Intensity：");
        ui->pushButtonCalibration->setText("Go To Calibration Position");
        ui->pushButton->setText("ResetHome");
        ui->pushButton_2->setText("FindHome");
    }
}

void Terminal::on_pushButton_clicked()
{
    if(m_iTgtZPosInPU<0 || m_iTgtZPosInPU >13000){
        ui->lineEdit->setText("Data is out of range.\n"
                              "(数据超出0-1300范围).\n");
        return;
    }
//    else{
//        ui->lineEdit->setText(QString::number(m_iTgtZPosInPU));
//    }
    QSettings appSettings;//
    appSettings.beginGroup("USERSET");
    appSettings.setValue("Home",m_iTgtZPosInPU);
    appSettings.endGroup();
    if(language=="Chinese")
        QMessageBox::information(this, tr("起点设置"),tr("起点设置成功.\n"),QMessageBox::Ok);
    else
        QMessageBox::information(this, tr("ResetHome"),tr("ResetHome Success.\n"),QMessageBox::Ok);
}
void Terminal::on_pushButton_2_clicked()
{
    QSettings appSettings;//
    appSettings.beginGroup("USERSET");
    m_iTgtZPosInPU=appSettings.value("Home",TGT).toInt();
    appSettings.endGroup();
    if(m_iTgtZPosInPU<0 || m_iTgtZPosInPU >13000){
        QMessageBoxByLanguage();
        return;
    }
    pPrinterComm->SendCmd("G"+QString::number(m_iTgtZPosInPU));
}

void Terminal::QMessageBoxByLanguage(){
    if(language=="Chinese"){
        QMessageBox::information(this, tr("目标值超过范围"),
                                       tr("请输入一个0-130.00的值.\n"
                                          /*"This will be the altitude for the next layer.\n"*/),
                                       QMessageBox::Ok);
    }else{
        QMessageBox::information(this, tr("Target Level (Z steps) Out of Range"),
                                       tr("Please enter an integer value between 0-130.00.\n"
                                          "This will be the altitude for the next layer.\n"),
                                       QMessageBox::Ok);
    }
}
