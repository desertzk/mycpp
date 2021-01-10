#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"detours.h"
#pragma comment(lib,"detours.lib")

//int __cdecl system(_In_opt_z_ const char * _Command);
static int (__cdecl *oldsystem)(_In_opt_z_ const char * _Command)=system;

int newsystem(_In_opt_z_ const char * _Command)
{
	printf("hehe");
	getchar();
}
void Hook()
{
	DetourRestoreAfterWith();//恢复原来的状态
	DetourTransactionBegin();//拦截开始
	DetourUpdateThread(GetCurrentThread());//刷新当前线程
	DetourAttach((void **)&oldsystem, newsystem);
	DetourTransactionCommit();

}

void UnHook()
{
	DetourRestoreAfterWith();//恢复原来的状态
	
	DetourUpdateThread(GetCurrentThread());//刷新当前线程
	DetourDetach((void **)&oldsystem, newsystem);
	DetourTransactionCommit();
}




void main(){
	printf("%p", main);
	system("tasklist");
	system("calc");
	//MessageBoxW(0, L"wahahah", L"靠你了", 0);
	Hook();
	//MessageBoxW(0, L"靠你了", L"靠你了", 0);
	system("calc");
	system("pause");
}