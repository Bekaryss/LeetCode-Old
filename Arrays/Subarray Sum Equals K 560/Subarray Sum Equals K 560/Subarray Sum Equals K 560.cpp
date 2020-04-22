// Subarray Sum Equals K 560.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
	int n = nums.size();
	int res = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += nums[j];
			if (sum == k) {
				res++;
			}
		}
	}
	return res;
}

int subarraySumMap(vector<int>& nums, int k) {
	unordered_map<int, int> map = { {0, 1} };
	int n = nums.size();
	int res = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += nums[i];
		if (map.find(sum - k) != map.end()) {
			res += map[sum - k];
		}
		map[sum]++;
	}
	return res;
}

int main()
{
	vector<int> nums = { 1,1,1 };
	std::cout << subarraySumMap(nums, 2) << endl;
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
