#include<stdlib.h>
#include<stdio.h>
#include"seqqueue.h"

void main(){
	SeqQueue* queue=SeqQueue_Create(10);

	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
		SeqQueue_Append(queue, (void *)&a[i]);
	}
	int tmp =  *((int *)SeqQueue_Header(queue));
	printf("队列的头元素:%d \n", tmp);
	printf("队列的length:%d \n", SeqQueue_Length(queue));
	printf("队列的cap:%d \n", SeqQueue_Capacity(queue));

	while (SeqQueue_Length(queue) > 0)
	{
		tmp = *((int *)SeqQueue_Retrieve(queue));
		printf("tmp:%d \n", tmp);
	}





	void SeqQueue_Clear(SeqQueue* queue);

	void SeqQueue_Destroy(queue);


	system("pause");
}