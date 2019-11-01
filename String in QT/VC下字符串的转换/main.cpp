#include <WinSock2.h>
#include <windows.h>
#include <stdio.h>
//GBK -> UTF-16
int test1(){
	//char text_gbk[] = {0xcd, 0xf5, 0xb4, 0xf3, 0xc3, 0xab, 0x00};  //����д��ͨ��д�����ʹ���һ��GBK�����ʽ�ַ���
	char text_gbk[] = "����ë"; //�ַ������泣��,ȡ����cpp�ļ�������ַ�����VC�¾���GBK�ַ���
	wchar_t text_utf16[256] = { 0 };
	int n = MultiByteToWideChar(CP_ACP, 0,
		text_gbk, strlen(text_gbk),
		text_utf16, 256);
	//ת����Ľ��wchar_t text_utf16[256] = {0x738b, 0x5927, 0x6dbd, 0x0000......}
	printf("��� �� %d �����ַ�\n", n);
	return 0;
}
//GBK -> UTF-16 ->UTF8
int test2(){
	char text_gbk[] = "����ë"; //�ַ������泣��,ȡ����cpp�ļ�������ַ�����VC�¾���GBK�ַ���
	//���ɣ��Ƚ�GBKת����UTF-16
	wchar_t text_utf16[256] = { 0 };
	int n1 = MultiByteToWideChar(CP_ACP, 0,
		text_gbk, strlen(text_gbk),
		text_utf16, 256);
	printf("��� �� %d �����ַ�\n", n1);
	//UTF-16 ->UTF8
	char text_utf8[256];
	int n2 = WideCharToMultiByte(CP_UTF8, 0, text_utf16, n1, text_utf8, 256, NULL, 0);
	printf("��� �� %d ���ֽ�\n", n2);
	return 0;
}

int main(){
	test1();
	test2();
	return 0;
}