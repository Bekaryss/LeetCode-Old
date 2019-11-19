// Coin Change 332.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
	int n = coins.size();
	int m = amount + 1;
	vector<int> dp(m, m);
	dp[0] = 0;
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (coins[j] <= i) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	if (dp[m - 1] == m) {
		return -1;
	}
	else {
		return dp[m - 1];
	}
}

int main()
{
	vector<int> coins = { 1, 2, 5 };
	int amount = 11;
	std::cout << coinChange(coins, amount) << endl;

	coins = { 2 };
	amount = 3;

	std::cout << coinChange(coins, amount) << endl;
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
