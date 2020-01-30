// Find Common Characters 1002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

vector<string> commonChars(vector<string>& A) {
	vector<unordered_map<char, int>> vchar(A.size());
	unordered_map<char, int> schar, rchar;
	int num = 0;
	for (int i = 0; i < A.size(); i++) {
		for (char c : A[i]) {
			if (schar[c] == num) {
				schar[c]++;
			}
			vchar[i][c]++;
		}
		num++;
	}
	for (auto i : schar) {
		if (i.second == num) {
			rchar[i.first] = 100;
		}
	}
	for (int i = 0; i < A.size(); i++) {
		for (auto j : rchar) {
			if (vchar[i].find(j.first) != vchar[i].end()) {
				int n = vchar[i][j.first];
				rchar[j.first] = min(j.second, n);
			}
		}
	}
	vector<string> res;
	for (auto j : rchar) {
		string s;
		while (j.second > 0) {
			s += j.first;
			res.push_back(s);
			s = "";
			j.second--;
		}
	}
	return res;
}

vector<string> commonCharsSolution(vector<string>& A) {
	vector<int> cnt(26, INT_MAX);
	vector<string> res;
	for (auto s : A) {
		vector<int> cnt1(26, 0);
		for (auto c : s)
			++cnt1[c - 'a'];
		for (auto i = 0; i < 26; ++i)
			cnt[i] = min(cnt[i], cnt1[i]);
	}
	for (auto i = 0; i < 26; ++i)
		for (auto j = 0; j < cnt[i]; ++j)
			res.push_back(string(1, i + 'a'));
	return res;
}

void PrintRes(vector<string> res) {
	for (string s : res) {
		cout << s << " ";
	}
	cout << endl;
}

int main()
{
	vector<string> input = { "bella","label","roller" };
	PrintRes(commonCharsSolution(input));
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
