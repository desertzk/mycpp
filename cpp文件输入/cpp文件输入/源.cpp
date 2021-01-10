#include<iostream>
#include<sstream>
using namespace std;

void main1()
{
	char ch[30] = { 0 };
	cin >> ch;
	cout << ch;
	cout.put('a');
	char str[80] = { 0 };
	cin.get();//读取回车
	cin.getline(str,80);
	cout << str<<endl;
	cout.write(str, 10);
	system("pause");
}

void main2()
{
	string mystring("china google microsoft 12.9 123 A");
	string str1, str2, str3;
	double db;
	int num;
	char ch;

	istringstream input(mystring);//创建一个字符串扫描流
	input >> str1 >> str2 >> str3 >> db >> num >> ch;
	cout << str1 << str2 << str3 << db << num << ch;



	cin.get();
}

void main()
{
	string mystring("china#google#microsoft#12.9#123#A");
	mystring.replace("#", " ");
	string str1, str2, str3;
	double db;
	int num;
	char ch;

	istringstream input(mystring);//创建一个字符串扫描流
	input >> str1 >> str2 >> str3 >> db >> num >> ch;
	cout << str1 << str2 << str3 << db << num << ch;



	cin.get();
}