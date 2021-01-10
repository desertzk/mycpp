#include<iostream>

using namespace std;
class fu
{
public:
	fu()
	{
		cout << "fu create " << endl;
	}

	~fu()
	{
		cout << "fu delete " << endl;
	}
};


class zi:public fu
{
public:
	zi()
	{
		cout << "zi create " << endl;
	}

	~zi()
	{
		cout << "zi delete " << endl;
	}
};

class sun :public zi
{
public:
	sun()
	{
		cout << "sun create " << endl;
	}

	~sun()
	{
		cout << "sun delete " << endl;
	}
};



void main()
{
	fu *pfu = new zi();
	delete pfu;
	system("pause");
}