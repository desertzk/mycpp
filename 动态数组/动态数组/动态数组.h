#include<stdio.h>
#include<stdlib.h>

struct data
{
	int *p;
	int len; 
	int stat;//0��������,1�����С����2����Ӵ�С
	int reallen;//��ʵ����
};

void init(struct data *pdata);

void add(struct data *pdata, int num);

void addarray(struct data *pdata, int *pnum, int n);

void print(struct data *pdata);

void destory(struct data *pdata);

void deleteone(struct data *pdata,int num);

void deleteall(struct data *pdata, int num);

int *finddata(struct data *pdata, int num);

int *findalldata(struct data *pdata, int num);//����һƬ�ڴ�����ҵ�������Ԫ��

void update(struct data *pdata, int oldnum, int newnum);

void sort(struct data *pdata, int num);