// Maximum Number of Vowels 1456.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int maxVowels(string s, int k) {
	unordered_set<char> vowel = { 'a', 'e', 'i', 'o', 'u' };
	int last = 0;
	int res = 0;
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (vowel.find(s[i]) != vowel.end()) {
			count++;
		}
		if (k <= i - last) {
			if (vowel.find(s[last]) != vowel.end()) {
				count--;
			}
			last++;
		}
		res = max(res, count);
	}
	return res;
}

int main()
{
	string s = "abciiidef";
	int k = 3;
	std::cout << maxVowels(s, k) << endl;
	s = "aeiou"; k = 2;
	std::cout << maxVowels(s, k) << endl;
	s = "leetcode"; k = 3;
	std::cout << maxVowels(s, k) << endl;
	s = "rhythms"; k = 4;
	std::cout << maxVowels(s, k) << endl;
	s = "tryhard"; k = 4;
	std::cout << maxVowels(s, k) << endl;
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
