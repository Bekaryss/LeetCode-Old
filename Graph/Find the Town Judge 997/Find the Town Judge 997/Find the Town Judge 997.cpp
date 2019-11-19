// Find the Town Judge 997.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int findJudge(int N, vector<vector<int>>& trust) {
	vector<int> t(N + 1, 0);
	for (auto i : trust) {
		t[i[0]]--;
		t[i[1]]++;
	}
	for (int i = 1; i < t.size(); i++) {
		if (t[i] == N - 1)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int N = 2;
	vector<vector<int>> trust = { {1, 2} };
    std::cout << findJudge(N, trust) << endl;
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
