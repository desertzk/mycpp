#include<iostream>

using namespace std;

template<int N>
struct data
{
	enum {res=data<N-1>::res+data<N-2>::res};
};

template<>
struct data<1>
{
	enum {res=1};
};

template<>
struct data<2>
{
	enum{res=2};
};

int getdata(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if(n==2)
	{
		return 2;
	}
	else{
		return getdata(n - 1) + getdata(n - 2);
	}
}


void main()
{
	const int myint = 40;
	int num = data<myint>::res;

	cout << num << endl;
	cout << getdata(40) << endl;
	system("pause");
}

//主要思想
//
//利用模板特化机制实现编译期条件选择结构，利用递归模板实现编译期循环结构，模板元程序则由编译器在编译期解释执行。
//
//优劣及适用情况
//
//通过将计算从运行期转移至编译期，在结果程序启动之前做尽可能多的工作，最终获得速度更快的程序。也就是说模板元编程的优势在于：
//
//1.以编译耗时为代价换来卓越的运行期性能（一般用于为性能要求严格的数值计算换取更高的性能）。通常来说，一个有意义的程序的运行次数（或服役时间）总是远远超过编译次数（或编译时间）。
//
//2.提供编译期类型计算，通常这才是模板元编程大放异彩的地方。
//
//模板元编程技术并非都是优点：
//
//1.代码可读性差，以类模板的方式描述算法也许有点抽象。
//
//2.调试困难，元程序执行于编译期，没有用于单步跟踪元程序执行的调试器（用于设置断点、察看数据等）。程序员可做的只能是等待编译过程失败，然后人工破译编译器倾泻到屏幕上的错误信息。
//
//3.编译时间长，通常带有模板元程序的程序生成的代码尺寸要比普通程序的大，
//
//4.可移植性较差，对于模板元编程使用的高级模板特性，不同的编译器的支持度不同。