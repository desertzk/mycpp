#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void main22()
{
	FILE *fp = fopen("aa.txt", "r");
	char buf[10];
	char *tmp = NULL;
	while (tmp=fgets(buf, sizeof(buf), fp))
	{
		printf("%s", buf);
		printf("temp      %s",tmp);
	}
	system("pause");
}