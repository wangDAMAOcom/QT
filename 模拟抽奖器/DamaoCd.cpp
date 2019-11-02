#ifdef _WIN32
#include "DamaoCd.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

std::string DamaoCd::exeLocation(char seperator /*= '\\'*/)
{
	//�õ�exe�ļ����ڵ�����·��
	char buf[512] = { 0 };
	GetModuleFileNameA(NULL, buf, 512);
	//�滻�ָ����win��׼�ָ����"\\"
	std::string filePath = buf;
	if (seperator != '\\'){
		for (int i = 0; i < filePath.length(); i++)
		{
			if (filePath[i] == '\\'){
				filePath[i] = seperator;
			}
		}
	}
	//ȥ���ļ����ƣ��õ�һ����Ŀ¼
	int pos = filePath.rfind(seperator);//rfind�Ǵ�������ʼ�ҵ�һ������Ҫ����ַ�
	std::string cd = filePath.substr(0, pos + 1);
	return cd;
}

void DamaoCd::cd(const std::string &targetDir)
{
	SetCurrentDirectoryA(targetDir.c_str());
}

void DamaoCd::cd()
{
	std::string where = exeLocation();
	cd(where);
}
#endif


