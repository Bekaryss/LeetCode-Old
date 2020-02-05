// Occurrences After Bigram 1078.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> findOcurrences(string text, string first, string second) {
    vector<string> res;
    istringstream ss(text);
    string prev2, prev, word;
    while (ss >> word) {
        if (prev2 == first && prev == second)
            res.push_back(word);
        prev2 = prev;
        prev = word;
    }
    return res;
}

void PrintRes(vector<string> res) {
    for (string s : res) {
        cout << s << " ";
    }
    cout << endl;
}

int main()
{
    string text = "alice is a good girl she is a good student", first = "a", second = "good";
    PrintRes(findOcurrences(text, first, second));
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
