#include<iostream>
#include<vector>
using namespace std;

class CTextBlock{
public:
	size_t length() const;
private:
	char *pText;
	mutable size_t textLength;
	mutable bool lengthIsValid;

};

size_t CTextBlock::length() const
{
	if (!lengthIsValid){
		textLength = strlen(pText);
		lengthIsValid = true;
	}
	return textLength;
}

void main()
{
	vector<int> vi = { 1, 2, 3, 4, 5, 51, 6, 7, 8, 9, 80 };
	//vector<int>::const_iterator
	cin.get();
}