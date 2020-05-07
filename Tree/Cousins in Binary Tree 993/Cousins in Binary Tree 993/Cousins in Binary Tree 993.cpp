// Cousins in Binary Tree 993.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isCousins(TreeNode* root, int x, int y) {
		queue<TreeNode*> que;
		if (root == NULL)
			return false;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			bool xval = false;
			bool yval = false;
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				if (cur->val == x) {
					xval = true;
				}
				if (cur->val == y) {
					yval = true;
				}
				if (cur->left != NULL && cur->right != NULL) {
					if (cur->left->val == x && cur->right->val == y) {
						return false;
					}
					if (cur->left->val == y && cur->right->val == x) {
						return false;
					}
				}
				if (cur->left != NULL)
					que.push(cur->left);

				if (cur->right != NULL)
					que.push(cur->right);
			}
			if (xval == true && yval == true)
				return true;
		}
		return false;
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
