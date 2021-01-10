#include<iostream>
#include<boost\array.hpp>
#include<algorithm>
#include<vector>
using namespace std;
using namespace boost;//有了这个下面就可以不用boost::



class add
{
public:
	void operator()(int i)
	{
		cout << i +1<< endl;
	}
};


void main()
{
	//cout<<(256 >> 1) % 256<<endl;
	boost::array<int, 5> barray = { 1, 2, 3, 4, 5 };
	barray[0] = 10;
	barray.at(4)=20;
	int *p = barray.data();//存储数组指针
	for (int i = 0; i < barray.size(); i++)
	{
		cout << barray[i] << "  " << p[i] << endl;
	}



	vector<int> myv;
	myv.push_back(11);
	myv.push_back(23);
	myv.push_back(34);

	for_each(myv.begin(), myv.end(), add());
	system("pause");
}