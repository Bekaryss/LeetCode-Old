// The k Strongest Values in an Array 1471.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getStrongest(vector<int>& arr, int k) {
	int n = arr.size();
	sort(arr.begin(), arr.end());
	int m = (n - 1) / 2;
	int median = arr[m];
	sort(arr.begin(), arr.end(), [&median](int& a, int& b) {
		if (abs(a - median) == abs(b - median)) {
			return a > b;
		}
		return abs(a - median) > abs(b - median);
		});
	vector<int> res;
	for (int i = 0; i < k; i++) {
		res.push_back(arr[i]);
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
	vector<int> arr = { 1, 2, 3, 4, 5 };
	int k = 2;
	PrintRes(getStrongest(arr, k));
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
