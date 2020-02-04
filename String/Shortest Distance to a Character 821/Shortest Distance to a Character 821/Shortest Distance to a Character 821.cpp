// Shortest Distance to a Character 821.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> shortestToCharSolution(string S, char C) {
    int n = S.size(), pos = -n;
    vector<int> res(n, n);
    for (int i = 0; i < n; ++i) {
        if (S[i] == C) 
            pos = i;
        res[i] = i - pos;
    }
    for (int i = pos - 1; i >= 0; --i) {
        if (S[i] == C)  
            pos = i;
        res[i] = min(res[i], pos - i);
    }
    return res;
}

vector<int> shortestToChar(string S, char C) {
    vector<int> res(S.size(), S.size());
    int sd = S.size();
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == C) {
            sd = 0;
        }
        else {
            sd++;
        }
        res[i]= min(sd, res[i]);
    }
    sd = S.size();
    for (int i = S.size()-1; i >= 0; i--)
    {
        if (S[i] == C) {
            sd = 0;
        }
        else {
            sd++;
        }
        res[i] = min(sd, res[i]);
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
    string s = "loveleetcode";
    char c = 'e';
    PrintRes(shortestToCharSolution(s, c));
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
