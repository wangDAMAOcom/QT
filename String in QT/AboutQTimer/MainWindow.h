#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void timerEvent(QTimerEvent *);

private:
    Ui::MainWindow *ui;
    int m_timeId;
};

#endif // MAINWINDOW_H
