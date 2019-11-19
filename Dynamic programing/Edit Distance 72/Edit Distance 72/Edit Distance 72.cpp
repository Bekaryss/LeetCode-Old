// Edit Distance 72.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
	int n = word1.size() + 1;
	int m = word2.size() + 1;
	vector<vector<int>> matrix(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == 0) {
				matrix[i][j] = i;
			}else if (i == 0) {
				matrix[i][j] = j;
			}
			else {
				if (word1[i - 1] == word2[j - 1]) {
					matrix[i][j] = matrix[i - 1][j - 1];
				}
				else {
					matrix[i][j] = min(matrix[i][j - 1], min(matrix[i - 1][j], matrix[i - 1][j - 1])) + 1;
				}
			}
		}
	}
	return matrix[n-1][m-1];
}

int main()
{
	string word1 = "horse", word2 = "ros";
	std::cout << minDistance(word1, word2) << endl;

	word1 = "intention", word2 = "execution";
	std::cout << minDistance(word1, word2) << endl;
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
