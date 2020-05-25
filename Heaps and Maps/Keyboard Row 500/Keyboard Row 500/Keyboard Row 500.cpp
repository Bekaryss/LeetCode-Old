// Keyboard Row 500.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
private:
	unordered_set<char> first = { 'q','w','e','r','t','y','u','i','o','p' };
	unordered_set<char> second = { 'a','s','d','f','g','h','j','k','l' };
	unordered_set<char> third = { 'z','x','c','v','b','n','m' };

	bool inRow(string s) {
		int category = 0;
		for (int i = 0; i < s.size(); i++) {
			int c = 0;
			if (first.find(tolower(s[i])) != first.end()) {
				c = 1;
			}
			else if (second.find(tolower(s[i])) != second.end()) {
				c = 2;
			}
			else if (third.find(tolower(s[i])) != third.end()) {
				c = 3;
			}

			if (category == 0) {
				category = c;
			}
			else if (category != c) {
				return false;
			}
		}
		return true;
	}
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> res;
		for (string s : words) {
			if (inRow(s)) {
				res.push_back(s);
			}
		}
		return res;
	}
};

void PrintRes(vector<string> res) {
	for (string s : res) {
		cout << s << " ";
	}
	cout << endl;
}

int main()
{
	Solution s;
	vector<string> input = { "Hello", "Alaska", "Dad", "Peace" };
	PrintRes(s.findWords(input));
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
