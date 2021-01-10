#include<iostream>

using namespace std;
class A
{
private:
	int b = 0;

public:
	void showB()
	{
		cout << b << endl;
	}
};

//void (*pshowB)()
void main()
{
	A *a=new A();
	void (A::* pshowb)() = &A::showB;
	(a->*pshowb)();
	system("pause");
}