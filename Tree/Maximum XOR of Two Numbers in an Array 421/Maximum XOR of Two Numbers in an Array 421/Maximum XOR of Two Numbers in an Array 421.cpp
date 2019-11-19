// Maximum XOR of Two Numbers in an Array 421.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Trie {
private:
	unordered_map<int, Trie*> children = {};
	bool isword = false;
public:
	Trie() {}

	int findMaxXOR(vector<int>& nums) {
		int maxXor = 0;
		for (int i = 0; i < nums.size(); i++) {
			Trie* node = this, * nodeXor = this;
			int num = nums[i];
			int curXor = 0;
			for (int j = 31; j >= 0; j--) {
				int index = ((num >> j) & 1);
				// insert new number in trie  
				if (!node->children.count(index))
					node->children[index] = new Trie();
				node = node->children[index];

				// compute max xor of that new number 
				// with all previously inserted
				int toggle = index == 1 ? 0 : 1;
				if (nodeXor->children.count(toggle)) {
					curXor = (curXor << 1) | 1;
					nodeXor = nodeXor->children[toggle];
				}
				else {
					curXor = (curXor << 1);
					nodeXor = nodeXor->children[index];
				}
			}
			maxXor = max(curXor, maxXor);
		}
		return maxXor;
	}
};

int findMaximumXOR(vector<int>& nums) {
	Trie trie;
	return trie.findMaxXOR(nums);
}

int main()
{
	vector<int> input = { 3, 10, 5, 25, 2, 8 };
	cout << findMaximumXOR(input) << endl;
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
