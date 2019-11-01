#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timeId = startTimer(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event){
    if (event->timerId() == m_timeId){
        QString time = QTime::currentTime().toString("HH::mm::ss");
        ui->label->setText(time);
    }

    return ;
}
