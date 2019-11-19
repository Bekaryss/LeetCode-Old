// Sort Characters By Frequency 451.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

string frequencySort(string s) {
	unordered_map<char, int> counter;
	string res = "";
	for (int i = 0; i < s.size(); i++) {
		counter[s[i]]++;
	}

	auto compare = [](pair<char, int> a, pair<char, int> b) {
		return a.second < b.second;
	};

	priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(compare)> q(compare);
	for (auto x : counter) {
		q.push(x);
	}

	while (!q.empty()) {
		pair<char, int> val = q.top();
		q.pop();
		res.append(val.second, val.first);
	}
	return res;
}

int main()
{
    std::cout << frequencySort("tree");
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
