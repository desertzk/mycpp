#include<iostream>
#include<array>
using namespace std;

template<typename T>
void showarray(array<T,10> arr,int n)
{
	cout << "TTTT" << endl;
}

template<typename T>
void showarray(array<T*, 10> parr, int n)
{
	cout << "TTTT****" << endl;
}

void main()
{
	array<int, 10> intarray = { 1, 2, 3, 4, 5 };
	array<int*, 10> pintarray = { 0 };
	for (int i = 0; i < 10; i++)
	{
		pintarray[i] = &intarray[i];
	}
	showarray(intarray, 10);
	showarray(pintarray, 10);
	system("pause");
}