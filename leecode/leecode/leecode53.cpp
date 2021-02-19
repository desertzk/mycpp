#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;


/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [0]
Output: 0
Example 4:

Input: nums = [-1]
Output: -1
Example 5:

Input: nums = [-100000]
Output: -100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		int max = nums[0];
 		for (int i = 1; i < nums.size(); i++)
		{
			
			nums[i] = std::max(nums[i] + nums[i - 1], nums[i]);
			if (nums[i] > max)
				max = nums[i];
		}
		return max;
	}
};


int main53()
{
	Solution s;
	vector<int> v3({ -2,1,-3,4,-1,2,1,-5,4 });
	auto root3 = s.maxSubArray(v3);



	system("pause");
	return 0;
}
