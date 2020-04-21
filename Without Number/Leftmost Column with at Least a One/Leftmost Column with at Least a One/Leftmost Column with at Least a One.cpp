// Leftmost Column with at Least a One.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BinaryMatrix {
public:
	int get(int x, int y);
	vector<int> dimensions();
};

class Solution {
public:
	int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
		vector<int> size = binaryMatrix.dimensions();
		int res = INT_MAX;
		for (int i = 0; i < size[0]; i++) {
			int left = 0, right = size[1] - 1;
			if (binaryMatrix.get(i, right) == 1)
				while (left <= right) {
					int mid = left + (right - left) / 2;
					if (binaryMatrix.get(i, mid) == 1) {
						right = mid - 1;
					}
					else {
						left = mid + 1;
					}
				}
			if (left < size[1] && binaryMatrix.get(i, left) == 1) {
				res = min(res, left);
			}
		}
		return res == INT_MAX ? -1 : res;
	}
};

int main()
{
	std::cout << "Hello World!\n";
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
