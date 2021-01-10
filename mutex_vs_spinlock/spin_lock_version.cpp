#include<string>
#include<iostream>
#include<thread>
#include<cstdlib>
#include"lock_free_queue.h"
#include <mutex>
#include <chrono>



using namespace std;
//×ÔÐýËø°æ±¾
//namespace optimistic {

struct A_struct
{
	int a;
};

struct B_struct
{
	double data[5];
};


LockFreeArrayQueue<A_struct> q_a(500000);


LockFreeArrayQueue<B_struct> q_b(100000);


int random_generator() {
	while (true) {
		A_struct a_s;
		//random generator 1-100
		a_s.a = rand() % 100 + 1;
		//cout << "q_a push" << q_a.size() << endl;
		//lock_guard<std::mutex> lock(mutx_a);
		q_a.push(a_s);
	}

}

int random_generator_double() {
	while (true) {
		B_struct b_s;
		for (int i = 0; i < 5; ++i) {
			b_s.data[i] = ((double)rand() / (RAND_MAX));
		}
		//cout << "q_b push" << q_b.size() << endl;
		//lock_guard<std::mutex> lock(mutx_b);
		q_b.push(b_s);
	}
}


long long calc_num = 0;
double sum_b_all;

double sum_struct_b()
{
	A_struct a_s = { 0 };
	B_struct b_s = { 0 };
	while (true) {
		if (!q_b.isEmpty())
		{
			//cout << "q_b pop"<< q_b.size() << endl;
			//lock_guard<std::mutex> lock(mutx_b);
			//b_s = q_b.front();
			q_b.pop(b_s);
		}

		if (!q_a.isEmpty())
		{
			//cout << "q_a pop" << q_a.size()<< endl;
			//lock_guard<std::mutex> lock(mutx_a);
			//a_s = q_a.front();
			q_a.pop(a_s);
		}

		double sum_b = 0;
		for (int i = 0; i < 5; ++i)
		{
			sum_b += b_s.data[i];
		}

		if (a_s.a % 2 == 0) {
			sum_b_all += sum_b;
		}
		else {
			sum_b_all -= sum_b;
		}

		++calc_num;
	}


}




static void print_number() {
	while (true)
	{
		std::this_thread::sleep_for(1s);


		cout << sum_b_all << endl;
		cout << calc_num << endl;
	}

}




int main()
{

	thread A(random_generator);
	thread B(random_generator_double);
	thread C(sum_struct_b);
	thread D(print_number);

	A.join();
	B.join();
	C.join();
	D.join();
	return 0;
}
//}
