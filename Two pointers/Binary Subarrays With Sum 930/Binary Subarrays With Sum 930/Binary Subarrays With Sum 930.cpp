// Binary Subarrays With Sum 930.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numSubarraysWithSum(vector<int>& A, int S) {
	unordered_map<int, int> c({ {0, 1} });
	int psum = 0, res = 0;
	for (int i : A) {
		psum += i;
		res += c[psum - S];
		c[psum]++;
	}
	return res;
}

int numSubarraysWithSumTwoP(vector<int>& A, int S) {
	int left = 0, right = 0, res = 0, sum = 0, n = A.size();
	for (; right < n; right++) {
		sum += A[right];
		while (left < right && sum > S) {
			sum -= A[left++];
		}
		if (sum == S)
			res++;
		for (int i = left; (sum == S && i < right && A[i] == 0); i++) {
			res++;
		}
	}
	return res;
}

int main()
{
	vector<int> input = { 1,0,1,0,1 };
	std::cout << numSubarraysWithSum(input, 2) << endl;

	input = { 0,0,0,0,0 };
	std::cout << numSubarraysWithSumTwoP(input, 0) << endl;
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
