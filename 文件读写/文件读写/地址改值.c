#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
2 ��дһ��ҵ������ʵ�ְ��ж�ȡ�ļ��������ݰ��յ������ڴ�ģ�ʹ�����ݴ�����������ͨ����������������
����ԭ��������������ѡ����һ
Ҫ��1�����Լ�����ѡ��һ���ӿڣ�����������ʵ�ֹ��ܣ�70��
Ҫ��2����д����������30��
Ҫ��3���Լ���д�ڴ��ͷź���
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

	//��һ�������
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
	//�ڶ��������
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