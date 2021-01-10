#include<stdio.h>
#include<stdlib.h>
#include"circlelist.h"

typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode* slider;
	int length;
}TCircleList;
//链表节点从0开始
CircleList* CircleList_Create(){
	TCircleList* ret = (TCircleList *)malloc(sizeof(TCircleList));
	if (ret == NULL){
		return NULL;
	}

	ret->length = 0;
	ret->header.next = NULL;
	ret->slider = NULL;
	return ret;
}

void CircleList_Destroy(CircleList* list){
	if (list == NULL){
		return;
	}
	free(list);
}

void CircleList_Clear(CircleList* list){
	TCircleList* sList = (TCircleList*)list;
	if (sList == NULL){
		return;
	}
	sList->length = 0;
	sList->header.next = NULL;
	sList->slider = NULL;
}

int CircleList_Length(CircleList* list){
	TCircleList* sList = (TCircleList*)list;
	if (list == NULL){
		return -1;
	}
	return sList->length;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos){
	int  i = 0;
	TCircleList* sList = (TCircleList*)list;
	if (list == NULL || node == NULL || pos < 0){
		return -1;
	}

	CircleListNode *current = (CircleListNode*)sList;
	for (i = 0; i < pos&&current->next != NULL;i++)
	{
		current = current->next;
	}
	node->next = current->next;//1
	current->next = node;//2

	//first insert node
	if (sList->length == 0){
		sList->slider = node;
	}

	sList->length++;

	//头插法
	if (current==(CircleListNode*)sList){
		CircleListNode *last = CircleList_Get(sList, sList->length - 1);
		last->next = current->next;//指向非头节点的第一个节点
	}
	return 1;
}

CircleListNode* CircleList_Get(CircleList* list, int pos){
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if (list == NULL || pos < 0){
		return NULL;
	}

	CircleListNode* current = (CircleListNode*)sList;
	for (int i = 0; i < pos; i++){
		current = current->next;
	}
	ret = current->next;
	return ret;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos){
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if ((sList != NULL) && (pos >= 0) && (sList->length > 0)){
		CircleListNode *current = (CircleListNode *)sList;
		CircleListNode *last = NULL;

		for (int i = 0; i < pos; i++){
			current = current->next;
		}

		//删除第一个元素
		if (current == (CircleListNode*)sList){
			last = CircleList_Get(sList, sList->length - 1);
		}
		ret = current->next;
		current->next = ret->next;

		sList->length--;

		//check whether list is null 如果要删除第一个元素
		if (last != NULL){
			sList->header.next = ret->next;
			last->next = ret->next;
		}
		//若删除的元素为游标所指的元素
		if (sList->slider == ret){
			sList->slider = ret->next;
		}
		//若删除元素后，链表长度为0
		if (sList->length == 0)
		{
			sList->header.next = NULL;
			sList->slider = NULL;
		}

	}
	return ret;
}

//add 关于游标的

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node){
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if (sList != NULL)
	{
		CircleListNode* current = (CircleListNode*)sList;
		int i = 0;
		//查找node在循环链表中的位置i
		for (i = 0; i < sList->length; i++){
			if (current->next == node){
				ret = current->next;
				break;
			}
			current = current->next;
		}

		if (ret != NULL){
			CircleList_Delete(sList, i);
		}

	}
	return ret;
}

CircleListNode* CircleList_Reset(CircleList* list){
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if (sList != NULL)
	{
		sList->slider = sList->header.next;
		ret = sList->slider;
	}

	return ret;
}

CircleListNode* CircleList_Current(CircleList* list){
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if (sList != NULL)
	{
		ret = sList->slider;
	}

	return ret;
}

CircleListNode* CircleList_Next(CircleList* list){
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if ((sList != NULL) && (sList->slider != NULL))
	{
		ret = sList->slider;
		sList->slider = ret->next;
	}

	return ret;
}
