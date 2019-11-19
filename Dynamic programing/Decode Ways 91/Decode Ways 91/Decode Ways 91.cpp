// Decode Ways 91.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDecodings(string s) {
	int n = s.size();
	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = s[0] == '0' ? 0 : 1;
	for (int i = 2; i <= n; i++) {
		int oneDigit = s[i - 1] - '0';
		int twoDigit = stoi(s.substr(i - 2, 2));
		if (1 <= oneDigit && oneDigit <= 9) {
			dp[i] += dp[i - 1];
		}
		if (10 <= twoDigit && twoDigit <= 26) {
			dp[i] += dp[i - 2];
		}
	}
	return dp[n];
}

int main()
{
	std::cout << numDecodings("12") << endl;
	std::cout << numDecodings("226") << endl;
	std::cout << numDecodings("101") << endl;
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
