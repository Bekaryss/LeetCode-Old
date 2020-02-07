// Average of Levels in Binary Tree 637.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

vector<double> averageOfLevels(TreeNode* root) {
	vector<double> res;
	queue<TreeNode*> level;
	level.push(root);
	while (!level.empty()) {
		int i = 0, size = level.size();
		double sum = 0;
		while (i < size) {
			TreeNode* cur = level.front();
			level.pop();
			sum += cur->val;
			if (cur->left != NULL)
				level.push(cur->left);
			if (cur->right != NULL)
				level.push(cur->right);
			i++;
		}
		res.push_back(sum / size);
	}
	return res;
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
