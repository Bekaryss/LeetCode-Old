// First Unique Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}
};

class FirstUnique {
private:
	unordered_map<int, Node*> map;
	Node* first, * last;

	void removeItem(Node* node) {
		if (node->left != NULL) {
			node->left->right = node->right;
		}
		else {
			first = node->right;
		}

		if (node->right != NULL) {
			node->right->left = node->left;
		}
		else {
			last = node->left;
		}
	}

	void addBack(int val) {
		if (map.find(val) == map.end()) {
			Node* node = new Node(val);
			node->left = last;
			node->right = NULL;
			if (last != NULL) {
				last->right = node;
			}
			last = node;
			if (first == NULL)
				first = node;
			map[val] = node;
		}
		else if (map[val] != NULL) {
			removeItem(map[val]);
			delete map[val];
			map[val] = NULL;
		}
	}

public:
	FirstUnique(vector<int>& nums) {
		first = NULL;
		last = NULL;
		for (int i : nums) {
			addBack(i);
		}
	}

	int showFirstUnique() {
		if (first != NULL) {
			return first->val;
		}

		return -1;
	}

	void add(int value) {
		addBack(value);
	}
};

int main()
{
	vector<int> input = { 2, 3, 5 };
	FirstUnique* firstUnique = new FirstUnique(input);
	cout << "2 = " << firstUnique->showFirstUnique() << endl; // return 2
	firstUnique->add(5);            // the queue is now [2,3,5,5]
	cout << "2 = " << firstUnique->showFirstUnique() << endl; // return 2
	firstUnique->add(2);            // the queue is now [2,3,5,5,2]
	cout << "3 = " << firstUnique->showFirstUnique() << endl; // return 3
	firstUnique->add(3);            // the queue is now [2,3,5,5,2,3]
	cout << "-1 = " << firstUnique->showFirstUnique() << endl; // return -1
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
