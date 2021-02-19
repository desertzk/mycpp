
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

/*
Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/is-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
	bool isSubsequence(string s, string t) {
		
		/*if (s.size() < t.size())
		{*/
		int j=0;
		char shortstr = s[j];
		for (int i = 0; i < t.size(); i++)
		{
			if (shortstr == t[i]) {
				j++;
				shortstr = s[j];
			}
				
		}
		if (j == s.size())
			return true;
		else
			return false;
		//}


	}
};


int main392()
{
	Solution s;
	string str = "abc";
	string t = "ahbgdc";
	auto root3 = s.isSubsequence(str,t);



	system("pause");
	return 0;
}