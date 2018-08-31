#ifndef SUPPORTSETTING_H
#define SUPPORTSETTING_H
/*Dan
  未使用的 支撑参数设置页面
*/
#include <QWidget>
#include <QDialog>
#include "mainwindow.h"

class PSupportSettings;

namespace Ui {
class SupportSetting;
}

class SupportSetting : public QDialog
{
    Q_OBJECT
    
public:
    explicit SupportSetting(PSupportSettings *pSettings, QWidget *parent = 0);
    ~SupportSetting();
    
private slots:
    void on_pushButtonRestoreDefaults_clicked();

    void on_pushButtonOK_clicked();

    void on_Support_Top_Penetration_horizontalSlider_valueChanged(int value);

    void on_Support_Top_AngleFactor_horizontalSlider_valueChanged(int value);

    void on_Support_Bottom_Penetration_horizontalSlider_valueChanged(int value);

    void on_Support_Bottom_AngleFactor_horizontalSlider_valueChanged(int value);

private:
    Ui::SupportSetting *ui;
    PSupportSettings* m_pSettings;
    void updateDialog();
    void stuffSettings();
};

#endif // SUPPORTSETTING_H
