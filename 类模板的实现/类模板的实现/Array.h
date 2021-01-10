#pragma once
template<class T>
class Array
{
public:
	Array()
	{
		this->pt = nullptr;
		this->count = 0;
	}
	Array(int length)
	{
		this->pt = new T[length];
		this->count = length;
	}
	~Array()
	{
		delete[] this->pt;
	}
	int size()
	{
		return this->count;
	}
	T get(int i)
	{
		if (i >= count || i < 0)
		{
			return nullptr;
		}
		return *(pt + i);
	}
	void set(T data,int i)
	{
		if (i >= count || i < 0)
		{
			return;
		}
		*(pt + i) = data;
	}

	T operator [](int num)
	{
		return this->get(num);
	}

private:
	T *pt;
	int count;
};

