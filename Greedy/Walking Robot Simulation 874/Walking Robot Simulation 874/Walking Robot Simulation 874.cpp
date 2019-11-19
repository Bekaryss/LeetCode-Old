// Walking Robot Simulation 874.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
	vector<pair<int, int>> directions = { {-1, 0 }, {0, 1}, {1, 0}, {0, -1} };
	unordered_set<string> ob;
	for (auto i : obstacles) {
		string s = to_string(i[0]) + " " + to_string(i[1]);
		ob.insert(s);
	}
	int x = 0, y = 0, direction = 1, maxDistSquare = 0;
	for (int i = 0; i < commands.size(); i++) {
		if (commands[i] == -2) {
			direction--;
			if (direction < 0) {
				direction += 4;
			}
		}
		else if (commands[i] == -1) {
			direction++;
			direction %= 4;
		}
		else {
			int step = 0;
			string s; 
			while (step < commands[i]) {
				s = to_string(x + directions[direction].first) + " " + to_string(y + directions[direction].second);
				if (ob.find(s) != ob.end()) {
					break;
				}
				x += directions[direction].first;
				y += directions[direction].second;
				step++;
			}
		}
		maxDistSquare = max(maxDistSquare, x * x + y * y);
	}
	return maxDistSquare;
}

int main()
{
	vector<int> commands = { 4, -1, 3 };
	vector<vector<int>>  obstacles = {};
	std::cout << robotSim(commands, obstacles) << endl;

	commands = { 4, -1, 4, -2, 4 };
	obstacles = { { 2, 4 } };
	std::cout << robotSim(commands, obstacles) << endl;
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
