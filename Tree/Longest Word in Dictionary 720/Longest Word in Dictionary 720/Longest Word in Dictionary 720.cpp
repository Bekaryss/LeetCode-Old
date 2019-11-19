// Longest Word in Dictionary 720.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Trie {
private:
	unordered_map<char, Trie*> children = {};
	int index = 0;
public:
	/** Initialize your data structure here. */
	Trie() {}

	/** Inserts a word into the trie. */
	void insert(string word, int index) {
		Trie* node = this;
		for (char ch : word) {
			if (!node->children.count(ch))
				node->children[ch] = new Trie();
			node = node->children[ch];
		}
		node->index = index;
	}



	/** Returns if the word is in the trie. */
	int search(string word) {
		Trie* node = this;
		int size = 0;
		int n = 0;
		for (char ch : word) {
			if (!node->children.count(ch))
				return -1;
			node = node->children[ch];
			size += node->index;
			n++;
			if (node->index != 0)
				n--;
		}
		if (n  == 0)
			return size;
		else
			return 0;
	}
};

string longestWord(vector<string>& words) {
	Trie trie;
	for (string word : words) {
		trie.insert(word, 1);
	}
	int maxv = 0;
	auto comp = [](pair<int, string> wordA, pair<int, string> wordB) {
		if (wordA.first == wordB.first) {
			return wordA.second > wordB.second;
		}
		else {
			return wordA.first < wordB.first;
		}
	};
	priority_queue < pair<int, string>, vector<pair<int, string>>, decltype(comp)> q(comp);
	for (string s : words) {
		q.push(make_pair(trie.search(s), s));
	}
	return q.top().second;
}

int main()
{
	vector<string> input = { "w","wo","wor","worl", "world"};
    std::cout << longestWord(input) << endl;

	input = { "ogz","eyj","e","ey","hmn","v","hm","ogznkb","ogzn","hmnm","eyjuo","vuq","ogznk","og","eyjuoi","d" };
	std::cout << longestWord(input) << endl;
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
