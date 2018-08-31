#ifndef CYCLEPRINTSETTING_H
#define CYCLEPRINTSETTING_H

#include <QWidget>
#include <QDialog>
#include "terminal.h"
/*Dan
  设置打印机的上升速度,下降速度,停留时间等
*/

class PCycleSettings;

namespace Ui {
class CyclePrintSetting;
}

class CyclePrintSetting : public QDialog
{
    Q_OBJECT
    
public:
    explicit CyclePrintSetting(PCycleSettings *pSettings, QWidget *parent = 0);
    ~CyclePrintSetting();
    
private slots:
    void on_pushButtonRestoreDefaults_clicked();

    void on_buttonBox_clicked();

    void on_pushButtonOK_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CyclePrintSetting *ui;
    PCycleSettings* m_pSettings;
    void updateDialog();
    void stuffSettings();
};

#endif // CYCLEPRINTSETTING_H
