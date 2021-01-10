#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
#include"linkqueue.h"


typedef struct _tag_LinkQueueNode{
	LinkListNode node;
	void *item;
}LinkQueueNode;

LinkQueue* LinkQueue_Create(){
	return LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue* queue){
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
}

void LinkQueue_Clear(LinkQueue* queue){
	while (LinkQueue_Length(queue) > 0){
		LinkQueue_Retrieve(queue);
	}
}

int LinkQueue_Append(LinkQueue* queue, void* item){
	if (queue == NULL||item==NULL)
	{
		return -1;
	}
	LinkQueueNode* queueNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (queueNode == NULL){
		return -2;
	}
	queueNode->item = item;

	int ret = LinkList_Insert(queue, (LinkListNode*)queueNode, LinkList_Length(queue));
	if (ret){
		return ret;
	}
	free(queueNode);
	return 0;

}

void* LinkQueue_Retrieve(LinkQueue* queue){
	void *myItem = NULL;
	LinkQueueNode *node = NULL;
	if (queue == NULL){
		return NULL;
	}
	node = (LinkQueueNode *)LinkList_Delete(queue, 0);
	if (node == NULL){
		return NULL;
	}
	myItem = node->item;
	if (node != NULL){
		free(node);
	}
	return myItem;
}

void* LinkQueue_Header(LinkQueue* queue){
	if (queue == NULL){
		return NULL;
	}
	LinkQueueNode *node = (LinkQueueNode *)LinkList_Get(queue, 0);
	if (node == NULL){
		return NULL;
	}
	void *myItem = node->item;

	return myItem;
}

int LinkQueue_Length(LinkQueue* queue){
	return LinkList_Length(queue);
}