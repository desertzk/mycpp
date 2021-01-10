#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *path = "D:\\大数据资料\\大数据相关数据\\kaifang.txt";
char *respath = "E:\\result.txt";

//int getfilesize(char *path)
//{
//	FILE *pf = file_open(path);
//	fseek(pf, 0, SEEK_END);
//	int num = ftell(pf);//文件开头到当前位置有多少字节
//	fclose(pf);
//	return num;
//}
void read()
{
	char findstr[20] = { 0 };
	scanf("%s", findstr);
	FILE *pfw;
	FILE *pfr;
	pfr = fopen(path, "r");//读取文件
	pfw = fopen(respath, "w");//写入结果
	if (pfr == NULL || pfw == NULL)
	{
		printf("文件操作失败");
		return;
	}
	else
	{

		fseek(pfr, 0, SEEK_END);//移动到文件尾部
		int filesize = ftell(pfr);//获取当前文件指针到文件开头多少字节
		printf("%d字节,%fK,%fM\n", filesize, filesize / 1024.0, filesize / 1024.0 / 1024.0);
		rewind(pfr);//移动到文件开头



		while (!feof(pfr))
		{
			char str[256] = { 0 };
			fgets(str, 256, pfr);//读取一行
			char *p = strstr(str, findstr);
			if (p != NULL)
			{
				printf("%s", str);//打印
				fputs(str, pfw);//写入
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
		printf("文件操作失败");
		return;
	}
	else{
		
		fseek(pfr, 0, SEEK_END);
		int filesize = ftell(pfr);//文件开头到当前位置有多少字节
		printf("%d字节，  %fK,%fM", filesize, filesize / 1024.0, filesize / 1024.0 / 1024.0);
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