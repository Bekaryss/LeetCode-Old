// Build an Array With Stack Operations 1441.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> buildArray(vector<int>& target, int n) {
    int j = 0;
    vector<string> res;
    for (int i = 1; i <= n; i++) {
        if (i == target[j]) {
            res.push_back("Push");
            j++;
            if (j >= target.size()) {
                break;
            }
        }
        else {
            res.push_back("Push");
            res.push_back("Pop");
        }
    }
    return res;
}

void PrintRes(vector<string> res) {
    for (string s : res) {
        cout << s << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> target = { 1, 3 };
    int n = 3;
    PrintRes(buildArray(target, n));
    target = { 1, 2, 3 }; n = 3;
    PrintRes(buildArray(target, n));
    target = { 1, 2 }; n = 4;
    PrintRes(buildArray(target, n));
    target = { 2, 3, 4 }; n = 4;
    PrintRes(buildArray(target, n));
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
