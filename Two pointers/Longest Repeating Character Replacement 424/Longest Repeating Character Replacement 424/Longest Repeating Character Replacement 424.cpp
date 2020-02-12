// Longest Repeating Character Replacement 424.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int characterReplacement(string s, int k) {
	int n = s.size();
	vector<int> char_counts(26);
	int i = 0, res = 0, max_count = 0;
	for (int j = 0; j < n; j++) {
		char_counts[s[j] - 'A']++;
		max_count = max(max_count, char_counts[s[j] - 'A']);
		while (j - i - max_count + 1 > k) {
			char_counts[s[i] - 'A']--;
			i++;
		}

		res = max(res, j - i + 1);
	}
	return res;
}

int main()
{
	std::cout << characterReplacement("ABAB", 2) << endl;
	std::cout << characterReplacement("AABABBA", 1) << endl;
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
