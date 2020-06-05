// Random Pick with Weight 528.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>

using namespace std;

class Solution {
	vector<vector<int>> arr;
	int total = 0;

public:
	Solution(vector<int>& w) {
		int count = 0;
		for (int i : w) {
			arr.push_back({ count + 1 , count += i });
		}
		total = count;
		srand(time(NULL));
	}

	int pickIndex() {
		int random = (rand() % total) + 1;
		int l = 0, r = arr.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (arr[mid][0] <= random && random <= arr[mid][1]) {
				return mid;
			}
			if (arr[mid][0] > random) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		return 0;
	}
};

int main()
{
	vector<int> input = { 1,5 };
	Solution s(input);
	for (int i = 0; i < 6; i++) {
		std::cout << s.pickIndex() << endl;
	}
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
