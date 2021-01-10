#include<stdio.h>
void main()
{
	int a = 10;
	register int c = 5;
	int b;
	_asm
	{
		mov eax,a
		add eax,5
		mov b,eax
	}
	printf("%d", b);
	getchar();
}