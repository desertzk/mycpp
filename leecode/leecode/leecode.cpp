// leecode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct ListNode {
	ListNode(const std::initializer_list<int>& v):val(0), next(nullptr) {
		int size = v.size();
		ListNode* cur = this;
		for (auto itm : v) {
			size--;
			cur->val = itm;
			if (size)
				cur->next = new ListNode();

			cur = cur->next;
		}
	}
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution {
//public:
//
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode* cur1 = l1;
//		ListNode* cur2 = l2;
//		bool tailcur1 = false;
//		bool tailcur2 = false;
//		ListNode* ret = new ListNode();
//		ListNode* root = ret;
//		int scale = 0;
//		for (; cur1!= nullptr || cur2!= nullptr; )
//		{
//			int n1 = cur1 ? cur1->val : 0;
//			int n2 = cur2 ? cur2->val : 0;
//			int sum =  n1 + n2;
//			if (scale > 0) {
//				sum += 1;
//				scale = 0;
//			}
//			if (sum >= 10)
//			{
//				sum = sum % 10;
//				scale = 1;
//			}
//
//			ret->val = sum;
//			ListNode* next = nullptr;
//			if(cur1->next!=nullptr || cur2->next != nullptr)
//				next = new ListNode();
//			//if (!tailcur1 || !tailcur2)
//			//	next = new ListNode();
//			ret->next = next;
//			ret = ret->next;
//			if (cur1)
//			{
//				cur1 = cur1->next;
//				
//			}
//			else {
//				tailcur1 = true;
//			}
//			if (cur2)
//			{
//				cur2 = cur2->next;
//			}
//			else {
//				tailcur2 = true;
//			}
//	
//		}
//		if (scale > 0)
//		{
//			ListNode* ret = new ListNode(scale);
//			scale = 0;
//		}
//		return root;
//	}
//};
class Solution {
public:

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* cur1 = l1;
		ListNode* cur2 = l2;
		ListNode* ret = new ListNode();
		ListNode* root = ret;
		int scale = 0;
		for (; cur1 != nullptr && cur2 != nullptr; )
		{
			int n1 = cur1 ? cur1->val : 0;
			int n2 = cur2 ? cur2->val : 0;
			int sum =  n1 + n2;
			if (scale > 0) {
				sum += 1;
				scale = 0;
			}
			if (sum >= 10)
			{
				sum = sum % 10;
				scale = 1;
			}

			ret->val = sum;
			ListNode* next = nullptr;
			if (cur1->next != nullptr || cur2->next != nullptr) {
				next = new ListNode();
				ret->next = next;
				ret = ret->next;
			}

			if (cur1->next!=nullptr && cur2->next != nullptr)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			else if (cur1->next != nullptr && cur2->next == nullptr)
			{
				cur1 = cur1->next;
				cur2 = new ListNode();
			}
			else if (cur1->next == nullptr && cur2->next != nullptr)
			{
				cur2 = cur2->next;
				cur1 = new ListNode();
			}
			else {
				cur1 = cur1->next;
				cur2 = cur2->next;
			}

		}
		if (scale > 0)
		{
			ret->next = new ListNode(scale);
			scale = 0;
		}
		return root;
	}
};


int main210114()
{
	Solution s;
	ListNode* ret = new ListNode({ 2, 4, 3 });
	ListNode* ret1 = new ListNode({ 5, 6, 4 });
	auto root = s.addTwoNumbers(ret, ret1);

	ListNode* ret3 = new ListNode({ 9, 9, 9 });
	ListNode* ret4 = new ListNode({ 9});
	auto root2 = s.addTwoNumbers(ret3, ret4);
 //   std::cout << "Hello World!\n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
