// Minimum Path Sum 64.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	int n = grid.size(), m = grid[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0 && j > 0) {
				int left = grid[i][j - 1], top = grid[i - 1][j];
				grid[i][j] += min(left, top);
			}
			else if (i == 0 && j != 0) {
				grid[i][j] += grid[i][j - 1];
			}
			else if (j == 0 && i != 0) {
				grid[i][j] += grid[i - 1][j];
			}
		}
	}
	return grid[n - 1][m - 1];
}

int main()
{
	vector<vector<int>> grid = {
		{1, 3, 1},
		{ 1,5,1 },
		{ 4,2,1 }
	};
	std::cout << minPathSum(grid) << endl;
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
