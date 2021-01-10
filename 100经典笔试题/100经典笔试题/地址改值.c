#include<stdio.h>
#include<stdlib.h>

void floatcmpzero(){
	float f = 0.000001;
	if (f< 0.00001&&f>-0.00001)
	{
		printf("equal");
	}
}

void GetMemory(char *p){
	p = (char *)malloc(100);

}

void main(){
	char *str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
	system("pause");
}