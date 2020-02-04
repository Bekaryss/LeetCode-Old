// Matrix Cells in Distance Order 1030.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> res;
    auto comp = [r0, c0](vector<int>& a, vector<int>& b)
    {
        return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
    };
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            res.push_back({ i, j });
        }
    }
    sort(res.begin(), res.end(), comp);
    return res;
}

void PrintRes(vector<vector<int>> res) {
    for (auto i : res) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int R = 1, C = 2, r0 = 0, c0 = 0;
    vector<vector<int>> res = allCellsDistOrder(R, C, r0, c0);
    PrintRes(res);
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
