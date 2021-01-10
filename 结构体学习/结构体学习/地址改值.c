#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define T_NUM 3

struct Student{
	char name[64];
	int age;
	char *introduce;
	char **teachers_name;
};

typedef struct _Teacher
{
	char name[64];
	int age;
	char class[32];
}Teacher;


int printArray(struct Student *sArray, int count){
	printf("开始打印。。。。。。");
	for (int i = 0; i < count; i++)
	{
		printf("%s", sArray[i].name);
		printf("\n%d",sArray[i].age); 
		printf("\n%s", sArray[i].introduce);
		for (int j = 0; j < T_NUM; j++){
			printf("\n%s", (sArray[i].teachers_name)[j]);
		}
	}

}

int sortArray(struct Student *sArray, int count){
	
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++){
			if ((sArray + i)->age<(sArray + j)->age){
				int temp = (sArray + j)->age;
				(sArray + j)->age = (sArray + i)->age;
				(sArray + i)->age = temp;
			}
		}
		
	}
	printf("排序完成\n");
	return 0;
}
struct Student * createSArray(int count)
{
	int i = 0;
	struct Student *p1 = malloc(count*sizeof(struct Student));
	if (p1 == NULL)
	{
		return NULL;
	}
	for (i = 0; i < count; i++){
		memset(&p1[i], 0, sizeof(struct Student));
		//memset(p1+i, 0, sizeof(struct Student));   same with lastrow
		(p1 + i)->introduce = (char *)malloc(128 * sizeof(char));
		memset((p1 + i)->introduce, 0, 128 * sizeof(char));

		 //(p1 + i)->teachers_name= (char **)malloc(sizeof(char **));

		(p1 + i)->teachers_name = (char **)malloc(T_NUM*sizeof(char *));
		for (int j = 0; j < T_NUM; j++)//teachers name  memory allocation
		{
			((p1 + i)->teachers_name)[j] = (char *)malloc(128 * sizeof(char));
			//*((*(p1 + i)->teachers_name) + j) = (char *)malloc(128 * sizeof(char));
			memset(((p1 + i)->teachers_name)[j], 0, 128 * sizeof(char));
		}

		//(p1 + i)->teachers_name = p2;
	}

	
	return p1;
}

void freeSArray(struct Student* sArray,int num){
	for (int i = 0; i < num; i++){
		if (sArray[i].introduce != NULL){
			free(sArray[i].introduce);
			sArray[i].introduce = NULL;
		}
		
	}


	if (sArray != NULL){
		free(sArray);
		sArray = NULL;//垃圾代码只改变了形参和实参无关系 
	}
}


void main(){
	struct Student* sArray = createSArray(2);
	//Teacher zz;

	int i = 0;
	for (i = 0; i < 2; i++)
	{
		//*(sArray[i].name) = "dfasdf";
		*(sArray + i)->name = "fsafd";
		printf("\nplease entry age");
		//scanf("%d", &sArray[i].age);
		scanf("%d", &sArray[i].age);
		printf("\nplease entry introduce");
		scanf("%s", sArray[i].introduce);
		for (int j = 0; j < T_NUM; j++){
			printf("\nplease entry teachersname");
			scanf("%s", *(sArray[i].teachers_name+j));
			//scanf("%s", (sArray[i].teachers_name)[j]);
		}
		
	}

	printArray(sArray,2);
	sortArray(sArray, 2);
	printArray(sArray, 2);


	freeSArray(sArray,2);
	system("pause");
}

//void main(){
//	char buf[64];
//	*buf = "dasfdfa";
//}