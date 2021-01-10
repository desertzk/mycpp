#include<stdio.h>
#include<stdlib.h>
#include"cltsocket.h"

int func(unsigned char*inData, int inDataLen, unsigned char **outData, int *outDataLen, void *Ref, int RefLen){
	printf("i am callback");
}

void main(){
	int ret = 0;
	void *handle = NULL;
	ret = cltSocketInit(&handle);
	if (ret != 1){
		printf("error");
	}
	char *buf = "sdfafdsadf";
	int len = strlen(buf);

	clitSocket_SetEncFunc(handle, func, NULL, 0);


	int re = cltSocketSend(handle, buf, len);
	//int size = 100;
	int size = 0;
	char bufre[100] = { 0 };




	int count = cltSocketRev(handle, bufre, &size);

	printf("%s", bufre);
	printf("\n%d", size);


	system("pause");
}