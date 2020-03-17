// Path In Zigzag Labelled Binary Tree 1104.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> pathInZigZagTree(int label) {
	int n = 0;
	int sum = 0;
	vector<int> res;
	while (label > sum) {
		sum += pow(2, n);
		n++;
	}
	int val;
	while (n > 0) {
		res.insert(res.begin(), label);
		val = (sum - label) / 2 + 1;
		int pt = pow(2, --n);
		sum -= pt;
		int num = pt / 2;
		label = sum - num + val;
	}
	return res;
}

void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	PrintRes(pathInZigZagTree(8));
	/*PrintRes(pathInZigZagTree(14));
	PrintRes(pathInZigZagTree(13));
	PrintRes(pathInZigZagTree(12));
	PrintRes(pathInZigZagTree(11));
	PrintRes(pathInZigZagTree(10));
	PrintRes(pathInZigZagTree(9));
	PrintRes(pathInZigZagTree(8));
	PrintRes(pathInZigZagTree(4));
	PrintRes(pathInZigZagTree(5));
	PrintRes(pathInZigZagTree(6));
	PrintRes(pathInZigZagTree(7));
	PrintRes(pathInZigZagTree(1));*/
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
