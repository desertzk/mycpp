#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ZSting
{
	char *p;
	int reallen;

}zstring;

void init(zstring *string);

void initwithlen(zstring *string,int len);

void initwithstring(zstring *string,char *copystring);

void printfstring(zstring *string);

void backaddchar(zstring *string, char c);

void backaddstring(zstring *string, char *str); 

char * findfirstchar(zstring *string, char ch);

int deletefirstchar(zstring *string, char ch);

int deletefirststring(zstring *string, char * const str);

void addchar(zstring *string, char c, int pos);

void addstring(zstring *string, char *str, int pos);


