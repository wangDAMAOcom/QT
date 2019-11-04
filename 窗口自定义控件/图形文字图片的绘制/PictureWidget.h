#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H
#include <QFrame>

class PictureWidget : public QFrame
{
    Q_OBJECT
public:
    PictureWidget(QWidget *parent);
private:
    virtual void paintEvent (QPaintEvent *event);
private:
    QPixmap m_picture; //
};

#endif // PICTUREWIDGET_H
