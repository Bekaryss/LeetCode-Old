// Design Browser History 1472.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BrowserHistory {
    vector<string> history;
    int index = 0;
    int stepb = 0;
    int stepf = 0;
public:
    BrowserHistory(string homepage) {
        history = { homepage };
        index = 0;
        stepb = 0;
        stepf = 0;
    }

    void visit(string url) {
        if (stepf > 0) {
            while (stepf > 0) {
                history.pop_back();
                stepf--;
            }
        }
        history.push_back(url);
        index++;
        stepb++;
    }

    string back(int steps) {
        if (stepb < steps) {
            index = index - stepb;
            stepf += stepb;
            stepb -= stepb; 
        }
        else {
            index = index - steps;
            stepf += steps;
            stepb -= steps;
        }

        return history[index];
    }

    string forward(int steps) {
        if (stepf < steps) {
            index = index + stepf;
            stepb += stepf;
            stepf -= stepf;
        }
        else {
            index = index + steps;
            stepb += steps;
            stepf -= steps;
        }

        return history[index];
    }
};

int main()
{
    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
    browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
    browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
    cout << browserHistory.back(1) << endl;                  // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
    cout << browserHistory.back(1) << endl;                       // You are in "facebook.com", move back to "google.com" return "google.com"
    cout << browserHistory.forward(1) << endl;                    // You are in "google.com", move forward to "facebook.com" return "facebook.com"
    browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
    cout << browserHistory.forward(2) << endl;                    // You are in "linkedin.com", you cannot move forward any steps.
    cout << browserHistory.back(2) << endl;                       // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
    cout << browserHistory.back(7) << endl;                       // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
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
