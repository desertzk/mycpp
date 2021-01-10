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

void main11(){
	mainw();
	FILE *fp = fopen("abc.txt", "r");
	if (fp == NULL)
	{
		printf("error is %s\n", strerror(errno));
	}
	else
	{
		struct person man;
		printf("%d\n", sizeof(man));
		memset(&man, 0, sizeof(man));

		
		while (fread(&man, sizeof(struct person), 1, fp))
		{
			printf("id:%d", man.id);
			printf("name:%s", man.name);
			printf("gender:%d", man.gender);
			printf("age:%d", man.age);
		}

		fclose(fp);
	}

	system("pause");
}