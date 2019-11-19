// Replace Words 648.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

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
	string search(string word) {
		Trie* node = this;
		string s = "";
		for (char ch : word) {
			if (node->isword == true)
				return s;
			if (!node->children.count(ch))
				return "";
			s += ch;
			node = node->children[ch];
		}
		return s;
	}
};

template<typename Out>
void split(const std::string& s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string& s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

string replaceWords(vector<string>& dict, string sentence) {
	Trie trie;
	for (string word : dict) {
		trie.insert(word);
	}
	vector<string> words = split(sentence, ' ');
	string ans = "";
	for (int i = 0; i < words.size(); i++) {
		string ts = trie.search(words[i]);
		if(ts != "") {
			if (i == words.size() - 1) {
				ans += ts;
			}
			else {
				ans += ts + " ";
			}
		}
		else {
			if (i == words.size() - 1) {
				ans += words[i];
			}
			else {
				ans += words[i] + " ";
			}
		}
	}
	return ans;
}

int main()
{
	vector<string>  dict = { "cat", "bat", "rat" };
	string sentence = "the cattle was rattled by the battery";
	cout << replaceWords(dict, sentence) << endl;

	dict = { "a", "aa", "aaa", "aaaa" };
	sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
	cout << replaceWords(dict, sentence) << endl;
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
