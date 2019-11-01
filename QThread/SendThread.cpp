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
	//开始运行线程（运行run函数）
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
	//获取文件大小
	fseek(fp, 0, SEEK_END);
	m_filesize = ftell(fp);
	//读取完文件大小后回到文件起始位置
	fseek(fp, 0, SEEK_SET);
	//开始模拟发送文件
	char buf[1024];
	int part = 0;
	while (1){
		int n = fread(buf, 1, 1024, fp);
		if (n <= 0){
			break;
		}
		m_bytesread += n;
		//每个一段时间，sleep一次
		part += n;
		if (part > 1024 * 32){
			QThread::msleep(50);//假装在传送
			part = 0;
		}
	}
	fclose(fp);
	m_status = 1;
	qDebug() << "Complete ..............";
}

