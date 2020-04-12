// String Matching in an Array 1408.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

vector<string> stringMatching(vector<string>& words) {
    unordered_set<string> set;
    vector<string> res;
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (i != j) {
                if (words[i].find(words[j]) != string::npos) {
                    set.insert(words[j]);
                }
            }
        }
    }
    for (string s : set) {
        res.push_back(s);
    }
    return res;
}

void PrintRes(vector<string> res) {
    for (string i : res) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<string> words = { "mass", "as", "hero", "superhero" };
    PrintRes(stringMatching(words));
    words = { "leetcode","et","code" };
    PrintRes(stringMatching(words));
    words = { "blue","green","bu" };
    PrintRes(stringMatching(words));
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
