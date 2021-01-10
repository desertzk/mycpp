#include<iostream>
#include<functional>

using namespace std;
//函数包装器 T函数类型 F是函数
template<typename T,typename F>
T run(T v, F f)
{
	static int count = 0;
	count++;
	cout << count << endl;
	return f(v);
}

template<typename T,typename T2, typename F>
T run(T v, T2 v2, F f)
{
	
	return f(v,v2);
}



//template<typename T,typename...Args>
//void showall(T value, Args...args)
//{
//	cout << value << endl;
//	//for ()
//	showall(value,args...);
//	
//}


void main()
{
	double db = 12.9;
	int i = 6;
	function < double(double)> fun1 = [](double u){
		return u * 2; 
	};
	function < double(double)> fun2 = [](double u){
		return u * u;
	};

	function < double(double,int)> fun3 = [](double u,int u2){
		return u * u2;
	};
	cout << run(db, fun1) << endl;
	cout << run(db, fun2) << endl;
	cout << run(db,i, fun3) << endl;

	cout << "通用函数可变参数模板" << endl;
	//showall(i);
	

	int arr[3] = { 1, 2, 3 };
	
	system("pause");
}