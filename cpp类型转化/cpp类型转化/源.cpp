#include<iostream>

using namespace std;

class fushu
{
public:
	fushu(int num)
	{
		x = num;
		y = num;
	}
	void print()
	{
		cout << x << " " << y << endl;
	}
	operator int()//类型转换函数 类类之间的转换函数    重载强转成int
	{
		return x + y;
	}
private:
	int x;
	int y;
};

void main()
{
	int num(100.9);
	fushu fushu1(num);
	int i = fushu1;
	cout << i << endl;
	system("pause");
}