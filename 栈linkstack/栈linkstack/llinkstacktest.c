#include<stdlib.h>
#include<stdio.h>
#include"linkstack.h"

void main111(){
	LinkStack* stack=LinkStack_Create();
	int a[10];
	
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
		LinkStack_Push(stack, (int *)(a+i));
	}
	int tmp=*(int *)LinkStack_Top(stack);
	printf("Õ»¶¥ÔªËØ£º%d\n", tmp);


	printf("stack len:%d \n",LinkStack_Size(stack));
	//printf("stack capacity:%d \n", LinkStack_Capacity(stack));


	while (LinkStack_Size(stack) > 0){
		int tmp = *((int *)LinkStack_Pop(stack));
		printf("%d\n", tmp);
	}
	//void LinkStack_Clear(LinkStack* stack);

	//int 

	//void* LinkStack_Pop(LinkStack* stack);

	//void* LinkStack_Top(LinkStack* stack);

	//int LinkStack_Size(LinkStack* stack);

	LinkStack_Destroy(stack);
	system("pause");
}