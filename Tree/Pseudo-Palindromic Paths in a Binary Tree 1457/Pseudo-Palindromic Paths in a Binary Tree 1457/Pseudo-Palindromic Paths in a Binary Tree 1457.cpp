// Pseudo-Palindromic Paths in a Binary Tree 1457.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isPalindromic(vector<int>& nums) {
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			map[nums[i]]++;
		}
		int odd = 0;
		for (auto i : map) {
			if (i.second % 2 != 0) {
				odd++;
			}
		}
		if (nums.size() % 2 != 0 && odd > 1) {
			return false;
		}
		else if (nums.size() % 2 == 0 && odd > 0) {
			return false;
		}
		return true;
	}

	void dfs(TreeNode* root, vector<int>& nums, int& res) {
		if (root == NULL)
			return;
		nums.push_back(root->val);
		if (root->left == NULL && root->right == NULL) {
			if (isPalindromic(nums))
				res++;
		}
		dfs(root->left, nums, res);
		dfs(root->right, nums, res);
		nums.pop_back();
	}

	int pseudoPalindromicPaths(TreeNode* root) {
		vector<int> nums;
		int res = 0;
		dfs(root, nums, res);
		return res;
	}
};

int main()
{
	std::cout << "Hello World!\n";
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
