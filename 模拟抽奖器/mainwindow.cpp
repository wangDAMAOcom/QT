#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DlgSelect.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	// 加载号码列表
	m_source.load();
	for (int i = 0; i < m_source.numbers.size(); i++){
		std::string &number = m_source.numbers[i];
		QListWidgetItem *item = new QListWidgetItem();
		item->setText(number.c_str());
		ui->listNumbers->addItem(item);
	}
	connect(ui->btnEnter, SIGNAL(clicked()), this, SLOT(onEnter()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onEnter()
{
	QStringList numbers;
	for (int i = 0; i < m_source.numbers.size(); i++)
	{
		std::string& value = m_source.numbers[i];
		numbers.append(value.c_str());
	}
	// 进入抽奖界面
	DlgSelect dlg(&numbers, this);
	dlg.exec();
	return; 
}
