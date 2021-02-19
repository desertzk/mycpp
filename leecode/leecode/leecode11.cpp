#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/*int findmax2(vector<int>& v,int begin,int end)
	{
		for(int )
		return weight * height;
	}
	//暴力解法会超时
	int maxArea(vector<int>& height) {
		int max_area = 0;
		for (int i = 0; i < height.size(); i++)
		{
			for (int j = 0; j < height.size(); j++)
			{
				int weight = j - i;
				int area = min(height[i],height[j])* weight;
				if (area > max_area)
					max_area = area;
			}
		}
		return max_area;
	}*/
	//double pointer
	int maxArea(vector<int>& height) {
		int max_area = 0;
		int right = height.size()-1;
		int left = 0;

		while (right != left)
		{
			int weight = right - left;
			int hei = min(height[right], height[left]);
			int area = hei * weight;
			if (area > max_area)
			{ 
				max_area = area;
				
			}

			if (height[right] >= height[left])
			{
				left++;
			}
			else {
				right--;
			}
				
		}
		/*for (int i = 0; i < height.size(); i++)
		{
			for (int j = 0; j < height.size(); j++)
			{
				int weight = j - i;
				int area = min(height[i], height[j]) * weight;
				if (area > max_area)
					max_area = area;
			}
		}*/
		return max_area;
	}


};


int main11()
{
	Solution s;
	vector<int> v({ 1,1 });
	auto root = s.maxArea(v);


	vector<int> v2({ 1,8,6,2,5,4,8,3,7 });
	auto root2 = s.maxArea(v2);
	//   std::cout << "Hello World!\n";
	return 0;
}