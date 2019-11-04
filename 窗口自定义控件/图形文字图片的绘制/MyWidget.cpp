#include "MyWidget.h"
#include <QPainter>
#include <QTimerEvent>

MyWidget::MyWidget(QWidget *parent):
     QFrame(parent)
{
    m_timerId = startTimer(500);
}

void MyWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    int width = this->width();
    int height = this->height();
    //QBrush控制填充的颜色
    painter.setBrush(QBrush(QColor(0x00, 0x00, 0x00)));
    //一个黑色的背景
    painter.drawRect(0, 0, width, height);
    //QPen负责线条的绘制
    QColor green(0XFF, 0XFF, 0x00);
    QPen pen(green);
    pen.setWidth(3);
    pen.setStyle(Qt::PenStyle::DashDotDotLine);
    painter.setPen(pen);
    //控制了如何填充
    QBrush brush(QColor(0xFF, 0, 0));
    painter.setBrush(brush);
    //通过画两个矩形，以及黑色的背景，可以看出后画的会覆盖先画的
    painter.drawRect(10, 10, 160,50);
    painter.drawRect(40, 20, 160, 50);
    //动画效果，频闪较低情况下
    painter.setPen(Qt::NoPen);
    if (m_times == 0){
        QBrush ani_brush(QColor(0x00, 0xff, 0));
        painter.setBrush(ani_brush);
        m_times++;
    }else{
        QBrush ani_brush(QColor(0x88, 0x88, 0x88));
        painter.setBrush(ani_brush);
        m_times = 0;
    }
    painter.drawEllipse(width / 2, height / 2, 40, 40);
}

void MyWidget::timerEvent(QTimerEvent *event){
    if (event->timerId() == m_timerId){
        update();//重绘，会执行paintEvent，但不是立即执行，所以实际间隔会大于定时器间隔的
    }
}
