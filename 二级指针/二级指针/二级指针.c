#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sort(char arr[10][30], int arrNum)
{
	if (arr == NULL || arrNum <= 0)
	{
		return -1;
	}
	for (int i = 0; i < arrNum; i++){
		for (int j = i + 1; j < arrNum; j++){
			if (strcmp(arr[i], arr[j])>0)
			{
				char buf[30] = {0};
				strcpy(buf, arr[j]);
				strcpy(arr[j], arr[i]);
				strcpy(arr[i], buf);
			}
		}
	}
	return 0;
}

void main(){
	char myArray[10][30] = { "ccccc", "aaaaa", "bbbb", "1111" };

	for (int i = 0; i < 10; i++){
		printf("%s", *(myArray + i));
	}
	system("pause");
}