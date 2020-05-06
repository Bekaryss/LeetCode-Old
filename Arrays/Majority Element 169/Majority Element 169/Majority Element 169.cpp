// Majority Element 169.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> map;
    int res = 0, count = 0;
    for (int i : nums) {
        map[i]++;
        if (count < map[i]) {
            res = i;
            count = map[i];
        }
    }
    return res;
}

int majorityElementMoore(vector<int>& nums) {
    int res = 0, count = 0;
    for (int i : nums) {
        if (count == 0) {
            res = i;
        }
        if (res == i) {
            count++;
        }
        else {
            count--;
        }
    }
    return res;
}

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
