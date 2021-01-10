#include<iostream>

using namespace std;
class parent
{
public:
	virtual void say()
	{
		cout << "parent say" << endl;
	}


	virtual void see();
};
void parent::see()
{

}

//
//class child :public parent
//{
//public:
//	void see()
//	{
//		cout << typeid(*this).name() << "see" << endl;
//	}
//};

void main()
{
	parent *p = new parent();
	p->say();
	system("pause");
}