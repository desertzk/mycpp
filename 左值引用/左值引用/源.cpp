#include<iostream>

using namespace std;

int* & getdata()
{
	int *p = new int;
	*p = 15;
	int* &rp = p;

	return rp;
}


void main()
{
	int num1 = 5;
	int num2 = 10;
	int *p1;
	int *p2;

	p1 = &num1;
	int* &rp1 = p1;//p1在内存中可以引用
	cout << *rp1 << endl;

	//int* &rp2 = &num2;//&num2这个在寄存器中生成的（不在内存中）所以不能引用//一个引用符引用左值
	int* &&rp3 = &num2;//两个引用符引用右值  //用于对象拷贝
	cout << *rp3 << endl;
	cout << "---------------------------" << endl;
	int * &p = getdata();

	cout << *p << endl;
	cout << *p << endl;

	system("pause");
}