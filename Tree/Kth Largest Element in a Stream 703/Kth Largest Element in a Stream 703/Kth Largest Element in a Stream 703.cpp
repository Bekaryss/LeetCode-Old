// Kth Largest Element in a Stream 703.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

using namespace std;

class KthLargest {
private:
	priority_queue<int, vector<int>, greater<int>> pq;
	int kth;
public:
	KthLargest(int k, vector<int>& nums) {
		kth = k;
		for (int i = 0; i < nums.size(); i++) {
			pq.push(nums[i]);
			if (pq.size() > k) {
				pq.pop();
			}
		}
	}

	int add(int val) {
		pq.push(val);
		if (pq.size() > kth) 
			pq.pop();
		return pq.top();
	}
};

int main()
{
    std::cout << "Hello World!\n";
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
