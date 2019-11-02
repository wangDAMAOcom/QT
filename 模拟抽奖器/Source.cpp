#include "Source.h"

Source::Source()
{

}

int Source::load()
{
	numbers.clear();
	//解析xml
	TiXmlDocument xml_doc;
	if (!xml_doc.LoadFile("numbers.xml")){
		return -1;
	}
	//找到根节点
	TiXmlElement *xml_root = xml_doc.RootElement();
	if (xml_root == nullptr){
		return -1;
	}
	//获取号码列表
	TiXmlElement *xml_parent = xml_root->FirstChildElement("NumberList");
	if (xml_parent){
		TiXmlElement* xml_child = xml_parent->FirstChildElement("Number");
		while (xml_child){
			std::string value = xml_child->GetText();
			numbers.push_back(value);
			xml_child = xml_child->NextSiblingElement("Number");
		}
	}
	return 0;
}
