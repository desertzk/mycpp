#include<stdlib.h>
#include<stdio.h>
#include"linklist.h"

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length; 
}TLinkList;


LinkList* LinkList_Create(){
	TLinkList *tList = malloc(sizeof(TLinkList));
	if (tList == NULL){
		return NULL;
	}
	tList->header.next = NULL;
	tList->length = 0;
	return tList;
}

void LinkList_Destroy(LinkList* list){
	if (list != NULL){
		free(list);
	}
}

void LinkList_Clear(LinkList* list){

	TLinkList *tList = (TLinkList *)list;
	if (tList == NULL){
		return;
	}
	tList->length = 0;
	tList->header.next = NULL;
	
}

int LinkList_Length(LinkList* list){
	TLinkList *tList = (TLinkList *)list;
	if (tList == NULL){
		return -1;
	}
	return tList->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos){
	TLinkList *tList = (TLinkList *)list;
	LinkListNode *current = NULL;

	if (tList == NULL || node == NULL || pos < 0){
		return -1;
	}
	current = &tList->header;

	for (int i = 0; i < pos&&current->next!=NULL; i++){
		current = current->next;
	}

	node->next = current->next;
	current->next = node;
	tList->length++;
	return 1;
}

LinkListNode* LinkList_Get(LinkList* list, int pos){
	TLinkList *tList = (TLinkList *)list;
	LinkListNode *current = NULL;

	if (tList == NULL || pos < 0||pos>=tList->length){
		return -1;
	}
	current = &tList->header;

	for (int i = 0; i < pos; i++){
		current = current->next;
	}
	return current->next;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos){
	TLinkList *tList = (TLinkList *)list;
	LinkListNode *current = NULL;
	LinkListNode *ret = NULL;
	if (tList == NULL || pos < 0 || pos >= tList->length){
		return NULL;
	}
	current = &tList->header;
	for (int i = 0; i < pos; i++){
		current = current->next;
	}
	ret = current->next;
	current->next = ret->next;
	//node->next = current->next;
	tList->length--;

	return ret;
}