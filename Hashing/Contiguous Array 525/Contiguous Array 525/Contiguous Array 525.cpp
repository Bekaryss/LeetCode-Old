// Contiguous Array 525.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> map = { {0, -1} };
    int count = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        count += nums[i] == 1 ? 1 : -1;
        if (map.find(count) != map.end()) {
            res = max(res, i - map[count]);
        }
        else {
            map[count] = i;
        }
    }
    return res;
}

int main()
{
    vector<int> input = { 0,1,1,1,0,1,1,0,1,0 };
    std::cout << "6 = " << findMaxLength(input) << endl;
    input = { 0,1 };
    std::cout << "2 = " << findMaxLength(input) << endl;
    input = { 0,1,0 };
    std::cout <<  "2 = " << findMaxLength(input) << endl;
    input = { 0,1,1,0,1,1,1,0 };
    std::cout  << "4 = " << findMaxLength(input) << endl;
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
