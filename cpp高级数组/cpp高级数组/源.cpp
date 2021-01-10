#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

void main1()
{
	vector<int> myvector;
	myvector.push_back(11);
	myvector.push_back(22);
	myvector.push_back(33);
	int res=0;
	//lambda表达式
	for_each(myvector.begin(), myvector.end(), [&res](int x){res += x; });
	cout << res << endl;
	system("pause");
}


void main2()
{
	vector<int> *pvector = new vector<int>();
	pvector->push_back(11);
	pvector->push_back(21);
	pvector->push_back(31);
	pvector->push_back(41);
	pvector->push_back(51);
	delete pvector;
	system("pause");
}


void main(){
	int int1 = 10;
	double double1 = 99.9;
	char ch = 'A';
	char *str = "hellochina";
	//多元数组元祖
	tuple<int, double, char, const char *> mytuple(int1 ,double1, ch, str);
	/*for (int i = 0; i < 4; i++)
	{
		auto data = mytuple.
	}*/
	auto data1 = get<0>(mytuple);
}