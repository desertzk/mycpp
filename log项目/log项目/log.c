#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void writelog(const char *log)
{
	time_t tDate;
	struct tm *eventTime;
	time(&tDate);
	eventTime = localtime(&tDate);
	int year = eventTime->tm_year + 1900;
	int month = eventTime->tm_mon + 1;
	int day = eventTime->tm_mday;
	int hour = eventTime->tm_hour;
	int minute = eventTime->tm_min;
	int second = eventTime->tm_sec;
	char sDate[20];

	sprintf(sDate, "%04d-%02d-%02d %02d:%02d:%02d", year, month, day, hour, minute, second);
	char s[512];
	sprintf(s, "%s  %s", sDate, log);

	FILE *fp = fopen("log.txt", "a+");
	if (fp == NULL){
		printf(" write log error %s", strerror(errno));
	}
	else{
		fputs(s, fp);
		fclose(fp);
	}



}

void main(){
	char buf[512];
	memset(buf, 0, sizeof(buf));
	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);
	writelog("dfasdgasdhahahahahahahha dasgdsaodfi,fngdcvsdfjn");
	system("pause");
}