// Check If It Is a Straight Line 1232.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

bool onLine(vector<int> p1, vector<int> p2, vector<int> p3) {
	int x = p1[0], x1 = p2[0], x2 = p3[0], y = p1[1], y1 = p2[1], y2 = p3[1];
	return (y - y1) * (x2 - x1) == (x - x1) * (y2 - y1);
}

bool checkStraightLine(vector<vector<int>>& coordinates) {
	for (int i = 2; i < coordinates.size(); i++) {
		if (onLine(coordinates[i - 2], coordinates[i - 1], coordinates[i]) == false)
			return false;
	}
	return true;
}

int main()
{
	vector<vector<int>> coordinates = { {1,2},{2,3},{3,4},{4,5},{5,6},{6,7} };
	std::cout << checkStraightLine(coordinates) << endl;
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
