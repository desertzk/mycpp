#define _CRT_SECURE_NO_WARNINGS
#include"mystring.h"

void init(zstring *string)
{
	string->p = NULL;
	string->reallen = 0;
}

void initwithlen(zstring *string, int len)
{
	string->p = (char *)calloc(len,sizeof(char));//equal malloc +memset
	string->reallen = len;
}

void initwithstring(zstring *string, char *copystring)
{
	int len = strlen(copystring);
	string->p = (char *)calloc(len + 1, sizeof(char));
	strcpy(string->p,copystring);
	string->reallen = len + 1;
}

void printfstring(zstring *string)
{
	printf("%s\n", string->p);
}

void backaddchar(zstring *string, char c)
{
	
	if (strlen(string->p) + 1 >= string->reallen)
	{
		string->p = realloc(string->p, strlen(string->p) + 1);
		string->reallen++;
		string->p[string->reallen - 2] = c;
		string->p[string->reallen - 1] = '\0';
	}
	else{
		int nowlen = strlen(string->p);//求出当前长度
		string->p[nowlen] = c;
		string->p[nowlen + 1] = '\0';
	}
}

void backaddstring(zstring *string, char * const str)
{
	int nowzstringlen = strlen(string->p);
	int addstringlen = strlen(str);
	if (nowzstringlen + addstringlen+ 1 > string->reallen)
	{
		int need = nowzstringlen + addstringlen + 1 - string->reallen;
		int oldlen = strlen(string->p);
		//char *old = string->p;
		string->p = (char *)realloc(string->p, string->reallen+need);
		
		string->p[oldlen] = '\0';
		//strcpy(string->p, old);
		strcat(string->p, str);//
		string->reallen = nowzstringlen + addstringlen + 1;
		
	}
	else{
		strcat(string->p, str);//
	}
}

void addchar(zstring *string, char c, int pos)
{
	if (string == NULL)
	{
		return;
	}
	if (strlen(string->p) + 1 == string->reallen)//要从新分配内存
	{
		
	}
	else
	{

	}
}

void addstring(zstring *string, char *str, int pos);

int deletefirstchar(zstring *string, char ch)
{
	char *p = strchr(string->p, ch);//
	if (p == NULL)
	{
		return 0;
	}
	char *pnext = p + 1;
	while (*pnext!='\0')
	{
		*p++ = *pnext++;

	}
	*p = '\0';
	return 1;
}


int deletefirststring(zstring *string, char *str)
{
	char *pres = strstr(string->p, str);
	if (pres == NULL)
	{
		return 0;
	}
	int len = strlen(str);
	char *pnext = pres + len;
	while (*pnext != '\0')
	{
		*pres++ = *pnext++;
		
	}
	*pres = '\0';
}

int getValue(char *key,char *value)
{
	FILE *fpc = fopen("config.txt", "r");
	while (!feof(fpc))
	{
		char buf[64]= { 0 };
		char *line = fgets(buf, sizeof(buf), fpc);
		printf("buf=%p line=%p\n", buf,line);
		//char tmpvalue[64] = { 0 };
		char *tmpvalue=strstr(line, key);
		if (tmpvalue != NULL)
		{
			//char kv[64] = { 0 };
			strcpy(value, (tmpvalue + strlen(key) + 1));
			//printf("%s\n", kv);
			//*value = kv;
			//return value;
		}
		return NULL;
	}
}

	//you must free strvector outside
	char ** strsplite(char *line, char* delimeter, int *count)
	{
		/*char *str = (char *)calloc(strlen(line) + 1, sizeof(char));
		char *freestr = str;
		strcpy(str, line);*/

		char *str=line;
		char *ptr = NULL;
		char **strvector = NULL;
		int tmp = *count=0;
		//*count = 0;
		//int lastsize = 0;
		//int *pl = &lastsize;
		while (ptr = strstr(str, delimeter))
		{
			*ptr = '\0';
			(*count + 1)*(strlen(str) + 1)*sizeof(char);
			strvector = (char **)realloc(strvector, (tmp + 1)*sizeof(char *));
			strvector[tmp] = str;
			//strcpy(strvector[*count], str);
			//*pl++;
			str = ptr+strlen(delimeter);
			tmp++;
		}
		if (*str != '\0')
		{
			strvector = (char **)realloc(strvector, (tmp + 1)*sizeof(char *));
			//strcpy(strvector[*count], str);
			strvector[tmp] = str;
			tmp++;
		}
		//free(freestr);里面不能free要在外面free
		*count = tmp;
		return strvector;
	}



void main(){
	//zstring str;
	//initwithstring(&str,"hehe");
	////backaddchar(&str, 's');
	//backaddstring(&str, "hello");
	//printfstring(&str);
	//deletefirstchar(&str, 'h');
	//printfstring(&str);
	//deletefirststring(&str, "lo");
	//printfstring(&str);



	/*char value[64] = { 0 };
	getValue("url", value);
	printf("kv=%s", value);*/



	char line[100] = "dfasdgnasd**ertertfdg**zzzzzkkkkkkkk";
	int count = 0;
	char **spit=strsplite(line, "**", &count);
	int i = 0;
	for (; i < count; i++)
	{
		printf("%s\n",spit[i]);
	}

	system("pause");
}