// Koko Eating Bananas 875.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int minEatingSpeed(vector<int>& piles, int H) {
	int res;
	int left = 1, right = 1000000000;
	while (left < right) {
		double mid = left + (right - left) / 2;
		int counter = 0;
		for (int i : piles) {
			counter += ceil(i / mid);
		}
		if (counter > H) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left;
}

int minEatingSpeedMy(vector<int>& piles, int H) {
	int res;
	int left = 1, right = 1000000000;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int counter = 0;
		for (int i : piles) {
			counter += i / mid;
			if (i % mid != 0) {
				counter++;
			}
			if (counter > H)
				break;
		}
		if (counter <= H) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int main()
{
	vector<int> piles = { 3, 6, 7, 11 };
	int H = 8;
	std::cout << minEatingSpeed(piles, H) << endl;

	piles = { 30, 11, 23, 4, 20 };
	H = 5;
	std::cout << minEatingSpeed(piles, H) << endl;

	piles = { 30, 11, 23, 4, 20 };
	H = 6;
	std::cout << minEatingSpeed(piles, H) << endl;
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
