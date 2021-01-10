#include<iostream>
#include<cstdarg>

using namespace std;


//int getmax(int *p, int count)
//{
//	int max(0);
//	max = p[0];
//	for (int i = 0; i < count; i++)
//	{
//		if (max<p[i])
//		{
//			max = p[i];
//		}
//	}
//}

template<typename T> T max(T *p, const int count)
{
	T maxdata(p[0]);
	for (int i = 1; i < count; i++)
	{
		if (maxdata < p[i])
		{
			maxdata = p[i];
		}
	}
	return maxdata;
}


template<typename NT>
NT sum(int count,NT data, ...)
{
	va_list arg_ptr;//参数列表的指针
	va_start(arg_ptr, count);//限定从开始
	NT sumres(0);
	for (int i = 0; i < count; i++)
	{
		sumres += va_arg(arg_ptr, NT);
	}
	va_end(arg_ptr);
	return sumres;
}


void main()
{
	int a[10] = {2,3,4,5,66,77,44,22,99,909};
	double b[10] = { 2, 3.9, 4.4, 5.8, 66, 77, 44, 22, 90.8, 90.9 };
	cout << max(a, 10) << endl;
	cout << max(b, 10) << endl;

	cout << sum(3,10,20,30) << endl;
	cout << sum(4, 10.1, 20.2, 30.3,40.4) << endl;
	system("pause");
}