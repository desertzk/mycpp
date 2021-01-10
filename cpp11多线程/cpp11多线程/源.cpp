#include<iostream>
#include<thread>
#include<string>

using namespace std;

void helloworld()
{
	cout << "hello dhq" << endl;
}

void hellozk()
{
	cout << "hello zk" << endl;
}

void hellozz()
{
	cout << "hello zz" << endl;
}

void run(int num)
{
	cout << "good " << num << endl;
}

void main()
{
	thread t1(helloworld);
	thread t2(hellozk);
	thread t3(hellozz);

	thread *p[10];
	for (int i = 0; i < 10; i++)
	{
		p[i]=new thread(run, i);
		//p[i]->join();//等待
		//p[i]->detach();//脱离当前主线程自由执行
	}
	system("pause");
}