#include<iostream>
#include<list>
using namespace std;

class A
{
public:
	static list<void *> *alist;
	A()
	{
		cout << typeid(*this).name() << "create"<<endl;
	}
	virtual ~A()
	{
		cout << typeid(*this).name()<<"destory"<< endl;
	}
	void * operator new(size_t size)   
	{
		
		A *pa = ::new A();
		alist->push_back(pa);
		return pa;
	}
	void operator delete(void *p)
	{
		/**/list<void *>::iterator it=alist->begin();
		for (; it != alist->end(); it++)
		{
			if (*it == p)
			{
				alist->remove(p);
				::delete p;
				break;
			}    
		}/**/
	}

	static void printMem()
	{
		
		for (list<void *>::iterator it = alist->begin(); it != alist->end(); it++)
		{
			cout << *it << endl;
		}

	}

};

list<void *> *A::alist = new list<void *>();

class B :public A
{
public:
	B()
	{
		cout << "B create" << endl;
	}
};

template<typename T>
class MemCtl
{
public:
	static list<void *> *alist;
	MemCtl()
	{
		cout << typeid(T).name()<<" create" << endl;
	}
	virtual ~MemCtl()
	{
		cout << "A destory" << endl;
	}
	void * operator new(size_t size)
	{
		A *pa = ::new A();
		alist->push_back(pa);
		return pa;
	}
	void operator delete(void *p)
	{
		/**/list<void *>::iterator it = alist->begin();
		for (; it != alist->end(); it++)
		{
			if (*it == p)
			{
				alist->remove(p);
				::delete p;
				break;
			}
		}/**/
	}

	static void printMem()
	{

		for (list<void *>::iterator it = alist->begin(); it != alist->end(); it++)
		{
			cout << *it << endl;
		}

	}

};




void main()
{
	B *pa1=new B();
	A *pa2=new A();

	A::printMem();
	delete pa1;
	A::printMem();
	system("pause");
}