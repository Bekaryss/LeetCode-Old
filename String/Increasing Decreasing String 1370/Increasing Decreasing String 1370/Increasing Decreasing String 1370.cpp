// Increasing Decreasing String 1370.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string sortString(string s) {
	int i = 0, n = s.size();
	string res = "";
	sort(s.begin(), s.end());
	char smallest = '0';
	char largest = '0';
	while (res.size() < n) {
		int i = 0;
		while (i < n && res.size() < n) {
			if (s[i] != '0') {
				if (smallest == '0') {
					res.push_back(s[i]);
					smallest = s[i];
					s[i] = '0';
				}
				else if (smallest < s[i]) {
					res.push_back(s[i]);
					smallest = s[i];
					s[i] = '0';
				}
			}
			i++;
		}
		smallest = '0';
		int j = s.size() - 1;
		while (j >= 0 && res.size() < n) {
			if (s[j] != '0') {
				if (largest == '0') {
					res.push_back(s[j]);
					largest = s[j];
					s[j] = '0';
				}
				else if (largest > s[j]) {
					res.push_back(s[j]);
					largest = s[j];
					s[j] = '0';
				}
			}
			j--;
		}
		largest = '0';

	}
	return res;
}

int main()
{
	string input = "aaaabbbbcccc";
	std::cout << "abccbaabccba = " << sortString(input) << endl;
	input = "rat";
	std::cout << "art = " << sortString(input) << endl;
	input = "leetcode";
	std::cout << "cdelotee = " << sortString(input) << endl;
	input = "ggggggg";
	std::cout << "ggggggg = " << sortString(input) << endl;
	input = "spo";
	std::cout << "ops = " << sortString(input) << endl;
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
