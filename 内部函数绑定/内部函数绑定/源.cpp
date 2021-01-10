#include<iostream>
#include<functional>

using namespace std;
using namespace std::placeholders;

class MyStruct
{
public:
	void add(int a)
	{
		cout << a << endl;
	}
	void add2(int a,int b)
	{
		cout << a+b << endl;
	}
};

void main()
{
	// MyStruct::add;
	//void(*pf)(int) =
	MyStruct struct1;
	auto func = bind(&MyStruct::add, &struct1, _1);
	auto func2 = bind(&MyStruct::add2, &struct1, _1,_2);
	void(MyStruct::*pf)(int) = &MyStruct::add;
	
	func(100);
	func2(20, 40);
	(struct1.*pf)(10);
	system("pause");
}


class A
{
public:
	int func(int x, int y)
	{
		printf("A::func:x=%d,y=%d/n", x, y);
		return (x<y ? x : y);
	}
};
typedef int (A::*p)(int, int);//指针名前一定要加上所属类型类名 A::的限定

int main2()
{
	p fun = &A::func;
	A a;                  //因为成员函数地址的解引用必须要附驻与某个对象的地址，所以我们必须创建某个对象。
	cout << "min:" << (a.*fun)(4, 5) << endl;
	return 0;
}