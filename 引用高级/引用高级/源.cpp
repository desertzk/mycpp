#include<iostream>

using namespace std;
int add(int a, int b)
{
	return a + b;
}

int minux(int a, int b)
{
	return a - b;
}

int(*& changep(int(*& pfunc)(int, int)))(int, int)//changep(int(*& pfunc)(int, int))  y    y change(y)
{
	pfunc = minux;
	return pfunc;
}

struct mystr
{
	char a[12];
	double b;
	int i;
};


void main()
{
	cout << sizeof(struct mystr) << endl;

	int(*pfunc)(int, int)(add);
	cout << pfunc(1, 2)<<endl;
	pfunc = changep(pfunc);
	cout << pfunc(1, 2) << endl;


	/*int a = 1, b = 2, c = 3;
	int &rp[3] = { &a, &b, &c };*///引用数组是不被支持的


	system("pause");
}