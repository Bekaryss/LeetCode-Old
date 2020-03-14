// Deepest Leaves Sum 1302.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void dfs(TreeNode* root, int& res, int& maxl, int length) {
		if (root == NULL) {
			return;
		}
		else if (root->left == NULL && root->right == NULL) {
			if (maxl < length) {
				maxl = length;
				res = root->val;
			}
			else if (maxl == length) {
				res += root->val;
			}
			return;
		}
		dfs(root->left, res, maxl, length++);
		dfs(root->right, res, maxl,  length++);
		return;
	}

	int deepestLeavesSum(TreeNode* root) {
		int res = 0, maxl = 0;
		dfs(root, res, maxl, 0);
		return res;
	}
};

int deepestLeavesSum(TreeNode* root) {
	int res = 0, i;
	queue<TreeNode*> q;
	q.push(root);
	while (q.size()) {
		for (i = q.size() - 1, res = 0; i >= 0; --i) {
			TreeNode* node = q.front(); q.pop();
			res += node->val;
			if (node->right) q.push(node->right);
			if (node->left)  q.push(node->left);
		}
	}
	return res;
}

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
