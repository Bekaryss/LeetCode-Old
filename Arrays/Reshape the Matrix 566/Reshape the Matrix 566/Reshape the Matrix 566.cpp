// Reshape the Matrix 566.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
	int r1 = nums.size(), c1 = nums[0].size();
	if (r * c > r1 * c1) {
		return nums;
	}
	vector<vector<int>> res(r, vector<int>(c));
	int i = 0, j = 0;
	for (int f = 0; f < r1; f++) {
		for (int g = 0; g < c1; g++) {
			res[i][j] = nums[f][g];
			j++;
			if (j == c) {
				i++;
				j = 0;
			}
		}
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
}

int main()
{
	vector<vector<int>> nums = { {1, 2}, {3, 4} };
	int r = 1, c = 4;
	PrintRes(matrixReshape(nums, r, c));
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
