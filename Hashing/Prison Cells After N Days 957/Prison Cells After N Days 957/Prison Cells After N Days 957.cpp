// Prison Cells After N Days 957.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string vectorS(vector<int> cells) {
	string s;
	for (int i : cells) {
		string st = to_string(i);
		s += st;
	}
	return s;
}

vector<int> prisonAfterNDays(vector<int>& cells, int N) {
	unordered_map<string, int> seen;
	while (N > 0) {
		vector<int> cells2(8);
		string str = vectorS(cells);
		seen[str] = N--;
		for (int i = 1; i < 7; i++) {
			cells2[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
		}
		cells = cells2;
		str = vectorS(cells);
		if (seen.find(str) != seen.end()) {
			int var = seen[str] - N;
			N %= var;
			cout << N << endl;
		}
	}
	return cells;
}

void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> cells = { 0, 1, 0, 1, 1, 0, 0, 1 };
	int N = 7;
	PrintRes(prisonAfterNDays(cells, N));

	cells = { 1, 0, 0, 1, 0, 0, 1, 0 };

	N = 100;
	PrintRes(prisonAfterNDays(cells, N));

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
