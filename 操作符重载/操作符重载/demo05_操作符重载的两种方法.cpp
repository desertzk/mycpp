#include "iostream"
using namespace std;

//a+bi
class  Complex
{
private:
	int a;
	int b;
	//通过友元函数实现+操作
	friend Complex operator+(Complex &c1, Complex &c2);
	//全局函 前置++
	friend Complex& operator++(Complex &c2);
public:
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout<<a<<"+"<<b<<"i"<<endl;
	}
public:
	//通过类的成员函数实现-操作
	Complex operator-(Complex &c2)
	{
		Complex tmp;
		tmp.a = this->a -c2.a;
		tmp.b = b -c2.b;
		return tmp;
	}
	Complex operator-(int j)
	{
		Complex tmp;
		tmp.a = this->a - j;
		tmp.b = b;
		return tmp;
	}

	// 前置--
	Complex& operator--()
	{
		this->a--;
		this->b--;
		return *this;
	}
};

Complex operator+(Complex &c1, Complex &c2)
{
	Complex tmp;
	tmp.a = c1.a + c2.a;
	tmp.b = c1.b + c2.b;
	return tmp;
}

Complex& operator++(Complex &c2)
{
	c2.a++;
	c2.b++;
	return c2;
}


//1操作符重载，首先是通过函数实现的。
void main()
{
	Complex c1(1, 2), c2(3, 4);

	//Complex c3 = ComAdd(c1, c2);
	//Complex c3 = operator+(c1, c2);
	//2  +操作符有两个参数 左操作数 和 右操作数
	//3 
	Complex c3 = c1 + c2;
	c3.printCom();

	Complex c4 = c1.operator-(c2);
	c4.printCom();
	
	Complex c5 = c1 - c2 ;
	c5.printCom();
	//目标 通过类的成员函数，完成操作符重载
	//1 要承认操作符重载是一个函数，要写函数原型
	//2 写出函数调用语言 c1.operator-(c2)
	//3 完善函数原型 

	++c2; 
	c2.printCom();
	
	//全局函数原型推导
	//Complex& operator++(Complex &c2);
	--c2; //c2.operator--();
	c2.printCom();


	
	system("pause");
}