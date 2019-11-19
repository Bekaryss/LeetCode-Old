// K Closest Points to Origin 973.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
	vector<vector<int>> res;
	auto comp = [](const vector<int> pointA, const vector<int> pointB)
	{
		return pow(pointA[0], 2) + pow(pointA[1], 2) > pow(pointB[0], 2) + pow(pointB[1], 2);
	};
	priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> q(comp);
	for (int i = 0; i < points.size(); i++) {
		q.push(points[i]);
	}
	for (int i = 0; i < K; i++) {
		res.push_back(q.top());
		q.pop();
	}
	return res;
}

vector<vector<int>> kClosestSolution(vector<vector<int>>& points, int K) {
	vector<vector<int>> res;
	auto comp = [](const vector<int> pointA, const vector<int> pointB)
	{
		return pow(pointA[0], 2) + pow(pointA[1], 2) < pow(pointB[0], 2) + pow(pointB[1], 2);
	};
	partial_sort(points.begin(), points.begin() + K, points.end(), comp);
	for (int i = 0; i < K; i++) {
		res.push_back(points[i]);
	}
	return res;
}

void PrintRes(vector<vector<int>> res) {
	for (vector<int> v : res) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << "end" << endl;
}

int main()
{
	vector<vector<int>> points = { {1, 3}, {-2, 2} };
	PrintRes(kClosest(points, 1));
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
