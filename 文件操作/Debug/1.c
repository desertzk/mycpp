#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//��д�����
//�����ַ���д�ļ�
void main01()
{
	int i = 0;
	FILE *fp = NULL;
	char a[] = "abcdefgddddd";
	//char *filename = "c:\\1.txt";
	//linux�º�win��ͨ��
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