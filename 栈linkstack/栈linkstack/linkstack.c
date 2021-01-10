#include<stdlib.h>
#include"linkstack.h"
#include"linklist.h"

typedef struct _tag_linkStackNode{
	LinkListNode node;
	void *item;
}linkStackNode;

LinkStack* LinkStack_Create(){
	return LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack){
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);//因为本来就是linklist底层库创建的类型就是linklist
}

void LinkStack_Clear(LinkStack* stack){
	if (stack == NULL){
		return;
	}
	while (LinkStack_Size(stack)){
		LinkStack_Pop(stack);
	}

}

int LinkStack_Push(LinkStack* stack, void* item){
	linkStackNode* lsnode = (linkStackNode*)malloc(sizeof(linkStackNode));
	lsnode->item = item;
	int ret=LinkList_Insert(stack, (LinkListNode*)lsnode, 0);//头插法省去了底层库循环遍历
	if (ret){
		return ret;
	}
	free(lsnode);
	return 0;//failed
}

void* LinkStack_Pop(LinkStack* stack){
	void *myItem = NULL;
	linkStackNode *node = NULL;
	if (stack == NULL){
		return NULL;
	}
	node = (linkStackNode*)LinkList_Delete(stack, 0);
	if (node == NULL){
		return NULL;
	}
	myItem = node->item;
	free(node);
	
	return myItem;
}

void* LinkStack_Top(LinkStack* stack){
	linkStackNode *node = NULL;
	if (stack == NULL){
		return NULL;
	}
	node = (linkStackNode *)LinkList_Get(stack, 0);
	if (node == NULL)
	{
		return NULL;
	}
	return node->item;
}

int LinkStack_Size(LinkStack* stack){
	if (stack == NULL){
		return -1;
	}

	return LinkList_Length(stack);
}