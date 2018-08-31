#ifndef SLICEDIALOG_H
#define SLICEDIALOG_H
/*Dan
  切片精度设置及保存地址设定
*/
#include <QDialog>

#include "OS_Wrapper_Functions.h"
#include "mainwindow.h"

class MainWindow;
namespace Ui {
class SliceDialog;
}

class SliceDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SliceDialog(MainWindow *main,QWidget *parent = 0);
    ~SliceDialog();
    
private slots:
    void on_BrowseButton_clicked();

    void on_SliceButton_clicked();


private:
    Ui::SliceDialog *ui;
    MainWindow *pMain;
};

#endif // SLICEDIALOG_H

