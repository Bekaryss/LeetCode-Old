// Duplicate Zeros 1089.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void duplicateZeros(vector<int>& arr) {
	int n = arr.size();
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 0) {
			arr.insert(arr.begin() + i, 0);
			arr.pop_back();
			i++;
		}
	}
}

void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> input = { 1,0,2,3,0,4,5,0 };
	duplicateZeros(input);
	PrintRes(input);
	input = { 1,2,3 };
	duplicateZeros(input);
	PrintRes(input);
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
