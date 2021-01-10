#include<stdio.h>
#include<stdlib.h>
#define MAXTOKEN 100
enum{
	NAME,
	PARENS,
	BRACKETS
};

void dcl(void);
void dirdcl(void);

int gettoken();
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1024];




void main(){
	while (gettoken() != EOF)
	{
		strcpy(datatype, token);
		out[0] = 0;
		dcl();
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
	system("pause");
}

int gettoken()
{
	int c, getch();
	void ungetch(int);
	char *p = token;
	while ((c = getch()) == ' ' || c == '\t');//remove space tab
	if (c == '('){
		if ((c = getch()) == ')'){
			strcpy(token, "()");
			return tokentype = PARENS;//means parentheses
		}
		else{
			ungetch(c);
			return tokentype = '(';
		}
	}
	else if (c == '['){
		for (*p++ = c; (*p++ = getch()) != ']';)
			;
		*p=0;
		return tokentype = BRACKETS;
	}
	else if (isalpha(c)){//�ж��ַ�ch�Ƿ�ΪӢ����ĸ����ΪСд��ĸ������2����Ϊ��д��ĸ������1
		for (*p++ = c; isalnum(c = getch());)
			*p++ = c;
		*p = 0;
		ungetch(c);
		return tokentype = NAME;
	}
else
	return tokentype = c;

}
void dcl()
{
	int ns;
	for (ns = 0; gettoken() == '*';)
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, "pointer to");
}

void dirdcl()
{
	int type;
	if (tokentype == '(')
	{
		dcl();
		if (tokentype != ')')
			printf("error : missing )\n");
	}
	else if (tokentype == NAME)
		strcpy(name, token);
	else
		printf("error: excepted name or (dcl)\n");
	while ((type=gettoken())==PARENS||type==BRACKETS)
	if (type == PARENS)
		strcat(out, " function returning");
	else{
		strcat(out, " array");
		strcat(out, token);
		strcat(out, " of");
	}
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp= 0;
int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("too many characters\n");
	else
		buf[bufp++] = c;
}