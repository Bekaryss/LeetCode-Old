// Angle Between Hands of a Clock 1344.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double angleClock(int hour, int minutes) {
	double res = 0;
	double minAngle = (double)minutes * 6;
	double hourAngle = ((double)hour * 60 + (double)minutes) / 2;
	res = abs(hourAngle - minAngle);
	res = min(res, 360 - res);
	return res;
}

int main()
{
	std::cout << angleClock(12, 30) << endl;
	std::cout << angleClock(3, 30) << endl;
	std::cout << angleClock(3, 15) << endl;
	std::cout << angleClock(12, 0) << endl;
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
