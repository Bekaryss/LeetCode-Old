// Perform String Shifts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string stringShift(string s, vector<vector<int>>& shift) {
	int sh = 0;
	for (auto i : shift) {
		sh += i[0] == 0 ? -i[1] : i[1];
	}
	bool left = sh < 0;
	sh = abs(sh);
	while (sh > 0) {
		if (left == true) {
			s.push_back(s.front());
			if (s.size() > 0) {
				s.erase(s.begin());
			}
		}
		else {
			s.insert(s.begin(), s.back());
			s.pop_back();
		}
		sh--;
	}
	return s;
}



string stringRotate(string s, vector<vector<int>>& shift) {
	int sh = 0;
	for (auto i : shift) {
		sh += i[0] == 0 ? -i[1] : i[1];
	}
	sh %= int(s.size());
	if (sh > 0) {
		rotate(s.begin(), next(s.begin(), sh), s.end());
	}
	else {
		rotate(s.rbegin(), next(s.rbegin(), -sh), s.rend());
	}
	return s;
}
int main()
{
	string s = "abc";
	vector<vector<int>> shift = { {0, 1} };
	std::cout << "cab = " << stringRotate(s, shift) << endl;

	s = "abcdefg";
	shift = { {1,1} ,{1,1},{0,2},{1,3} };
	std::cout << "efgabcd = " << stringShift(s, shift) << endl;
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
