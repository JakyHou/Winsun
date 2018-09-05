#ifndef DIALOG_H
#define DIALOG_H
/*Dan
  ��ҳ����ʾ�趨,������ӡ������,��ӡ��x,y,z����,���ؾ���
*/
#include <QDialog>

#include "mainwindow.h"

class MainWindow;

namespace Ui {
class PrintSettingDialog;
}

class PrintSettingDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PrintSettingDialog(MainWindow *main,QWidget *parent = 0);
    ~PrintSettingDialog();
    void closeEvent(QCloseEvent *);
    void UpdateExtentsUI();

//    void showEvent(QShowEvent *);
    
signals:
    void setPrinter(int);
    void setMaterial(int);
    void setThickness(int);
    void setDlg(int);

private slots:
    void on_pushButtonOK_clicked();

    void on_toolButtonMore_clicked();

public slots:
    void on_printercombo_currentIndexChanged(int index);

    void showIt();

//    void OnSetThickness(int);
private:
    Ui::PrintSettingDialog *ui;
    MainWindow *pMain;

    bool bShowMore;
};

#endif // DIALOG_H
