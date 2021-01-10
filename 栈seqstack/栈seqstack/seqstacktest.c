#include<stdio.h>
#include<stdlib.h>
#include"seqstack.h"

void main(){
	SeqStack* stack = NULL;
	int a[10];
	stack = SeqStack_Create(10);

	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
		SeqStack_Push(stack,(void *)(a+i));
	}
	int tmp = *((int *)SeqStack_Top(stack));
	printf("%d\n",tmp);
	printf("stack len:%d \n",SeqStack_Size(stack));
	printf("stack capacity:%d \n",SeqStack_Capacity(stack));


	while (SeqStack_Size(stack) > 0){
		int tmp = *((int *)SeqStack_Pop(stack));
		printf("%d\n", tmp);
	}

	/*
	void 

	void SeqStack_Clear(SeqStack * stack);

	int SeqStack_Push(SeqStack* stack, void* item);

	void* SeqStack_Pop(SeqStack* stack);

	void* SeqStack_Top(SeqStack* stack);

	int SeqStack_Size(SeqStack * stack);

	int SeqStack_Capacity(SeqStack * stack);
	*/
	
	SeqStack_Destory(stack);


	system("pause");
}