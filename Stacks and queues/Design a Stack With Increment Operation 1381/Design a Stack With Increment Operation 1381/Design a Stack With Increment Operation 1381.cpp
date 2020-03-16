// Design a Stack With Increment Operation 1381.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class CustomStack {
private:
	int maxS;
	vector<int> stack;
public:
	CustomStack(int maxSize) {
		maxS = maxSize;
	}

	void push(int x) {
		if (stack.size() < maxS) {
			stack.push_back(x);
		}
	}

	int pop() {
		if (stack.size() > 0) {
			int last = stack[stack.size() - 1];
			stack.pop_back();
			return last;
		}
		else {
			return -1;
		}
	}

	void increment(int k, int val) {
		for (int i = 0; i < stack.size(); i++) {
			if (k <= 0) {
				break;
			}
			stack[i] += val;
			k--;
		}
	}
};

int main()
{
	CustomStack customStack(3); // Stack is Empty []
	customStack.push(1);                          // stack becomes [1]
	customStack.push(2);                          // stack becomes [1, 2]
	cout << customStack.pop() << endl;            // return 2 --> Return top of the stack 2, stack becomes [1]
	customStack.push(2);                          // stack becomes [1, 2]
	customStack.push(3);                          // stack becomes [1, 2, 3]
	customStack.push(4);                          // stack still [1, 2, 3], Don't add another elements as size is 4
	customStack.increment(5, 100);                // stack becomes [101, 102, 103]
	customStack.increment(2, 100);                // stack becomes [201, 202, 103]
	cout << customStack.pop() << endl;            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
	cout << customStack.pop() << endl;            // return 202 --> Return top of the stack 202, stack becomes [201]
	cout << customStack.pop() << endl;			  // return 201 --> Return top of the stack 201, stack becomes []
	cout << customStack.pop() << endl;			  // return -1 --> Stack is empty return -1.
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
