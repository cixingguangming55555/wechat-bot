/*---------------------------------------
       馈人玫瑰之手，历久犹有余香
=========================================
说明：微信2.7.1.88内存直接获取好友信息示例
地址：https://github.com/cixingguangming55555/wechat-bot
致谢：感谢在看雪、B站共享好文、好视频的各位大佬
---------------------------------------*/
#include  "pch.h"
#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <list>
#include <stack>
using std::list;
using std::stack;
using std::wstring;
DWORD g_root_node = 0;
DWORD WINAPI read_data(HANDLE process, DWORD address)
{
	DWORD node = 0;
	LPDWORD readByte = NULL;

	BOOL is_read = ::ReadProcessMemory(process, (LPVOID)(address), &node, 4, readByte);
	if (is_read == FALSE)
	{
		return 0;
	}
	return node;
}
DWORD WINAPI GetModuleBaseAddress(DWORD dwPID, const TCHAR szModule[MAX_MODULE_NAME32 + 1])
{
	HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
	MODULEENTRY32 me32;
	DWORD  dwModuleAddress = 0;

	// Take a snapshot of all modules in the specified process.
	hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPID);
	if (hModuleSnap == INVALID_HANDLE_VALUE)
	{
		OutputDebugString(TEXT("CreateToolhelp32Snapshot (of modules)"));
		return(FALSE);
	}

	// Set the size of the structure before using it.
	me32.dwSize = sizeof(MODULEENTRY32);

	// Retrieve information about the first module,
	// and exit if unsuccessful
	if (!Module32First(hModuleSnap, &me32))
	{
		OutputDebugString(TEXT("Module32First"));  // show cause of failure
		CloseHandle(hModuleSnap);           // clean the snapshot object
		return(FALSE);
	}

	// Now walk the module list of the process,
	// and display information about each module
	do
	{
		int iLen = ::lstrcmp(me32.szModule, szModule);
		if (iLen == 0)
		{
			dwModuleAddress = (DWORD)me32.modBaseAddr;
		}

	} while (Module32Next(hModuleSnap, &me32));

	CloseHandle(hModuleSnap);

	if (dwModuleAddress == 0)
	{
		return 0;
	}
	return dwModuleAddress;
}
DWORD WINAPI GetProcessID(const TCHAR szProcessName[MAX_PATH])
{
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	DWORD dwPID = 0;

	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		OutputDebugString(TEXT("GetProcessID:CreateToolhelp32Snapshot failed\r\n"));
		return -1;
	}

	//
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		//__OutputDebugString(_T("GetProcessID:loop is begin\r\n"));

		int iLen = ::lstrcmp(pe32.szExeFile, szProcessName);
		if (iLen == 0)
		{
			//__OutputDebugString(_T("GetProcessID:pe32.th32ProcessID is :%d \r\n"), pe32.th32ProcessID);
			//__OutputDebugString(_T("GetProcessID:pe32.szExeFile is :%s\r\n"), pe32.szExeFile);
			dwPID = pe32.th32ProcessID;
		}
		bMore = ::Process32Next(hProcessSnap, &pe32);
	}

	//
	::CloseHandle(hProcessSnap);
	if (dwPID == 0)
	{
		return 0;
	}
	return dwPID;

}
wstring getstr_from_mem(HANDLE hProcess, DWORD lpBaseAddress, int nSize)
{
	BYTE *tempbuf = new BYTE[nSize * 2]{ 0 };
	DWORD len = 0;
	if (ReadProcessMemory(hProcess, (LPVOID)lpBaseAddress, tempbuf, nSize * 2, &len) == 0)
	{
		return NULL;
	}

	wchar_t *p = new wchar_t[nSize + 1]{ 0 };
	wmemcpy_s(p, nSize, (wchar_t*)tempbuf, nSize);
	wstring result = { 0 };
	result.assign(p);
	if (NULL != p) { delete[] p; p = NULL; }
	if (NULL != tempbuf) { delete[] tempbuf; tempbuf = NULL; }
	return result;
}

wstring getinfo(HANDLE process,DWORD node,DWORD offset) 
{
	DWORD address = node + offset;
	DWORD address_len = address + 0x04;
	DWORD memadd = read_data(process, address);
	DWORD memlen = read_data(process, address_len);
	
	wstring result;
	if (memlen != 0) 
	{
		result = getstr_from_mem(process, memadd, memlen);
	}
	else 
	{
		result = TEXT("");
	}
	
	return result;
}


int index = 0;
list<int> nodelist;
void preorder_node(HANDLE process,DWORD node)
{
	if (node == g_root_node) return;
	for(auto item :nodelist)
	{
		if (item == node) return;
	}

	nodelist.push_back(node);
	index++;
	DWORD node1 = read_data(process, node);
	DWORD node2 = read_data(process, node + 4);
	DWORD node3 = read_data(process, node + 8);
	
	wstring wxid=getinfo(process,node,0x10);
	_wsetlocale(LC_ALL, L"chs");
	wprintf(TEXT("-------------------------------\n"));
	wprintf(TEXT("wxid:\t%s\n"),wxid.c_str());
	wstring nick = getinfo(process, node, 0x8c);
	wprintf(TEXT("nick:\t%s\n"), nick.c_str());
	
	preorder_node(process,node1);
	preorder_node(process,node2);
	preorder_node(process,node3);
}

int main()
{
	DWORD dwid = GetProcessID(TEXT("WeChat.exe"));
	HANDLE h_process = ::OpenProcess(PROCESS_VM_READ, false, dwid);
	if (h_process == NULL) 
	{
		return 0;
	}
	DWORD module_address =GetModuleBaseAddress(dwid, TEXT("WeChatWin.dll"));
	printf("module address:\t0x%X\n", module_address);

	DWORD base_address = module_address + 0x1397A8C;
	DWORD link_point   = read_data(h_process, base_address);
	DWORD header_node = link_point + 0x8c;
	printf("root node:\t0x%X\n", header_node);

	DWORD header = read_data(h_process, header_node);
	printf("header address:\t0x%X\n", header);
	g_root_node = header;
	printf("####################################\n");
	DWORD node1 = read_data(h_process, header);
	DWORD node2 = read_data(h_process, header + 4);
	DWORD node3 = read_data(h_process, header + 8);
	
	printf("node1 address:\t0x%X\n", node1);
	printf("node2 address:\t0x%X\n", node2);
	printf("node3 address:\t0x%X\n", node3);
	
	
	nodelist.push_back(header);
	preorder_node(h_process, node1);

	CloseHandle(h_process);

	system("pause");
	return 0;
}


