// Longest Turbulent Subarray 978.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxTurbulenceSize(vector<int>& A) {
	int inc = 1, dec = 1, res = 0;
	for (int i = 1; i < A.size(); i++) {
		if (A[i - 1] < A[i]) {
			inc = dec + 1;
			dec = 1;
		}
		else if (A[i - 1] > A[i]) {
			dec = inc + 1;
			inc = 1;
		}
		else {
			dec = 1;
			inc = 1;
		}
		res = max(res, max(inc, dec));
	}
	return res;
}

int main()
{
	vector<int> input = { 9,4,2,10,7,8,8,1,9 };
	std::cout << maxTurbulenceSize(input) << endl;
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
