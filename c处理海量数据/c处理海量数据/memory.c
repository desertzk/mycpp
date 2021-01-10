#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

static char path[100]="D:\\大数据资料\\大数据相关数据\\1E~001.txt";
static char **pp = NULL;
int getcolum()
{
	int i = 0;
	FILE *pf = fopen(path, "r");
	if (pf == NULL)
	{
		return -1;
	}
	else
	{
		while (!feof(pf))
		{
			char str[50] = { 0 };
			fgets(str, 50, pf);
			i++;

		}
		
	}
	fclose(pf);
	return i;
}

int getwigth()
{
	int maxlen = 0;
	FILE *pf = fopen(path, "r");
	if (pf == NULL)
	{
		return -1;
	}
	else
	{
		while (!feof(pf))
		{
			char str[1024] = { 0 };
			fgets(str, 1024, pf);
			//i++;
			int length = strlen(str);
			if (maxlen < length)
			{
				maxlen = length;
			}

		}
		
	}
	fclose(pf);
	return maxlen;
}

void init(int col)
{
	pp = (char **)malloc(sizeof(char *)*col);
	memset(pp, 0, sizeof(char*)*col);
	FILE *pf = fopen(path, "r");
	if (pf == NULL)
	{
		return -1;
	}
	for (int i = 0; i < col; i++)
	{
		char str[128] = { 0 };
		fgets(str, 50, pf);
		int length = strlen(str);
		pp[i] = calloc(strlen(strlen(str) + 1));
		
		if (pp[i] == NULL)
		{
			return;
		}
		strcpy(pp[i], str);
	}
	fclose(pf);
}

void search(char *str,int col)
{
	for (int i = 0; i < col; i++)
	{
		if (pp[i] == NULL)
			return;
		char *p = strstr(pp[i], str);
		if (p != NULL)
		{
			printf("%s\n", p);
		}
	}
}

void main()
{
	int col = getcolum();
	printf("%d\n", col);
	init(col);
	//printf("%d\n", getwigth());
	while (1)
	{
		char str[1024] = { 0 };
		scanf("%s", str);
	}
	getchar();
}
