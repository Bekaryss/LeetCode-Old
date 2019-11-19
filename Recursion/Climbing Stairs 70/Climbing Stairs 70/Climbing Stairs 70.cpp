// Climbing Stairs 70.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int i, int n, vector<int>& memo) {
	if (i > n) {
		return 0;
	}
	if (i == n) {
		return 1;
	}
	if (memo[i] > 0) {
		return memo[i];
	}
	memo[i] = climbStairs(i + 1, n, memo) + climbStairs(i + 2, n, memo);
	return memo[i];
}

int climbStairs(int n) {
	vector<int> memo(n + 1);
	return climbStairs(0, n, memo);
}

int climbStairsDP(int n) {
	if (n == 0 || n == 1)
		return 1;
	vector<int> dp(n + 1);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main()
{
    std::cout << climbStairsDP(2) << endl;
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
