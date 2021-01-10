#include<iostream>

using namespace std;

template<typename T>
void myswap(T &a, T &b)
{
	//std::cout<<
	T temp = a;
	a = b;
	b = temp;
}

void main()
{
	int num1 = 100;
	int num2 = 10;
	myswap(num1, num2);
	cout << num1 << "   " << num2;
	system("pause");
}