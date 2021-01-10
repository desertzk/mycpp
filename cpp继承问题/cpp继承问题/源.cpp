#include<iostream>

using namespace std;
class Base
{
private:
	int x;
public:
	virtual void mf1() = 0;
	virtual void mf1(int){}
	virtual void mf2(){}
	void mf3();
	void mf3(double);
};

void Base::mf1()
{
	cout << "Base::mf1()" << endl;
}

class Derived:public Base
{
public:
	using Base::mf1;
	virtual void mf1(){};
	void mf3(){};
	void mf4(){};
protected:
private:
};


void main()
{
	Derived d;
	int x=0;
	d.mf1();
	d.mf1(x);
	d.mf2();
	d.mf3();
	d.mf3(x);//error
	system("pause");
}