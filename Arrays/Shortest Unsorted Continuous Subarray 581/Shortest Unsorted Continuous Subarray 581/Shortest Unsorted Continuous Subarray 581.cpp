// Shortest Unsorted Continuous Subarray 581.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int findUnsortedSubarraySolution(vector<int>& nums) {
	vector<int> snums = nums;
	sort(snums.begin(), snums.end());
	int start = snums.size(), end = 0;
	for (int i = 0; i < snums.size(); i++) {
		if (snums[i] != nums[i]) {
			start = min(start, i);
			end = max(end, i);
		}
	}
	return (end - start >= 0 ? end - start + 1 : 0);
}

int findUnsortedSubarray(vector<int>& nums) {
	priority_queue<int, vector<int>, greater<int>> minV;
	priority_queue<int, vector<int>, less<int>> maxV;
	for (int i : nums) {
		minV.push(i);
		maxV.push(i);
	}
	int start = nums.size();
	for (int i = 0; i < nums.size(); i++) {
		if (minV.top() == nums[i]) {
			minV.pop();
		}
		else {
			start = i;
			break;
		}
	}
	int end = 0;
	for (int i = nums.size()-1; i >= 0; i--) {
		if (maxV.top() == nums[i]) {
			maxV.pop();
		}
		else {
			end = i;
			break;
		}
	}
	if (end - start > 0) {
		return end - start + 1;
	}
	else {
		return 0;
	}

}

int main()
{
	vector<int> input = { 2, 6, 4, 8, 10, 9, 15 };
	std::cout << findUnsortedSubarray(input) << endl;
	input = { 1,3,2,2,2 };
	std::cout << findUnsortedSubarray(input) << endl;
	input = { 3,2,3,2,4 };
	std::cout << findUnsortedSubarray(input) << endl;
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
