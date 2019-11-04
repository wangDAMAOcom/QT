#ifndef CIRCLEWIDGET_H
#define CIRCLEWIDGET_H
#include <QFrame>

class CircleWidget : public QFrame
{
    Q_OBJECT
public:
    CircleWidget(QWidget *parent);
    virtual void paintEvent(QPaintEvent *event);
};

#endif // CIRCLEWIDGET_H
