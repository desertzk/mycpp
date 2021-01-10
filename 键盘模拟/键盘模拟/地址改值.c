#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void openqq(){
	ShellExecuteA(0, "open", "F:\\QQ\\QQProtect\\Bin\\QQProtect.exe",0,0,1);
}

void chat()
{
	Sleep(1000);
	while (1)
	{

		keybd_event('H', 0, 0, 0);
		keybd_event('H', 0, 2, 0);
		keybd_event('E', 0, 0, 0);
		keybd_event('E', 0, 2, 0);
		keybd_event('L', 0, 0, 0);
		keybd_event('L', 0, 2, 0);/**/
		keybd_event('Z', 0, 0, 0);
		keybd_event('Z', 0, 2, 0);
		Sleep(500);
		keybd_event('H', 0, 0, 0);
		keybd_event('H', 0, 2, 0);
		keybd_event('U', 0, 0, 0);
		keybd_event('U', 0, 2, 0);
		keybd_event('A', 0, 0, 0);
		keybd_event('A', 0, 2, 0);/**/
		keybd_event(13, 0, 0, 0);//enter
		keybd_event(13, 0, KEYEVENTF_KEYUP, 0);
	}
}

void closeqq()
{
	system("taskkill /f /im QQ.exe");
}

void show()
{
	HWND win = FindWindowA("TXGuiFoundation","QQ");
	if (win != NULL)
	{
		ShowWindow(win, SW_SHOW);
	}
}


void hide(){
	HWND win = FindWindowA("TXGuiFoundation", "QQ");
	if (win != NULL)
	{
		ShowWindow(win, SW_HIDE);
	}
}

void up(){
	HWND win = FindWindowA("TXGuiFoundation", "QQ");
	if (win != NULL)
	{
		RECT rectwindow;//区域
		GetWindowRect(win, &rectwindow);//获取区域
		SetWindowPos(win, NULL, rectwindow.left, rectwindow.top+100, 300, 300, 1);
	}
}



void main(){
	//openqq();
	//Sleep(5000);
	//up();
	//Sleep(1000);
	//up();
	//Sleep(1000);
	//up();
	////show();
	//Sleep(5000);
	//hide();

	chat();

	//closeqq();
	
	system("pause");
}