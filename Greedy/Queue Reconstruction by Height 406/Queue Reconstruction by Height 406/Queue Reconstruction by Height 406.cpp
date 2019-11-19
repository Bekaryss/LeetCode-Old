// Queue Reconstruction by Height 406.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	vector<vector<int>> res;
	sort(people.begin(), people.end(), [](const vector<int>& first, const vector<int>& second) 
		{ 
			return first[0] > second[0] || (first[0] == second[0] && first[1] < second[1]); 
		});
	for (vector<int> i : people) {
		res.insert(res.begin() + i[1], i);
	}
	return res;
}

void PrintRes(vector<vector<int>> res) {
	for (auto i : res) {
		for (int j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	vector<vector<int>> input = { {7, 0},{4, 4},{7, 1},{5, 0},{6, 1},{5, 2} };
	PrintRes(reconstructQueue(input));
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
