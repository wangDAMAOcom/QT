#include "PictureWidget.h"
#include <QPainter>

PictureWidget::PictureWidget(QWidget *parent)
    :QFrame(parent)
{
    m_picture.load(":/AboutWidget/Resources/logo.jpg");
}

// 目标矩形按比例填充到源矩形, 返回实际的target位置
inline QRect scale(QRect source, QRect target)
{
    int target_w = target.width();
    int target_h = target.height();

    int image_w = source.width();
    int image_h = source.height();

    if(image_w <= 0) image_w = 1;
    if(image_h <= 0) image_h = 1;
    //调整比例
    int scaled_w = target_w;
    int scaled_h = image_h * target_w / image_w;
    if(scaled_h > target_h)
    {
        scaled_h = target_h;
        scaled_w = target_h * image_w / image_h;
    }

    // 坐在中心
    int x = (target_w - scaled_w)/2;
    int y = (target_h - scaled_h)/2;
    return QRect(x, y, scaled_w, scaled_h);
}

void PictureWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int width = this->width();
    int height = this->height();
    //QRect target (0, 0, width/2, height/2); // 目标矩形
    //QRect target (width/2, height/2, width/2, height/2); // 目标矩形
    QRect target (0,0,width,height); // 目标矩形
    //
    int img_width = m_picture.width();
    int img_height = m_picture.height();
    QRect source(0, 0, img_width, img_height); // 源矩形，也就是图片
    if(0)
    {
        /* 简单画图 */
        painter.drawPixmap(target, m_picture, source);
    }
    else
    {
        /* 锁定长宽比,是图片保持原本比例 */
        QRect scaled_target = scale(source, target);
        painter.drawPixmap(scaled_target, m_picture, source);
    }
}



