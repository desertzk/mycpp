#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void main11(){
	int myarr[3][5] = { 0 };
	printf("myarr:%d  myarr+1:%d", myarr, myarr + 1);
	system("pause");
}


void main(){
	//ָ������
	//char *p1[3]= { "123", "456", "789" };
	char *p1[] = { "123", "456", "789" };
	//��ά����
	char p2[3][4]= { "123", "456", "789"};
	//�ֹ���ά�ڴ�
	char **p3 = (char **)malloc(3 * sizeof(char *));
	for (int i = 0; i < 3; i++){
		p3[i] = (char *)malloc(100 * sizeof(char));
		sprintf(p3[i], "%d %d %d", i);
	}

}