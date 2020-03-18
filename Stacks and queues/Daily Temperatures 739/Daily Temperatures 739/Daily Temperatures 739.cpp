// Daily Temperatures 739.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
	int n = T.size() - 1;
	stack<int> st;
	vector<int> res(n + 1);
	for (int i = n; i >= 0; i--) {
		while (!st.empty() && T[i] >= T[st.top()]) {
			st.pop();
		}
		res[i] = !st.empty() ? st.top() - i : 0;
		st.push(i);
	}
	return res;
}

void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> t = { 73, 74, 75, 71, 69, 72, 76, 73 };
	PrintRes(dailyTemperatures(t));
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
