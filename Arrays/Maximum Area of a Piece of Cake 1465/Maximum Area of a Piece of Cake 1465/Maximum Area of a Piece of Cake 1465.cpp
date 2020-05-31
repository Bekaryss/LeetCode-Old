// Maximum Area of a Piece of Cake 1465.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    vector<int> hPiece, wPiece;
    const unsigned int M = 1000000007;
    int last = 0;
    sort(horizontalCuts.begin(), horizontalCuts.end());
    for (int i : horizontalCuts) {
        hPiece.push_back(i - last);
        last = i;
    }
    hPiece.push_back(h - last);

    last = 0;
    sort(verticalCuts.begin(), verticalCuts.end());
    for (int i : verticalCuts) {
        wPiece.push_back(i - last);
        last = i;
    }
    wPiece.push_back(w - last);

    long long maxH = 0;
    for (long long i : hPiece) {
        maxH = max(maxH, i);
    }
    long long maxW = 0;
    for (long long i : wPiece) {
        maxW = max(maxW, i);
    }
    long long res = maxH * maxW;
    return res % M;
}

int main()
{
    int h = 5, w = 4;
    vector<int> horizontalCuts = { 1, 2, 4 }, verticalCuts = { 1, 3 };
    std::cout << maxArea(h, w, horizontalCuts, verticalCuts) << endl;

    h = 5, w = 4;
    horizontalCuts = { 3, 1 }, verticalCuts = { 1 };
    std::cout << maxArea(h, w, horizontalCuts, verticalCuts) << endl;

    h = 5, w = 4;
    horizontalCuts = { 3 }, verticalCuts = { 3 };
    std::cout << maxArea(h, w, horizontalCuts, verticalCuts) << endl;
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
