// Partition Array for Maximum Sum 1043.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSumAfterPartitioning(vector<int>& A, int K) {
	int N = A.size();
	vector<int> dp(N);
 	for (int i = 0; i < N; i++) {
		int curMax = 0;
		for (int k = 1; k <= K && i - k + 1 >= 0; k++) {
			curMax = max(curMax, A[i - k + 1]);
			dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + curMax * k);
		}
	}
	return dp[N - 1];
}

int main()
{
	vector<int> A = { 1, 15, 7, 9, 2, 5, 10 };
	int K = 3;
    std::cout << maxSumAfterPartitioning(A, K) << endl;
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
