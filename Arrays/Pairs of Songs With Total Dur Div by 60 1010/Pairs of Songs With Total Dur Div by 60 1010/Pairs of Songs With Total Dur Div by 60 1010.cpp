// Pairs of Songs With Total Dur Div by 60 1010.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int numPairsDivisibleBy60(vector<int>& time) {
    int res = 0;
    vector<int> c(60);
    for (int t : time) {
        int num = 60 - t % 60;
        res += c[num % 60];
        c[t % 60]++;
    }
    return res;
}

int main()
{
    vector<int> input = { 30,20,150,100,40 };
    std::cout << numPairsDivisibleBy60(input) << endl;
    input = { 60,60,60 };
    std::cout << numPairsDivisibleBy60(input) << endl;
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
