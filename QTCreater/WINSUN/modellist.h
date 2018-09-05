#ifndef MODELLIST_H
#define MODELLIST_H
/*Dan
  ui文件未使用
*/
#include <QWidget>
#include "mainwindow.h"
class MainWindow;
class B9ModelInstance;

namespace Ui {
class ModelList;
}

class ModelList : public QWidget
{
    Q_OBJECT
    
public:
    explicit ModelList(MainWindow *main,QWidget *parent = 0);
    ~ModelList();

    void UpdateInterface();
    void AddTagToModelList(QListWidgetItem* item);
    std::vector<B9ModelInstance*> GetSelectedInstances();
    QList<QListWidgetItem*> GetSelectedItem();


    double getThickness();
    
private slots:
    void PushTranslations();
    void RefreshSelectionsFromList();

private:
    Ui::ModelList *ui;

    MainWindow *pMain;
};

#endif // MODELLIST_H
