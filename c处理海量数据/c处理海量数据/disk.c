#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

static char path[100] = "D:\\大数据资料\\大数据相关数据\\1E~001.txt";

void showlist(char *pstr)
{
	FILE *pf = fopen(path, "r");
	if (pf == NULL)
	{
		printf("fopen error");
		return;
	}
	else{
		
		while (!feof(pf))
		{
			char tempstr[1024] = { 0 };
			fgets(tempstr, 1024, pf);
			int length = strlen(tempstr);
			if (length > 1024)
			{
				return;
			}
			char *p = strstr(tempstr, pstr);
			if (p != NULL)
			{
				printf("%s\n", tempstr);
			}
		}
	}
	fclose(pf);
		
}

void main2()
{
	char search_str[100] = { 0 };
	printf("you want?\n");
	scanf("%s", search_str);
	
	showlist(search_str);
	system("pause");
}