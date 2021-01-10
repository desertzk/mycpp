#include<stdlib.h>
#include<stdio.h>
#include"linklist.h"

typedef struct _Teacher{
	LinkListNode *node;
	char name[32];
	int age;
}Teacher;

void main(){
	int ret = 0;
	LinkList* list = NULL;
	Teacher t1, t2, t3, t4, t5;
	t1.age = 10;
	t2.age = 20;
	t3.age = 30;
	t4.age = 40;
	t5.age = 50;
	list = LinkList_Create();

	ret = LinkList_Length(list);

	ret = LinkList_Insert(list, (LinkListNode*)&t1, LinkList_Length(list));
	ret = LinkList_Insert(list, (LinkListNode*)&t2, LinkList_Length(list));
	ret = LinkList_Insert(list, (LinkListNode*)&t3, LinkList_Length(list));
	ret = LinkList_Insert(list, (LinkListNode*)&t4, LinkList_Length(list));
	ret = LinkList_Insert(list, (LinkListNode*)&t5, LinkList_Length(list));

	for (int i = 0; i < LinkList_Length(list); i++){
		Teacher* tmp = (Teacher*)LinkList_Get(list, i);
		if (tmp != NULL){
			printf("%d\n", tmp->age);
		}
	}


	int len = LinkList_Length(list);
	for (int i = 0; i <len ; i++){
		Teacher* tmp = (Teacher*)LinkList_Delete(list, 0);
		if (tmp != NULL){
			printf("%d\n", tmp->age);
		}
	}


	LinkList_Destroy(list);
	system("pause");
}