// Binary Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* insert(int index, vector<int>& input) {
	Node* node = new Node();
	node->data = input[index];
	int n = input.size();

	int left = index * 2 + 1;
	if (left < n) {
		node->left = insert(left, input);
	}
	int right = index * 2 + 2;
	if (right < n) {
		node->right = insert(right, input);
	}

	return node;
}

Node* buildTree(vector<int>& input) {
	Node* root = insert(0, input);
	return root;
}

void PrintTree(Node* root) {
	Node* node = root;
	queue<Node*> levels;
	levels.push(node);
	while (!levels.empty()) {
		int size = levels.size();
		for (int i = 0; i < size; i++) {
			node = levels.front();
			levels.pop();
			if (node->left)
				levels.push(node->left);
			if (node->right)
				levels.push(node->right);
			cout << node->data << " ";
		}
		cout << endl;
	}
}

int height(Node* root) {
	int hl = 0, hr = 0;
	if (root == NULL)
		return 0;
	if (root->left)
		hl = height(root->left);
	if (root->right)
		hr = height(root->right);
	return max(hl, hr) + 1;
}

void reverse(Node* root) {
	if (root) {
		if (root->left && root->right) {
			Node* temp = root->left;
			root->left = root->right;
			root->right = temp;
			reverse(root->left);
			reverse(root->right);
		}
		else if (root->left && !root->right) {
			reverse(root->left);
		}
		else if (!root->left && root->right) {
			reverse(root->right);
		}
	}
}

int lookup(Node* root, int target) {
	if (root == NULL)
		return -1;
	else {
		if (root->data == target)
			return root->data;
		else {
			int left = lookup(root->left, target);
			int right = lookup(root->right, target);
			if (left != -1)
				return left;
			else if (right != -1)
				return right;
			else {
				return -1;
			}
		}
	}
}

int getWidth(Node* root, int level) {
	if (!root)
		return 0;
	if (level == 1)
		return 1;
	else if (level > 1)
		return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
}

int getMaxWidth(Node* root) {
	int maxWidth = 0;
	int width = 0;
	int h = height(root);
	for (int i = 1; i <= h; i++) {
		width = getWidth(root, i);
		maxWidth = max(width, maxWidth);
	}
	return maxWidth;
}

int main()
{
	vector<int> input = { 0,1,2,3,4,5,6 };
	Node* root = buildTree(input);
	PrintTree(root);
	cout << "height = " << height(root) << endl;
	reverse(root);
	PrintTree(root);
	for (int i : input) {
		cout << "lookup = " << lookup(root, i) << endl;
	}
	cout << "lookup = " << lookup(root, 7) << endl;

	cout << "maxWidth = " << getMaxWidth(root) << endl;

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
