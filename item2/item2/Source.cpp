#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>


using namespace std;
//运行时间很长而且数大有问题
unsigned long GetResult(unsigned long a, unsigned long b) {
	for (int x = 1; x < INT_MAX; x++) {
		unsigned long tmp = pow(a, x);
		if (tmp % b == 1)
			return x;
	}
	return 0;


}


//bing 后发现是幂运算取模问题
unsigned long GetResult1(unsigned long a, unsigned long b) {
	int i = (a % b);  //i代表我们每次运算时要乘的数字
	
	for (int x = 1; x < INT_MAX; x++) {
		unsigned long tmp = pow(i, x);
		if (tmp % b == 1)
			return x;
	}
	
	return 0;
}

int fast_pow(int a, int b, int c)
{
	int ans = 1;   ///记录结果
	a = a % c;   ///预处理，使得a处于c的数据范围之下
	while (b != 0)
	{
		if (b & 1)///奇数
		{
			ans = (ans * a) % c;///消除指数为奇数的影响
		}
		b >>= 1;    ///二进制的移位操作,不断的遍历b的二进制位
		a = (a * a) % c;   ///不断的加倍
	}
	return ans;
}
//这个答案最快 不过我是百度抄的
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