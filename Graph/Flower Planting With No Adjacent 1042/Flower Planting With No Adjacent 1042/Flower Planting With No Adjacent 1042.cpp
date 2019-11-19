// Flower Planting With No Adjacent 1042.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
	unordered_map<int, unordered_set<int>> garden(N);
	vector<int> res(N);
	for (int i = 0; i < paths.size(); i++) {
		garden[paths[i][0]].insert(paths[i][1]);
		garden[paths[i][1]].insert(paths[i][0]);
	}
	for (int i = 1; i <= N; i++) {
		vector<bool> val(5, false);
		for (int j : garden[i]) {
			val[res[j-1]] = true;
		}
		for (int f = 1; f < val.size(); f++) {
			if (val[f] == false) {
				res[i-1] = f;
				break;
			}
		}
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
	int N = 3;
	vector<vector<int>> paths = { {1, 2}, {2, 3}, {3, 1} };
	PrintRes(gardenNoAdj(N, paths));
	N = 1;
	paths = { };
	PrintRes(gardenNoAdj(N, paths));
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
