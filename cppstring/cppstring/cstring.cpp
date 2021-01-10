#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

vector<char *>* splite(char *str, char* fstr,char ***arrstr,int *strnum)//省内存法
{
	char* copystr = (char *)malloc(strlen(str) + 1);
	memset(copystr,0, sizeof(copystr));
	strcpy(copystr,str);//最后还原
	char* i = str;//前指针
	//char **tmparr;
	vector<char *> *tmparr = new vector<char *>();
	char* chnext = 0;
	for (; chnext = strstr(i, fstr);)
	{
		//if (chnext == 0)//第一个为找到的
		//	continue;
		int size = chnext-i + 1;//string  end \0 so +1
		char *tmpstr =(char *) calloc(size, sizeof(char));
		
		memcpy_s(tmpstr, size - 1, i, size - 1);
		tmparr->push_back(tmpstr);
		//int chnext = strstr(str, fstr);
		i = chnext + strlen(fstr);
	}
	int size=str + strlen(str) - i + 1;//last
	char *tmpstr = (char *)calloc(size, sizeof(char));

	memcpy_s(tmpstr, size - 1, i, size - 1);
	tmparr->push_back(tmpstr);
	str = copystr;
	return tmparr;
	
}

int main()
{
	
	char *str = ",,dga,sfga,sfda";
	
	vector<char *>* v = splite(str, ",", NULL, NULL);
	vector<char *>::iterator it = v->begin();
	while (it != v->end())
	{
		printf("%s\n", *it++);
	}
	system("pause");
}