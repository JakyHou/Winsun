#ifndef STATUSWIDGET_H
#define STATUSWIDGET_H

#include <QWidget>
#include "mainwindow.h"

class MainWindow;

namespace Ui {
class statusWidget;
}

class statusWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit statusWidget(MainWindow *main,QWidget *parent = 0);
    ~statusWidget();
    void UpdateExtentsUI();
    void setPrintModel(bool isPrint);
    
public slots:
    void setPrinter(int index);
    void setThickness(int index);
    void setThickness(QString s);
    QString getPrinter();
    double getThickness();

private slots:
    void on_thicknesscombo_currentIndexChanged(int index);

    void on_printercombo_currentIndexChanged(int index);

private:
    Ui::statusWidget *ui;
    MainWindow *pMain;
};

#endif // STATUSWIDGET_H
