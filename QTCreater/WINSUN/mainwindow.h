#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*Dan
  软件主窗体,包括菜单栏(file,edit,view,slice,tools)
*/
#include <QMainWindow>
#include "ui_mainwindow.h"
#include <supportsetting.h>
#include <showslices.h>
#include <materialscatalog.h>
#include <cycleprintsetting.h>
#include <buildspace.h>
#include <terminal.h>
#include <printwindow.h>
#include <print.h>

#include <QCloseEvent>
#include <QDesktopWidget>
#include <QSplashScreen>
#include "logfilemanager.h"
#include "helpsystem.h"

#include "layout/worldview.h"
#include "layout/slicecontext.h"
#include "layout/loop.h"
#include "layout/layoutprojectdata.h"

#include "modellist.h"
#include "supportsetting.h"
#include "supportparameter.h"

#include "myballon.h"
#include "sizewidget.h"
#include "positionwidget.h"
#include "orientationwidget.h"
#include "printsettingdialog.h"
#include "viewwidget.h"
#include "statuswidget.h"
#include "sliceslider.h"
#include "slicedialog.h"
#include <time.h>

class PrintSettingDialog;
class ShowSlices;
class MainWindow;
class b9PrinterModelManager;
class B9UpdateManager;
class B9LayoutProjectData;
class WorldView;
class ModelData;
class B9ModelInstance;
class SliceDebugger;
class B9SupportStructure;
class SupportParameter;
class ModelList;
class PrintWindow;
class MyBallonWidget;
class sizeWidget;
class PositionWidget;
class OrientationWidget;
class viewWidget;
class statusWidget;
class Terminal;
class Print;
class SliceContext;
class Loop;
class SliceSlider;
class SliceDialog;


//namespace Ui {
//class MainWindow;
//}

class PSupportSettings {
public:
    PSupportSettings(){loadSettings();}
    ~PSupportSettings(){}
    void updateValues(); // Opens a dialog and allows user to change settings

    void loadSettings();
    void saveSettings();
    void setFactorySettings();

    double m_dBaseRadius, m_dTopRadius, m_dMidRadius, m_dBottomRadius;
    double m_dBaseLength, m_dTopLength, m_dMidLength, m_dBottomLength;
    QString m_baseAttachShape, m_topAttachShape, m_midAttachShape, m_bottomAttachShape;
    double m_dTopPenetration, m_dBottomPenetration;
    double m_dTopAngleFactor, m_dBottomAngleFactor;
    double m_autoDistance;    
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //（width,height)——Computer screen size
    explicit MainWindow(int width,int height, QWidget *parent = 0);
    ~MainWindow();
    void InitInterface();
    std::vector<B9ModelInstance*> GetAllInstances();
    std::vector<B9ModelInstance*> GetSelectedInstances();
    std::vector<ModelData*> GetAllModelData(){return ModelDataList;}
    B9LayoutProjectData* ProjectData(){return project;}


signals:
    void eventHiding();
    void selectedDirChanged(QString s);
    void setVersion(QString s);
    void setName(QString s);
    void setDescription(QString s);
    void setXYPixel(QString s);
    void setZLayer(QString s);
    void setSliceIndicator(QString s);
    void PercentCompletedUpdate(qint64,qint64);


public slots:
    void setPrinterToModel1();
    void setPrinterToModel2();

    void OnSetSupprotWidget(int iLength);//supportparameter widget size

    //---------------------------------file-----------------------------------------
    void New();
    QString Open(bool withoutVisuals = false);
    void Save();
    void SaveAs();

    void showWSTLfile(QString filepath);//layout file
    void showWSfile(/*QString filepath*/);//slice file

    //exporting
    void PromptExportToSTL();//export the whole layout to a stl file.
    bool ExportToSTL(QString filename);//stl file
    bool ExportToSTL(QDataStream & pOut);
    void ExportToSlice(QDataStream & out,
                           std::map<int,std::vector< std::vector < QVector2D > > >& mapTri,
                           std::map<int,std::vector<QVector2D > >& mapLine);


    //----------------------------------edit--------------------------------------
    //model
    B9ModelInstance* AddModel(QString filepath = "", bool bypassVisuals = false);
    void RemoveAllInstances();
    void CleanModelData();//cleans andy modeldata that does not have a instance!
    void AddTagToModelList(QListWidgetItem* item);

    //layout
    void on_ButtonScale_clicked();
    void on_ButtonRotate_clicked();
    void on_ButtonMove_clicked();
    void on_ButtonAuto_clicked();
    //language
    void getLanguage(int index);
    //ModelTools interface
    void SetToolModelSelect();
    void SetToolModelMove();
    void SetToolModelSpin();
    void SetToolModelOrientate();
    void SetToolModelScale();

    //interface
    void SetXYPixelSizePreset(QString size);
    void SetZLayerThickness(QString thick);
    void SetProjectorX(QString);
    void SetProjectorY(QString);
    void SetProjectorPreset(int index);
    void SetZHeight(QString z);
    void SetAttachmentSurfaceThickness(QString num);

    void UpdateInterface();//sets the translation interface fields acourding to what instance/instances are selected.
    void OnModelSpinSliderReleased();

    //TOOLS
    void SetTool(QString toolname);//calls the functions below

    void ExitToolAction();//use to panic out of a mouse down tool action.

    B9ModelInstance* FindInstance(QListWidgetItem* item);//given a item you can find the connected instance

    //selection
    void RefreshSelectionsFromList();//searches through all active listitems and selects their corresponding instance;
    void Select(B9ModelInstance* inst);//selects the given instance
    void DeSelect(B9ModelInstance* inst);//de-selects the given instance
    void SelectOnly(B9ModelInstance* inst);//deselects eveything and selects only the instance
    void DeSelectAll();//de-selects all instances
    void SetSelectionPos(double x, double y, double z, int axis = 0);
    void SetSelectionRot(QVector3D newRot);
    void SetSelectionScale(double x, double y, double z, int axis = 0);
    void SetSelectionFlipped(bool flipped);
    void DropSelectionToFloor();
    void ResetSelectionRotation();
    void DuplicateSelection();
    void DeleteSelection();//delete whatever is selected - support or instance..
    void DeleteSelectedInstances();

    void setButtonEnable(bool enable);
    void setWidgetVisible(bool enable);
    void setButtonStyleSheet(QPushButton *btn, bool enable);

    void on_curNumOfLayers(int);

    //------------------------------------------Support Mode-----------------------------------------------
    void on_ButtonSupport_clicked(bool isSupport=true);
    void SetSupportMode(bool tog = true);//Sets everything up for editing supports for the selected instance.
                            //when either the tab is clicked or the menu item - a selected instance
                            //can be assumed
    B9SupportStructure* FindSupportByName(QString name);
    std::vector<B9SupportStructure*>* GetSelectedSupports();
    bool IsSupportSelected(B9SupportStructure* sup);
    void DeSelectSupport(B9SupportStructure* sup);
    void DeSelectAllSupports();
    void DeleteSelectedSupports();//called from remove button.
    void DeleteSupport(B9SupportStructure* pSup);
    void MakeSelectedSupportsVertical();
    void MakeSelectedSupportsStraight();

    //SupportTools interface
    void SetToolSupportAdd();
    void SetToolSupportDelete();
    void RemoveAllSupports();

    //Support parameters Interface
    void OnSupport_Top_AttachType_Changed(bool updateInterface = true);
    void OnSupport_Top_Radius_Changed(bool updateInterface = true);
    void OnSupport_Top_Length_Changed(bool updateInterface = true);
    void OnSupport_Top_Penetration_Changed(bool updateInterface = true);
    void OnSupport_Top_AngleFactor_Changed(bool updateInterface = true);
    void OnSupport_Mid_AttachType_Changed(bool updateInterface = true);
    void OnSupport_Mid_Radius_Changed(bool updateInterface = true);
    void OnSupport_Bottom_AttachType_Changed(bool updateInterface = true);
    void OnSupport_Bottom_Radius_Changed(bool updateInterface = true);
    void OnSupport_Bottom_Length_Changed(bool updateInterface = true);
    void OnSupport_Bottom_Penetration_Changed(bool updateInterface = true);
    void OnSupport_Bottom_AngleFactor_Changed(bool updateInterface = true);

    void OnBasePlatePropertiesChanged();//Foundation (BasePlate)

    void ResetSupportLight();//connected to push button
    void ResetSupportMedium();//connected to push button
    void ResetSupportHeavy();//connected to push button
    void FillSupportParamsWithDefaults();

    //support hiding
    bool HidingSupports();
    void OnToggleSupportHiding(bool tog);


    //returns a valid instance if we are editing it in support mode.
    B9ModelInstance* SupportModeInst();

    //-------------------------------------slicing-------------------------------------------
    void doSlice();
    bool SliceWorld();//prompts the user to slice to world to different formats.
    bool SliceWorldToJob(QString filename);//slices to whole world to a job file
    bool SliceWorldToSlc(QString filename);//slices to whole world to a slc file
    void CancelSlicing(); //connected to the progress bar to stop slicing.


    //--------------------------------------print--------------------------------------------------
    void doPrint();
    void showPrintWindow();
    void showPrintWindow1();
    void showCatalog();
    void showSliceWindow();


    //------------------------------------events------------------------------------------
    void keyPressEvent(QKeyEvent * event );
    void keyReleaseEvent(QKeyEvent * event );
    void mouseReleaseEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void hideEvent(QHideEvent *event);
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent * event );
    void ChangeToEnglish();
    void ChangeToChinese();

public:
    Ui::MainWindow ui;
    int m_width,m_height;

    QLabel *lable;

    PrintSettingDialog *pPriSetDlg;

    bool bModel,bLayout,bSupport;
    bool bView,bSize,bPos,bRot,bSup,bAdv;

    ModelList *pModelList;

//    viewWidget *view;
    sizeWidget *size;
    OrientationWidget *orientation;
    PositionWidget *position;
    SupportParameter *pSupport;

    QWidget *bakground;
    QWidget *bakgroundModel;
    QWidget *bakgroundLayout;
    QWidget *bakgroundSupport;
    QWidget *bakgroundSlice;
    QWidget *bakgroundPrint;

    QWidget *bakgroundAdd;
    QWidget *bakgroundDelete;
    QWidget *bakgroundDuplicate;

    QWidget *bakgroundScale;
    QWidget *bakgroundRotate;
    QWidget *bakgroundMove;

    QWidget *bakgroundAddSup;
    QWidget *bakgroundDeleteSup;
    QWidget *bakgroundAuto;
    QWidget *bakgroundClean;
    QWidget *bakgroundSupOption;

    statusWidget *status;

//    MyBallonWidget *pMBW_View;
    MyBallonWidget *pMBW_Size;
    MyBallonWidget *pMBW_Rotate;
    MyBallonWidget *pMBW_Position;
    MyBallonWidget *pMBW_ModelList;
    MyBallonWidget *pMBW_Support;

    QPushButton *pButtonModel;
    QPushButton *pButtonLayout;
    QPushButton *pButtonSupport;
    QPushButton *pButtonSlice;
    QPushButton *pButtonPrint;

//    QPushButton *pButtonView;
    QPushButton *pButtonAdd;
    QPushButton *pButtonDelete;
    QPushButton *pButtonDuplicate;

    QPushButton *pButtonScale;
    QPushButton *pButtonRotate;
    QPushButton *pButtonMove;

    QPushButton *pButtonAddSup;
    QPushButton *pButtonDeleteSup;
    QPushButton *pButtonAuto;
    QPushButton *pButtonClean;
    QPushButton *pButtonSupOption;


    QPushButton *pButtonTop;
    QPushButton *pButtonBottom;
    QPushButton *pButtonLeft;
    QPushButton *pButtonRight;
    QPushButton *pButtonFront;
    QPushButton *pButtonBack;

    QAction *pActionSupport;

    SliceSlider *curNumOfLayersSlider;
//    QSlider *curNumOfLayersSlider;

    Terminal *t;
    PrintWindow *pw;
    Print *pPrint;
    ShowSlices *pSliceView;
    WorldView *pWorldView;

    B9LayoutProjectData* project;

    CrushedPrintJob cPJ;

    CrushedPrintJob *m_pCPJ;
    CrushedPrintJob *newCPJ;
    PSupportSettings *pSettings;

    std::vector<ModelData*> ModelDataList;

    bool cancelslicing;

    //support mode
    B9ModelInstance* currInstanceInSupportMode;
    bool oldModelConstricted;//for raising models that are too close to the ground in support mode.
    QVector3D oldPan;
    QVector3D oldRot;
    float oldZoom;
    QString oldTool;
    bool hideSupports;
    std::vector<B9SupportStructure*> currSelectedSupports;//what supports are currently in selection.
    QString language;
    QString current_language;
    QTranslator *tor;

    void LanguageInit();
    void UpdateByLanguage();
};

#endif // MAINWINDOW_H
