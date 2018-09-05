#ifndef SUPPORTPARAMETER_H
#define SUPPORTPARAMETER_H
/*Dan
  支撑添加页面参数设置
*/
#include <QWidget>
#include "mainwindow.h"

class PSupportSettings;
class MainWindow;

namespace Ui {
class SupportParameter;
}

class SupportParameter : public QWidget
{
    Q_OBJECT
    
public:
    explicit SupportParameter(QWidget *parent, MainWindow *main);
    ~SupportParameter();
    void updateDialog();
    void stuffSettings();
    bool getBaseIsChecked();
    
signals:
    void setSupportWidget(int);

private slots:
    void on_radioButtonAdd_toggled(bool checked);

    void on_radioButtonDelete_toggled(bool checked);

    void on_pushButtonCleanAll_clicked();

    void on_pushButtonRestoreDefaults_clicked();

    void on_Support_Top_Penetration_horizontalSlider_valueChanged(int value);

    void on_Support_Top_AngleFactor_horizontalSlider_valueChanged(int value);

    void on_Support_Bottom_Penetration_horizontalSlider_valueChanged(int value);

    void on_Support_Bottom_AngleFactor_horizontalSlider_valueChanged(int value);

//    void on_Support_Base_AttachType_comboBox_currentIndexChanged(const QString &arg1);

//    void on_Support_Top_AttachType_comboBox_currentIndexChanged(const QString &arg1);

//    void on_Support_Mid_AttachType_comboBox_currentIndexChanged(const QString &arg1);

//    void on_Support_Bottom_AttachType_comboBox_currentIndexChanged(const QString &arg1);

//    void on_Support_Base_Radius_doubleSpinBox_valueChanged(double arg1);

//    void on_Support_Base_Length_doubleSpinBox_valueChanged(double arg1);

//    void on_Support_Top_Length_doubleSpinBox_valueChanged(double arg1);

//    void on_Support_Top_Radius_doubleSpinBox_valueChanged(double arg1);

//    void on_Support_Mid_Radius_doubleSpinBox_valueChanged(double arg1);

//    void on_Support_Bottom_Length_doubleSpinBox_valueChanged(double arg1);

//    void on_Support_Bottom_Radius_doubleSpinBox_valueChanged(double arg1);

    void on_checkBoxBase_toggled(bool checked);


    void on_pushButtonAutoSupport_clicked();

    void on_toolButtonAdvanced_clicked();

    void on_pushButtonSave_clicked();

    void on_Support_Base_Coverage_horizontalSlider_valueChanged(int value);

    void on_doubleSpinBoxDensity_editingFinished();

private:
    Ui::SupportParameter *ui;

    MainWindow *pMain;
    PSupportSettings *m_pSettings;
    bool bShowAdvanced;
};

#endif // SUPPORTPARAMETER_H

