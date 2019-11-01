#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QTextCodec>
#include "GBK.h"
//QString是一个Unicode16编码的类
//同时封装了一个QChar类代表宽字符
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(OnBtnTest()));
    //会出现“乱码”的现象因为cpp是GBK编码，不能直接给QString
   // QString str = "你好中国";
    //解决方法
    QString str = QString::fromLocal8Bit("你好中国");
    ui->lineEdit->setText(str);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::OnBtnTest(){
     //会出现“乱码”的现象因为cpp是GBK编码，不能直接给QString
    // QString str = "你好中国";
     //解决方法
     QString str = QString::fromLocal8Bit("你好中国");
     ui->lineEdit->setText(str);
     //QString->GBK
     QString text = ui->lineEdit->text();
     QByteArray bytes = text.toLocal8Bit();
     const char *gbk = bytes.data();
	 //本地编码:Local8bits,中文windows本地编码是GBK
	 //如果是linux的话，那么本地编码可能就是UTF-8,如果是互相数据传输，那么就不会很保险
	 auto size = sizeof(gbk);

	 //UTf-8->QString : c风格字符串->QString
	 char utf8[] = { 0xE4, 0xBD, 0xA0, 0xE5, 0xA5, 0xBD, 0 };
	 QString str2 = QString::fromUtf8(utf8);//把utf8转换成QString来显示
	 //QString -> UTF-8 : QString->C风格字符串
	 QString text_2 = ui->lineEdit->text();
	 QByteArray bytes_2 = text.toUtf8();
	 const char *utf8_result = bytes.data();
	 int size_2 = bytes.size();
	 //GBK头文件中的函数测试
	 QString str_gbk = GBK::ToUnicode("不会出现乱码的");
	 ui->lineEdit->setText(str_gbk);

	 std::string cstr_gbk = GBK::FromUnicode(ui->lineEdit->text());//得到的是GBK编码的字符串
     return ;
 }
