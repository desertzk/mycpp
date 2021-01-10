#include<iostream>

using namespace std;

void *operator new(size_t size)
{
	if (size <= 0)
	return 0;

	void *p = malloc(size);
	return p;
}

void *operator new[](size_t size)
{
	cout << "new[]" << endl;
	return operator new(size);//每个对象挨个调用已 
}

void operator delete(void *p)
{
	//if (p)
	free(p);
}

void operator delete[](void *p)
{
	cout << "delete[]" << endl;
	return operator delete(p);
}

class Myclass{
	int i;
	char * name;
public:
	Myclass(){
		cout << "myclass create" << endl;
	}
	~Myclass(){
		cout << "myclass destory" << endl;
	}
};

void main()
{
	Myclass *p = new Myclass[5];
	delete[]p;
	system("pause");
}