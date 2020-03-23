// Shift 2D Grid 1260.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
	int n = grid.size() - 1, m = grid[0].size() - 1;
	while (k > 0) {
		int tmp = grid[n][m];
		for (int i = n; i >= 0; i--) {
			for (int j = m; j >= 0; j--) {
				if (j < m) {
					grid[i][j + 1] = grid[i][j];
				}
				if (j == m && i < n) {
					grid[i + 1][0] = grid[i][j];
				}
			}
		}
		grid[0][0] = tmp;
		k--;
	}
	return grid;
}

void PrintRes(vector<vector<int>> res) {
	for (auto i : res) {
		for (int j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<int>> grid = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int k = 1;
	PrintRes(shiftGrid(grid, k));

	grid = { {3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13} };
	k = 4;
	PrintRes(shiftGrid(grid, k));
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
