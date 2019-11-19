// Delete Node in a BST 450.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* findMin(TreeNode* root) {
	if (root == NULL)
		return NULL;
	if (root->left == NULL)
		return root;
	else {
		return findMin(root->left);
	}
}

TreeNode* deleteNode(TreeNode* root, int key) {
	if (root == NULL)
		return NULL;
	else if (key < root->val)
		root->left = deleteNode(root->left, key);
	else if (key > root->val)
		root->right = deleteNode(root->right, key);
	else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		else if (root->left == NULL) {
			TreeNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root;
			root = root->left;
			delete temp;
		}
		else {
			TreeNode* temp = findMin(root->right);
			root->val = temp->val;
			root->right = deleteNode(root->right, temp->val);
		}
	}
	return root;
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
