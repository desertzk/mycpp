#include<stdio.h>
#include<stdlib.h>

struct data
{
	int *p;
	int len; 
	int stat;//0代表无序,1代表从小到大，2代表从大到小
	int reallen;//真实长度
};

void init(struct data *pdata);

void add(struct data *pdata, int num);

void addarray(struct data *pdata, int *pnum, int n);

void print(struct data *pdata);

void destory(struct data *pdata);

void deleteone(struct data *pdata,int num);

void deleteall(struct data *pdata, int num);

int *finddata(struct data *pdata, int num);

int *findalldata(struct data *pdata, int num);//返回一片内存包含找到的所有元素

void update(struct data *pdata, int oldnum, int newnum);

void sort(struct data *pdata, int num);