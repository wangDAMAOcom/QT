#include <WinSock2.h>
#include <windows.h>
#include <stdio.h>
//GBK -> UTF-16
int test1(){
	//char text_gbk[] = {0xcd, 0xf5, 0xb4, 0xf3, 0xc3, 0xab, 0x00};  //这种写法通用写法，就代表一个GBK编码格式字符串
	char text_gbk[] = "王大毛"; //字符串字面常量,取决于cpp文件本身的字符集，VC下就是GBK字符集
	wchar_t text_utf16[256] = { 0 };
	int n = MultiByteToWideChar(CP_ACP, 0,
		text_gbk, strlen(text_gbk),
		text_utf16, 256);
	//转换后的结果wchar_t text_utf16[256] = {0x738b, 0x5927, 0x6dbd, 0x0000......}
	printf("结果 ： %d 个宽字符\n", n);
	return 0;
}
//GBK -> UTF-16 ->UTF8
int test2(){
	char text_gbk[] = "王大毛"; //字符串字面常量,取决于cpp文件本身的字符集，VC下就是GBK字符集
	//过渡，先将GBK转换成UTF-16
	wchar_t text_utf16[256] = { 0 };
	int n1 = MultiByteToWideChar(CP_ACP, 0,
		text_gbk, strlen(text_gbk),
		text_utf16, 256);
	printf("结果 ： %d 个宽字符\n", n1);
	//UTF-16 ->UTF8
	char text_utf8[256];
	int n2 = WideCharToMultiByte(CP_UTF8, 0, text_utf16, n1, text_utf8, 256, NULL, 0);
	printf("结果 ： %d 个字节\n", n2);
	return 0;
}

int main(){
	test1();
	test2();
	return 0;
}