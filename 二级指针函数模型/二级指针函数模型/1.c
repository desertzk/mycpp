#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int spitstr(char *str, char *sign){
	char *sev = str;
	char *recordp = str;
	if (str == NULL||sign == NULL)
	{
		return -1;
	}

	for (int i = 0; *(str+i) != '\0'; i++){
		printf("%c \n", str[i]);
	}

	for (; *sev != '\0'; recordp++){
		char dstbuf[100] = {0};
		recordp = strstr(sev, sign);
		int count = recordp - sev;
		char *result = memcpy(dstbuf, sev, count);

		printf("%s \n", dstbuf);
		sev+=count+1;
	}
}

void main(){
	char *p = "abcdef,afdsac,eeee,bbb,ert,ytt,";
	char *sign = ",";
	spitstr(p, sign);
	system("pause");
}