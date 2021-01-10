#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>
//ÊÊÓÃÓÚlinux windows²»¼æÈÝ
void main(){
	char buf[128];
	memset(buf, 0, sizeof(buf));
	getcwd(buf, sizeof(buf));
	DIR *dp;
	struct dirent *dirp;
	dp = opendir(buf);
	if (dp == NULL)
	{
		printf("error is %s\n", strerror(errno));
		return 1;
	}

	while (dirp = readdir(dp))
	{
		printf("%s\n", dirp->d_name);
	}
}