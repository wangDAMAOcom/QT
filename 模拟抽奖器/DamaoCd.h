#ifndef DAMAOCD_H
#define DAMAOCD_H
#include <string>

//用于设置当前进程的"当前目录"，限于windows，今后应跟进linux版本

class DamaoCd
{
public:
	//得到exe文件所在的目录
	static std::string exeLocation(char seperator = '\\');
	//切换到目标位置
	static void cd(const std::string &targetDir);
	//切换到exe所在的位置
	static void cd();
};

#endif // DAMAOCD_H
