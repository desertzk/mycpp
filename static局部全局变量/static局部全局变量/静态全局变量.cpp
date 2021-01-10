#include<stdio.h>
#include<stdlib.h>

void main()
{
	for (int i = 0; i < 10; i++)
	{
		static int b = 1;
		b += 1;
		printf("%d\n", b);
	}
	//b = 3;
	getchar();
}