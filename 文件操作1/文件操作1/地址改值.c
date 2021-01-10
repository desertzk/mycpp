#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
struct person
{
	int id;
	char name[16];
	int age;
	int gender;
};

void mainw(){
	FILE *fp = fopen("abc.txt", "a");
	if (fp == NULL)
	{
		printf("error is %s\n", strerror(errno));
	}else
	{
		struct person man[10];
		printf("%d\n", sizeof(man));
		memset(&man, 0, sizeof(man));

		man[0].id = 0;
		strcpy(man[0].name, "omygod");
		man[0].age = 20;
		man[0].gender = 1;

		man[1].id = 1;
		strcpy(man[1].name, "om1234");
		man[1].age = 21;
		man[1].gender = 1;

		fwrite(&man, sizeof(struct person), 2, fp);
		fclose(fp);
	}

	system("pause");
}