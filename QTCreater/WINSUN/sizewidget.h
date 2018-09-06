#ifndef SIZEWIDGET_H
#define SIZEWIDGET_H
/*Dan
  模型缩放操作
*/
#include <QWidget>
#include "mainwindow.h"
class MainWindow;
class B9ModelInstance;

namespace Ui {
class sizeWidget;
}

class sizeWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit sizeWidget(MainWindow *main,QWidget *parent = 0);
    ~sizeWidget();

    void UpdateInterface();

    void UpdateByLanguage();
private slots:
    void PushTranslations();

    void on_doubleSpinBox_scale_valueChanged(double arg1);

    void on_pushButtonDrop_To_Floor_clicked();

    void on_doubleSpinBox_scale_editingFinished();

private:
    Ui::sizeWidget *ui;
    MainWindow *pMain;
    QString language;
};

#endif // SIZEWIDGET_H

