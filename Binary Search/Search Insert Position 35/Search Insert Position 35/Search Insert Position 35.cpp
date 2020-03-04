// Search Insert Position 35.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int l = 0, r = nums.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] > target) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return l;
}

int main()
{
	vector<int> input = { 1,3,5,6 };
	std::cout << searchInsert(input, 5) << endl;
	input = { 1,3,5,6 };
	std::cout << searchInsert(input, 2) << endl;
	input = { 1,3,5,6 };
	std::cout << searchInsert(input, 7) << endl;
	input = { 1,3,5,6 };
	std::cout << searchInsert(input, 0) << endl;
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
