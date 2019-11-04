#include "MainWindow.h"
#include <QApplication>
#include "MyWidget.h"
#include "WordWidget.h"
#include "PictureWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();
    //MyWidget是几何图片等绘制
//    MyWidget win(nullptr);
//    win.show();
    //WordWidget是关于文字的例子
//    WordWidget win_word(nullptr);
//    win_word.resize(400,300);
//    win_word.move(200,200);
//    win_word.show();
    //PictureWidget是显示图片的例子
    PictureWidget win_pic(nullptr);
    win_pic.resize(300, 600);
    win_pic.move(200, 200);
    win_pic.show();
    return a.exec();
}
