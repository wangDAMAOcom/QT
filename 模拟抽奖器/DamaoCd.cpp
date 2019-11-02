#ifdef _WIN32
#include "DamaoCd.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

std::string DamaoCd::exeLocation(char seperator /*= '\\'*/)
{
	//得到exe文件所在的完整路径
	char buf[512] = { 0 };
	GetModuleFileNameA(NULL, buf, 512);
	//替换分割符，win标准分割符是"\\"
	std::string filePath = buf;
	if (seperator != '\\'){
		for (int i = 0; i < filePath.length(); i++)
		{
			if (filePath[i] == '\\'){
				filePath[i] = seperator;
			}
		}
	}
	//去除文件名称，得到一个纯目录
	int pos = filePath.rfind(seperator);//rfind是从右向左开始找第一个符合要求而字符
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


