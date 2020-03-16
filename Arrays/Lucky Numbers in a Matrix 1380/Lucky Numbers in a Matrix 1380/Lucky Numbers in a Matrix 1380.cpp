// Lucky Numbers in a Matrix 1380.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> luckyNumbers(vector<vector<int>>& matrix) {
	int m = matrix.size(), n = matrix[0].size();
	vector<int> minR(m, INT_MAX), maxC(n, INT_MIN);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			minR[i] = min(minR[i], matrix[i][j]);
			maxC[j] = max(maxC[j], matrix[i][j]);
		}
	}
	vector<int> res;
	for (int i : minR) {
		for (int j : maxC) {
			if (i == j) {
				res.push_back(i);
			}
		}
	}
	return res;
}

void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << endl;
	}
	cout << endl;
}

int main()
{
	vector<vector<int>>  matrix = { { 3, 7, 8 }, { 9, 11, 13 }, { 15, 16, 17} };
	PrintRes(luckyNumbers(matrix));
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
