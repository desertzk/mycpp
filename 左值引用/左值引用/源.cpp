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
	int* &rp1 = p1;//p1���ڴ��п�������
	cout << *rp1 << endl;

	//int* &rp2 = &num2;//&num2����ڼĴ��������ɵģ������ڴ��У����Բ�������//һ�����÷�������ֵ
	int* &&rp3 = &num2;//�������÷�������ֵ  //���ڶ��󿽱�
	cout << *rp3 << endl;
	cout << "---------------------------" << endl;
	int * &p = getdata();

	cout << *p << endl;
	cout << *p << endl;

	system("pause");
}