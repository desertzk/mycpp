#include<stdio.h>
#include<string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(void){
	int nlines;
	if (nlines = readlines(lineptr, MAXLINES) >= 0){
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr,nlines);
		return 0;
	}
	else{
		printf("error:input too big to sort");
		return 1;
	}
}

#define MAXLEN 1000
int getline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0){
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else{
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
		return nlines;
	}
}

int getline(char s[], int lim){
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF&&c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void writelines(char *lineptr[], int nlines){
	int i;
	for (i = 0; i < nlines; i++){
		printf("%s\n", lineptr[i]);
	}
}

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
	if (allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	}
else
	return 0;
}

void afree(char *p){
	if (p > allocbuf&&p < allocbuf + ALLOCSIZE)
		allocp = p;
}