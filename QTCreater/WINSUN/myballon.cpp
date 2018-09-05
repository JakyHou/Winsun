#include "myballon.h"
#include "qpainter.h"
#include <QPen>
#include <QDebug>

MyBallonWidget::MyBallonWidget(QWidget *parent) :
    QWidget(parent)
{

}

MyBallonWidget::~MyBallonWidget()
{

}

void MyBallonWidget::paintEvent(QPaintEvent *e)
{
    QRectF rectangle1(-5, -5, this->width()+10, this->height()+10);
    QRectF rectangle2(10, 0, this->width()-10, this->height());

//    QRectF rectangle(50.0, 10.0, this->width()-20-40, this->height()-20);
//    QPointF points[3] = {
//       QPointF(40, 33),
//       QPointF(51, 28),
//       QPointF(51, 38),
//   };

        QPainter painter(this);
        painter.setRenderHint( QPainter::Antialiasing, true );
        painter.setBrush(QBrush(QColor(233, 233 ,233,255)));//240,240,240
        painter.drawRoundedRect(rectangle1,-10,-10);//绘制背景色
        painter.setBrush(QBrush(QColor(255,255,255)));
        painter.drawRoundedRect(rectangle2,10,10);//绘制气泡框的矩形部分


        QPointF points[3] = {
           QPointF(0, 23),
           QPointF(11, 18),
           QPointF(11, 28),
       };


       QPen pen;
       pen.setColor(QColor(255,255,255));
       painter.setPen(pen);
       painter.drawPolygon(points, 3);//绘制气泡框的三角形部分

       QPen pen1;
       pen.setColor(Qt::black);
       painter.setPen(pen1);
       painter.drawLine(points[0],points[1]);
       painter.drawLine(points[0],points[2]);

}
