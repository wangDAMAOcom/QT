#ifndef _SOURCE_H
#define _SOURCE_H
//��ȡxml���ص绰����
#include "DamaoTinyXml.h"
class Source{
public:
	Source();
	int load();
public:
	std::vector<std::string> numbers;
};

#endif // !_SOURCE_H
