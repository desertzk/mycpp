#pragma once
#include"hashnode.h"

template<class T>
class Hash
{
public:
	hashnode<T> *p;
	int num;
	Hash();
	~Hash();
	void init(T *pt, int size);
	int hashFunc(int key);
	bool isin(int key, T t);
	hashnode<T> * find(int key);
};

