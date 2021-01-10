#include "iostream"
#include "algorithm"
#include "cmath"
#include "vector"
using namespace std;

//定义一个老师

//打印上业务数据结构，是上层的事情，stl根本没有必要去关心，
void callbakFunc(int &v)
{
	cout<<v<<endl;
}
int comp(const int &a, const int &b)
{
	return a<b;
}
void main()
{
	vector<int> v(5);
	for (int i=0; i<5; i++)
	{
		v[i] = rand()%10;
	}

	for (int i=0; i<5; i++)
	{
		printf("%d ", v[i]);
	}

	for_each(v.begin(),v.end(), callbakFunc);

	sort(v.begin(),v.end(), comp);

	for (int i=0; i<5; i++)
	{
		printf("%d ", v[i]);
	}


	
	
	system("pause");
}
