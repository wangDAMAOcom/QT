#ifndef _QT_GBK_H
#define _QT_GBK_H

#include <QString>
#include <QTextCodec>
#include <string>
//using std::string;

class GBK
{
public:
	//QTextCode�����ֹ�ת������(QString�ڲ����ô���)  QString(Unicode) -> std::string (GBK)
	static std::string FromUnicode(const QString &qstr)
	{
		QTextCodec *pCodec = QTextCodec::codecForName("gb2312");
		if (pCodec == nullptr) return "";
		/*���pCodecΪNULL, ��˵�����Qt��װλ�ò���Ĭ��λ��*/
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
	/* ȡ�����϶̵ĺ����� : w: wide-char  a: ansi */
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