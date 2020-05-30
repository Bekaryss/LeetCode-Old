// Check If a Word Occurs As a Prefix 1455.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int isPrefixOfWord(string sentence, string searchWord) {
	vector<string> words;
	int last = 0;
	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] == ' ') {
			words.push_back(sentence.substr(last, i - last));
			last = i + 1;
		}
		if (i + 1 == sentence.size()) {
			words.push_back(sentence.substr(last, i + 1 - last));
		}
	}
	int index = 1;
	for (string s : words) {
		int i = 0, j = 0;
		bool pref = true;
		if (s.size() < searchWord.size())
			pref = false;
		while (i < s.size() && j < searchWord.size()) {
			if (s[i] != searchWord[j]) {
				pref = false;
				break;
			}
			i++;
			j++;
		}
		if (pref == true) {
			return index;
		}
		index++;
	}
	return -1;
}

int main()
{
	string sentence = "i am tired", searchWord = "you";
	std::cout << isPrefixOfWord(sentence, searchWord) << endl;
	sentence = "i use triple pillow", searchWord = "pill";
	std::cout << isPrefixOfWord(sentence, searchWord) << endl;
	sentence = "hello from the other side", searchWord = "they";
	std::cout << isPrefixOfWord(sentence, searchWord) << endl;
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
