// Sort the Matrix Diagonally 1329.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
	vector<vector<int>> matrix;

	for (int i = mat.size() - 1; i >= 0; i--) {
		int i1 = i;
		int j = 0;
		vector<int> d;
		while (i1 < mat.size() && j < mat[0].size()) {
			d.push_back(mat[i1][j]);
			i1++;
			j++;
		}
		matrix.push_back(d);
	}
	for (int j = 1; j < mat[0].size(); j++) {
		int i = 0;
		int j1 = j;
		vector<int> d;
		while (i < mat.size() && j1 < mat[0].size()) {
			d.push_back(mat[i][j1]);
			i++;
			j1++;
		}
		matrix.push_back(d);
	}

	for (vector<int>& i : matrix) {
		sort(i.begin(), i.end());
	}
	int c = 0;
	for (int i = mat.size() - 1; i >= 0; i--) {
		int i1 = i;
		int j = 0;
		int d = 0;
		while (i1 < mat.size() && j < mat[0].size()) {
			mat[i1][j] = matrix[c][d];
			i1++;
			j++;
			d++;
		}
		c++;
	}
	c = mat.size();
	for (int j = 1; j < mat[0].size(); j++) {
		int i = 0;
		int j1 = j;
		int d = 0;
		while (i < mat.size() && j1 < mat[0].size()) {
			mat[i][j1] = matrix[c][d];
			i++;
			j1++;
			d++;
		}
		c++;
	}
	return mat;
}

int main()
{
	vector<vector<int>>  mat = { {3, 3, 1, 1},
								 {2, 2, 1, 2},
								 {1, 1, 1, 2} };
	vector<vector<int>> res = diagonalSort(mat);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
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
