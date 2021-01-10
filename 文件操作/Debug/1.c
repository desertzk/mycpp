#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//读写概念建立
//按照字符读写文件
void main01()
{
	int i = 0;
	FILE *fp = NULL;
	char a[] = "abcdefgddddd";
	//char *filename = "c:\\1.txt";
	//linux下和win下通用
	char *filename = "c:/1.txt";
	fp = fopen(filename, "a+");
	if (fp == NULL)
	{
		printf("func fopen() err\n");
		return ;
	}
	// int fputc(int ch,FILE *stream);
	for (i=0; i<strlen(a); i++)
	{
		fputc(a[i], fp);
	}
	fclose(fp);	
}
void main02()
{
	int i = 0;
	FILE *fp = NULL;
	char *filename = "c:/1.txt";
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("func fopen() err\n");
		return ;
	}

	while(!feof(fp))
	{
		char tmpc = fgetc(fp);
		printf("%c", tmpc);
	}
	
	fclose(fp);	
}

void main()
{
	//main01();
	main02();
	system("pause");
}