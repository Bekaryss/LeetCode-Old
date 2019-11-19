// Last Stone Weight 1046.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
	priority_queue<int, vector<int>, less<int>> pq;

	for (int i = 0; i < stones.size(); i++) {
		pq.push(stones[i]);
	}

	while (pq.size() > 1) {
		int s1 = pq.top(); 
		pq.pop();
		int s2 = pq.top();
		pq.pop();
		if (abs(s1 - s2) > 0) {
			pq.push(abs(s1 - s2));
		}
	}
	return pq.empty() == true ? 0 : pq.top();
}

int main()
{
	vector<int> input = { 2,7,4,1,8,1 };
	cout << lastStoneWeight(input) << endl;
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
