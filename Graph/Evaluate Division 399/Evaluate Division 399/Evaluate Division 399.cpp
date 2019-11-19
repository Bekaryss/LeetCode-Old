// Evaluate Division 399.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;

unordered_map<string, unordered_map<string, double>> buildGraph(vector<vector<string>>& equations, vector<double>& values){
	unordered_map<string, unordered_map<string, double>> graph;
	string u, v;

	for (int i = 0; i < equations.size(); i++) {
		u = equations[i][0];
		v = equations[i][1];

		graph[u][v] = values[i];
		graph[v][u] = 1 / values[i];
	}
	return graph;
}

double getPathWeight(string start, string end, unordered_set<string>& visited, unordered_map<string, unordered_map<string, double>>& graph) {
	if (graph.find(start) == graph.end())
		return -1.0;

	if (graph[start].find(end) != graph[start].end())
		return graph[start][end];

	visited.insert(start);
	for (auto neighbour : graph[start]) {
		if (visited.find(neighbour.first) == visited.end()) {
			double pw = getPathWeight(neighbour.first, end, visited, graph);
			if (pw != -1.0) {
				return pw * neighbour.second;
			}
		}
	}
	return -1.0;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	unordered_map<string, unordered_map<string, double>> graph = buildGraph(equations, values);
	vector<double> res;
	for (int i = 0; i < queries.size(); i++) {
		unordered_set<string> visited;
		res.push_back(getPathWeight(queries[i][0], queries[i][1], visited, graph));
	}
	return res;
}

void PrintRes(vector<double> res) {
	for (double i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<vector<string>> equations = { {"a", "b"}, {"b", "c"} };
	vector<double> values = { 2.0, 3.0 };
	vector<vector<string>> queries = { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };
	PrintRes(calcEquation(equations, values, queries));
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
