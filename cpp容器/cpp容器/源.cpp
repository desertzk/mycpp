#include<iostream>
#include<vector>
#include<array>
#include<tuple>
#include<list>
using namespace std;

void main1()
{
	list<int> mylist;

	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);
	//mylist[1];
	auto ibegin = mylist.begin();//ָ�룬ָ��һ�����������������洢��λ��
	auto iend = mylist.end();
	//list�õ��������б���
	for (; ibegin != iend; ibegin++)
	{
		cout << *ibegin << endl;
		printf("%p,%p\n", ibegin._Ptr, ibegin);//����
	}

	cin.get();


}
//listɾ��
void main()
{
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);
	mylist.push_back(5);
	auto i = mylist.begin();//ɾ��Ԫ�أ������ڵ�������
	//++i;
	//++i;
	//++i;
	//auto i = mylist.end();//end���һ��û��ʵ�壬
	//
	//i--;
	mylist.erase(i);//��ʽ�洢���������±����
	//ֻ���õ����������������ֻ����++��--
	//mylist.clear();���
	auto ibegin = mylist.begin();//ָ�룬ָ��һ�����������������洢��λ��
	auto iend = mylist.end();

	//for (; ibegin != iend; ibegin++)
	//{
	//	if ((*ibegin) == 3)
	//	{
	//		mylist.erase(ibegin);//ɾ��,ɾ����ʱ��������ᷢ��
	//		break;
	//	}
	//	//cout << *ibegin << endl;
	//}
	{
		auto ibegin = mylist.begin();//ָ�룬ָ��һ�����������������洢��λ��
		auto iend = mylist.end();

		for (; ibegin != iend; ibegin++)
		{
			cout << *ibegin << endl;
		}
	}
	cin.get();
}

void main4()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	list<int > mylist(a, a + 5);//���������ʼ����
	//���ݿ�ʼ��ַ�����ݽ�����ַ
	//	mylist(0);
	//mylist[1];ֻ���õ���������
	mylist.push_back(10);
	mylist.push_front(12);
	auto ibegin = mylist.begin();//ָ�룬ָ��һ�����������������洢��λ��
	auto iend = mylist.end();

	for (; ibegin != iend; ibegin++)
	{
		if (*ibegin == 3)
		{
			mylist.insert(ibegin, 30);
			break;//ɾ�����߲��룬���������ᷢ���仯
		}
	}

	mylist.remove(30);//ֱ��һ������������Ԫ����ɾ��

	{
		auto ibegin = mylist.begin();//ָ�룬ָ��һ�����������������洢��λ��
		auto iend = mylist.end();

		for (; ibegin != iend; ibegin++)
		{
			cout << *ibegin << endl;
		}
	}
	cin.get();





}

void main5()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	list<int > mylist(a, a + 5);//���������ʼ����
	auto rb = mylist.rbegin();
	auto re = mylist.rend();
	//ͬʱ�����뷽�����
	for (; rb != re; rb++)
	{
		cout << *rb << endl;
	}

	cin.get();




}

void  main6()
{
	int a[5] = { 1, 2, 3, 104, 5 };
	list<int > mylist1(a, a + 5);//���������ʼ����
	int b[5] = { 11, 122, 33, 44, 55 };
	list<int > mylist2(b, b + 5);//���������ʼ����
	mylist1.sort();
	mylist2.sort();//����


	mylist1.merge(mylist2);//�ϲ�֮ǰ��������



	{
		auto ibegin = mylist1.begin();//ָ�룬ָ��һ�����������������洢��λ��
		auto iend = mylist1.end();

		for (; ibegin != iend; ibegin++)
		{
			cout << *ibegin << endl;
		}
	}
	cout << "\n\n\n";
	{
		auto ibegin = mylist2.begin();//ָ�룬ָ��һ�����������������洢��λ��
		auto iend = mylist2.end();

		for (; ibegin != iend; ibegin++)
		{
			cout << *ibegin << endl;
		}
	}
	cin.get();
}

void main7()
{

	int a[6] = { 1, 2, 98, 2, 5, 98 };
	list<int> mylist1(a, a + 6);//���������ʼ����
	{
		auto ibegin = mylist1.begin();//ָ�룬ָ��һ�����������������洢��λ��
		auto iend = mylist1.end();

		for (; ibegin != iend; ibegin++)
		{
			cout << *ibegin << endl;
		}
	}
	mylist1.sort();
	mylist1.unique();//Ψһ����������
	cout << "\n\n\n";
	{
		auto ibegin = mylist1.begin();//ָ�룬ָ��һ�����������������洢��λ��
		auto iend = mylist1.end();

		for (; ibegin != iend; ibegin++)
		{
			cout << *ibegin << endl;
		}
	}

	cin.get();


}
