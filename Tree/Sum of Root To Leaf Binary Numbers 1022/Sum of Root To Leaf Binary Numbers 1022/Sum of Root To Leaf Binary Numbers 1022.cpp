// Sum of Root To Leaf Binary Numbers 1022.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void dfs(TreeNode* root, vector<int>& leaf, vector<vector<int>>& bint) {
	if (root == NULL)
		return;

	leaf.push_back(root->val);
	if (root->left == NULL && root->right == NULL) {
		bint.push_back(leaf);
		return;
	}
	if (root->left != NULL) {
		dfs(root->left, leaf, bint);
		leaf.pop_back();
	}
	if (root->right != NULL) {
		dfs(root->right, leaf, bint);
		leaf.pop_back();
	}
	return;
}

int sumRootToLeafOwn(TreeNode* root) {
	vector<int> leaf;
	vector<vector<int>> res;
	dfs(root, leaf, res);
	int counter = 0;
	for (auto i : res) {
		int t = 0;
		int count = 0;
		for (int j = i.size() - 1; j >= 0; j--) {
			count += i[j] * pow(2, t);
			t++;
		}
		counter += count;
	}
	return counter;
}

int sumRootToLeaf(TreeNode* root, int val = 0) {
	if (!root)
		return 0;
	val = (val * 2 + root->val);
	return root->left == root->right ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
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
