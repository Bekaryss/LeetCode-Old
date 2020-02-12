// Permutation in String 567.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isp(vector<int> counter) {
    for (int i = 0; i < 26; i++) {
        if (counter[i] != 0)
            return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
        return false;
    vector<int> counter(26);
    for (int i = 0; i < s1.size(); i++) {
        counter[s1[i] - 'a']++;
        counter[s2[i] - 'a']--;
    }
    if (isp(counter))
        return true;
    for (int i = s1.size(); i < s2.size(); i++) {
        counter[s2[i] - 'a']--;
        counter[s2[i - s1.size()] - 'a']++;
        if (isp(counter))
            return true;
    }
    return false;
}

int main()
{
    std::cout << "Hello World!\n";
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
