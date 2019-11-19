// Redundant Connection 684.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;



class Solution {
	unordered_set<int> seen;
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		unordered_map<int, vector<int>> graph;
		for (auto edge : edges) {
			seen.clear();
			if (!graph[edge[0]].empty() && !graph[edge[1]].empty() && dfs(graph, edge[0], edge[1])) {
				return edge;
			}
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		return {};
	}

	bool dfs(unordered_map<int, vector<int>> graph, int source, int target) {
		if (seen.find(source) == seen.end()) {
			seen.insert(source);
			if (source == target)
				return true;
			for (int nei : graph[source]) {
				if (dfs(graph, nei, target))
					return true;
			}
		}
		return false;
	}
};

class DSU {
	vector<int> parent;
	vector<int> rank;
public:
	DSU(int size) {
		for (int i = 0; i < size; i++) {
			parent.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int x) {
		if (parent[x] != x)
			parent[x] = find(parent[x]);
		return parent[x];
	}

	bool uni(int x, int y) {
		int xr = find(x), yr = find(y);
		if (xr == yr) {
			return false;
		}
		else if (rank[xr] < rank[yr]) {
			parent[xr] = yr;
		}
		else if (rank[xr] > rank[yr]) {
			parent[yr] = xr;
		}
		else {
			parent[yr] = xr;
			rank[xr]++;
		}
		return true;
	}
};

class SolutionDSU {
	int MAX_EDGE_VAL = 1001;
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		DSU dsu(MAX_EDGE_VAL);
		for (auto edge : edges) {
			if (!dsu.uni(edge[0], edge[1]))
				return edge;
		}
		return {};
	}
	
};



void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	SolutionDSU sl;
	vector<vector<int>> input = { {1, 2}, { 1, 3 }, { 2, 3 } };
	PrintRes(sl.findRedundantConnection(input));

	input = { {1,2}, {2,3}, {3,4}, {1,4}, {1,5} };
	PrintRes(sl.findRedundantConnection(input));
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
