#include<stdio.h>
#include<stdlib.h>

void main(){
	int a[] = { 1, 2, 3, 4 };
	int *c = (int *)(&a + 1);
	int i = *(c - 1);
	printf("i=%d",i);
	system("pause");
}