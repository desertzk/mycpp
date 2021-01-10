#include<iostream>
#include"A.h"
using namespace std;
//void A::show()
//{
//	cout << "a show";
//}

class B :public A
{
public:
	virtual void show()
	{
		cout << "hehe" << endl;
	}
	~B()
	{
		cout << "B destroy" << endl;
	}
};

class C:public B
{
public:
	virtual void show()
	{
		cout << "cc" << endl;
	}
	~C()
	{
		cout << "c destroy" << endl;
	}

protected:
private:
};

class D
{
public:
	B *b;
protected:
private:
};

void main()
{
	B *c=new C();
	c->show();
	
	D *d = new D();
	d->b = c;
	delete c;
	delete d;
	system("pause");
}