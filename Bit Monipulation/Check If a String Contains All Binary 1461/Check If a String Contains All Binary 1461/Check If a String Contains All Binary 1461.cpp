// Check If a String Contains All Binary 5409.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <unordered_set>

using namespace std;

unordered_set<string> getAllValue(string s, int k) {
	unordered_set<string> all;
	for (int i = k; i <= s.size(); i++) {
		all.insert(s.substr(i - k, k));
	}
	return all;
}

bool hasAllCodes(string s, int k) {
	unordered_set<string> all = getAllValue(s, k);
	for (int i = 0; i < pow(2, k); i++) {
		string str = std::bitset<20>(i).to_string();
		if (all.find(str.substr(20 - k, k)) == all.end())
			return false;
	}
	return true;
}

int main()
{
	string s = "00110110";
	int k = 2;
	std::cout << hasAllCodes(s, k) << endl;
	s = "00110"; k = 2;
	std::cout << hasAllCodes(s, k) << endl;
	s = "0110"; k = 1;
	std::cout << hasAllCodes(s, k) << endl;
	s = "0110"; k = 2;
	std::cout << hasAllCodes(s, k) << endl;
	s = "0000000001011100"; k = 4;
	std::cout << hasAllCodes(s, k) << endl;
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
