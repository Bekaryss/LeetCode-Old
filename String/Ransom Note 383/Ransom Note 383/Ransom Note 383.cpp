// Ransom Note 383.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> map;
    for (char i : magazine) {
        map[i]++;
    }
    for (char i : ransomNote) {
            map[i]--;
            if (map[i] < 0)
                return false;
    }
    return true;
}

int main()
{
    std::cout << "false = " << (canConstruct("a", "b") == true ? "true" : "false") << endl;
    std::cout << "false = " << (canConstruct("aa", "ab") == true ? "true" : "false") << endl;
    std::cout << "true = " << (canConstruct("aa", "aab") == true ? "true" : "false") << endl;
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
