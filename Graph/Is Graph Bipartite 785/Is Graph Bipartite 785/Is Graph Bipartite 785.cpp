// Is Graph Bipartite 785.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool dfs(int node, int color, unordered_map<int, vector<int>>& g, unordered_map<int, int>& visited) {
	if (visited[node] != 0) {
		return visited[node] == color;
	}
	visited[node] = color;
	for (int i = 0; i < g[node].size(); i++) {
		if (dfs(g[node][i], -color, g, visited) == false)
			return false;
	}
	return true;
}

bool isBipartite(vector<vector<int>>& graph) {
	unordered_map<int, vector<int>> g;
	unordered_map<int, int> visited;
	for (int i = 0; i < graph.size(); i++) {
		g[i] = {};
		visited[i] = 0;
		for (int j = 0; j < graph[i].size(); j++) {
			g[i].push_back(graph[i][j]);
		}
	}
	
	for (int i = 0; i < graph.size(); i++) {
		if (visited[i] == 0 && dfs(i, 1, g, visited) == false) {
			return false;
		}
	}
	return true;
}

int main()
{
	vector<vector<int>> input = { {1,3}, {0,2}, {1,3}, {0,2} };
    std::cout << (isBipartite(input) == true ? "true" : "false") << endl;
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
