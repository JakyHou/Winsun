#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include "mainwindow.h"
/*Dan
  ģ����������ǰ����鿴
*/
class MainWindow;

namespace Ui {
class viewWidget;
}

class viewWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit viewWidget(MainWindow *main,QWidget *parent = 0);
    ~viewWidget();
    
    void UpdateByLanguage();
private:
    Ui::viewWidget *ui;
    QString language;
    MainWindow *pMain;
};

#endif // VIEWWIDGET_H
