// Two City Scheduling 1029.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int twoCitySchedCost(vector<vector<int>>& costs) {
	int res = 0;
	sort(costs.begin(), costs.end(), [](const vector<int>& costA, const vector<int>& costB)
		{
			return costA[0]-costA[1] < costB[0] - costB[1];
		});
	for (int i = 0; i < costs.size(); i++) {
		if (i < costs.size() / 2) {
			res += costs[i][0];
		}
		else {
			res += costs[i][1];
		}
	}
	return res;
}

int main()
{
	vector<vector<int>> input = { {10, 20}, {30, 200}, {400, 50}, {30, 20} };
	std::cout << twoCitySchedCost(input) << endl;
	input = { {259, 770}, { 448, 54 }, { 926, 667 }, { 184, 139 }, { 840, 118 }, { 577, 469 } };
	std::cout << twoCitySchedCost(input) << endl;
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
