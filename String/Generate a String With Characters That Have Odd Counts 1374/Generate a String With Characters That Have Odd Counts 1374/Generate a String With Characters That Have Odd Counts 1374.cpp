// Generate a String With Characters That Have Odd Counts 1374.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string generateTheString(int n) {
		int occur = 0, div = 0, mod = 0;
		for (int i = 1; i <= 500; i += 2) {
			if (n / i < 21 && (n % i) % 2 != 0) {
				div = i;
				occur = n / i;
				mod = n % i;
				break;
			}

			if (n / i <= 21 && (n % i) == 0) {
				div = i;
				occur = n / i;
				mod = n % i;
				break;
			}
		}
		string res;
		for (int i = 97; i <= 132; i++) {
			if (occur <= 0) {
				while (mod > 0) {
					res.push_back(i);
					mod--;
				}
				break;
			}
			int c = 0;
			while (c < div) {
				res.push_back(i);
				c++;
			}
			occur--;
		}
		return res;
	}
};

class Solution1 {
public:
	string generateTheString(int n) {
		return "b" + string(n - 1, 'a' + n % 2);
	}
};

int main()
{
	Solution s;
	std::cout << s.generateTheString(4) << endl;
	std::cout << s.generateTheString(2) << endl;
	std::cout << s.generateTheString(7) << endl;
	std::cout << s.generateTheString(77) << endl;
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
