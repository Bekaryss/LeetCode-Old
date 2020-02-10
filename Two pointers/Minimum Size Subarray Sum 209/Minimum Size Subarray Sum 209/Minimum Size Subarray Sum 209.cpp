// Minimum Size Subarray Sum 209.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
	if (nums.size() == 0) {
		return 0;
	}

	int i = 0, j = 0;
	int sum = 0;
	int total = 0;
	int min = 10000;
	while (i < nums.size()) {
		if (sum >= s) {
			if (min > total) {
				min = total;

			}
			total = 0;
			sum = 0;
			i++;
			j = i;
		}
		else if (sum < s && j < nums.size()) {
			sum = sum + nums[j];
			j++;
			total++;
		}
		else {
			sum = sum - nums[i];
			i++;
			total--;
		}


	}
	if (min != 10000)
		return min;
	else
		return 0;
};

int minSubArrayLenSolution(int s, vector<int>& nums)
{
	int n = nums.size();
	int ans = INT_MAX;
	int left = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += nums[i];
		while (sum >= s) {
			ans = min(ans, i + 1 - left);
			sum -= nums[left++];
		}
	}
	return (ans != INT_MAX) ? ans : 0;
}

int main()
{
	std::cout << "Hello World!\n";
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
