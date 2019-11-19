// Binary Search Tree Iterator 173.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
	queue<int> nodes;
public:
	BSTIterator(TreeNode* root) {
		stack<TreeNode*> rnodes;
		while (root != NULL || !rnodes.empty()) {
			while (root != NULL) {
				rnodes.push(root);
				root = root->left;
			}
			root = rnodes.top();
			rnodes.pop();
			nodes.push(root->val);
			root = root->right;
		}
	}

	/** @return the next smallest number */
	int next() {
		if (!nodes.empty()) {
			int val = nodes.front();
			nodes.pop();
			return val;
		}
		else {
			return -1;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (!nodes.empty())
			return true;
		else
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
