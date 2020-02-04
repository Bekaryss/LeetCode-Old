// Leaf-Similar Trees 872.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(vector<int>& leafs, TreeNode* root) {
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL) {
		leafs.push_back(root->val);
	}
	dfs(leafs, root->left);
	dfs(leafs, root->right);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
	vector<int> r1, r2;
	dfs(r1, root1);
	dfs(r2, root2);
	if (r1.size() == r2.size()) {
		for (int i = 0; i < r1.size(); i++) {
			if (r1[i] != r2[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}
#pragma region Solution
int dfsSolution(stack<TreeNode*>& s) {
	while (true) {
		TreeNode* node = s.top(); s.pop();
		if (node->right) s.push(node->right);
		if (node->left) s.push(node->left);
		if (!node->left && !node->right) return node->val;
	}
}

bool leafSimilarSolution(TreeNode* root1, TreeNode* root2) {
	stack<TreeNode*> s1, s2;
	s1.push(root1); s2.push(root2);
	while (!s1.empty() && !s2.empty())
		if (dfsSolution(s1) != dfsSolution(s2)) return false;
	return s1.empty() && s2.empty();
}
#pragma endregion


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
