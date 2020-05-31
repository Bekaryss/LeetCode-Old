// Reorder Routes to Make All Paths 1466.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void dfs(unordered_map<int, vector<int>>& tree, unordered_set<int>& visited, unordered_set<int>& canGoZero, int index, int& res) {
	visited.insert(index);
	for (int z : tree[index]) {
		if (z > 0) {
			canGoZero.insert(z);
		}
	}
	for (int z : tree[index]) {
		if (canGoZero.find(abs(z)) == canGoZero.end()) {
			res++;
			canGoZero.insert(abs(z));
		}
		if (visited.find(abs(z)) == visited.end()) {
			dfs(tree, visited, canGoZero, abs(z), res);
		}
	}
}

int minReorder(int n, vector<vector<int>>& connections) {
	unordered_map<int, vector<int>> tree;
	for (auto i : connections) {
		tree[i[0]].push_back(-i[1]);
		tree[i[1]].push_back(i[0]);
	}
	unordered_set<int> canGoZero = { 0 };
	unordered_set<int> visited;
	int res = 0;
	dfs(tree, visited, canGoZero, 0, res);
	return res;
}

int main()
{
	vector<vector<int>> connections = { {0,1},{1,3},{2,3},{4,0},{4,5} };
	std::cout << minReorder(6, connections) << endl;
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
