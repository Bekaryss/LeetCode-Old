// Maximum Depth of N-ary Tree 559.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

int maxDepth(Node* root, int depth) {
	if (root == NULL)
		return depth;
	else {
		depth += 1;
		int maxd = depth;
		for (auto node : root->children) {
			maxd = max(maxd, maxDepth(node, depth));
		}
		return maxd;
	}
}

int maxDepth(Node* root) {
	return maxDepth(root, 0);
}


int maxDepthS(Node* root) {
	if (root == NULL)
		return 0;
	else {
		int depth = 0;
		for (auto node : root->children) {
			depth = max(maxDepth(node), depth);
		}
		return depth + 1;
	}
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
