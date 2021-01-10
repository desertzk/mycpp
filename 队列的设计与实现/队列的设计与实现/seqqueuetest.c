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
	printf("���е�ͷԪ��:%d \n", tmp);
	printf("���е�length:%d \n", SeqQueue_Length(queue));
	printf("���е�cap:%d \n", SeqQueue_Capacity(queue));

	while (SeqQueue_Length(queue) > 0)
	{
		tmp = *((int *)SeqQueue_Retrieve(queue));
		printf("tmp:%d \n", tmp);
	}





	void SeqQueue_Clear(SeqQueue* queue);

	void SeqQueue_Destroy(queue);


	system("pause");
}