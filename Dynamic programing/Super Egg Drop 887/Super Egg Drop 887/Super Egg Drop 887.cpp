// Super Egg Drop 887.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int superEggDrop(int K, int N) {
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
	int m = 0;
	while (dp[m][K] < N) {
		m++;
		for (int k = 1; k <= K; ++k)
			dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
	}
	return m;
}

int main()
{
	std::cout << superEggDrop(2, 6) << endl;
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
