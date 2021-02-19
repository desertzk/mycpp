#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>


using namespace std;
//����ʱ��ܳ���������������
unsigned long GetResult(unsigned long a, unsigned long b) {
	for (int x = 1; x < INT_MAX; x++) {
		unsigned long tmp = pow(a, x);
		if (tmp % b == 1)
			return x;
	}
	return 0;


}


//bing ������������ȡģ����
unsigned long GetResult1(unsigned long a, unsigned long b) {
	int i = (a % b);  //i��������ÿ������ʱҪ�˵�����
	
	for (int x = 1; x < INT_MAX; x++) {
		unsigned long tmp = pow(i, x);
		if (tmp % b == 1)
			return x;
	}
	
	return 0;
}

int fast_pow(int a, int b, int c)
{
	int ans = 1;   ///��¼���
	a = a % c;   ///Ԥ����ʹ��a����c�����ݷ�Χ֮��
	while (b != 0)
	{
		if (b & 1)///����
		{
			ans = (ans * a) % c;///����ָ��Ϊ������Ӱ��
		}
		b >>= 1;    ///�����Ƶ���λ����,���ϵı���b�Ķ�����λ
		a = (a * a) % c;   ///���ϵļӱ�
	}
	return ans;
}
//�������� �������ǰٶȳ���
unsigned long GetResult2(unsigned long a, unsigned long b) {
	for (int x = 1; x < INT_MAX; x++) {
		if (fast_pow(a, x, b) == 1)
			return x;
	}
	return 0;
}


void main()
{
	cout << GetResult2(3, 19) << endl;
	cout << GetResult1(3, 19) << endl;
	cout<<GetResult(3, 19)<<endl;


}