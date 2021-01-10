#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
	int *p = NULL;
	strcpy(p, "dfasdfa");
	printf("%s", *p);
	system("pause");
}


void main1(){
	int a = 10;
	int *p;
	p = &a;
	printf("%d \n", &a);
	printf("%d \n", a);
	//8191656

	*((int *)8191656) = 30;
	printf("%d \n", a);
	system("pause");
}