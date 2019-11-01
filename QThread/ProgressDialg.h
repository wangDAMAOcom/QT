#ifndef PROGRESSDIALG_H
#define PROGRESSDIALG_H

#include <QDialog>
class SendThread;
namespace Ui {
class ProgressDialg;
}

class ProgressDialg : public QDialog
{
	Q_OBJECT

public:
	explicit ProgressDialg(QString filePath, QWidget *parent = 0);
	~ProgressDialg();
	virtual void timerEvent(QTimerEvent *);
private slots:
	void receiveProgress(int);
private:
	Ui::ProgressDialg *ui;
	QString m_filePath{};
	SendThread *m_thread{};//负责模拟传送文件的线程
	int m_timerId{};
};

#endif // PROGRESSDIALG_H
