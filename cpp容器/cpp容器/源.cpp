#include<iostream>
#include<vector>
#include<array>
#include<tuple>
#include<list>
using namespace std;

void main1()
{
	list<int> mylist;

	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);
	//mylist[1];
	auto ibegin = mylist.begin();//指针，指向一个迭代器，迭代器存储了位置
	auto iend = mylist.end();
	//list用迭代器进行遍历
	for (; ibegin != iend; ibegin++)
	{
		cout << *ibegin << endl;
		printf("%p,%p\n", ibegin._Ptr, ibegin);//重载
	}

	cin.get();


}
//list删除
void main()
{
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);
	mylist.push_back(5);
	auto i = mylist.begin();//删除元素，依赖于迭代器，
	//++i;
	//++i;
	//++i;
	//auto i = mylist.end();//end最后一个没有实体，
	//
	//i--;
	mylist.erase(i);//链式存储，不允许下标访问
	//只能用迭代器，链表迭代器只能用++，--
	//mylist.clear();清空
	auto ibegin = mylist.begin();//指针，指向一个迭代器，迭代器存储了位置
	auto iend = mylist.end();

	//for (; ibegin != iend; ibegin++)
	//{
	//	if ((*ibegin) == 3)
	//	{
	//		mylist.erase(ibegin);//删除,删除的时候迭代器会发生
	//		break;
	//	}
	//	//cout << *ibegin << endl;
	//}
	{
		auto ibegin = mylist.begin();//指针，指向一个迭代器，迭代器存储了位置
		auto iend = mylist.end();

		for (; ibegin != iend; ibegin++)
		{
			cout << *ibegin << endl;
		}
	}
	cin.get();
}

void main4()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	list<int > mylist(a, a + 5);//根据数组初始化，
	//传递开始地址，传递结束地址
	//	mylist(0);
	//mylist[1];只能用迭代器访问
	mylist.push_back(10);
	mylist.push_front(12);
	auto ibegin = mylist.begin();//指针，指向一个迭代器，迭代器存储了位置
	auto iend = mylist.end();

	for (; ibegin != iend; ibegin++)
	{
		if (*ibegin == 3)
		{
			mylist.insert(ibegin, 30);
			break;//删除或者插入，迭代器都会发生变化
		}
	}

	mylist.remove(30);//直接一个函数，根据元素来删除

	{
		auto ibegin = mylist.begin();//指针，指向一个迭代器，迭代器存储了位置
		auto iend = mylist.end();

		for (; ibegin != iend; ibegin++)
		{
			cout << *ibegin << endl;
		}
	}
	cin.get();





}

void main5()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	list<int > mylist(a, a + 5);//根据数组初始化，
	auto rb = mylist.rbegin();
	auto re = mylist.rend();
	//同时正向与方向查找
	for (; rb != re; rb++)
	{
		cout << *rb << endl;
	}

	cin.get();




}

void  main6()
{
	int a[5] = { 1, 2, 3, 104, 5 };
	list<int > mylist1(a, a + 5);//根据数组初始化，
	int b[5] = { 11, 122, 33, 44, 55 };
	list<int > mylist2(b, b + 5);//根据数组初始化，
	mylist1.sort();
	mylist2.sort();//排序


	mylist1.merge(mylist2);//合并之前必须有序



	{
		auto ibegin = mylist1.begin();//指针，指向一个迭代器，迭代器存储了位置
		auto iend = mylist1.end();

		for (; ibegin != iend; ibegin++)
		{
			cout << *ibegin << endl;
		}
	}
	cout << "\n\n\n";
	{
		auto ibegin = mylist2.begin();//指针，指向一个迭代器，迭代器存储了位置
		auto iend = mylist2.end();

		for (; ibegin != iend; ibegin++)
		{
			cout << *ibegin << endl;
		}
	}
	cin.get();
}

void main7()
{

	int a[6] = { 1, 2, 98, 2, 5, 98 };
	list<int> mylist1(a, a + 6);//根据数组初始化，
	{
		auto ibegin = mylist1.begin();//指针，指向一个迭代器，迭代器存储了位置
		auto iend = mylist1.end();

		for (; ibegin != iend; ibegin++)
		{
			cout << *ibegin << endl;
		}
	}
	mylist1.sort();
	mylist1.unique();//唯一依赖于排序
	cout << "\n\n\n";
	{
		auto ibegin = mylist1.begin();//指针，指向一个迭代器，迭代器存储了位置
		auto iend = mylist1.end();

		for (; ibegin != iend; ibegin++)
		{
			cout << *ibegin << endl;
		}
	}

	cin.get();


}
