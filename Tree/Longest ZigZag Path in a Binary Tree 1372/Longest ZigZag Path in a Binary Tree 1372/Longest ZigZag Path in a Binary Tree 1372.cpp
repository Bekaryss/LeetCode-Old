// Longest ZigZag Path in a Binary Tree 1372.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	void dfsLeftToRight(TreeNode* root, vector<int>& zigzag, int& cur) {
		if (root == NULL)
			return;

		zigzag[cur]++;
		dfsRightToLeft(root->right, zigzag, cur);
		if (root->left != NULL) {
			zigzag.push_back(0);
			cur++;
			dfsLeftToRight(root->left, zigzag, cur);
		}

	}

	void dfsRightToLeft(TreeNode* root, vector<int>& zigzag, int& cur) {
		if (root == NULL)
			return;
		zigzag[cur]++;
		dfsLeftToRight(root->left, zigzag, cur);
		if (root->right != NULL) {
			zigzag.push_back(0);
			cur++;
			dfsRightToLeft(root->right, zigzag, cur);
		}
	}

	int longestZigZag(TreeNode* root) {
		vector<int> zigzag = { -1 };
		int cur = 0;
		dfsRightToLeft(root, zigzag, cur);
		int longest = 0;
		for (int i : zigzag) {
			longest = max(longest, i);
		}
		return longest;
	}
};

class Solution1 {
public:
	int longestZigZag(TreeNode* root) {
		int maxLength = 0;
		traverse(root, true, maxLength);
		return maxLength - 1;
	}
private:
	int traverse(TreeNode* root, bool isLeft, int& maxL) {
		if (root == NULL)
			return 0;
		int left = traverse(root->left, true, maxL) + 1;
		int right = traverse(root->right, false, maxL) + 1;
		maxL = max(maxL, max(left, right));
		return isLeft ? right : left;
	}
};

int main()
{
	TreeNode* root1 = new TreeNode(1);
	TreeNode* root2 = new TreeNode(2);
	TreeNode* root3 = new TreeNode(3);
	TreeNode* root4 = new TreeNode(4);
	TreeNode* root5 = new TreeNode(5);
	TreeNode* root6 = new TreeNode(6);
	TreeNode* root7 = new TreeNode(7);
	TreeNode* root8 = new TreeNode(8);

	root1->right = root2;
	root2->left = root3;
	root2->right = root4;
	root4->left = root5;
	root4->right = root6;
	root5->right = root7;
	root7->right = root8;
	Solution s;
	std::cout << s.longestZigZag(root1) << endl;
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
