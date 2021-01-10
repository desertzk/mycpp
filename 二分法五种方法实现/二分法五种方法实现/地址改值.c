#include<stdio.h>
#include<stdlib.h>

int birnarysearch(int *arr,int size,int find)
{
	int min = 0;
	int max = size;
	int now = max / 2;
	for (int i = 0; i < size; i++)
	{
		if (arr[now]>find)
		{
			max = now;
			now = (max + min) / 2;
		}
		else if (arr[now] < find)
		{
			min = now;
			now = (min + max) / 2;
			
		}
		else if (arr[now] == find){
			return now;
		}
	}
}

void main(){
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printf("%d",birnarysearch(arr, 10, 8));
	system("pause");
}