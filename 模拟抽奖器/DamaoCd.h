#ifndef DAMAOCD_H
#define DAMAOCD_H
#include <string>

//�������õ�ǰ���̵�"��ǰĿ¼"������windows�����Ӧ����linux�汾

class DamaoCd
{
public:
	//�õ�exe�ļ����ڵ�Ŀ¼
	static std::string exeLocation(char seperator = '\\');
	//�л���Ŀ��λ��
	static void cd(const std::string &targetDir);
	//�л���exe���ڵ�λ��
	static void cd();
};

#endif // DAMAOCD_H
