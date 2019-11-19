// Palindrome Pairs 336.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Trie {
public:
	unordered_map<char, Trie*> children = {};
	int wordId = -1;
	vector<int> wordIdList = {};
};

bool isPalindrome(string word, int i, int j) {
	while (i < j) {
		if (word[i++] != word[j--])
			return false;
	}
	return true;
}


void insert(string word, Trie* root, int index) {
	for (int i = word.size() - 1; i >= 0; i--) {
		char ch = word[i];

		if (!root->children.count(ch)) {
			root->children[ch] = new Trie();
		}

		if (isPalindrome(word, 0, i)) {
			root->wordIdList.push_back(index);
		}

		root = root->children[ch];
	}

	root->wordIdList.push_back(index);
	root->wordId = index;
}

void search(string& word, int i, Trie* root, vector<vector<int>>& res) {
	for (int j = 0; j < word.size(); j++) {
		if (root->wordId >= 0 && root->wordId != i && isPalindrome(word, j, word.size() - 1)) {
			res.push_back({ i, root->wordId });
		}
		root = root->children[word[j]];
		if (root == NULL)
			return;
	}

	for (int j : root->wordIdList) {
		if (i != j) {
			res.push_back({ i, j });
		}
	}
}

vector<vector<int>> palindromePairs(vector<string>& words) {
	Trie* root = new Trie();
	vector<vector<int>> res;

	for (int i = 0; i < words.size(); i++) {
		insert(words[i], root, i);
	}

	for (int i = 0; i < words.size(); i++) {
		search(words[i], i, root, res);
	}

	return res;
}

void PrintRes(vector<vector<int>> res) {
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	vector<string> input = { "abcd", "dcba", "lls", "s", "sssll" };
	PrintRes(palindromePairs(input));
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
