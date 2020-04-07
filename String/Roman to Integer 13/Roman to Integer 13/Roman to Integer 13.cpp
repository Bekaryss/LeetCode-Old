// Roman to Integer 13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
	unordered_map<char, int> map = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
	int res = 0, cur = map[s[0]];
	for (int i = 1; i < s.size(); i++) {
		if (cur > map[s[i]]) {
			res += cur;
			cur = 0;
		}
		if (map[s[i]] > map[s[i - 1]]) {
			res += map[s[i]] - cur;
			cur = 0;
		}
		else {
			cur += map[s[i]];
		}
	}
	res += cur;
	return res;
}

int main()
{
	std::cout << "3 = " << romanToInt("III") << endl;
	std::cout << "4 = " << romanToInt("IV") << endl;
	std::cout << "9 = " << romanToInt("IX") << endl;
	std::cout << "58 = " << romanToInt("LVIII") << endl;
	std::cout << "1994 = " << romanToInt("MCMXCIV") << endl;
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
