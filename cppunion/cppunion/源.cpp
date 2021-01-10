#include<iostream>

using namespace std;
union un
{
	int a;
	char b;
};

//union sub :un
//{
//
//};

struct father
{
	father()
	{
		cout << "father create" << endl;

	}
	~father()
	{
		cout << "father delete" << endl;

	}
	int a;
};

struct subf :father
{
	subf()
	{
		cout << "sub" << endl;
	}
	~subf()
	{
		cout << "sub delete" << endl;
	}
};


class my{
public:
	static class mymy
	{
	public:
		 int num;
	};
};

class X
{
public:
	
	X(int a)
	{
		this->a = a;
	}
	X(){
		X(10);
	};
	int a;
};

void main()
{
	X x;
	X x1;
	X &rx = x;
	rx = x1;
	cout << x.a << endl;
	father *sf = new subf();
	delete sf;

	//my::mymy::num = 0;
	//cout << my::mymy::num;
	system("pause");
}