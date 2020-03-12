// Sum of Mutated Array Closest to Target 1300.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findBestValue(vector<int>& arr, int target) {
	sort(arr.begin(), arr.end());
	int near = 100000, res = 0;
	int left = 0, right = 100000;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int cur = 0;
		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] <= mid) {
				cur += arr[j];
			}
			else {
				cur += mid;
			}
		}
		if (abs(target - near) >= abs(target - cur) && mid < target) {
			if (abs(target - near) == abs(target - cur)) {
				near = cur;
				res = min(mid, res);
			}
			else {
				near = cur;
				res = mid;
			}
		}
		if (target > cur) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return res;
}

int main()
{
	vector<int> arr = { 4, 9, 3 };
	int target = 10;
	std::cout << findBestValue(arr, target) << endl;
	arr = { 2, 3, 5 };
	target = 10;
	std::cout << findBestValue(arr, target) << endl;
	arr = { 60864, 25176, 27249, 21296, 20204 };
	target = 56803;
	std::cout << findBestValue(arr, target) << endl;

	arr = { 1547,83230,57084,93444,70879 };
	target = 71237;
	std::cout << findBestValue(arr, target) << endl;
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
