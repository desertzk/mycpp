#include<iostream>
#include"Hash.h"
#include"Hash.cpp"
using namespace std;

void main()
{
	Hash<int> myhash;
	int a[10] = { 10, 11, 22, 33, 44, 55, 66, 77, 88, 99 };
	myhash.init(a, 10);
	cout << myhash.isin(4,44)<<endl;
	hashnode<int> *p = myhash.find(8);
	cout << p->t << endl;
	system("pause");
}