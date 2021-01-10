#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void writefilebychar(){
	//°´ÕÕ×Ö·û¶ÁÐ´ÎÄ¼þ
	FILE *fp = NULL;
	char *filename = "1.c";
	char *a = "fadsfasdgdfgshkuwif";
	fp = fopen(filename, "a+");
	if (fp == NULL){
		printf("func fopen() err");
	}
	for (int i = 0; i < strlen(a); i++){
		fputc(a[i], fp);
	}
	fclose(fp);
}

void readfilebychar(){

	FILE *fp = NULL;
	fp = fopen("1.c", "r");
	if (fp == NULL){
		printf("func fopen() err");
	}
	while (!feof(fp))
	{
		char tmpc = fgetc(fp);
		printf("%c", tmpc);
	}
}

void readfilebyline(){
	char str[1024] = { 0 };
	FILE *fp = NULL;
	fp = fopen("1.c", "r");
	if (fp == NULL){
		printf("func fopen() err");
	}
	while (!feof(fp))
	{
		char *temp = fgets(str, 1024, fp);
		if (temp != NULL){
			printf("%s", temp);
		}
		else{
			printf("fgets error");
		}
			
	}
}

void main(){
	readfilebyline(); 
	system("pause");
}