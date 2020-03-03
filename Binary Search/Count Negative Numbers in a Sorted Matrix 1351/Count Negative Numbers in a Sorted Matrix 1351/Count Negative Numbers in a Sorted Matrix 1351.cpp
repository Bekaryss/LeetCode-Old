// Count Negative Numbers in a Sorted Matrix 1351.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int countNegatives(vector<vector<int>>& grid) {
	int count = 0;
	for (int i = grid.size() - 1; i >= 0; i--) {
		for (int j = grid[i].size() - 1; j >= 0; j--) {
			if (grid[i][j] < 0) {
				count++;
			}
			else {
				break;
			}
		}
	}
	return count;
}

int countNegativesBS(vector<vector<int>>& grid) {
	int count = 0;
	for (int i = grid.size() - 1; i >= 0; i--) {
		int l = 0, r = grid[i].size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (grid[i][mid] < 0) {
				r--;
			}
			else {
				l++;
			}
		}
		count += (grid[i].size() - l);
	}
	return count;
}

int main()
{
	vector<vector<int>> input = { {4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3} };
	std::cout << countNegativesBS(input) << endl;
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
