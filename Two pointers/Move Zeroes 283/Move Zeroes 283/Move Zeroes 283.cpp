// Move Zeroes 283.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
	int i = 0, j = 0;
	while (i < nums.size()) {
		if (nums[i] != 0 && nums[j] == 0) {
			swap(nums[i], nums[j]);
		}
		if (nums[j] != 0) {
			j++;
		}
		i++;
	}
}

void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> input = { 0,1,0,3,12 };
	moveZeroes(input);
	PrintRes(input);
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
