#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
	//递归版本超时
	/*
	bool canJump(vector<int>& nums) {
		//cout << nums.size() << endl;
		if (nums.size() == 1)
			return true;
		else if (nums.size() < 1)
			return false;
		
		int range = nums[0];
		for (int i = range; i > 0; i--) {
			if (i > nums.size() - 1)
				continue;
			auto first = nums.begin() + i;
			auto end = nums.end();
			vector<int> sub(first, end);
			if (canJump(sub))
				return true;
		}
		return false;
	}*/
	//这里走尽可能远的路代表贪心
	bool canJump(vector<int>& nums) {
		if (nums.size() == 1)
			return true;
		//cout << nums.size() << endl;
		int reach = nums.size() - 1;

		int range = nums[nums.size()-2];
		for (int i = nums.size() - 2; i >= 0; i--) {
			if (i + nums[i] >= reach)
				reach = i;
			if (reach == 0)
				return true;
		}
		return false;
	}
};


int main55()
{
	Solution s;
	vector<int> v3({ 0 });
	auto root3 = s.canJump(v3); 

	vector<int> v0({ 2,3,1,1,4 });
	auto root0 = s.canJump(v0);
	//cout << root0 << endl;

	vector<int> v1({1,3,2});
	auto root1 = s.canJump(v1);

	vector<int> v2({2 ,0});
	auto root2 = s.canJump(v2);

	return 0;
}