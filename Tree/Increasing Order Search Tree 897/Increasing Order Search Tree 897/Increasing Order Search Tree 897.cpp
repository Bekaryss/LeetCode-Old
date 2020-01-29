// Increasing Order Search Tree 897.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(vector<int>& res, TreeNode* node) {
	if (node == NULL)
		return;
	dfs(res, node->left);
	res.push_back(node->val);
	dfs(res, node->right);
}

TreeNode* increasingBST(TreeNode* root) {
	vector<int> res;
	dfs(res, root);
	TreeNode* head = NULL, * cur = NULL;
	for (int i = 0; i < res.size(); i++) {
		if (head == NULL) {
			head = cur = new TreeNode(res[i]);
		}
		else {
			cur->right = new TreeNode(res[i]);
			cur = cur->right;
		}
	}
	return head;
}

TreeNode* increasingBSTS(TreeNode* root, TreeNode *tail = NULL) {
	if (!root) return tail;
	TreeNode* res = increasingBSTS(root->left, root);
	root->left = NULL;
	root->right = increasingBSTS(root->right, tail);
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
