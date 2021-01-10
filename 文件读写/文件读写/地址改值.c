#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
2 编写一个业务函数，实现按行读取文件。把内容按照第三种内存模型打包数据传出，把行数通过函数参数传出。
函数原型有两个，任意选择其一
要求1：请自己任意选择一个接口（函数），并实现功能；70分
要求2：编写测试用例。30分
要求3：自己编写内存释放函数
*/
#define LineMaxLen 1024
int readFile(const char *pfilename/*in*/, char ***p/*out*/, int *lineNum/*out*/){
	int rv = 0,tmpline=0;
	FILE *fp = NULL;
	char lineBuf[LineMaxLen];
	char* pCur =NULL, *pBegin=NULL,*pEnd=NULL;
	char **tmpFile = NULL;
	//char*** pService = p;

	if (pfilename == NULL || lineNum == NULL){
		rv = -1;
		printf("param err");
		goto End;
	}
	fp= fopen(pfilename, "r");
	if (fp == NULL){
		rv = -2;
		goto End;
	}

	//第一遍读行数
	while (!feof(fp)){
		memset(lineBuf, 0, sizeof(lineBuf));
		pCur = fgets(lineBuf, LineMaxLen, fp);
		if (pCur == NULL){
			continue;
		}
		else{

			tmpline++;
		}
	}

	tmpFile = (char **)malloc((tmpline + 1)*sizeof(char *));
	if (tmpFile == NULL){
		goto End;
	}
	//第二遍读内容
	tmpline = 0;
	fseek(fp, 0L, SEEK_SET);
	while (!feof(fp)){
		memset(lineBuf, 0, sizeof(lineBuf));
		pCur = fgets(lineBuf, LineMaxLen, fp);
		if (pCur == NULL){
			continue;
		}
		else{
			int tmplen = strlen(lineBuf);
			tmpFile[tmpline] = (char *)malloc((tmplen+1)*sizeof(char));
			if (tmpFile[tmpline] == NULL){
				goto End;
			}
			strcpy(tmpFile[tmpline], lineBuf);
			tmpline++;
		}
	}
	*lineNum = tmpline;
	*p = tmpFile;

End:
	if (fp != NULL){
		fclose(fp);
	}

	return rv;
}

void freeReadFile(char ***tmpFile,int line){
	char **pserv = *tmpFile;
	for (int i = 0; i < line; i++){
		free(pserv[i]);
	}
	free(pserv);
	pserv = NULL;
	*tmpFile = pserv;
}

void main(){
	char *filename = "14.cpp";
	char **p = NULL;
	int line = 0;
	readFile(filename, &p, &line);
	if (p == NULL)
		return;
	for (int i = 0; i < line; i++){
		printf("%s", *(p + i));
	}
	freeReadFile(&p, line);
	system("pause");
}