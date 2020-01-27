// Rank Transform of an Array 1331.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
	unordered_map<int, int> map;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> res;
	for (int i : arr) {
		pq.push(i);
	}
	int rank = 0;
	while (!pq.empty())
	{
		if (map.find(pq.top()) == map.end()) {
			rank++;
			map[pq.top()] = rank;
		}
		else {
			map[pq.top()] = rank;
		}
		pq.pop();
	}
	for (int i : arr) {
		res.push_back(map[i]);
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
	vector<int> arr = { 40, 10, 20, 30 };
	PrintRes(arrayRankTransform(arr));
	arr = { 100,100,100 };
	PrintRes(arrayRankTransform(arr));
	arr = { 37, 12, 28, 9, 100, 56, 80, 5, 12 };
	PrintRes(arrayRankTransform(arr));
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
