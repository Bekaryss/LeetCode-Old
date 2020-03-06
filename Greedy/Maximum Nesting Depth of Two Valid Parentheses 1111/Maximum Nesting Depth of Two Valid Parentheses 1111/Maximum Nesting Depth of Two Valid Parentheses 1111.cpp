// Maximum Nesting Depth of Two Valid Parentheses 1111.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> maxDepthAfterSplit(string seq) {
	vector<int> res(seq.size(), 0);
	int count = 0;
	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == '(') {
			res[i] = count++ % 2;
		}
		else {
			res[i] = --count % 2;
		}
	}
	return res;
}

vector<int> maxDepthAfterSplitSolution(string seq) {
	vector<int> ans(seq.size());
	int cnt = 0;
	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == '(') {
			if (i > 0 && seq[i - 1] == '(')
				cnt++;
			ans[i] = cnt % 2;
		}
		else {
			if (seq[i - 1] == ')')
				cnt--;
			ans[i] = cnt % 2;
		}
	}
	return ans;
}

void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << endl;
	}
	cout << endl;
}

int main()
{
	string seq = "(()())";
	PrintRes(maxDepthAfterSplit(seq));

	seq = "()(())()";
	PrintRes(maxDepthAfterSplit(seq));
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
