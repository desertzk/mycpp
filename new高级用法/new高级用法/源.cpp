#include<iostream>

using namespace std;
int N = 5;
const int bufsize = 512;
char *buf[bufsize] = { 0 };
void main()
{
	double *p1, *p2;
	p1 = new double[N];//
	p2 = new (buf)double[N];//ָ����������ڴ�,������֮ǰ����buf���ڴ�
	for (int i = 0; i < N; i++)
	{
		p1[i] = p2[i] = i + 10.8;
		cout << &p1[i] << "   " << &p2[i] << endl;
	}

	system("pause");
}