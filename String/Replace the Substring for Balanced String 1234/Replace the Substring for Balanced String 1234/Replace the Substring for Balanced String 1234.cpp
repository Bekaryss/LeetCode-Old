// Replace the Substring for Balanced String 1234.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int balancedString(string s) {
    unordered_map<char, int> count;
    int n = s.size(), k = n / 4, i = 0, res = n;
    for (char c : s) {
        count[c]++;
    }
    for (int j = 0; j < n; ++j) {
        count[s[j]]--;
        while (i < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k) {
            res = min(res, j - i + 1);
            count[s[i++]] += 1;
        }
    }
    return res;
}

int main()
{
    std::cout << balancedString("QWER") << endl;
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
