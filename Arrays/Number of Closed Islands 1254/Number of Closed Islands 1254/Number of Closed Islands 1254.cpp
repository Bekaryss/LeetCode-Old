// Number of Closed Islands 1254.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int dfs(int i, int j, vector<vector<int>>& grid) {
	if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
		return 0;
	if (grid[i][j] > 0)
		return 1;
	grid[i][j] = 2;
	return dfs(i + 1, j, grid) * dfs(i - 1, j, grid) * dfs(i, j + 1, grid) * dfs(i, j - 1, grid);
}

int closedIsland(vector<vector<int>>& grid) {
	int cnt = 0;
	for (int i = 0; i < grid.size(); ++i)
		for (int j = 0; j < grid[0].size(); ++j)
			if (grid[i][j] == 0)
				cnt += dfs(i, j, grid);
	return cnt;
}

void PrintMatrix(vector<vector<int>>& grid) {
	for (auto i : grid) {
		for (int j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<int>> grid = { {1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0} };
	/*std::cout << closedIsland(grid) << endl;
	PrintMatrix(grid);
	grid = { {0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0} };
	std::cout << closedIsland(grid) << endl;
	grid = { {1} };
	std::cout << closedIsland(grid) << endl;*/

	grid = { {1,1,1},{0,0,1},{1,1,1} };
	std::cout << closedIsland(grid) << endl;
	PrintMatrix(grid);
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
