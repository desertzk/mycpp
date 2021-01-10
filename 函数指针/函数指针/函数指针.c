#include<stdio.h>
#include<stdlib.h>

typedef int Array[10];
void main(){
	Array a;
	a[0] = 1;
	for (int i = 0; i < 10; i++){
		printf("a[%d]= %d\n", i, a[i]);
	}
	system("pause");
}