#include<stdio.h>
#include<stdlib.h>
typedef char(*pfun)();

char mygetc()
{
	printf("myget");
}

void main(){
	pfun p = mygetc;
	p();
	system("pause");
}