#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"detours.h"
#pragma comment(lib,"detours.lib")

//BOOL
//WINAPI
//CreateProcessW(
//_In_opt_ LPCWSTR lpApplicationName, //可执行模块名
//_Inout_opt_ LPWSTR lpCommandLine,   //命令行字符串
//_In_opt_ LPSECURITY_ATTRIBUTES lpProcessAttributes,  //进程的安全属性
//_In_opt_ LPSECURITY_ATTRIBUTES lpThreadAttributes,   //线程的安全属性
//_In_ BOOL bInheritHandles,                           //句柄继承标致
//_In_ DWORD dwCreationFlags,                          //创建标致
//_In_opt_ LPVOID lpEnvironment,                       //指向新的环境块的指针
//_In_opt_ LPCWSTR lpCurrentDirectory,                 //指向当前目录名的指针
//_In_ LPSTARTUPINFOW lpStartupInfo,                   //指向启动信息结构的指针
//_Out_ LPPROCESS_INFORMATION lpProcessInformation     //指向进程信息结构的指针
//);

//保留函数指针地址
static BOOL
(WINAPI *OLDCreateProcessW)(
LPCWSTR lpApplicationName, //可执行模块名
LPWSTR lpCommandLine,   //命令行字符串
LPSECURITY_ATTRIBUTES lpProcessAttributes,  //进程的安全属性
LPSECURITY_ATTRIBUTES lpThreadAttributes,   //线程的安全属性
BOOL bInheritHandles,                           //句柄继承标致
DWORD dwCreationFlags,                          //创建标致
LPVOID lpEnvironment,                       //指向新的环境块的指针
LPCWSTR lpCurrentDirectory,                 //指向当前目录名的指针
LPSTARTUPINFOW lpStartupInfo,                   //指向启动信息结构的指针
LPPROCESS_INFORMATION lpProcessInformation     //指向进程信息结构的指针
) = CreateProcessW;


BOOL *NEWCreateProcessW(
	LPCWSTR lpApplicationName, //可执行模块名
	LPWSTR lpCommandLine,   //命令行字符串
	LPSECURITY_ATTRIBUTES lpProcessAttributes,  //进程的安全属性
	LPSECURITY_ATTRIBUTES lpThreadAttributes,   //线程的安全属性
	BOOL bInheritHandles,                           //句柄继承标致
	DWORD dwCreationFlags,                          //创建标致
	LPVOID lpEnvironment,                       //指向新的环境块的指针
	LPCWSTR lpCurrentDirectory,                 //指向当前目录名的指针
	LPSTARTUPINFOW lpStartupInfo,                   //指向启动信息结构的指针
	LPPROCESS_INFORMATION lpProcessInformation)
{
	MessageBoxA(0, "lock", "die........", 0);
	return 0;
}

void Hook()
{
	DetourRestoreAfterWith();//恢复原来的状态
	DetourTransactionBegin();//拦截开始
	DetourUpdateThread(GetCurrentThread());//刷新当前线程
	DetourAttach((void **)&OLDCreateProcessW, NEWCreateProcessW);
	DetourTransactionCommit();

}

void UnHook()
{
	DetourRestoreAfterWith();//恢复原来的状态

	DetourUpdateThread(GetCurrentThread());//刷新当前线程
	DetourDetach((void **)&OLDCreateProcessW, NEWCreateProcessW);
	DetourTransactionCommit();
}

void main1(){
	ShellExecuteA(0, "open", "calc", 0, 0, 1);
	STARTUPINFO si = { sizeof(si) };//启动信息
	PROCESS_INFORMATION pi;//保存了进程的信息
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1;//1表示显示创建的进程的窗口
	wchar_t cmd[] = L"c:/program files/internet explorer/iexplore.exe";
	CreateProcessW(NULL, cmd, NULL, NULL, 0, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	
}

_declspec(dllexport) void go()
{
	MessageBoxA(0, "in", "in", 0);
	Hook();
	//system("tasklist&pause");
	Sleep(1000 * 60);
	UnHook();
}