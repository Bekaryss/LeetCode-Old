// Shuffle the Array 1470.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> res;
    for (int i = 0; i < n; i++) {
        res.push_back(nums[i]);
        res.push_back(nums[i + n]);
    }
    return res;
}

void PrintRes(vector<int> res) {
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = { 2, 5, 1, 3, 4, 7 };
    int n = 3;
    PrintRes(shuffle(nums, n));
    nums = { 1, 2, 3, 4, 4, 3, 2, 1 }; n = 4;
    PrintRes(shuffle(nums, n));
    nums = { 1, 1, 2, 2 }; n = 2;
    PrintRes(shuffle(nums, n));
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
