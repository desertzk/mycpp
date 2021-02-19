#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int videoStitching(vector<vector<int>>& clips, int T) {
		sort(clips.begin(), clips.end(), [](auto a, auto b)-> bool { return a[0] < b[0]; });
		vector<int> dp(99999);
		fill(dp.begin(), dp.end(), 101);
		dp[0] = 0;        // base case 尝试定义 dp[j]，表示：覆盖 [0, j]区间的最少片段数

		for (int i = 0; i < clips.size(); i++) { // 遍历每个片段
			auto start = clips[i][0];  
			auto end = clips[i][1];// 获取当前片段的开始和结束时间
			for (int j = start + 1; j <= end; j++) { // 计算当前片段上每个点的dp[j]
				dp[j] = min(dp[j], dp[start] + 1);
			}
		}
		if (dp[T] == 101) { // 如果dp值为101，说明覆盖不了[0:T]，否则返回dp[T]
			return -1;
		}
		return dp[T];


	}
};


int main1024()
{
	Solution s;
	vector<vector<int>> clips = { {0, 2} ,{4, 6},{8, 10},{1, 9},{1, 5},{5, 9} };
	//string str = "babad";
	auto root = s.videoStitching(clips,10);
	vector<vector<int>> clips1 = { {0, 4}, { 2, 8 } };
	auto root1 = s.videoStitching(clips1, 5);
	cout << root;
	return 0;
}