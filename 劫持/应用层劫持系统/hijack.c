#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"detours.h"
#pragma comment(lib,"detours.lib")

//BOOL
//WINAPI
//CreateProcessW(
//_In_opt_ LPCWSTR lpApplicationName, //��ִ��ģ����
//_Inout_opt_ LPWSTR lpCommandLine,   //�������ַ���
//_In_opt_ LPSECURITY_ATTRIBUTES lpProcessAttributes,  //���̵İ�ȫ����
//_In_opt_ LPSECURITY_ATTRIBUTES lpThreadAttributes,   //�̵߳İ�ȫ����
//_In_ BOOL bInheritHandles,                           //����̳б���
//_In_ DWORD dwCreationFlags,                          //��������
//_In_opt_ LPVOID lpEnvironment,                       //ָ���µĻ������ָ��
//_In_opt_ LPCWSTR lpCurrentDirectory,                 //ָ��ǰĿ¼����ָ��
//_In_ LPSTARTUPINFOW lpStartupInfo,                   //ָ��������Ϣ�ṹ��ָ��
//_Out_ LPPROCESS_INFORMATION lpProcessInformation     //ָ�������Ϣ�ṹ��ָ��
//);

//��������ָ���ַ
static BOOL
(WINAPI *OLDCreateProcessW)(
LPCWSTR lpApplicationName, //��ִ��ģ����
LPWSTR lpCommandLine,   //�������ַ���
LPSECURITY_ATTRIBUTES lpProcessAttributes,  //���̵İ�ȫ����
LPSECURITY_ATTRIBUTES lpThreadAttributes,   //�̵߳İ�ȫ����
BOOL bInheritHandles,                           //����̳б���
DWORD dwCreationFlags,                          //��������
LPVOID lpEnvironment,                       //ָ���µĻ������ָ��
LPCWSTR lpCurrentDirectory,                 //ָ��ǰĿ¼����ָ��
LPSTARTUPINFOW lpStartupInfo,                   //ָ��������Ϣ�ṹ��ָ��
LPPROCESS_INFORMATION lpProcessInformation     //ָ�������Ϣ�ṹ��ָ��
) = CreateProcessW;


BOOL *NEWCreateProcessW(
	LPCWSTR lpApplicationName, //��ִ��ģ����
	LPWSTR lpCommandLine,   //�������ַ���
	LPSECURITY_ATTRIBUTES lpProcessAttributes,  //���̵İ�ȫ����
	LPSECURITY_ATTRIBUTES lpThreadAttributes,   //�̵߳İ�ȫ����
	BOOL bInheritHandles,                           //����̳б���
	DWORD dwCreationFlags,                          //��������
	LPVOID lpEnvironment,                       //ָ���µĻ������ָ��
	LPCWSTR lpCurrentDirectory,                 //ָ��ǰĿ¼����ָ��
	LPSTARTUPINFOW lpStartupInfo,                   //ָ��������Ϣ�ṹ��ָ��
	LPPROCESS_INFORMATION lpProcessInformation)
{
	MessageBoxA(0, "lock", "die........", 0);
	return 0;
}

void Hook()
{
	DetourRestoreAfterWith();//�ָ�ԭ����״̬
	DetourTransactionBegin();//���ؿ�ʼ
	DetourUpdateThread(GetCurrentThread());//ˢ�µ�ǰ�߳�
	DetourAttach((void **)&OLDCreateProcessW, NEWCreateProcessW);
	DetourTransactionCommit();

}

void UnHook()
{
	DetourRestoreAfterWith();//�ָ�ԭ����״̬

	DetourUpdateThread(GetCurrentThread());//ˢ�µ�ǰ�߳�
	DetourDetach((void **)&OLDCreateProcessW, NEWCreateProcessW);
	DetourTransactionCommit();
}

void main1(){
	ShellExecuteA(0, "open", "calc", 0, 0, 1);
	STARTUPINFO si = { sizeof(si) };//������Ϣ
	PROCESS_INFORMATION pi;//�����˽��̵���Ϣ
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1;//1��ʾ��ʾ�����Ľ��̵Ĵ���
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