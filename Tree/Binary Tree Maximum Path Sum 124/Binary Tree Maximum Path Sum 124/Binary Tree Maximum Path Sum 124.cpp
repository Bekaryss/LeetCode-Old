// Binary Tree Maximum Path Sum 124.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

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
	int res = INT_MIN;
public:
	int dfs(TreeNode* root) {
		if (root == NULL)
			return 0;
		int left = dfs(root->left);
		int right = dfs(root->right);
		int sum = root->val + left + right;
		int leftsum = root->val + left;
		int rightsum = root->val + right;
		res = max(max(sum, res), max(leftsum, rightsum));
		return max(root->val, max(leftsum, rightsum));
	}

	int dfsSolution(TreeNode* node) {
		if (node == NULL)
			return 0;
		int left = max(dfsSolution(node->left), 0);
		int right = max(dfsSolution(node->right), 0);
		res = max(res, node->val + left + right);
		return node->val + max(left, right);
	}

	int maxPathSum(TreeNode* root) {
		res = max(res, dfs(root));
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
