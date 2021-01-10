#include<stdio.h>
#include<stdlib.h>

void main(){
	char str[4][10] = { "notepad", "calc", "tasklist", "ipconfig" };
	printf("%d\n", sizeof(str));
	char (*p)[10] = str;
	for (int i = 0; i < 4; i++){
		system(*(p+i));//str[i]
	}
	system("pause");

}