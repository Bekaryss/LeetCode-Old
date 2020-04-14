// Counting Elements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countElements(vector<int>& arr) {
	unordered_set<int> set;
	int res = 0;
	for (int i : arr) {
		set.insert(i);
	}
	for (int i : arr) {
		if (set.find(i + 1) != set.end()) {
			res++;
		}
	}
	return res;
}

int main()
{
	vector<int> arr = { 1,2,3 };
	std::cout << countElements(arr) << endl;
	arr = { 1,1,3,3,5,5,7,7 };
	std::cout << countElements(arr) << endl;
	arr = { 1,3,2,3,5,0 };
	std::cout << countElements(arr) << endl;
	arr = { 1,1,2,2 };
	std::cout << countElements(arr) << endl;
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
