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
			int res = a^b;//������
			int wei = (a&b) << 1;//��λ�����ƣ�����2��
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
		return a;//����������������0
	}
	else
	{
		int res = a^b;//������
		int wei = (a&b) << 1;//��λ�����ƣ�����2��
		//a+b=a^b+(a&b)<<1;//���ʽ

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