#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gas-station
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:


	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		vector<int> gasmax(gas.begin(), gas.end());
		sort(gasmax.begin(), gasmax.end(),std::greater<int>());
		int tank = 0;
		for (int k = 0; k < gas.size(); k++)
		{
			//int max = gasmax[0];
			//if (gas[i] == max)
			//{
			int i = k;
				int start = i;
				tank = gas[i];
				for (int j = 0; j < gas.size(); j++)
				{
					
					tank = tank - cost[i];
					if (tank < 0)
					{
						//gasmax.erase(gasmax.begin());
						break;
					}
					i++;
					i = i % gas.size();
					


					tank += gas[i];

				}
				if (tank >= 0)
					return start;
				
			//}
			//else {
			//	continue;
			//}

			
		}

		return -1;
	}
};


int main134()
{
	Solution s;



	vector<int> gas5({ 2, 0, 1, 2, 3, 4, 0 });

	vector<int> cost5({ 0, 1, 0, 0, 0, 0, 11 });
	auto root5 = s.canCompleteCircuit(gas5, cost5);


	vector<int> gas4({ 4, 5, 3, 1, 4 });

	vector<int> cost4({ 5, 4, 3, 4, 2 });
	auto root4 = s.canCompleteCircuit(gas4, cost4);


	vector<int> gas3({ 1,2,3,4,5 });

	vector<int> cost3({ 3, 4, 5, 1, 2 });
	auto root3 = s.canCompleteCircuit(gas3, cost3);

	vector<int> gas2({ 2,3,4 });

	vector<int> cost2({ 3,4,3 });
	auto root2 = s.canCompleteCircuit(gas2, cost2);


	vector<int> gas({ 5, 1, 2, 3, 4 });

	vector<int> cost({ 4, 4, 1, 5, 1 });
	auto root = s.canCompleteCircuit(gas, cost);

	return 0;
}
