// Maximum Sum BST in Binary Tree 1373.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
// isBinaryST, CurSum, minV, maxV

vector<int> dfs(TreeNode* root, int& res) {
	if (root == NULL) {
		return { 1, 0, INT_MAX, INT_MIN };
	}
	vector<int> left = dfs(root->left, res);
	vector<int> right = dfs(root->right, res);
	if (left[0] == 1 && right[0] == 1) {
		if (left[3] < root->val && root->val < right[2]) {
			int sum = root->val + left[1] + right[1];
			res = max(res, sum);
			if (left[3] == INT_MIN) {
				left[3] = root->val;
			}
			if (right[2] == INT_MAX) {
				right[2] = root->val;
			}
			return { 1, sum, left[3], right[2] };
		}
	}
	return { 0, 0, 0, 0 };
}

int maxSumBST(TreeNode* root) {
	int res = 0;
	vector<int> tr = dfs(root, res);
	return res;
}

int main()
{
	TreeNode* root1 = new TreeNode(4);
	TreeNode* root2 = new TreeNode(2);
	TreeNode* root3 = new TreeNode(3);
	TreeNode* root4 = new TreeNode(1);
	TreeNode* root5 = new TreeNode(5);
	root1->left = root2;
	root1->right = root5;
	root2->left = root4;
	root2->right = root3;

	std::cout << maxSumBST(root1) << endl;
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
