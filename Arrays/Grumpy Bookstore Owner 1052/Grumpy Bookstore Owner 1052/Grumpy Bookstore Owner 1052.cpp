// Grumpy Bookstore Owner 1052.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
	int grumpy_s = 0, dir_s = 0, n = customers.size();
	for (int i = 0; i < n; i++) {
		if (grumpy[i] == 0) {
			dir_s += customers[i];
			customers[i] = 0;
		}
	}
	int cur = 0;
	int i = 0, j = 0;
	while (i < n) {
		if (i - j < X) {
			cur += customers[i];
			i++;
		}
		else {
			if (grumpy[j] == 1)
				cur -= customers[j];
			j++;
		}
		grumpy_s = max(grumpy_s, cur);
	}
	return dir_s + grumpy_s;
}

int main()
{
	vector<int> customers = { 1, 0, 1, 2, 1, 1, 7, 5 }, grumpy = { 0, 1, 0, 1, 0, 1, 0, 1 };
	std::cout << maxSatisfied(customers, grumpy, 3) << endl;
	customers = { 2, 6, 6, 9 }, grumpy = { 0, 0, 1, 1 };
	std::cout << maxSatisfied(customers, grumpy, 1) << endl;
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
