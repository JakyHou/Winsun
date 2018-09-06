#ifndef POSITIONWIDGET_H
#define POSITIONWIDGET_H
/*Dan
  视图模型移动操作
*/
#include <QWidget>
#include "mainwindow.h"
class MainWindow;
class B9ModelInstance;

namespace Ui {
class PositionWidget;
}

class PositionWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit PositionWidget(MainWindow *main,QWidget *parent = 0);
    ~PositionWidget();
    void UpdateInterface();

    void UpdateByLanguage();
private slots:
    void PushTranslations();
    
private:
    Ui::PositionWidget *ui;
    MainWindow *pMain;
    QString language;
};

#endif // POSITIONWIDGET_H
