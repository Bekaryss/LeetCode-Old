// Valid Parenthesis String 678.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool checkValidString(string s) {
    int cmin = 0, cmax = 0;
    for (char c : s) {
        if (c == '(') {
            cmin++;
            cmax++;
        }
        else if (c == ')') {
            cmax--;
            cmin = max(cmin - 1, 0);
        }
        else {
            cmax++;
            cmin = max(cmin - 1, 0);
        }
        if (cmax < 0) return false;
    }

    return  cmin == 0;
}

int main()
{
    std::cout << checkValidString("()") << endl;
    std::cout << checkValidString("()()") << endl;
    std::cout << checkValidString("(*)") << endl;
    std::cout << checkValidString("(*))") << endl;
    std::cout << checkValidString("((*))") << endl;
    std::cout << checkValidString("(*)))") << endl;
    std::cout << checkValidString(")(") << endl;
    std::cout << checkValidString("(*()") << endl;
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
