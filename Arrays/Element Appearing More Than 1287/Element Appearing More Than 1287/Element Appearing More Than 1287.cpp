// Element Appearing More Than 1287.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findSpecialInteger(vector<int>& arr) {
	int res = 0;
	unordered_map<int, int> map;
	for (int i = 0; i < arr.size(); i++) {
		map[arr[i]]++;
	}
	int tf = toupper((double)arr.size() / 4);
	int minv = arr.size();
	for (auto i : map) {
		if (i.second > tf && i.second <= minv) {
			minv = i.second;
			res = i.first;
		}
	}
	return res;
}

int findSpecialIntegerSolution(vector<int>& arr) {
	int n = arr.size(), l = arr.size() / 4;

	for (int i = 0; i < arr.size() - l; i++) {
		if (arr[i] == arr[i + l]) {
			return arr[i];
		}
	}

	return -1;
}

int binarySearch(vector<int>& arr, int target) {
	int l = 0, r = arr.size() - 1;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (target > arr[mid]) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return r;
}

int findSpecialIntegerSolutionBS(vector<int>& arr) {
	if (arr.size() == 1)
		return arr[0];
	int n = arr.size();
	vector<int> quar = { arr[n / 4], arr[n / 2], arr[n * 3 / 4] };
	for (int i : quar) {
		int first = binarySearch(arr, i);
		if (arr[first + n / 4] == i) {
			return arr[first];
		}
	}
	return -1;
}

int main()
{
	vector<int> arr = { 1, 2, 2, 6, 6, 6, 6, 7, 10 };
	std::cout << findSpecialIntegerSolutionBS(arr) << endl;
	arr = { 6700,8858,8858,8858,8858 };
	std::cout << findSpecialIntegerSolutionBS(arr) << endl;
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
