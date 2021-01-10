#include<stdio.h>
#include<stdlib.h>

void main(){

	int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2 };
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(&a));//这其实就是指针的大小
	printf("%d   %p\n", sizeof(*a),*a);
	printf("%d   %p\n", sizeof(**a),**a);
	system("pause");
}