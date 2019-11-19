// Balanced Binary Tree 110.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getDepth(TreeNode* root) {
	if (root == NULL)
		return 0;
	int left = getDepth(root->left);
	if (left != -1) {
		int right = getDepth(root->right);
		if (right != -1) {
			return abs(left-right) <= 1 ? 1 + max(left, right) : -1;
		}
	}
	return -1;
}

bool isBalanced(TreeNode* root) {
	return getDepth(root) != -1;
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
