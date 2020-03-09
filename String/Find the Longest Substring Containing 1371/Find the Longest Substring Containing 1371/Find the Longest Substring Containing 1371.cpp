// Find the Longest Substring Containing 1371.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int findTheLongestSubstring(string s) {
	unordered_map<char, int> voewlToIndex = { {'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4} };
	unordered_map<int, int> stateToIndex;
	stateToIndex.insert({ 0, -1 });
	int state = 0, maxLen = 0;
	for (int i = 0; i < s.size(); ++i) {
		char cur = s[i];
		if (voewlToIndex.find(cur) != voewlToIndex.end()) {
			int digit = voewlToIndex[cur];
			int num = 1 << digit;
			state ^= num;
		}
		if (stateToIndex.find(state) == stateToIndex.end())
			stateToIndex[state] = i;
		maxLen = max(maxLen, i - stateToIndex[state]);
	}
	return maxLen;
}

int main()
{

	std::cout << findTheLongestSubstring("bcabcbec") << endl;
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
