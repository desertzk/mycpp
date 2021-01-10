#include<iostream>
#include<set>
#include<map>

using namespace std;

struct strless
{
	bool operator()(const char *str1, const char *str2)//·Âº¯Êı
	{
		return strcmp(str1, str2) < 0;
	}
};


void main1()
{
	set<int> myset;
	myset.insert(10);
	myset.insert(2);
	myset.insert(3);
	myset.insert(40);
	myset.insert(5);
	myset.insert(6);
	myset.insert(7);
	auto ib = myset.begin();
	auto ie = myset.end();
	while (ib != ie)
	{
		cout << *ib++ << endl;
	}
	system("pause");
}

void main2()
{
	
	const char *cmd[] = {"abc","calc","notepad","const"};
	set<const char *, strless> myset(cmd,cmd+4,strless());

	pair<set<const char *>::iterator, bool> p=myset.insert("9876");
	cout << "pair start" << endl;
	cout << *(p.first) << "  " << p.second << endl;


	auto ib = myset.begin();
	auto ie = myset.end();
	for (; ib != ie; ib++)
	{
		cout << *ib << endl;
	}
	set<const char *, strless>::iterator pfind = myset.find("calc");
	cout << *pfind << endl;

	cin.get();
}

void main()
{
	map<const char *, int> mymap;
	mymap["big"] = 5;
	mymap["middle"] = 4;
	mymap["small"] = 3;

	cin.get();
}