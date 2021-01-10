#include<stdio.h>
#include<stdlib.h>
#include"seqlist.h"

typedef struct _tag_SeqList{
	int length;
	int capacity;
	unsigned int *node; 
}TSeqList;

typedef void SeqList;
//typedef void SeqListNode;

//SeqList* SeqList_Create(int capacity){
//	TSeqList *ret = NULL;
//	ret = (TSeqList *)malloc(sizeof(TSeqList));
//	ret->capacity = capacity;
//	if (ret->node==NULL){
//		return NULL;
//	}
//	ret->node = (unsigned int *)malloc(sizeof(int )*capacity);
//	ret->length = 0;
//
//	return ret;
//}

SeqList* SeqList_Create(int capacity){
	TSeqList *ret = NULL;
	ret = (TSeqList *)malloc(sizeof(TSeqList)+sizeof(unsigned int)*capacity);//猜想unsigned int 可以代表地址的值
	ret->capacity = capacity;
	if (ret->node == NULL){
		return NULL;
	}
	ret->node = (unsigned int *)(ret + 1);
	ret->length = 0;

	return ret;
}


void SeqList_Destroy(SeqList* list){
	if (list == NULL){
		return;
	}

	free(list);
	return;
}

void SeqList_Clear(SeqList* list){
	TSeqList *tlist = (TSeqList *)list;
	if (list == NULL){
		return;
	}
	tlist->length = 0;
	
}

int SeqList_Length(SeqList* list){
	TSeqList *tlist = (TSeqList *)list;
	if (list == NULL){
		return -1;
	}
	 
	 return tlist->length;
}

int SeqList_Capacity(SeqList* list){
	TSeqList *tlist = (TSeqList *)list;
	if (list == NULL){
		return -1;
	}
	 
	 return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos){
	if (list == NULL || node == NULL){
		return -1;
	}
	TSeqList *tlist = list;
	if (pos<0 || pos>=tlist->capacity){
		return -2;
	}
	//判断是否已满
	if (tlist->length >= tlist->capacity){
		return -3;
	}

	//容错如果已有5个要求存第7个，那么就帮用户存第五个
	if (pos > tlist->length){
		pos = tlist->length;
	}




	for (int i = tlist->length; i > pos; i--){
		tlist->node[i] = tlist->node[i - 1];
	}
	tlist->node[pos] = (unsigned int)node;//猜想unsigned int 可以代表地址的值
	tlist->length++;
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos){
	TSeqList *tlist = list;
	if (list == NULL || pos < 0 || pos >= tlist->length){
		return NULL;
	}
	return (SeqListNode*)tlist->node[pos];
}

SeqListNode* SeqList_Delete(SeqList* list, int pos){
	TSeqList *tlist = (TSeqList *)list;
	SeqListNode *ret = NULL;
	if (list == NULL || pos < 0 || pos >= tlist->length){
		return NULL;
	}
	ret = (SeqListNode*)tlist->node[pos];
	for (int i = pos; i +1< tlist->length; i++){
		tlist->node[i] = tlist->node[i + 1];
	}
	tlist->length--;
	return ret;
}
