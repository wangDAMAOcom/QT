#include "mainwindow.h"
#include <QApplication>
#include "DamaoCd.h"

int main(int argc, char *argv[])
{
	DamaoCd::cd();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
