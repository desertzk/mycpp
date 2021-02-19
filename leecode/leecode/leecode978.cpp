#include <iostream>
#include<vector>
#include <algorithm>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	int maxTurbulenceSize(vector<int>& arr) {
		if (arr.size()==1)
			return 1;
		int size = arr.size();
		vector<int> dp(size);
		int greater = 0;
		int pre_greater = 0;
		if (arr[0] > arr[1])
			greater = 1;
		fill(dp.begin(), dp.end(), 1);
		for (int cur = 1; cur < size - 1; cur++)
		{
			if (greater) {
				pre_greater = greater;
				if (arr[cur] < arr[cur + 1]){
					greater = 0;
					if (pre_greater != greater) {
						dp[cur] = dp[cur - 1] + 1;
					}
					
				}
				else{
					greater = 1;
					if (pre_greater != greater) {
						dp[cur] = dp[cur - 1] + 1;
					}
				}
				
			}
			else {
				pre_greater = greater;
				if (arr[cur] > arr[cur + 1]){
					greater = 1;
					if (pre_greater != greater) {
						dp[cur] = dp[cur - 1] + 1;
					}
				}
				else{
					greater = 0;
					if (pre_greater != greater) {
						dp[cur] = dp[cur - 1] + 1;
					}
				}
			}

		}

		int ret = *max_element(dp.begin(),dp.end());
		if (ret != 1)
			++ret;
		return ret;

	}
};


int main()
{
	Solution s;
	vector<int> k = { 9, 4 , 2, 10, 7, 8, 8, 1, 9 };
	
	//string str = "babad";
	auto root = s.maxTurbulenceSize(k);
	vector<int> clips1 = { 9, 9 };
	auto root1 = s.maxTurbulenceSize(clips1);
	cout << root;
	return 0;
}