#include<iostream>
#include"Array.h"
#include<string>
using namespace std;

void main()
{
	string str = "zk";
	Array<string> myarr(5);//= { "calc", "notepad", "hehe", "tasklist", "dfas" };
	for (int i = 0; i < myarr.size(); i++)
	{
		str += "z";
		myarr.set(str, i);
		std::cout << myarr[i].c_str() << endl;
	}
	/*string str1 = "dafsadfasgd";
	cout << str1 << endl;*/
	system("pause");
}