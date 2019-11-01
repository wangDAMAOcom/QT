#include "ProgressDialg.h"
#include "ui_ProgressDialg.h"
#include "GBK.h"
#include "SendThread.h"
#include "GBK.h"

ProgressDialg::ProgressDialg(QString filePath, QWidget *parent):
   m_filePath(filePath), QDialog(parent),
    ui(new Ui::ProgressDialg)
{
    ui->setupUi(this);
	setWindowTitle(GBK::ToUnicode("���ͽ���"));

	
	//��·��ת����GBK��ʽ
	std::string path = GBK::FromUnicode(m_filePath);
	//�����߳�
	m_thread = new SendThread();
	connect(m_thread, SIGNAL((int)), this, SLOT(receiveProgress(int)));
	m_thread->Create(path.c_str());

	//����һ����ʱ����ʱ���
	m_timerId = startTimer(500);
}

ProgressDialg::~ProgressDialg()
{
    delete ui;
}

void ProgressDialg::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == m_timerId){
		int progress = m_thread->GetProgress();
		ui->progressBar->setValue(progress);
		if (progress >= 100){
			m_thread->Destroy();
			delete m_thread;
			//�ļ�����������رն�ʱ��
			killTimer(m_timerId);
			this->accept();
		}
	}
}

void ProgressDialg::receiveProgress(int)
{

}
