#ifndef DLGSELECT_H
#define DLGSELECT_H

#include <QDialog>
#include "ui_DlgSelect.h"

class DlgSelect : public QDialog{
	Q_OBJECT
public:
	DlgSelect(QStringList *numbers, QWidget *parent = 0);
	~DlgSelect();
	//��ʱ��
	virtual void timerEvent(QTimerEvent *);
	//���ڱ���ϵ
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
	bool m_working; // ���ڳ齱
	int  m_now; // ��ǰ��ʾ

	int* m_flags; // ���ظ���ȡ
	int  m_total;
	int  m_selected; // �Ѿ������еĸ��� <= m_total
};

#endif // DLGSELECT_H