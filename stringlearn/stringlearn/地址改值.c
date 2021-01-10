#include<stdio.h>
#include<stdlib.h>

void main(){
	int count = 0;
	int i = 0, j = 0;
	char *p = " abcpiod  ";
	j = strlen(p);
	while (isspace(p[i]) && p[i] != '\0')
		i++;
	while (isspace(p[j]) && j > 0)
		j--;
	count = j - i+1;
	printf("count=%d", count);
	system("pause");
}