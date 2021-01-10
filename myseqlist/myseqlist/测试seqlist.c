#include<stdlib.h>
#include"seqlist.h"

typedef struct _Teacher{
	char *name;
	int age;
}Teacher;

void main(){
	SeqList * list=SeqList_Create(10);

	Teacher t1, t2;
	//t3
	struct _Teacher t3;

	t1.age = 10;
	t2.age = 20;
	t3.age = 30;

	int ret = SeqList_Insert(list, (SeqListNode*)&t1, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t2, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t3, 0);

	//Ñ­»·±éÀú
	for (int i = 0; i<SeqList_Length(list); i++)
	{
		Teacher *tmp = (Teacher *)SeqList_Get(list, i);
		printf("age:%d \n", tmp->age);
	}

	//Ñ­»·É¾³ı
	int len = SeqList_Length(list);
	for (int i = 0; i<len; i++)
	{
		Teacher *tmp = (Teacher *)SeqList_Delete(list, 0);
		printf("age:%d \n", tmp->age);
	}

	SeqList_Destroy(list);
	system("pause");
}