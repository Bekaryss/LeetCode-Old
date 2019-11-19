// Map Sum Pairs 677.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Trie {
private:
	unordered_map<char, Trie*> children = {};
	int value = 0;
public:
	/** Initialize your data structure here. */
	Trie() {}

	/** Inserts a word into the trie. */
	void insert(string word, int value) {
		Trie* node = this;
		for (char ch : word) {
			if (!node->children.count(ch))
				node->children[ch] = new Trie();
			node = node->children[ch];
		}
		node->value = value;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	Trie* startsWith(string prefix) {
		Trie* node = this;
		for (char ch : prefix) {
			if (!node->children.count(ch))
				return NULL;
			node = node->children[ch];
		}
		return node;
	}

	int sum(Trie* node) {
		int sumv = 0;
		for (auto n : node->children) {
			sumv += sum(n.second);
		}
		sumv += node->value;
		return sumv;
	}
};

class MapSum {
private:
	Trie trie;
public:
	/** Initialize your data structure here. */
	MapSum() {

	}

	void insert(string key, int val) {
		trie.insert(key, val);
	}

	int sum(string prefix) {
		int sum = 0;
		Trie* node = trie.startsWith(prefix);
		if (node != NULL)
		{
			sum = trie.sum(node);
		}
		return sum;
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
