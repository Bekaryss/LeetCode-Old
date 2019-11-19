// Find Eventual Safe States 802.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool dfs(int node, unordered_map<int, vector<int>>& g, unordered_map<int, int>& visited) {
	if (visited[node] != 0) {
		return visited[node] == 1;
	}
	visited[node] = 2;
	for (int i = 0; i < g[node].size(); i++) {
		if (dfs(g[node][i], g, visited) == false) {
			return false;
		}
	}
	visited[node] = 1;
	return true;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	unordered_map<int, vector<int>> g;
	vector<int> res;
	unordered_map<int, int> visited;
	for (int i = 0; i < graph.size(); i++) {
		g[i] = {};
		for (int j = 0; j < graph[i].size(); j++) {
			g[i].push_back(graph[i][j]);
		}
		visited[i] = 0;
	}
	for (int i = 0; i < graph.size(); i++) {
		if (dfs(i, g, visited) == true) {
			res.push_back(i);
		}
	}
	return res;
}

void PrintRes(vector<int> res) {
	for (int i : res)
	{
		cout << i << " ";
	}
	cout << endl;
}


int main()
{
	vector<vector<int>> graph = { {1,2},{2,3},{5},{0},{5},{},{} };
	PrintRes(eventualSafeNodes(graph));

	graph = { {}, { 0,2,3,4 }, { 3 }, { 4 }, {} };
	PrintRes(eventualSafeNodes(graph));
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
