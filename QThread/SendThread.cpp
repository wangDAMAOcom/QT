#include "SendThread.h"
#include <QDebug>

SendThread::SendThread()
{

}

int SendThread::Create(const char *fileName)
{
	strcpy(m_filepath, fileName);
	m_filesize = 0;
	m_bytesread = 0;
	//��ʼ�����̣߳�����run������
	this->start();
	return 0;
}

void SendThread::Destroy()
{
	wait();
}

int SendThread::GetProgress()
{
	if (m_filesize < 0) return 0;
	return m_bytesread * 100 / m_filesize;
}

void SendThread::run()
{
	FILE *fp = fopen(m_filepath, "rb");
	if (!fp){
		m_status = -1;
		return;
	}
	//��ȡ�ļ���С
	fseek(fp, 0, SEEK_END);
	m_filesize = ftell(fp);
	//��ȡ���ļ���С��ص��ļ���ʼλ��
	fseek(fp, 0, SEEK_SET);
	//��ʼģ�ⷢ���ļ�
	char buf[1024];
	int part = 0;
	while (1){
		int n = fread(buf, 1, 1024, fp);
		if (n <= 0){
			break;
		}
		m_bytesread += n;
		//ÿ��һ��ʱ�䣬sleepһ��
		part += n;
		if (part > 1024 * 32){
			QThread::msleep(50);//��װ�ڴ���
			part = 0;
		}
	}
	fclose(fp);
	m_status = 1;
	qDebug() << "Complete ..............";
}

