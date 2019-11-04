#include "WordWidget.h"
#include <QPen>
#include <QPainter>
#include <QFont>
#include "GBK.h"
#include <QRect>
#include <QTextOption>

WordWidget::WordWidget(QWidget *parent)
    :QFrame(parent)
{

}

void WordWidget::paintEvent(QPaintEvent *event){
    //simple();
    //wrap();
    dynamic();
}

void WordWidget::simple(){
    QPainter painter(this);
    int width = this->width();
    int heigth = this->height();
    //设置字的颜色
    painter.setPen(QColor(0xFF, 0, 0));
    //设置字体
    QFont font("Times",  16, QFont::Bold, true);
    painter.setFont(font);
    //显示文本
    painter.drawText(0, 0, width, heigth,
                     Qt::AlignHCenter | Qt::AlignVCenter,
                     GBK::ToUnicode("汉堡你好呀"));
}

void WordWidget::wrap(){
    QPainter painter(this);
    int width = this->width();
    int heigth = this->height();
    //设置字的颜色
    painter.setPen(QColor(0xFF, 0, 0));
    //设置字体
    QFont font("Times",  16, QFont::Bold, true);
    painter.setFont(font);
    QString longtext = GBK::ToUnicode("中国的陆地面积约960万平方千米，东部和南部大陆海岸线1.8万多千米");
    QRect rect(0, 0, width, heigth);
    //设置文字显示格式
    QTextOption option;
    //会根据显示窗体大小自动换行
    option.setWrapMode(QTextOption::WrapAnywhere);
    painter.drawText(rect, longtext, option);
}

void WordWidget::dynamic(){
    QPainter painter(this);
    int width = this->width();
    int height = this->height();
    QFont font("Times",  16, QFont::Normal, false);
    painter.setFont(font);
    // 动态显示
    QString longtext = GBK::ToUnicode("陆地面积约960万平方千米，东部和南部大陆海岸线1.8万多千米");
    //QFontMetrics可以计算字体的高度和宽度
    QFontMetrics metric(font);
    QRect boundingRect = metric.boundingRect(0, 0,width, height,
        Qt::AlignHCenter | Qt::AlignVCenter,
        longtext);
    qDebug("width: %d , height: %d (%d,%d)\n",
        boundingRect.width(), boundingRect.height(),
        width, height);
    //如果窗口比文字显示区域宽，可以完全显示所有文字
    if(boundingRect.width() <= width)
    {
        painter.drawText(0, 0,width, height,   // 指定位置
            Qt::AlignHCenter | Qt::AlignVCenter, // 指定对齐等属性
            longtext
            );
    }
    //如果窗口比文字需要全部显示窄的话
    else
    {
        // 逐步缩短尝试
        for(int i = longtext.length() - 1; i >= 0 ; i--)
        {
            QString substr = longtext.left(i);
            QString showtext = substr + "...";
            QRect bounding = metric.boundingRect(0, 0,width, height,
                Qt::AlignHCenter | Qt::AlignVCenter,
                showtext);
            if(bounding.width() < width)
            {
                painter.drawText(0, 0,width, height,   // 指定位置
                    Qt::AlignHCenter | Qt::AlignVCenter, // 指定对齐等属性
                    showtext
                    );
                break;
            }
        }
    }
}
