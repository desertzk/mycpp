#include<iostream>
#define MAX_SIZE 8

using namespace std;

int cnt = 0, row = 2, arr[MAX_SIZE + 2] = { -1,1,1 };
void print()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (arr[i] == j + 1)
			{
				cout << "1";
			}
			else{
				cout << "0";
			}
			
		}
		cout << endl;
		//cout << endl;
	}
}

bool judge()
{
	int i;
	for (i = 1; i < row; i++)
	{
		if (arr[i] == arr[row] || row - i == arr[row] - arr[i] || row - i == arr[i] - arr[row])
			return true;//error
	}
	return false;
}

void pop()
{
	if (arr[row] < MAX_SIZE)
		arr[row]++;
	else{
		row--;
		pop();
	}
}

void work()
{
	
	if (judge())
	{
		pop();
	}
	else
	{
		arr[++row]=1;
		if (row > MAX_SIZE)
		{
			print();
			return;
		}
	}
	work();
}

void main()
{
	//arr[row] = 1;
	work();
	system("pause");
}