// Minimum Time to Collect All Apples in a Tree 1443.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool dfs(int key, unordered_map<int, vector<int>>& tree, vector<bool>& hasApple, int& res, unordered_map<int, bool>& visited) {
	if (visited.find(key) != visited.end()) {
		return false;
	}
	visited[key] = true;
	if (tree.find(key) == tree.end()) {
		return hasApple[key];
	}
	bool val = false;
	for (int i = 0; i < tree[key].size(); i++) {
		res++;
		bool curV = dfs(tree[key][i], tree, hasApple, res, visited);
		if (curV != true)
			res--;
		else
			res++;
		val |= curV;
	}

	if (hasApple[key] == true) {
		return true;
	}
	return val;
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
	unordered_map<int, vector<int>> tree;
	unordered_map<int, bool> visited;
	for (int i = 0; i < edges.size(); i++) {
		if (tree.find(edges[i][0]) == tree.end()) {
			tree[edges[i][0]] = { edges[i][1] };
		}
		else {
			tree[edges[i][0]].push_back(edges[i][1]);
		}
		if (tree.find(edges[i][1]) == tree.end()) {
			tree[edges[i][1]] = { edges[i][0] };
		}
		else {
			tree[edges[i][1]].push_back(edges[i][0]);
		}

	}
	int res = 0;
	dfs(0, tree, hasApple, res, visited);
	return res;
}

int main()
{
	int n = 7;
	vector<vector<int>> edges = { {0,1},{0,2},{1,4},{1,5},{2,3},{2,6} };
	vector<bool> hasApple = { false,false,true,false,true,true,false };
	std::cout << minTime(n, edges, hasApple) << endl;

	n = 4;
	edges = { {0, 2}, { 0,3 }, { 1,2 } };
	hasApple = { false, true, false, false };
	std::cout << minTime(n, edges, hasApple) << endl;
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
