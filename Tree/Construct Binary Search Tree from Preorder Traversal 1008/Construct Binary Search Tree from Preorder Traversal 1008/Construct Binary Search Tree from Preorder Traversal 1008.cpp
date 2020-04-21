// Construct Binary Search Tree from Preorder Traversal 1008.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int index = 0;

TreeNode* dfs(vector<int>& preorder, int bound) {
	if (index >= preorder.size() || preorder[index] > bound) {
		return NULL;
	}
	TreeNode* node = new TreeNode(preorder[index++]);
	node->left = dfs(preorder, node->val);
	node->right = dfs(preorder, bound);
	return node;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
	return dfs(preorder, INT_MAX);
}

int main()
{
	vector<int> input = { 8,5,1,7,10,12 };
	TreeNode* node = bstFromPreorder(input);
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
