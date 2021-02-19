#include <iostream>
#include<vector>
#include <algorithm>
#include<set>
#include<tuple>
using namespace std;

/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

*/




class Solution {
public:
	
	//暴力解
	//vector<vector<int>> threeSum(vector<int>& nums) {
	//	vector<vector<int>> ret;
	//	int cnt = 3;
	//	for (int i = 0; i < nums.size()-2; i++)
	//	{
	//		for (int j = i + 1; j < nums.size() - 1; j++)
	//		{
	//			for (int k = j + 1; k < nums.size(); k++)
	//			{
	//				int sum = nums[i] + nums[j] + nums[k];
	//				if (sum == 0)
	//				{
	//					auto search = check.find(make_tuple(nums[i], nums[j], nums[k]));

	//					if (search != check.end()) {
	//						continue;
	//					}
	//					else {
	//						vector<int> good;
	//						good.push_back(nums[i]);
	//						good.push_back(nums[i + 1]);
	//						good.push_back(nums[i + 2]);
	//						ret.push_back(good);
	//						check.insert(make_tuple(nums[i], nums[j], nums[k]));
	//					}

	//				}
	//			}
	//		}

	//	}
	//	return ret;
	//}

	//自己的双指针法not work
	vector<vector<int>> threeSum(vector<int>& nums) {
 
		set<tuple<int, int, int>> check;
		vector<vector<int>> ret;
		if (nums.size() < 3)
			return ret;
		sort(nums.begin(),nums.end());
		for (int start = 0,end = nums.size()-1;start<end;)
		{
			int add_tmp = nums[start] + nums[end];
			if (abs(add_tmp) > nums[end] && nums[end]!=0)
			{
				start++;
				continue;
			}
			else if (add_tmp < nums[start] && nums[start] != 0)
			{
				end--;
				continue;
			}
			else if(add_tmp < 0){
				for (int i = end - 1; i > start; i--)
				{
					if (add_tmp + nums[i] == 0)
					{
						if (check.find(make_tuple(nums[start], nums[i], nums[end])) == check.end())
						{
							vector<int> good;
							good.push_back(nums[start]);
							good.push_back(nums[i]);
							good.push_back(nums[end]);
							check.insert(make_tuple(nums[start], nums[i], nums[end]));
							ret.push_back(good);
						}

						break;
					}
				}
				start++;
			}
			else if (add_tmp > 0) {
				for (int i = start + 1; i < end; i++)
				{
					if (add_tmp + nums[i] == 0)
					{
						if (check.find(make_tuple(nums[start], nums[i], nums[end])) == check.end())
						{
							vector<int> good;
							good.push_back(nums[start]);
							good.push_back(nums[i]);
							good.push_back(nums[end]);
							check.insert(make_tuple(nums[start], nums[i], nums[end]));
							ret.push_back(good);
						}
						//start++;
						
						break;
					}


				}
				
				end--;
			}
			else {
				for (int i = start; i < end; i++)
				{
					if (nums[i] == 0)
					{
						if (check.find(make_tuple(nums[start], nums[i], nums[end])) == check.end())
						{
							vector<int> good;
							good.push_back(nums[start]);
							good.push_back(nums[i]);
							good.push_back(nums[end]);
							check.insert(make_tuple(nums[start], nums[i], nums[end]));
							ret.push_back(good);
						}
						//start++;
						if (i * 2 < nums.size())
							end--;
						else
							start++;
						break;
					}
	
				}
				//

			}

		}
		return ret;
	}
};




int main15()
{
	Solution s;
	
	vector<int> v0({ 1, 2, -2, -1 });
	auto root0 = s.threeSum(v0);

	vector<int> v({ -1, 0, 1, 2, -1, -4 });
	auto root = s.threeSum(v);

	vector<int> v3({ -2, 0, 1, 1, 2 });
	auto root3 = s.threeSum(v3);

	vector<int> v1({ 1, 1, -2 });
	auto root1 = s.threeSum(v1);

	vector<int> v2({0,0,0});
	auto root2 = s.threeSum(v2);
	//   std::cout << "Hello World!\n";
	return 0;
}