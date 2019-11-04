#ifndef WORDWIDGET_H
#define WORDWIDGET_H
#include <QFrame>

class WordWidget : public QFrame
{
    Q_OBJECT
public:
    WordWidget(QWidget *parent);
private:
    virtual void paintEvent(QPaintEvent *event);
private:
    void simple(); // 简单测试
    void wrap();   // 换行显示
    void dynamic(); // 动态测试宽度
};

#endif // WORDWIDGET_H
