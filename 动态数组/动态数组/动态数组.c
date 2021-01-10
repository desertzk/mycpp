#include"动态数组.h"
struct data data1;

void init(struct data *pdata)
{
	pdata->p = NULL;
	pdata->len = 0;
	pdata->stat = 0;
	pdata->reallen = 0;
}

//add a num
void add(struct data *pdata, int num)
{
	if (pdata->p == NULL)
	{
		pdata->p = (int *)malloc(sizeof(int));
		pdata->len += 1;
		pdata->p[pdata->len - 1] = num;
		pdata->stat = 0;
	}
	else
	{
		pdata->p = (int *)realloc(pdata->p, (pdata->len + 1)*sizeof(int));
		pdata->len += 1;
		pdata->p[pdata->len - 1] = num;
		pdata->stat = 0;
	}
	pdata->reallen += 1;
}

//add nums 
void addarray(struct data *pdata, int *pnum, int n)
{
	if (pdata->p == NULL)
	{
		pdata->p = (int *)malloc(sizeof(int)*n);
		pdata->len += n;
		for (int i = 0; i < n; i++)
		{
			pdata->p[i] = pnum[i];
		}

	}
	else
	{
		pdata->p = (int *)realloc(pdata->p, (pdata->len + n)*sizeof(int));

		for(size_t i = 0; i < n; i++)
		{
			pdata->p[i + pdata->len] = pnum[i];
		}
		pdata->len += n;
	}
	pdata->stat = 0;
}

void print(struct data *pdata)
{
	for (size_t i = 0; i < pdata->len; i++)
	{
		printf("%d\n", *(pdata->p+i));
	}
}

void destory(struct data *pdata)
{
	if (pdata->p != NULL)
	{
		free(pdata->p);
		pdata->len = 0;
		pdata->p = NULL;
		pdata->reallen = 0;
	}
}

void sort(struct data *pdata, int order)//order=0,从小到大
{
	if (order == 0)
	{
		for (size_t i = 0; i < pdata->len-1; i++)
		{
			for (int j = 0; j < pdata->len - i-1; j++)
			{
				if (pdata->p[j]>pdata->p[j + 1])
				{
					pdata->p[j] = pdata->p[j] ^ pdata->p[j + 1];
					pdata->p[j + 1] = pdata->p[j] ^ pdata->p[j + 1];
					pdata->p[j] = pdata->p[j] ^ pdata->p[j + 1];
				}
			}
		}
		pdata->stat = 1;
	}
	else
	{
		for (size_t i = 0; i < pdata->len - 1; i++)
		{
			for (int j = 0; j < pdata->len - i-1; j++)
			{
				if (pdata->p[j]<pdata->p[j + 1])
				{
					pdata->p[j] = pdata->p[j] ^ pdata->p[j + 1];
					pdata->p[j + 1] = pdata->p[j] ^ pdata->p[j + 1];
					pdata->p[j] = pdata->p[j] ^ pdata->p[j + 1];
				}
			}
		}
		pdata->stat = 2;
	}
	
}


void deleteone(struct data *pdata, int num)
{
	int *p = finddata(pdata, num);
	if (p == NULL)
	{
		return NULL;
	}
	else{
		int current = p - pdata->p;
		for (int i = current; i < pdata->len - 1; i++)
		{
			pdata->p[i] = pdata->p[i + 1];
		}
		pdata->len -= 1;
	}

}

int *finddata(struct data *pdata, int num)
{
	if (pdata->stat == 0)
	{
		for (int i = 0; i < pdata->len; i++)
		{
			if (num == pdata->p[i])
			{
				return &pdata->p[i];
			}
		}
	}
	else{
		int up = 0;
		int down = pdata->len - 1;
		while (up <=down)
		{
			int middle = (up + down) / 2;
			if (pdata->p[middle] == num)
			{
				return &pdata->p[middle];
			}
			else if (pdata->p[middle] >num)
			{
				down = middle - 1;
			}
			else if(pdata->p[middle] <num)
			{
				up = middle + 1;
				
			}
		}
		return NULL;
	}
}

void insert(struct data *pdata, int num, int insertnum)//前插
{
	int *p = finddata(pdata, num);
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		
	}
}

void main(){
	int a[10] = { 1, 2, 31, 14, 5, 6, 7, 8, 9, 0 };
	init(&data1);
	add(&data1, 18);
	add(&data1, 11);
	add(&data1, 17);
	add(&data1, 15);
	add(&data1, 20);
	addarray(&data1, a, 10);
	deleteone(&data1, 20);
	sort(&data1, 0);
	print(&data1);

	int *pfind = finddata(&data1, 31);
	printf("\n%d,%p", *pfind, pfind);

	destory(&data1);

	//addarray(&data1, a, 10);
	//print(&data1);
	system("pause");
}