#include<stdio.h>
#include<stdlib.h>

typedef union{ long i; char k[10]; char c; }DATA;
struct data{ double cat; DATA cow; short dog; }too;
struct data1{ short cat; DATA cow; int dog; };

void main(){
	printf("%d\n", sizeof(struct data1));
	system("pause");
}