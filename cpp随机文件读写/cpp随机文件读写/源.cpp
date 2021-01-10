#include<iostream>
#include<fstream>
using namespace std;

void main1()
{
	ofstream fout("p.txt");
	fout << "dsafdgasgasrg324215324623562" << endl;
	fout.close();
	ifstream fin("p.txt");
	fin.seekg(9, ios::beg);
	char ch;
	while (fin.get(ch))
	{
		cout << ch;
	}
	fin.close();
	system("pause");
}

void main()
{
	ofstream fout("p.txt");
	fout << "dsafdgasgasrg324215324623562" << endl;
	fout.close();
	ofstream fos("p.txt",ios::in|ios::out);
	char str[] = "11111111111";
	fos.seekp(9, ios::beg);
	fos << str;
	fos.close();
	//ifstream fin("p.txt");
	ifstream fin("p.txt");
	char ch;
	while (fin.get(ch))
	{
		cout << ch;
	}
	fin.close();
	system("pause");
}