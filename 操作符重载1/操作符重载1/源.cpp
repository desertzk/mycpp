#include<iostream>

using namespace std;
class mycomplex
{
public:
	friend ostream & operator<<(ostream & out, mycomplex &complex);
	mycomplex(int x, int y) :x(x), y(y)
	{
	}
	~mycomplex()
	{
	}
	mycomplex& operator++()
	{
		this->x++;
		this->y++;
		//return *this;
	}

private:
	int x;
	int y;
	void show()
	{
		cout << x << "+" << y << "i" << endl;
	}
};



ostream & operator <<(ostream & out, mycomplex &complex)
{
	out << complex.x << "+" << complex.y <<"i"<< endl;
	return out;
}

void main()
{
	mycomplex comp1(1,2);
	cout << comp1;
	mycomplex com2(7,8);
	com2 = ++comp1;
	cout << comp1;
	cout << com2;
	system("pause");
}