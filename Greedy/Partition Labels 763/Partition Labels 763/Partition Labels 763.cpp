// Partition Labels 763.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> partitionLabels(string S) {
	unordered_map<char, int> map;
	for (int i = 0; i < S.size(); i++) {
		map[S[i]] = i;
	}
	vector<int> res;
	int j = 0, anchor = 0;
	for (int i = 0; i < S.size(); i++)
	{
		j = max(j, map[S[i]]);
		if (i == j) {
			res.push_back(i - anchor + 1);
			anchor = i + 1;
		}
	}
	return res;
}

int main()
{
	vector<int> res = partitionLabels("ababcbacadefegdehijhklij");
	for (int i : res)
	{
		cout << i << " ";
	}
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
