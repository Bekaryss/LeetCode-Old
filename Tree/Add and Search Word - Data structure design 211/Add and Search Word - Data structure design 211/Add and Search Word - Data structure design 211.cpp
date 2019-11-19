// Add and Search Word - Data structure design 211.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Trie {
private:
	unordered_map<char, Trie*> children = {};
	bool isword = false;
public:
	/** Initialize your data structure here. */
	Trie() {}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie* node = this;
		for (char ch : word) {
			if (!node->children.count(ch))
				node->children[ch] = new Trie();

			node = node->children[ch];
		}
		node->isword = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word, int start, Trie* node) {
		int size = word.size();
		for (int i = start; i < size; i++) {
			if (word[i] != '.') {
				if (!node->children.count(word[i]))
					return false;
				node = node->children[word[i]];
			}
			else {
				if (node->children.size() == 0) {
					return false;
				}
				else {
					Trie* tmp = node;
					for (int j = 0; j < 26; j++) {
						char index = 'a' + j;
						if (node->children.count(index)) {
							tmp = node->children[index];
							if (search(word, i + 1, tmp)) {
								return true;
							}
						}
					}
					return false;
				}	
			}
		}
		return node->isword;
	}
};

class WordDictionary {
private:
	Trie trie;
public:
	/** Initialize your data structure here. */
	WordDictionary() {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		trie.insert(word);
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return trie.search(word, 0, &trie);
	}
};

int main()
{
	WordDictionary wd;
	/*wd.addWord("bad");
	wd.addWord("dad");
	wd.addWord("mad");
	cout << (wd.search("pad") == true ? "true" : "false") << endl;
	cout << (wd.search("bad") == true ? "true" : "false") << endl;
	cout << (wd.search(".ad") == true ? "true" : "false") << endl;
	cout << (wd.search("b..") == true ? "true" : "false") << endl;*/


	wd.addWord("at");
	wd.addWord("and");
	wd.addWord("an");
	wd.addWord("add");
	cout << (wd.search(".a") == true ? "true" : "false") << endl;
	cout << (wd.search(".at") == true ? "true" : "false") << endl;
	wd.addWord("bat");
	cout << (wd.search(".at") == true ? "true" : "false") << endl;
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
