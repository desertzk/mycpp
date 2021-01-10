#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define datatype char

typedef struct queue
{
	datatype data[MAX];
	int front;//out
	int rear;//in

}Queue;

void init(Queue *myqueue);

int isempty(Queue *myqueue);//1 is empty 0 not empty

void enQueue(Queue *myqueue, datatype object);//»Î∂”

datatype deQueue(Queue *myqueue);//out

void printQueue(Queue *myqueue);

datatype getHead(Queue *myqueue);

