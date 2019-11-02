#include "DlgSelect.h"
#include <QTimerEvent>
#include "GBK.h"
#include <QStringList>
#include "QMessageBox.h"
#include <QCloseEvent>

DlgSelect::DlgSelect(QStringList *numbers, QWidget *parent /*= 0*/)
	:QDialog(parent), 
	ui(new Ui::DlgSelect)
{
	ui->setupUi(this);
	m_numbers = numbers;
	m_iconStart = QIcon(":/Resouces/Resources/play.png");
	m_iconStop = QIcon(":/Resouces/Resources/stop.png");

	m_selected = 0;
	m_total = numbers->length();
	m_flags = new int[m_total];
	for (int i = 0; i < m_total; i++)
		m_flags[i] = 0;

	// 事件
	connect(ui->m_btnStart, SIGNAL(clicked()), this, SLOT(onSelectNext()));
}

DlgSelect::~DlgSelect()
{
	delete ui;
	delete[] m_flags;
}

void DlgSelect::timerEvent(QTimerEvent *event)
{
	// 翻到下一个
	int next = m_now;
	while (1)
	{
		// 回头
		next++;
		if (next >= m_total) next = 0;
		// 确保不重复
		if (!m_flags[next])
			break;
	}
	m_now = next;
	// 显示	
	ui->m_ctlDisplay->setText(m_numbers->at(m_now));
}

void DlgSelect::closeEvent(QCloseEvent *event)
{
	// 如果保存失败，则不关闭此对话框
	if (saveResults() < 0)
	{
		event->ignore();
		return;
	}
	QDialog::closeEvent(event);
}

int DlgSelect::onSelectNext()
{
	// 都抽中了
	if (m_selected >= m_total) return 0;

	if (!m_working)
	{
		// 启动抽奖
		m_now = 0;
		m_timerId = startTimer(100);
		ui->m_btnStart->setIcon(m_iconStop);
		m_working = true;
	}
	else
	{
		// 停止
		killTimer(m_timerId);
		m_working = false;
		ui->m_btnStart->setIcon(m_iconStart);
		// 
		m_flags[m_now] = 1;
		QString number = m_numbers->at(m_now);
		ui->m_lstResult->addItem(new QListWidgetItem(number));
	}
	return 0;
}

int DlgSelect::saveResults()
{
	// 将结果保存到文件, append方式
	FILE* fp = fopen("results.txt", "ab");
	if (!fp)
	{
		QMessageBox::critical(this,
			GBK::ToUnicode("严重错误"), "无法保存结果!");
		return -1;
	}
	fprintf(fp, "----------- result ---------\n");
	// 从结果列表里取得所有条目，保存到文件里
	for (int i = 0; i < ui->m_lstResult->count(); i++)
	{
		QListWidgetItem* item = ui->m_lstResult->item(i);
		QString qValue = item->text();
		std::string number = GBK::FromUnicode(qValue);
		fprintf(fp, "%s\n", number.c_str());
	}
	fclose(fp);
	return 0;
}

