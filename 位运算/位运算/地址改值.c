#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void main(){
	int num;
	scanf("%d", &num);
	
	int data = 1 << 31;//ֻ��1000 0000 0000 0000 ���κ����붼�ܻ�ȡ��һλ����ȷֵ
	printf("num=%d,&num=%p\n", num, &num);
	for (int i = 1; i <= 32; i++)
	{
		if ((num&data) == 0)
		{
			putchar('0'); 
		}
		else
		{
			putchar('1');
		}
		num <<= 1;
		if (i % 4 == 0)
		{
			printf("  ");
		}
	}
	system("pause");
}