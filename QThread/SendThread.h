#ifndef SENDTHREAD_H
#define SENDTHREAD_H
#include <QThread>


class SendThread : public QThread
{
public:
    SendThread();
	~SendThread() = default;
	//创建与销毁线程
	int Create(const char *fileName);
	void Destroy();
	//获取传输状态，如果等于100代表已经完成
	int GetProgress();
signals:
	void sigProgress(int);
private:
	//线程入口函数，需要重写实现自己的内容
	void run();
private:
	char m_filepath[128];
	int m_filesize; // 文件的总字节数 
	int m_bytesread; // 读取并处理了多少字节
	int m_status; // 任务的状态
};

#endif // SENDTHREAD_H
