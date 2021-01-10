#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *string_encrypt(char *pass, char *string)
{
	int passlen = strlen(pass);
	int stringlen = strlen(string);
	if (stringlen%passlen==0)
	{
		int count = stringlen/passlen;
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < passlen; j++)
			{
				string[i*passlen + j] ^= pass[j];
			}
		}
		
	}
	else
	{
		int count = stringlen / passlen;
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < passlen; j++)
			{
				string[i*passlen + j] ^= pass[j];
			}
		}
		int left = stringlen % passlen;
		for (int k = 0; k < left; k++)
		{
			string[count*passlen + k] ^= pass[k];
		}
	}
	return string;
}

char *string_decryption(char *pass, char *string)
{

}

void file_encrypt(char *srcpath, char *despath, char *password)
{
	FILE *pfr, *pfw;
	pfr = fopen(srcpath, "r");
	pfw = fopen(despath, "w");
	if (pfr == NULL || pfw == NULL)
	{
		fclose(pfr);
		fclose(pfw);
		return;
	}
	else{
		
		while (!feof(pfr))
		{
			char string[256] = { 0 };
			fgets(string, 256, pfr);
			string_encrypt(password, string);
			fputs(string, pfw);
		}
		fclose(pfr);
		fclose(pfw);
	}

}

void file_decryption(char *srcpath, char *despath, char *password)
{

}

void encrypt_file_with_bytes(char *srcpath, char *despath, char *password)
{
	FILE *pfr, *pfw;
	pfr = fopen(srcpath, "r");
	pfw = fopen(despath, "w");
	if (pfr == NULL || pfw == NULL)
	{
		fclose(pfr);
		fclose(pfw);
		return;
	}
	else{
		int filelen = getfilesize(srcpath);
		int passlength = strlen(password);
		char *newstr = (char *)malloc(sizeof(char)*(filelen+1));
		for (int i = 0; i < filelen; i++)
		{
			char ch = fgetc(pfr);
			newstr[i] = ch;
			putchar(ch);
			//if (i<filelen / passlength)
			//{
			//	
			//}
			//else{

			//}
		}
		newstr[filelen] = '\0';
		string_encrypt(password, newstr);
		for (int i = 0; i < filelen; i++)
		{
			fputc(newstr[i], pfw);
		}
		fclose(pfr);
		fclose(pfw);
	}
}

int getfilesize(char *path)
{
	FILE *pf = fopen(path, "r");
	if (pf == NULL)
	{
		return -1;
	}
	else{
		fseek(pf, 0, SEEK_END);
		int length = ftell(pf);
		return length;
	}
}


void main(){
	/*char string[20] = "abcdefghijk";
	char *pass = "123";
	printf("%s\n", string_encrypt(pass, string));
	printf("%s\n", string_encrypt(pass, string));*/
	/*file_encrypt("C:\\Users\\admin\\Desktop\\1.txt", "C:\\Users\\admin\\Desktop\\2.txt", "123");
	file_encrypt("C:\\Users\\admin\\Desktop\\2.txt", "C:\\Users\\admin\\Desktop\\3.txt", "123");
*/
	printf("byte:%d\n", getfilesize("C:\\Users\\admin\\Desktop\\New Text Document (3).txt"));
	encrypt_file_with_bytes("C:\\Users\\admin\\Desktop\\New Text Document (3).txt","C:\\Users\\admin\\Desktop\\1.txt","ABC");
	encrypt_file_with_bytes("C:\\Users\\admin\\Desktop\\1.txt", "C:\\Users\\admin\\Desktop\\2.txt", "ABC");
	system("pause");
}