#include<iostream>

using namespace std;

class jia
{
public:
	jia(int a, int b) :x(a), y(b)
	{

	}
	int jiafa()
	{
		return x + y;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	int newjiafa(int a, int b)
	{
		if (a == 0)
		{
			return b;
		}
		else if (b == 0)
		{
			return a;
		}
		else
		{
			int res = a^b;//先求结果
			int wei = (a&b) << 1;//进位，左移，乘以2，
			//a+b=a^b+(a&b)<<1;
			std::cout << "res=" << res << " " << "wei=" << wei << "\n";
			return newjiafa(res, wei);
		}
	}

private:
	int x;
	int y;


};

int newjiafa(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	else if (b == 0)
	{
		return a;//让相与慢慢趋势于0
	}
	else
	{
		int res = a^b;//先求结果
		int wei = (a&b) << 1;//进位，左移，乘以2，
		//a+b=a^b+(a&b)<<1;//表达式

		std::cout << "res=" << res << " " << "wei=" << wei << "\n";
		return newjiafa(res, wei);
	}


}



void main()
{
	jia  jia1(5, 7);
	std::cout << jia1.newjiafa(5,7) << std::endl;
	system("pause");
}