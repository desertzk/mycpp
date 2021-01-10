#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>

void run(void *p)
{
	int *px = (int *)p;
	printf("%d\n", *px);
	MessageBoxA(0, "dfas", "QWE", 0);
}

void main(){

	for (int i = 0; i < 5; i++)
	{
		_beginthread(run, 0, &i);
		//run(NULL);
	}
	system("pause");
}