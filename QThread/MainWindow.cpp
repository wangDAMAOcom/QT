#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include "GBK.h"
#include <ProgressDialg.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnSelect, SIGNAL(clicked()), this, SLOT(OnBtnSelect()));
	connect(ui->btnSend, SIGNAL(clicked()), this, SLOT(OnBtnSend()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnBtnSelect(){
	QString path = QFileDialog::getOpenFileName(this, GBK::ToUnicode("选择文件"));
    QByteArray arr = path.toLocal8Bit();
    const char *c_arr = arr.data();
    if (path.length() < 0) return ;
    ui->lineEdit->setText(GBK::ToUnicode(c_arr));
}

void MainWindow::OnBtnSend()
{
	QString path = ui->lineEdit->text();
	ProgressDialg dlg(path, this);
	dlg.exec();
	return ;
}
