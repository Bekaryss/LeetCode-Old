// Divisor Game 1025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

bool divisorGame(int N) {
	return N % 2 == 0;
}

bool divisorGameDP(int N) {
	vector<bool> dp(N + 1);
	dp[1] = false;
	for (int i = 2; i <= N; i++) {
		for (int j = i - 1; j >= 1; j--) {
			if (i % j == 0 && dp[i - j] == false) {
				dp[i] = true;
				break;
			}
		}
	}
	return dp[N];
}

int main()
{
    std::cout << "Hello World!\n";
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
