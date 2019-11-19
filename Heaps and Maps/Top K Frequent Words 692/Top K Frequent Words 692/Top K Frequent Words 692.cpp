// Top K Frequent Words 692.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
	unordered_map<string, int> counter;
	vector<string> res;
	for (int i = 0; i < words.size(); i++) {
		counter[words[i]]++;
	}

	auto compare = [](pair<string, int> a, pair<string, int> b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second < b.second;
	};

	priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)> q(compare);
	for (auto x : counter) {
		q.push(x);
	}
	int n = 0;
	while (!q.empty()) {
		if (n == k)
			break;
		pair<string, int> val = q.top();
		q.pop();
		res.push_back(val.first);
		n++;
	}
	return res;
}

int main()
{
	vector<string> input = { "i", "love", "leetcode", "i", "love", "coding" };
	input = topKFrequent(input, 2);
	for (string s : input) {
		cout << s << " ";
	}
	cout << endl;
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
