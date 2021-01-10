#include<iostream>
#include<cstdlib>
#include<cctype>
using namespace std;
#define MAX 1024
double analyze(char *str);

char *extract(char *str, int &index)
{
	char *pstr(nullptr);
	int num(0);
	int bufindex(index);

	do{
		switch (str[index])
		{
		case ')': 
			if (0 == num)
			{
				++index;
				pstr = new char[index - bufindex];
				if (!pstr)//new failed
				{
					throw "malloc failed";
				}
				strncpy_s(pstr, index - bufindex, str + bufindex, index - bufindex - 1);
				return pstr;
			}
			else{
				num--;

			}
			break;
		case '(':
			num++;
			break;
	
		}
	} while (str[index++] != '\0');
}

double getnum(char *str, int &index)
{
	double value(0.0);
	if (str[index] == '(')
	{
		char *substr(nullptr);
		substr = extract(str, ++index);
		value = analyze(substr);
		delete[] substr;
		return value;
	}

	if (!isdigit(str[index]))
	{
		char error[64] = "get error";
		throw error;
		//return -1.0;
	}

	



	while (isdigit(*(str + index)))
	{
		value = 10 * value + (*(str + index) - '0');
		index++;
	}
	if (str[index] != '.')
	{
		return value;
	}
	else
	{
		double decimal(1.0);
		while (isdigit(*(str + (++index))))
		{
			decimal = decimal / 10;
			value += (*(str + index) - '0')*decimal;
		}
	}

	return value;
}

double calculate(char *str, int &index)
{
	double value(0.0);
	value = getnum(str, index);
	while (1)
	{
		if (str[index] == '*')
		{
			value *= getnum(str, ++index);
		}
		else if (str[index] == '/')
		{
			value /= getnum(str, ++index);
		}
		else{ break; }
	}
	
	

	return value;
}

double analyze(char *str)
{
	double value(0.0);
	int index(0);
	value += calculate(str, index);//first catch first num
	for (;; )
	{
		switch (*(str + (index++)))
		{
		case '\0':
			return value;
		case '+':
			value += calculate(str, index);
			break;
		case '-':
			value -= calculate(str, index);
			break;
		default:
			break;
		}
	}
}

//double calculate(double x, double y)
//{
//
//}



void main()
{
	/*int i = 5;
	int j = 0;
	cout << i + j++ << endl;*/
	char str[MAX] = { 0 };
	cin.getline(str, MAX);
	int i = 0;
	//cout << getnum(str, i)<<endl;
	cout << analyze(str)<<endl;
	system("pause");
}