#include<stdio.h>
#include<stdlib.h>

//void print(int **iarr,int size)
//{
//	for (int i = 0;i<)
//}

void main(){
	int c[5] = {1,2,3,4,5};
	int *pc = c;
	int (*pac)[5] = &c;
	int **ppac = &c;
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", *(pc + i));
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", *(c + i));
	}
	for (int i = 0; i < 5; i++)//������֪����20�ֽڽ�����Ϊ������4*5
	{
		printf("%d\n", *((*pac) + i));
	}
	//*ppac[i]Ϊ�λ��ж�
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", *(ppac+i));
	}/**/


	int myarray[3][5];
	int temp = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			myarray[i][j] = temp++;
		}
	}
	printf("&myarray:%d &myarray+1:%d\n", &myarray, &myarray + 1);
	printf("myarray:%d myarray+1:%d\n", myarray, myarray + 1);//��ʵ��������(*pmyarray)[5],˵��myarray������һ������ָ��
	system("pause");
}