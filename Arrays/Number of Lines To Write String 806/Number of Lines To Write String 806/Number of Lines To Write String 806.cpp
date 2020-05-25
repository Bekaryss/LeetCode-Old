// Number of Lines To Write String 806.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> numberOfLines(vector<int>& widths, string S) {
	int lines = 1, width = 0;
	for (int i = 0; i < S.size(); i++) {
		int num = widths[S[i] - 97];
		width += num;
		if (width > 100) {
			lines++;
			width = num;
		}
	}
	return { lines, width };
}

void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> widths = { 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
	string S = "abcdefghijklmnopqrstuvwxyz";
	PrintRes(numberOfLines(widths, S));
	widths = { 4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
	S = "bbbcccdddaaa";
	PrintRes(numberOfLines(widths, S));
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
