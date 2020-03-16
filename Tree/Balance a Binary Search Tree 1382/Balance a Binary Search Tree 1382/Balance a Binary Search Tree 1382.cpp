// Balance a Binary Search Tree 1382.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	void inorderT(TreeNode* root, vector<int>& arr) {
		if (root == NULL) {
			return;
		}
		inorderT(root->left, arr);
		arr.push_back(root->val);
		inorderT(root->right, arr);
	}

	TreeNode* builBBST(vector<int>& arr, int left, int right) {
		if (left > right)
			return NULL;
		int mid = (left + right) / 2;
		TreeNode* node = new TreeNode(arr[mid]);
		node->left = builBBST(arr, left, mid-1);
		node->right = builBBST(arr, mid+1, right);
		return node;
	}

	TreeNode* balanceBST(TreeNode* root) {
		vector<int> arr;
		inorderT(root, arr);
		for (int i : arr) {
			cout << i << " ";
		}
		cout << endl;
		return builBBST(arr, 0, arr.size()-1);
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
