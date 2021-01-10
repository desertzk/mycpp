#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE * file_open(char *path)
{
	FILE *pf;
	pf = fopen(path, "r");
	if (pf == NULL)
	{
		return -1;
	}
}

int getfilesize(char *path)
{
	FILE *pf = file_open(path);
	fseek(pf, 0, SEEK_END);
	int num = ftell(pf);//�ļ���ͷ����ǰλ���ж����ֽ�
	fclose(pf);
	return num;
}


int getlinenum(char *path)
{
	FILE *pf = file_open(path);
	int i = 0;
	while (!feof(pf))
	{
		char str[275];
		fgets(str, 275, pf);
		i++;//ͳ������
	}
	fclose(pf);
	return i;
}

int mallocforfl(char ***fpl,char *path,int linenum)
{
	
	char ** p = malloc(sizeof(char *)*linenum);
	FILE *pf = file_open(path);
	
	for (int i = 0; i < linenum; i++)
	{
		char str[275] = { 0 };
		fgets(str, 275, pf);
		int strlength = strlen(str) + 1;//��ȡҪ������ַ�������
		char *px = (char *)malloc(sizeof(char)*strlength);//�����ڴ�
		strcpy(px, str);
		px[strlength - 1] = '\0';
		p[i] = px;//*(p+i)
	}

	*fpl = p;
	printf("it's all in memory\n");
	return 0;
}

void findstr(char *search, char **finmem,int linenum)
{
	for (int i = 0; i < linenum; i++)
	{
		char *ptmp = strstr(finmem[i], search);
		if (ptmp != NULL)
		{
			printf("\n%s", finmem[i]);
		}
	}
}

void main(){
	//char *path = "C:\\Users\\admin\\Desktop\\��.txt";
	char *path = "E:\\kaifang.txt";
	int num =getfilesize(path);
	printf("%d�ֽڣ�  %fK,%fM", num, num/1024.0,num/1024.0/1024.0);
	int linenum = getlinenum(path);
	printf("\n��%d��", linenum);
	char **pf = NULL;
	mallocforfl(&pf, path, linenum);
	char searchstr[100] = { 0 };
	scanf("%s", searchstr);
	findstr(searchstr, pf, linenum);

	system("pause");
}