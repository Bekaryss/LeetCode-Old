// Moving Stones Until Consecutive II 1040.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> numMovesStonesII(vector<int>& stones) {
	sort(stones.begin(), stones.end());
	int i = 0, n = stones.size(), low = n;
	int high = max(stones[n - 1] - n + 2 - stones[1], stones[n - 2] - stones[0] - n + 2);
	for (int j = 0; j < n; ++j) {
		while (stones[j] - stones[i] >= n) ++i;
		if (j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2)
			low = min(low, 2);
		else
			low = min(low, n - (j - i + 1));
	}
	return { low, high };
}

void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> input = { 7,4,9 };
	PrintRes(numMovesStonesII(input));
	input = { 6,5,4,3,10 };
	PrintRes(numMovesStonesII(input));
	input = { 100,101,104,102,103 };
	PrintRes(numMovesStonesII(input));
	input = { 8,7,6,5,10 };
	PrintRes(numMovesStonesII(input));
	input = { 8,7,6,5,2 };
	PrintRes(numMovesStonesII(input));
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
