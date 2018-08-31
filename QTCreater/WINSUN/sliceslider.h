#ifndef SLICESLIDER_H
#define SLICESLIDER_H
/*Dan
  切片显示中的滚动条操作
*/
#include <QWidget>

namespace Ui {
class SliceSlider;
}

class SliceSlider : public QWidget
{
    Q_OBJECT
    
public:
    explicit SliceSlider(QWidget *parent = 0);
    ~SliceSlider();
    
signals:
    void curNumOfLayers(int);

public slots:
    void setNumOfLayers(int);

private slots:
    void on_curNumOfLayersSlider_valueChanged(int value);

    void on_spinBoxCurNumOfLayers_valueChanged(int arg1);

    void on_lineEditCurNumOfLayers_returnPressed();

private:
    Ui::SliceSlider *ui;
};

#endif // SLICESLIDER_H
