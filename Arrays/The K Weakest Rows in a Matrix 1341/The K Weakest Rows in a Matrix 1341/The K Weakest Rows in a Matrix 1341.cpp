// The K Weakest Rows in a Matrix 1341.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
	vector<pair<int, int>> rset;
	vector<int> res;
	for (int i = 0; i < mat.size(); i++) {
		int count = 0;
		for (int j : mat[i]) {
			count += j;
		}
		rset.push_back(make_pair(i, count));
	}
	sort(rset.begin(), rset.end(), [](const pair<int, int>& left, const pair <int, int>& right)
		{
			if (left.second == right.second) {
				return left.first < right.first;
			}
			else {
				return (left.second < right.second);
			}
		});
	int n = 0;
	for (auto i : rset) {
		if (n == k)
			break;
		res.push_back(i.first);
		n++;
	}
	return res;
}

void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<vector<int>> mat =
	{ {1, 1, 0, 0, 0},
	{1, 1, 1, 1, 0},
	{1, 0, 0, 0, 0},
	{1, 1, 0, 0, 0},
	{1, 1, 1, 1, 1} };
	int k = 3;
	PrintRes(kWeakestRows(mat, k));
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
