#include<iostream>
#include<vector>
using namespace std;

struct Teacher{
	char *name;
	int age;
};

void main222()
{
	struct Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	vector<Teacher *> v(0);
	v.push_back(&t1);
	v.push_back(&t2);
	v.push_back(&t3);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i]->age << endl;
	}

	system("pause");
}