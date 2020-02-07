// 3Sum 15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	int i = 0;
	while (i < nums.size()) {
		int j = i + 1, n = nums.size() - 1;
		while (j < n) {
			int sum = nums[i] + nums[j] + nums[n];
			if (sum > 0) {
				n--;
			}
			else if (sum < 0) {
				j++;
			}
			else {
				res.push_back({ nums[i], nums[j], nums[n] });
				j++;
				n--;
				while (j < n && nums[j] == nums[j - 1]) j++;
				while (j < n && nums[n] == nums[n + 1]) n--;
			}
		}
		i++;
		while (i < nums.size() && nums[i] == nums[i - 1]) i++;
	}
	return res;
}

void PrintRes(vector<vector<int>> res) {
	for (auto i : res) {
		for (int j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	vector<int> input = { -1, 0, 1, 2, -1, -4 };
	PrintRes(threeSum(input));
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
