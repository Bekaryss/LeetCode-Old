// Number of Squareful Arrays 996.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
	unordered_map<int, int> count;
	unordered_map<int, unordered_set<int>> cand;
	int res = 0;
public:
	int numSquarefulPerms(vector<int>& A) {
		for (int &a : A) {
			count[a]++;
		}
		for (auto &i : count) {
			for (auto& j : count) {
				int x = i.first, y = j.first, s = sqrt(x + y);
				if (s * s == x + y)
					cand[x].insert(y);
			}
		}
		for (auto e : count)
			dfs(e.first, A.size() - 1);
		return res;
	}

	void dfs(int x, int left) {
		count[x]--;
		if (left == 0)
			res++;
		for (int y : cand[x]) {
			if (count[y] > 0)
				dfs(y, left - 1);
		}
		count[x]++;
	}
};

int main()
{
	Solution sl;
	vector<int> input = { 1, 17, 8 };
	std::cout << sl.numSquarefulPerms(input) << endl;
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
