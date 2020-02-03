// Maximum Sum of Two Non-Over Subarrays 1031.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    for (int i = 1; i < A.size(); i++) {
        A[i] += A[i - 1];
    }
    int res = A[L + M - 1], Lmax = A[L - 1], Mmax = A[M - 1];
    for (int i = L + M; i < A.size(); ++i) {
        Lmax = max(Lmax, A[i - M] - A[i - L - M]);
        Mmax = max(Mmax, A[i - L] - A[i - L - M]);
        res = max(res, max(Lmax + A[i] - A[i - M], Mmax + A[i] - A[i - L]));
    }
    return res;
}

int main()
{
    vector<int> input = { 0,6,5,2,2,5,1,9,4 };
    int L = 1, M = 2;
    std::cout << maxSumTwoNoOverlap(input, L, M) << endl;
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
