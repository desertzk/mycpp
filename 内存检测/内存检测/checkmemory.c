#include<stdio.h>
#include<stdlib.h>

_declspec(dllexport) void go()
{
	void *p1 =(void *)0x0040000;
	//void *p2 = 0x472000;
	int i = 0;
	for (char *p = p1; i < 0x472000; i++, p++)
	{
		int *px = (int *)p;
		if (*px == 25)
		{

			//printf("%p\n", px);
		}
		
	}
}