// Coin Change 2 512.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int change(int amount, vector<int>& coins) {
	int n = coins.size() + 1;
	int m = amount + 1;
	vector<vector<int>> dp(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == 0) {
				dp[i][j] = 1;
			}
			else if (i == 0) {
				dp[i][j] = 0;
			}
			else if (coins[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
			}
		}
	}
	return dp[n-1][m-1];
}

int main()
{
	vector<int> coins = { 1, 2, 5 };
    std::cout << change(5, coins) << endl;
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
