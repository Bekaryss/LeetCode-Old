// Longest Common Subsequence 1143.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();
	vector<vector<int>> nm(n + 1, vector<int>(m + 1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				nm[i][j] = 0;
			}
			else if (text1[i - 1] == text2[j - 1]) {
				nm[i][j] = nm[i - 1][j - 1] + 1;
			}
			else {
				nm[i][j] = max(nm[i - 1][j], nm[i][j - 1]);
			}
		}
	}
	return nm[n][m];
}

int main()
{
	string text1 = "b", text2 = "c";
	std::cout << longestCommonSubsequence(text1, text2) << endl;
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
