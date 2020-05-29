// Fair Candy Swap 888.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
	vector<int> res;
	int sumA = 0, sumB = 0;
	unordered_set<int> setB;
	for (int i : A) {
		sumA += i;
	}
	for (int i : B) {
		sumB += i;
		setB.insert(i);
	}
	int x = (sumB - sumA) / 2;
	for (int i:A) {
		if (setB.find(i + x) != setB.end()) {
			return { i, i + x };
		}
	}
	return {};
}

void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> A = { 1, 1 }, B = { 2, 2 };
	PrintRes(fairCandySwap(A, B));
	A = { 1, 2 }, B = { 2, 3 };
	PrintRes(fairCandySwap(A, B));
	A = { 2 }, B = { 1, 3 };
	PrintRes(fairCandySwap(A, B));
	A = { 1, 2, 5 }, B = { 2, 4 };
	PrintRes(fairCandySwap(A, B));
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
