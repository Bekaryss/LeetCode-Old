// Max Consecutive Ones III 1004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestOnesS(vector<int>& A, int K) {
    int i = 0, j;
    for (j = 0; j < A.size(); ++j) {
        if (A[j] == 0) K--;
        if (K < 0 && A[i++] == 0) K++;
    }
    return j - i;
}

int longestOnes(vector<int>& A, int K) {
    int i = 0, j = 0, len = 0;
    while (i < A.size()) {
        while (i < A.size() && (K >= 0)) {
            K -= A[i] == 1 ? 0 : 1;
            if (K >= 0)
                len = max(len, i - j + 1);
            i++;
        }
        while (j <= i && K < 0) {
            K += A[j] == 1 ? 0 : 1;
            j++;
        }
    }
    return len;
}

int main()
{
    vector<int> A = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
    int K = 2;
    std::cout << longestOnes(A, K) << endl;

    A = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
    K = 3;
    std::cout << longestOnes(A, K) << endl;
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
