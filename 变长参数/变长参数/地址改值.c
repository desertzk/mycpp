#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

int add(int n, ...)
{
	va_list v;//保存可以变长的参数列表
	va_start(v, n);//从n的之后所有参数保存之
	for (int i = 0; i < n; i++)
	{
		int data = va_arg(v, int);
		printf("%d\n", data);
	}
	va_end(v);//free list
	return 0;
}

void main(){
	//printf("%d", add(1, 1));
	int i = 1;
	int *pi = &i;
	//(*pi)++;
	int a = *pi++;
	printf("%d\n", a);
	
	system("pause");
}