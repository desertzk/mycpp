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
	DetourRestoreAfterWith();//�ָ�ԭ����״̬
	DetourTransactionBegin();//���ؿ�ʼ
	DetourUpdateThread(GetCurrentThread());//ˢ�µ�ǰ�߳�
	DetourAttach((void **)&oldsystem, newsystem);
	DetourTransactionCommit();

}

void UnHook()
{
	DetourRestoreAfterWith();//�ָ�ԭ����״̬
	
	DetourUpdateThread(GetCurrentThread());//ˢ�µ�ǰ�߳�
	DetourDetach((void **)&oldsystem, newsystem);
	DetourTransactionCommit();
}




void main(){
	printf("%p", main);
	system("tasklist");
	system("calc");
	//MessageBoxW(0, L"wahahah", L"������", 0);
	Hook();
	//MessageBoxW(0, L"������", L"������", 0);
	system("calc");
	system("pause");
}