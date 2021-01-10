#include"╤сап.h"

void init(Queue *myqueue)
{
	myqueue->front = myqueue->rear = NULL;

}

int isempty(Queue *myqueue)
{
	if (myqueue->front == myqueue->rear)
	{
		return 1;
	}
	else{
		return 0;
	}
}


void enQueue(Queue *myqueue, datatype object)
{
	if (myqueue->rear == MAX)
	{
		printf("queue full");
		return;
	}
	else{
		myqueue->data[myqueue->rear] = object;
		myqueue->rear += 1;
		
	}
}

datatype DeQueue(Queue *myqueue)
{
	if (myqueue->front == myqueue->rear)
	{
		printf("queue empty");
		//return;
	}
	else{
		myqueue->front += 1;
		return myqueue->data[myqueue->front - 1];
	}
}

void printQueue(Queue *myqueue)
{
	if (myqueue->front == myqueue->rear)
	{
		printf("\nempty");
	}
	else{
		for (int i = myqueue->front; i < myqueue->rear; i++)
		{
			printf("%c", myqueue->data[i]);
		}
	}
}

datatype getHead(Queue *myqueue)
{
	if (myqueue->front == myqueue->rear)
	{
		printf("empty");
	}
	else{
		return myqueue->data[myqueue->front];
	}
}

void main(){
	Queue queue;
	init(&queue);
	enQueue(&queue, 'a');
	enQueue(&queue, 'b');
	enQueue(&queue, 'c');
	enQueue(&queue, 'd');
	printQueue(&queue);
	printf("\n%c",DeQueue(&queue));
	printf("\n%c", DeQueue(&queue));
	printf("\n%c", getHead(&queue));
	
	system("pause");
}