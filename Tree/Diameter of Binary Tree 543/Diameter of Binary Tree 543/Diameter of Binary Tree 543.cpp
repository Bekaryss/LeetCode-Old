// Diameter of Binary Tree 543.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int dfs(TreeNode* node, int& res) {
		if (node == NULL) {
			return 0;
		}
		int left = dfs(node->left, res);
		int right = dfs(node->right, res);
		res = max(res, left + right);
		return max(left + 1, right + 1);
	}

	int diameterOfBinaryTree(TreeNode* root) {
		int res = 0;
		dfs(root, res);
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
