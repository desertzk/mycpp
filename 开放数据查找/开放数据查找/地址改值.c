#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *path = "D:\\����������\\�������������\\kaifang.txt";
char *respath = "E:\\result.txt";

//int getfilesize(char *path)
//{
//	FILE *pf = file_open(path);
//	fseek(pf, 0, SEEK_END);
//	int num = ftell(pf);//�ļ���ͷ����ǰλ���ж����ֽ�
//	fclose(pf);
//	return num;
//}
void read()
{
	char findstr[20] = { 0 };
	scanf("%s", findstr);
	FILE *pfw;
	FILE *pfr;
	pfr = fopen(path, "r");//��ȡ�ļ�
	pfw = fopen(respath, "w");//д����
	if (pfr == NULL || pfw == NULL)
	{
		printf("�ļ�����ʧ��");
		return;
	}
	else
	{

		fseek(pfr, 0, SEEK_END);//�ƶ����ļ�β��
		int filesize = ftell(pfr);//��ȡ��ǰ�ļ�ָ�뵽�ļ���ͷ�����ֽ�
		printf("%d�ֽ�,%fK,%fM\n", filesize, filesize / 1024.0, filesize / 1024.0 / 1024.0);
		rewind(pfr);//�ƶ����ļ���ͷ



		while (!feof(pfr))
		{
			char str[256] = { 0 };
			fgets(str, 256, pfr);//��ȡһ��
			char *p = strstr(str, findstr);
			if (p != NULL)
			{
				printf("%s", str);//��ӡ
				fputs(str, pfw);//д��
			}



		}








		fclose(pfr);
		fclose(pfw);


	}
	system(respath);
	system("pause");
}
void main(){
	//read();
	char findstr[20] = {0};
	scanf("%s", findstr);
	FILE *pfw;
	FILE *pfr;
	pfr = fopen(path, "r");
	pfw = fopen(respath, "w");
	if (pfr == NULL || pfw == NULL)
	{
		printf("�ļ�����ʧ��");
		return;
	}
	else{
		
		fseek(pfr, 0, SEEK_END);
		int filesize = ftell(pfr);//�ļ���ͷ����ǰλ���ж����ֽ�
		printf("%d�ֽڣ�  %fK,%fM", filesize, filesize / 1024.0, filesize / 1024.0 / 1024.0);
		rewind(pfr);

		while (!feof(pfr))
		{
			char str[256] = { 0 };
			fgets(str, 256, pfr);
			char *p = strstr(str, findstr);
			if (p != NULL){
				printf("%s\n", str);//
				fputs(str, pfw);
			}
		}
	}

	fclose(pfr);
	fclose(pfw);
	system("pause");
}