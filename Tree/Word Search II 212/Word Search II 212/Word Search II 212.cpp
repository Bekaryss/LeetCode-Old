// Word Search II 212.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Trie {
public:
	unordered_map<char, Trie*> children;
	string word = "";
};

Trie* buildTrie(vector<string> words) {
	Trie* root = new Trie();
	for (string word : words) {
		Trie* node = root;
		for (char ch : word) {
			if (!node->children.count(ch)) {
				node->children[ch] = new Trie();
			}
			node = node->children[ch];
		}
		node->word = word;
	}
	return root;
}

void dfs(vector<vector<char>>& board, int i, int j, Trie* curr, vector<string>& res) {
	char c = board[i][j];
	if (c == '#' || !curr->children.count(c))
		return;
	curr = curr->children[c];
	if (curr->word != "") {
		res.push_back(curr->word);
		curr->word = "";
	}
	board[i][j] = '#';
	if (i > 0)
		dfs(board, i - 1, j, curr, res);
	if (j > 0)
		dfs(board, i, j - 1, curr, res);
	if(i<board.size()-1)
		dfs(board, i + 1, j, curr, res);
	if (j < board[0].size() - 1)
		dfs(board, i, j + 1, curr, res);
	board[i][j] = c;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	Trie* root = buildTrie(words);
	vector<string> res;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			dfs(board, i, j, root, res);
		}
	}
	return res;
}

int main()
{
	vector<vector<char>> board = {
		{'o', 'a', 'a', 'n'},
		{'e', 't', 'a', 'e'},
		{'i', 'h', 'k', 'r'},
		{'i', 'f', 'l', 'v'}
	};
	vector<string> words = { "oath", "pea", "eat", "rain" };
	
	vector<string> res = findWords(board, words);

	for (string word : res)
	{
		cout << word << endl;
	}

	board = {
		{'a'},
		{'a'},
		
	};
	words = { "aaa" };

	res = findWords(board, words);

	for (string word : res)
	{
		cout << word << endl;
	}
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
