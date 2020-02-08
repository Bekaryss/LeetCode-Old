// Number of Sub-arrays of Size K 1343.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
	int sum = 0, res = 0;
	int i = 0, j = 0;
	int count = 0;
	while (i < arr.size()) {
		if (count < k) {
			sum += arr[i];
			count++;
			i++;
		}
		else {
			sum -= arr[j];
			j++;
			count--;
		}
		if (count == k && sum / k >= threshold) {
			res++;
		}
	}
	return res;
}

int main()
{
	vector<int> arr = { 2, 2, 2, 2, 5, 5, 5, 8 };
	std::cout << numOfSubarrays(arr, 3, 4) << endl;
	arr = { 1, 1, 1, 1, 1 };
	std::cout << numOfSubarrays(arr, 1, 0) << endl;
	arr = { 11, 13, 17, 23, 29, 31, 7, 5, 2, 3 };
	std::cout << numOfSubarrays(arr, 3, 5) << endl;
	arr = { 7, 7, 7, 7, 7, 7, 7 };
	std::cout << numOfSubarrays(arr, 7, 7) << endl;
	arr = { 4,4,4,4 };
	std::cout << numOfSubarrays(arr, 4, 1) << endl;
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
