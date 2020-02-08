// Number of Steps to Reduce a Number to Zero 1342.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int numberOfSteps(int num) {
	int res = 0;
	while (num > 0) {
		if (num % 2 == 0) {
			num >>= 1;
		}
		else {
			num--;
		}
		res++;
	}
	return res;
}

int main()
{
	std::cout << numberOfSteps(14) << endl;
	std::cout << numberOfSteps(8) << endl;
	std::cout << numberOfSteps(123) << endl;
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
