#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		//相当于列一个表格
		vector<vector<int>> dp(n, vector<int>(n));
		string ans;
		// 1. 状态定义
	   // dp[i][j] 表示s[i...j] 是否是回文串
		for (int l = 0; l < n; ++l) {//l代表长度
			for (int i = 0; i + l < n; ++i) {
				int j = i + l;
				if (l == 0) {//一个字符的时候
					dp[i][j] = 1;
				}
				else if (l == 1) { //两个字符的时候
					dp[i][j] = (s[i] == s[j]);
				}
				else {//多个字符的时候 看看外面两个字符串是否相等 然后看看左下方
					dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
				}
				if (dp[i][j] && l + 1 > ans.size()) {//更长的时候才会进这里
					ans = s.substr(i, l + 1);
				}
			}
		}
		return ans;

	}
	
};


int main5()
{
	Solution s;
	string str = "babad";
	auto root = s.longestPalindrome(str);


	return 0;
}