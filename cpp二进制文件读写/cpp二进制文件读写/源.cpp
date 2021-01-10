#include<iostream>
#include<fstream>
using namespace std;
//按字节的方式，文件加密解密都要用到它
void main1()
{
	ofstream fos("D:/inst1111111111.exe",ios::binary);
	ifstream fin("D:/inst.exe", ios::binary);
	if (!fos || !fin)
	{
		cout << "open err" << endl;
		return;
	}

	char ch = 0;
	while (fos&&fin.get(ch))
	{
		fos.put(ch);
	}


	fin.close();
	fos.close();
	system("pause");
}


struct MyStruct
{
	int i;
	double db;

};

void main()
{

	ofstream fout("big.txt", ios::binary);
	MyStruct ss[5] = { { 1, 1.1 }, { 2, 2.2 }, { 3, 3.3 }, { 4, 4.4 }, { 5, 5.5 } };
	fout.write((char *)ss, sizeof(MyStruct)* 5);
	fout.close();

	ifstream fin("big.txt", ios::binary);
	MyStruct *p = new MyStruct[5];//动态分配内存
	fin.read((char *)p, sizeof(MyStruct)* 5);
	fin.close();

	for (int i = 0; i < 5; i++)
	{
		std::cout << p[i].i << " " << p[i].db << std::endl;
	}

	cin.get();






}