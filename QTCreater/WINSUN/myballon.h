#ifndef MYBALLON_H
#define MYBALLON_H
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPushButton>


class MyBallonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyBallonWidget(QWidget *parent = 0);
    ~MyBallonWidget();

public:
    void  paintEvent(QPaintEvent *e);


};
#endif // MYBALLON_H
