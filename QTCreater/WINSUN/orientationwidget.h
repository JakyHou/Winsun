#ifndef ORIENTATIONWIDGET_H
#define ORIENTATIONWIDGET_H
/*Dan
  视图模型旋转操作
*/
#include <QWidget>
#include "mainwindow.h"
class MainWindow;
class B9ModelInstance;


namespace Ui {
class OrientationWidget;
}

class OrientationWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit OrientationWidget(MainWindow *main,QWidget *parent = 0);
    ~OrientationWidget();
    void UpdateInterface();
    
private slots:
    void PushTranslations();

    void on_pushButtonDrop_To_Floor_clicked();

private:
    Ui::OrientationWidget *ui;
    MainWindow *pMain;
};

#endif // ORIENTATIONWIDGET_H
