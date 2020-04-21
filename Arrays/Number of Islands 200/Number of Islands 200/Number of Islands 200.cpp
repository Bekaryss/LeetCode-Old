// Number of Islands 200.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(int i, int j, vector<vector<char>>& grid) {
	if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
		return;
	grid[i][j] = '0';
	dfs(i + 1, j, grid);
	dfs(i - 1, j, grid);
	dfs(i, j + 1, grid);
	dfs(i, j - 1, grid);
}

int numIslands(vector<vector<char>>& grid) {
	int res = 0;
	for (int i = 0; i < grid.size(); ++i)
		for (int j = 0; j < grid[0].size(); ++j)
			if (grid[i][j] == '1') {
				res++;
				dfs(i, j, grid);
			}
	return res;
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
