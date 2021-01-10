#include<stdio.h>
#include<stdlib.h>

void main(){
	int a[3][4];
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(&a));
	printf("%d\n", sizeof(*a));//16
	system("pause");
}