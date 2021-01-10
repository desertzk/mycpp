#include<stdio.h>
#include<stdlib.h>
//fangfa1

void swap(int array[], int i, int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int partition(int array[],int low,int high){
	int pv = array[low];
	while (low < high){
		while ((low < high) && (array[high] >= pv)){
			high--;
		}
		swap(array, low, high);
		while ((low < high) && (array[low] <= pv)){
			low++;
		}
		swap(array, low, high);
	}
	return low; 
}



void QSort(int array[], int low, int high){
	if (low < high){
		int pivot = partition(array, low, high);
		QSort(array, low, pivot - 1);
		QSort(array, pivot + 1, high);
	}
}


//fangfa2
void change(int *pi, int *pj)
{
	int temp = *pi;
	*pi = *pj;
	*pj = temp;

}

void show(int *p,int n)
{
	for (int i = 0; i < n; i++)
	{
		//for ()
		printf("%5d", p[i]);
	}
	printf("\n");
}


void quicksort(int *p,int left,int right)
{
	int i = left;
	int j = right + 1; 
	//int a[10] = { 10, 9, 20, 8, 38, 49, 11, 15, 5, 18 };
	if (i < j)//ѭ���Ŀ�������
	{
		do{//����
			do{
				i++;
			} while (p[i] < p[left] && i <= right);//ͳ�Ƶ�һ��С��������
			
			do{
				j--;
			} while (p[j] >= p[left] && j>left);//ͳ�Ƶ�һ�����ڵ���
			printf("p[%d]=%d,p[%d]=%d\n", i, p[i], j, p[j]);
			if (i < j)
			{
				change(&p[i], &p[j]);
			}	
			show(p, 12);
		} while (i < j);//�ȷָ��С�Ķ�����ǰ����

		
		change(&p[left], &p[j]);//j��Ϊ�ָ��
		printf("\n\n\n");
		show(p, 12);
		quicksort(p, left, j - 1);//�ָ����
		quicksort(p, j + 1, right);//�ָ��ұ�
	}
}



void main(){
	int a[12] = { 10, 9, 20, 8, 38, 49, 11, 15, 5, 18,7,2 };
	show(a, 12);
	quicksort(a, 0, 12 - 1);

	system("pause");
}