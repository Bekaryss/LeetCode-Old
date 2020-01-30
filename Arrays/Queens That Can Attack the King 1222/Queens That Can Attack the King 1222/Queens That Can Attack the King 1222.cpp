// Queens That Can Attack the King 1222.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
	vector<vector<int>> res;
	vector<vector<int>> dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
	vector<vector<bool>> ch(8, vector<bool>(8, false));
	for (auto i : queens) {
		ch[i[0]][i[1]] = true;
	}
	for (int i = 0; i < 8; i++) {
		int x = king[0], y = king[1];
		while ((x >= 0 && x < 8) && (y >= 0 && y < 8)) {
			if (ch[x][y] == true) {
				res.push_back({ x,y });
				break;
			}
			x += dir[i][0];
			y += dir[i][1];
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
	vector<vector<int>> queens = { {0, 1},{1, 0},{4, 0},{0, 4},{3, 3},{2, 4} };
	vector<int> king = { 0, 0 };
	vector<vector<int>> res = queensAttacktheKing(queens, king);
	PrintRes(res);
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
