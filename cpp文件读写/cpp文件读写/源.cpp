#include<iostream>
#include<fstream>

using namespace std;

void main1()
{
	ifstream fin;
	fin.open("1.txt");
	char str[128] = { 0 };
	for (int i = 0; i < 4; i++){
		fin.getline(str, sizeof(str));
		cout << str << endl;
	}
	fin.close();

}

void main3()
{
	//fstream fio("2.txt", ios::in | ios::out);
	//fio << "11111111111" << endl;
	//fio << "22222222222" << endl;
	//fio << "33333333334" << endl;
	//fio << "4444444444444" << endl;
	//fio.seekg(ios::beg);
	//
	//for (int i = 0; i < 4; i++){
	//	char str[128] = { 0 };
	//	fio.getline(str, sizeof(str));
	//	cout << str << endl;
	//}
	//fio.close();

	fstream fio("4.txt", ios_base::out);
	//fio << "锄禾日当午" << endl;//写入文件
	//fio << "地雷买下土" << endl;//写入文件
	//fio << "谭胜来跳舞" << endl;//写入文件
	//fio << "炸成250" << endl;//写入文件
	
	fio.write("锄禾日当午",5);
	fio.flush();
	//fio.seekg(ios::beg);//文件指针  ios::beg开始

	//for (int i = 0; i < 4; i++)
	//{
	//	char str[50] = { 0 };
	//	fio.getline(str, 50);
	//	cout << str << endl;
	//}
	fio.close();



	cin.get();
}

void main4()
{
	ofstream fout;
	fout.open("1.txt");
	fout << "sdfagasrtueoriutewot892475298492"<<endl;
	fout << "wot892475298492" << endl;
	fout << "sdfagasrtue2475298492" << endl;
	fout << "sdfagasrtueoriutewot8" << endl;
	fout.close();

	ifstream fin;
	fin.open("1.txt");
	char str[128] = { 0 };
	//while (fin.getline(str, sizeof(str))
	fin >> str;
	cout << str;
	fin.close();

	main1();
	//main2();
	system("pause");
}

void main5()
{
	ifstream fin("1.txt");
	ofstream fout("10.txt");
	if (!fin || !fout)
	{
		cout << "ofstream error";

	}/**/
	char ch=0;
	while(fin.get(ch))
	{
		//char ch = fin.get();
		fout.put(ch);
	}

	fin.close();
	fout.close();
	cout << "copy ok";
	//fout.open("/");
	cin.get();
}

void main()
{
	ofstream fout("10.txt",ios::app);
	fout << "222222222222";
	fout.close();
}