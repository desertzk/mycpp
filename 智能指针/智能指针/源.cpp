#include<iostream>
#include<memory>
using namespace std;

void main()
{
	 
	for (int i = 0; i < 10000; i++)
	{
		double *p = new double;
		auto_ptr<double> autop(p);//����ָ��98
	}
	for (int i = 0; i < 10000; i++)
	{
		unique_ptr<double> pdb(new double);//����ָ��11
	}

	system("pause");
}