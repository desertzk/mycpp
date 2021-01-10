#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void disundisQQ()
{
	HWND win;//指针，返回窗口的编号
	win = FindWindowA("TXGuiFoundation", "QQ");//寻找QQ
	if (win == NULL)
	{
		printf("can't find");

	}
	else
	{
		while (1)
		{
			ShowWindow(win,SW_HIDE);
			Sleep(1000);
			ShowWindow(win, SW_SHOW);
			Sleep(1000);
		}
	}
}

void moveQQ()
{
	HWND win;//指针，返回窗口的编号
	win = FindWindowA("TXGuiFoundation", "QQ");//寻找QQ
	if (win == NULL)
	{
		printf("can't find");

	}
	else
	{
		for (int x = 0; x < 1500; x+= 10)
		{
			SetWindowPos(win, NULL, x, 0, 300, 400, 1);
			Sleep(30);
		}

		{
			int y = 0;
			while (y <= 800)
			{
				SetWindowPos(win, NULL, 1500, y, 300, 400, 1);
				Sleep(30);
				y += 10;
			}
		}

		{
			int x = 1500;
			do
			{
				Sleep(30);
				x -= 10;
				SetWindowPos(win, NULL, x, 800, 300, 400, 1);
			} while (x);
		}

		{
			int y = 800;
			HEHE:if (y)
			{
					 Sleep(30);
					 y -= 10;
					 SetWindowPos(win, NULL, 0, y, 300, 400, 1);
					 goto HEHE;
			}
		}


		{
			move(win, 0);
		}

		
		
	}
}

move(HWND win,int x)
{
	Sleep(30);
	SetWindowPos(win, NULL, x, x*9/16, 300, 400, 1);
	if (x > 1600)
		return;
	printf("%d", x);
	move(win, x + 10);
	
	

		
}

void main(){
	//disundisQQ();
	while (1)
	moveQQ();
	system("pause");
}