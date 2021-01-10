#include<iostream>
#include<thread>
#include<Windows.h>
#include<vector>

using namespace std;
using namespace std::this_thread;

void msg(){
	MessageBoxA(0, "12345", "67890", 0);
}

void main1()
{

	auto n = thread::hardware_concurrency();
	cout << n << endl;
	cout << "thread=" << get_id()<<endl;//获取当前的线程编号
	//for (int i = 0; i < 6; i++){
		thread thr1(msg);
		thread thr2(msg);
		thread thr3(msg);
		thr1.join();
		thr2.join();
		thr3.join();
	//}
	system("pause");
}

void main()
{
	vector<thread *> threads;
	for (int i = 0; i < 10; i++)
	{
		threads.push_back(new thread(msg));
	}
	for (auto th:  threads)
	{
		th->join();
	}
}