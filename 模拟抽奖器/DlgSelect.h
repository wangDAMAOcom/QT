#ifndef DLGSELECT_H
#define DLGSELECT_H

#include <QDialog>
#include "ui_DlgSelect.h"

class DlgSelect : public QDialog{
	Q_OBJECT
public:
	DlgSelect(QStringList *numbers, QWidget *parent = 0);
	~DlgSelect();
	//定时器
	virtual void timerEvent(QTimerEvent *);
	//窗口被关系
	virtual void closeEvent(QCloseEvent *);
private slots:
	int onSelectNext();
private:
	int saveResults();
private:
	Ui::DlgSelect *ui;
	QStringList *m_numbers{};
	QIcon m_iconStart, m_iconStop;
	int  m_timerId;
	bool m_working; // 正在抽奖
	int  m_now; // 当前显示

	int* m_flags; // 不重复抽取
	int  m_total;
	int  m_selected; // 已经被抽中的个数 <= m_total
};

#endif // DLGSELECT_H