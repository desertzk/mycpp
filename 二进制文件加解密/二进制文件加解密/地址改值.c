#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int getfilesize(char *path)
{
	FILE *pf = fopen(path, "r");
	if (pf == NULL)
	{
		return -1;
	}
	else{
		fseek(pf, 0, SEEK_END);
		int length = ftell(pf);
	}
}


void encryption(char *oldpath, char *newpath)
{
	FILE *pfr, *pfw;
	pfr = fopen(oldpath,"rb");
	pfw = fopen(newpath, "wb");
	if (pfr == NULL || pfw == NULL)
	{
		fclose(pfr);
		fclose(pfw);
		return;
	}
	else{
		int length = getfilesize(oldpath);
		char *p = (char *)malloc(length*sizeof(char));
		fread(p, sizeof(char), length, pfr);
		for (int i = 0; i < length; i++)
		{
			p[i] ^= 'A';
		}

		fwrite(p, sizeof(char), length, pfw);
		fclose(pfr);
		fclose(pfw);
	}
}

void main(){
	char *oldpath = "D:\\Program Files (x86)\\Tencent\\QQGAME\\QQGame.exe";
	char *enpath = "D:\\Program Files (x86)\\Tencent\\QQGAME\\QQGameA.exe";
	char *depath = "D:\\Program Files (x86)\\Tencent\\QQGAME\\QQGameB.exe";
	encryption(oldpath, enpath);
	encryption(enpath, depath);
	system("pause");
}