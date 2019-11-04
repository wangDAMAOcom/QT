#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QFrame>

class MyWidget : public QFrame
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent);
    virtual void paintEvent(QPaintEvent *event);
    virtual void timerEvent(QTimerEvent *event);
private:
      int m_timerId;
      int m_times{0};
};

#endif // MYWIDGET_H
