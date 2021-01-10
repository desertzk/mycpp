#include<iostream>

using namespace std;
class A
{
public:
	
	virtual void a()
	{
		cout << "in A" << endl;
	}
	/*virtual void a1();
	virtual void a2();
	virtual void a3();
	virtual void a4();*/
private:
	int f, g, h;
	virtual void b()
	{
		cout << "Ab" << endl;
	}
};

class B : public A
{
public:
	void a()
	{
		cout << "in B" << endl;
	}
	virtual void c()
	{
		cout << "in C" << endl;
	}
};



void main()
{
	cout << sizeof(A) << endl;//都只有一个指针指向虚函数表
	cout << sizeof(B) << endl;
	A *ca=new B();
	B *cb=new B();
	ca->a();
	cb->a();
	system("pause");
}