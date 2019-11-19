// Best Time to Buy and Sell Stock II 122.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int maxprofit = 0;
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] > prices[i - 1])
			maxprofit += prices[i] - prices[i - 1];
	}
	return maxprofit;
}

int maxProfitV(vector<int>& prices) {
	int i = 0;
	if (prices.size() == 0)
		return 0;
	int valley = prices[0];
	int peak = prices[0];
	int maxprofit = 0;

	while (i < prices.size() - 1) {
		while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
			i++;
		valley = prices[i];
		while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
			i++;
		peak = prices[i];
		maxprofit += peak - valley;
	}
	return maxprofit;
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
