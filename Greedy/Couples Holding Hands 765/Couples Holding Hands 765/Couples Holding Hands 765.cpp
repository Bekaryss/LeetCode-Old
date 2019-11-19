// Couples Holding Hands 765.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minSwapsCouples(vector<int>& row) {
	unordered_map<int, int> pos;
	for (int i = 0; i < row.size(); i++) {
		pos[row[i]] = i;
	}
	int res = 0;
	for (int i = 0; i < row.size(); i += 2) {
		int couple = row[i] % 2 == 0 ? row[i] + 1 : row[i] - 1;
		if (row[i + 1] != couple) {
			int tmp = row[i + 1];
			pos[row[i + 1]] = pos[couple];
			row[pos[couple]] = tmp;
			pos[couple] = i + 1;
			row[i + 1] = couple;
			res++;
		}
	}
	return res;
}

int main()
{
	vector<int> row = { 0, 2, 1, 3 };
	std::cout << minSwapsCouples(row) << endl;
	row = { 0, 2, 4, 6, 7, 1, 3, 5 };
	std::cout << minSwapsCouples(row) << endl;
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
