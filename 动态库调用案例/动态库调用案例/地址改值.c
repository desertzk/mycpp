#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"socketclientdll.h"

void main111(){
	int ret = 0;
	void *handle = NULL;
	ret = cltSocketInit(&handle);
	if (ret != 1){
		printf("error");
	}
	char *buf = "sdfafdsadf";
	int len = strlen(buf);
	int re = cltSocketSend(handle, buf, len);
	//int size = 100;
	int size = 0;
	char bufre[100] = { 0 };
	
	int count = cltSocketRev(handle, bufre, &size);

	printf("%s", bufre);
	printf("\n%d", size);
	system("pause");
}

void main()
{
	extern int  LogLevel[5];
	ITCAST_LOG(__FILE__,__LINE__, LogLevel[0], 0, "fdsaf");//前两个实参是c语言预定义宏定义的表示当前文件当前行
}