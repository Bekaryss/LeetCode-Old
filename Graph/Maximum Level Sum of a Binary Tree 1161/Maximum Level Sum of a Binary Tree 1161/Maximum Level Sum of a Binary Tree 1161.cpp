// Maximum Level Sum of a Binary Tree 1161.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxLevelSum(TreeNode* root) {
		queue<TreeNode*> qr;
		qr.push(root);
		int res = 1;
		int maxV = INT_MIN;
		int level = 1;
		while (!qr.empty()) {
			int n = qr.size();
			int curV = 0;
			for (int i = 0; i < n; i++) {
				TreeNode* ch = qr.front();
				qr.pop();
				curV += ch->val;
				if (ch->left)
					qr.push(ch->left);
				if (ch->right)
					qr.push(ch->right);
			}
			if (curV > maxV) {
				maxV = curV;
				res = level;
			}
			level++;
		}
		return res;
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
