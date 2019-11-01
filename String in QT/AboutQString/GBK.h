
#ifndef _QT_GBK_H
#define _QT_GBK_H

#include <QString>
#include <QTextCodec>
#include <string>
//using std::string;

class GBK
{
public:
	//QTextCode用于手工转换编码(QString内部调用此类)  QString(Unicode) -> std::string (GBK)
	static std::string FromUnicode(const QString &qstr)
	{
		QTextCodec *pCodec = QTextCodec::codecForName("gb2312");
		if (pCodec == nullptr) return "";
		/*如果pCodec为NULL, 则说明你的Qt安装位置不是默认位置*/
		QByteArray arr = pCodec->fromUnicode(qstr);
		std::string cstr = arr.data();
		return cstr;
	}
	//std::string(GBK) -> QString(UniCode)
	static QString ToUnicode(const std::string& cstr){
		QTextCodec *pCodec = QTextCodec::codecForName("gb2312");
		if (pCodec == nullptr) return "";
		QString str = pCodec->toUnicode(cstr.c_str(), cstr.length());
		return str;
	}
	/* 取两个较短的函数名 : w: wide-char  a: ansi */
	// QString(Unicode) -> std::string (GBK)
	static std::string w2a(const QString& qstr)
	{
		return FromUnicode(qstr);
	}

	// std::string (GBK) -> QString(Unicode)
	static QString a2w(const std::string& cstr)
	{
		return ToUnicode(cstr);
	}
};
#endif

