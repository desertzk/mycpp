#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

struct print
{
	void operator()(int x)
	{
		cout << x << endl;
	}
};

void main1()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11 };
	int *p = find(a, a + 10,6);
	cout << (void *)a << (void *)(a + 10) << endl;
	cout << p << endl;
	cout << *p << endl;
	if (p == (a + 10))
	{
		cout << "not found" << endl;
	}

	for_each(a, a + 10, print());
	system("pause");
}

void main()
{
	multiset <int>myset;//可以重复
	myset.insert(11);
	myset.insert(12);
	myset.insert(13);
	myset.insert(14);
	myset.insert(14);
	auto ib = myset.begin();
	auto ie = myset.end();
	for (; ib != ie; ib++)
	{
		cout << *ib << endl;
		printf("%p,%p\n", ib, ib._Ptr);//智能指针
	}
	cin.get();
}