// Compare Strings by Frequency of the Smallest Character 1170.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int smallest(string s) {
    vector<int> al(26);
    for (int i = 0; i < s.size(); i++) {
        al[s[i] - 'a']++;
    }
    for (int i : al) {
        if (i > 0) {
            return i;
        }
    }
    return 0;
}

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> q, w;
    for (string s : queries) {
        q.push_back(smallest(s));
    }
    for (string s : words) {
        w.push_back(smallest(s));
    }
    vector<int> res;
    for (int i : q) {
        int count = 0;
        for (int j : w) {
            if (i < j) {
                count++;
            }
        }
        res.push_back(count);
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
    vector<string> queries = { "cbd" }, words = { "zaaaz" };
    PrintRes(numSmallerByFrequency(queries, words));
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
