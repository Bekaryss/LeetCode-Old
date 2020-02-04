// Remove Element 27.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        if (nums[j] == val) {
            nums.pop_back();
            j--;
        }
        else if (nums[i] == val) {
            swap(nums[i], nums[j]);
            nums.pop_back();
            j--;
        }
        else {
            i++;
        }
    }
    return nums.size();
}

int main()
{
    vector<int> input = { 0,1,2,2,3,0,4,2 };
    std::cout << removeElement(input, 2) << endl;
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
