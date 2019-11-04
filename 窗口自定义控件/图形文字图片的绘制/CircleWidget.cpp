#include "CircleWidget.h"
#include <QPainter>
CircleWidget::CircleWidget(QWidget *parent)
    :QFrame(parent)
{

}

 void CircleWidget::paintEvent(QPaintEvent *event){
     QPainter painter(this);
     int width = this->width();
     int height = this->height();
     painter.setBrush(QBrush(QColor(0x00, 0xFF, 0x00)));
     //画一个绿色的圆
     painter.drawEllipse(0, 0, width, height);
     painter.drawText(0, 0, width, height,
         Qt::AlignCenter | Qt::AlignVCenter,
         QStringLiteral("你好"));
 }
