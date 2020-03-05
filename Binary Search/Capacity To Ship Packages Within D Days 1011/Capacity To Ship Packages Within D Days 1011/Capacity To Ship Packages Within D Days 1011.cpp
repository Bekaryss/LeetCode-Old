// Capacity To Ship Packages Within D Days 1011.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int shipWithinDays(vector<int>& weights, int D) {
	int left = 0, right = 0;
	for (int w : weights) {
		left = max(left, w);
		right += w;
	}
	while (left < right) {
		int mid = (left + right) / 2, need = 1, cur = 0;
		for (int i = 0; i < weights.size(); i++) {
			if (need > D)
				break;
			if (cur + weights[i] > mid) {
				cur = 0;
				need++;
			}
			cur += weights[i];
		}
		if (need > D) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left;
}

int main()
{
	vector<int> input = { 1,2,3,4,5,6,7,8,9,10 };
	std::cout << shipWithinDays(input, 5) << endl;
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
