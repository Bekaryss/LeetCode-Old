// How Many Numbers Are Smaller Than the Current Number 1365.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
	vector<int> arr = nums;
	unordered_map<int, int> map;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < nums.size(); i++) {
		map[arr[i]] = i;
	}
	for (int i = 0; i < nums.size(); i++) {
		nums[i] = map[nums[i]];
	}
	return nums;
}

void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> input = { 8,1,2,2,3 };
	PrintRes(smallerNumbersThanCurrent(input));
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
