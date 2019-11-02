#ifndef _SOURCE_H
#define _SOURCE_H
//读取xml加载电话号码
#include "DamaoTinyXml.h"
class Source{
public:
	Source();
	int load();
public:
	std::vector<std::string> numbers;
};

#endif // !_SOURCE_H
