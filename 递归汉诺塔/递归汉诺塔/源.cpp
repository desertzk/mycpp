#include<iostream>

using namespace std;

void han(int n, char a, char b, char c)
{
	if (n < 1)
	{
		return;
	}
	else{
		han(n - 1, a, c, b);//a���ƶ���b��
		cout << a << "->" << c << endl;
		han(n - 1, b, a, c);//b���ƶ���c��
	}
}

union Myunion{
	int i;
	double db;
	void go(){

	}
};

struct Mystruct{
	int i;
	double db;
	void go(){

	}
};

void main()
{
	cout << "union  " << sizeof(Myunion) << "  struct  " << sizeof(Mystruct);

	int n;
	cin >> n;
	cout << "n=" << n << endl;
	han(n, 'a', 'b', 'c');


	system("pause");
}