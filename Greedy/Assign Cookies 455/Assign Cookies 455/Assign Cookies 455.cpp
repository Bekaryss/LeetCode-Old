// Assign Cookies 455.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int res = 0;
	int i = 0;
	int j = 0;
	while(i < g.size() && j<s.size()) {
		if (g[i] <= s[j]) {
			res++;
			i++;
		}
		j++;
	}
	return res;
}

int main()
{
	vector<int> ch = { 1,2,3 };
	vector<int> co = { 1,1 };
    std::cout << findContentChildren(ch, co) << endl;

	ch = { 10, 9, 8, 7 };
	co = { 5, 6, 7, 8 };
	std::cout << findContentChildren(ch, co) << endl;
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
