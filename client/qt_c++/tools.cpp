#include "tools.h"
#ifdef _WIN32
#include <windows.h> 
#else
#include <iconv.h>
#endif
using namespace std;

std::string UTF8ToGBK(const char * data)
{
	string re = "";
	//1 UFT8 转为unicode win utf16
#ifdef _WIN32
	//1.1 统计转换后字节数
	int len = MultiByteToWideChar(CP_UTF8,	//转换的格式
		0,			//默认的转换方式
		data,		//输入的字节
		-1,			//输入的字符串大小 -1 找\0
		0,//输出
		0//输出的空间大小
	);
	if (len <= 0)
		return re;
	wstring udata;
	udata.resize(len);
	MultiByteToWideChar(CP_UTF8, 0, data, -1, (wchar_t*)udata.data(), len);

	//2 unicode 转GBK
	len = WideCharToMultiByte(CP_ACP, 0, (wchar_t*)udata.data(), -1, 0, 0,
		0,	//失败默认替代字符
		0	//是否使用默认替代 
	);
	if (len <= 0)
		return re;
	re.resize(len);
	WideCharToMultiByte(CP_ACP, 0, (wchar_t*)udata.data(), -1, (char*)re.data(), len, 0, 0);
#else
	re.resize(1024);
	int inlen = strlen(data);
	Convert((char*)"utf-8", (char*)"gbk", (char*)data, inlen, (char*)re.data(), re.size());
	int outlen = strlen(re.data());
	re.resize(outlen);
#endif
	return re;
}

std::string GBKToUTF8(const char * data)
{
	string re = "";
#ifdef _WIN32	
	//GBK转unicode
	//1.1 统计转换后字节数
	int len = MultiByteToWideChar(CP_ACP,	//转换的格式
		0,			//默认的转换方式
		data,		//输入的字节
		-1,			//输入的字符串大小 -1 找\0
		0,//输出
		0//输出的空间大小
	);
	if (len <= 0)
		return re;
	wstring udata;
	udata.resize(len);
	MultiByteToWideChar(CP_ACP, 0, data, -1, (wchar_t*)udata.data(), len);

	//2 unicode 转utf-8
	len = WideCharToMultiByte(CP_UTF8, 0, (wchar_t*)udata.data(), -1, 0, 0,
		0,	//失败默认替代字符
		0	//是否使用默认替代 
	);
	if (len <= 0)
		return re;
	re.resize(len);
	WideCharToMultiByte(CP_UTF8, 0, (wchar_t*)udata.data(), -1, (char*)re.data(), len, 0, 0);
#else
	re.resize(1024);
	int inlen = strlen(data);
	Convert((char*)"gbk", (char*)"utf-8", (char*)data, inlen, (char*)re.data(), re.size());
	int outlen = strlen(re.data());
	re.resize(outlen);
#endif
	return re;
}
