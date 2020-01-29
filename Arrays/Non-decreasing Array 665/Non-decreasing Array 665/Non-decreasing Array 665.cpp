// Non-decreasing Array 665.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkPossibility(vector<int>& nums) {
	int cnt = 0;
	for (int i = 1; i < nums.size() && cnt <= 1; i++) {
		if (nums[i - 1] > nums[i]) {
			cnt++;
			if (i - 2 < 0 || nums[i - 2] <= nums[i])
				nums[i - 1] = nums[i];
			else
				nums[i] = nums[i - 1];
		}
	}
	return cnt <= 1;
}

int main()
{
	vector<int> input = { 4,2,3 };
	std::cout << (checkPossibility(input) == true ? "true" : "false") << endl;
	input = { 4, 2, 1 };
	std::cout << (checkPossibility(input) == true ? "true" : "false") << endl;
	input = { 3,4,2,3 };
	std::cout << (checkPossibility(input) == true ? "true" : "false") << endl;
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
