#include<stdio.h>
#include<Windows.h>

__declspec(naked) void test()
{
	__asm {
		int 3
		stac
		mov eax,1

	}
}



ULONG64 x;
void main()
{
	printf("test address %p",test);
	system("pause");
	__asm {
		int 21h
		

	}
	printf("%p", x);
	system("pause");

}

