#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


void main(){
	int i = 0;
	int sum = 0;
	for (i = 0; i < 100; i++)
	{
		if (i % 2)
			sum += i;
	}
	printf("%d", sum);
}

/*#define PI 3.1415926
float r = 0;
float h = 0;
printf("please entry r:\n");
scanf("%f",&r);
printf("please entry h:\n");
scanf("%f", &h);
float V = PI*r*r*h / 3;
printf("V is %f\n",V);*/


/*int score = 0;
while (1)
{
printf("please entry  score:\n");
scanf("%d", &score);
if (score >= 80)
{
printf("A\n");
}
else if (score > 60 && score < 80)
{
printf("B\n");
}
else
{
printf("C\n");
}
}*/