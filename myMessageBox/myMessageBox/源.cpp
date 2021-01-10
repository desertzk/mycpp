#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdarg.h>
#include<tchar.h>
#include<windows.h>

using namespace std;

int MessageBoxPrintf(TCHAR *szCaption, TCHAR * szFormat, ...)
{
	TCHAR szbuf[1024] = {0};
	va_list pArgList;
	va_start(pArgList,szFormat);
	_vsntprintf(szbuf, sizeof(szbuf) / sizeof(TCHAR), szFormat, pArgList);
	va_end(pArgList);
	return MessageBox(NULL, szbuf, szCaption, MB_OK);
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstane, PSTR szCmdLine, int iCmdShow)
{
	int x = 12,y=100,z=200;
	int cxScreen = GetSystemMetrics(SM_CXSCREEN);
	int cyScreen = GetSystemMetrics(SM_CYSCREEN);
	MessageBoxPrintf(TEXT("title"),TEXT("Hello %d,%d,%d"),x,y,z);
	return 0;
}