#include <iostream>
#include<vector>
#include <algorithm>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	int monotoneIncreasingDigits(int N) {
		// = to_string(N);
		//int size = str_N.size();
		stack<int> tmp_num;
		//char result[12] = { 0 };
		//int pre = 
		
		int i = N;
		bool is_increase = true;
		for (; i >= 0; i--)
		{
			is_increase = true;
			string str_N = to_string(i);
			int size = str_N.size();
			int pre = str_N[--size] - '0';
			while (--size > -1)
			{
				int cur = str_N[size] - '0';
				if (cur > pre)
				{
					is_increase = false;
					continue;
				}
				else {
					pre = cur;
				}
			}
			if (is_increase)
				return i;
		}
		
		/*while (int i = --size)
		{
			int num = atoi(&str_N[i]);
			tmp_num.push(num);
		}*/
		//for(int i= str_N[;)
	}
};


int main738()
{
	Solution s;
	int k = 10;
	//string str = "babad";
	auto root = s.monotoneIncreasingDigits(k);
	//vector<vector<int>> clips1 = { {0, 4}, { 2, 8 } };
	auto root1 = s.monotoneIncreasingDigits(1234);
	cout << root;
	return 0;
}