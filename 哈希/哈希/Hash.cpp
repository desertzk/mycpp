#include "Hash.h"

template<class T>
Hash<T>::Hash()
{
	this->num = 10;
	this->p = new hashnode<T>[this->num];
}

template<class T>
Hash<T>::~Hash()
{
	delete[] p;
}

template<class T>
int Hash<T>::hashFunc(int key)
{
	return key % num;
}

template<class T>
void Hash<T>::init(T *pt,int size)
{
	for (int i = 0; i < size; i++)
	{
		p[i].key = i;
		p[i].t = pt[i];
		p[i].cn = 0;
	}
	
}

template<class T>
bool Hash<T>::isin(int key,T t)
{
	int res = hashFunc(key);
	if ((*(p + res)).t== t)
	//if (p[res].t == t)
	{
		return true;
	}
	else{
		return false;
	}
}
template<class T>
hashnode<T> * Hash<T>::find(int key)
{
	return p+key;
}
 
