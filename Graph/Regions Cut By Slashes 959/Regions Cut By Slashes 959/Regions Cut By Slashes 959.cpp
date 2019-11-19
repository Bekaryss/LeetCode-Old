// Regions Cut By Slashes 959.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	vector<int> parent;
public:
	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unionI(int x, int y) {
		parent[find(x)] = find(y);
	}

	int regionsBySlashes(vector<string>& grid) {
		int n = grid.size();
		int s = 4 * n * n;
		for (int i = 0; i < s; ++i) {
			parent.push_back(i);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int root = 4 * (i * n + j);
				char val = grid[i][j];
				if (val != '\\') {
					unionI(root + 0, root + 1);
					unionI(root + 2, root + 3);
				}
				if (val != '/') {
					unionI(root + 0, root + 2);
					unionI(root + 1, root + 3);
				}

				// north south
				if (i + 1 < n)
					unionI(root + 3, (root + 4 * n) + 0);
				if (i - 1 >= 0)
					unionI(root + 0, (root - 4 * n) + 3);
				// east west
				if (j + 1 < n)
					unionI(root + 2, (root + 4) + 1);
				if (j - 1 >= 0)
					unionI(root + 1, (root - 4) + 2);
			}
		}
		int ans = 0;
		for (int x = 0; x < 4 * n * n; ++x) {
			if (find(x) == x)
				ans++;
		}

		return ans;
	}
};

int main()
{
	vector<string> input = { " /", "/ " };
	Solution sl;
	std::cout << sl.regionsBySlashes(input) << endl;
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
