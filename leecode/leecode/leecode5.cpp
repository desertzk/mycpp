#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		//�൱����һ�����
		vector<vector<int>> dp(n, vector<int>(n));
		string ans;
		// 1. ״̬����
	   // dp[i][j] ��ʾs[i...j] �Ƿ��ǻ��Ĵ�
		for (int l = 0; l < n; ++l) {//l������
			for (int i = 0; i + l < n; ++i) {
				int j = i + l;
				if (l == 0) {//һ���ַ���ʱ��
					dp[i][j] = 1;
				}
				else if (l == 1) { //�����ַ���ʱ��
					dp[i][j] = (s[i] == s[j]);
				}
				else {//����ַ���ʱ�� �������������ַ����Ƿ���� Ȼ�󿴿����·�
					dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
				}
				if (dp[i][j] && l + 1 > ans.size()) {//������ʱ��Ż������
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