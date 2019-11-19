// Keys and Rooms 841.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
	unordered_set<int> visited;
	queue<vector<int>> q;
	q.push(rooms[0]);
	visited.insert(0);
	while(!q.empty()) {
		vector<int> room = q.front();
		q.pop();
		for (int j = 0; j < room.size(); j++) {
			if (visited.find(room[j]) == visited.end()) {
				visited.insert(room[j]);
				q.push(rooms[room[j]]);
			}
		}
	}
	return visited.size() == rooms.size();
}

int main()
{
	vector<vector<int>> input = {{1}, {2}, {3}, {}} ;
	std::cout << canVisitAllRooms(input) << endl;
	input = { {1, 3}, {3, 0, 1}, {2}, {0} };
    std::cout << canVisitAllRooms(input) << endl;
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
