// Largest Values From Labels 1090.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

//struct for combining data
struct item {
	int value;
	int label;
	item(int _value, int _label)
		:value(_value), label(_label)
	{}
};

//Custom compare function
bool comp(const item* itemA, const item* itemB) {
	return itemA->value < itemB->value;
}


int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
	priority_queue<item*, vector<item*>, decltype(&comp)> items(comp);
	unordered_map<int, int> labelMap;
	//fill items nad labelMap
	for (int i = 0; i < values.size(); i++) {
		item* it = new item(values[i], labels[i]);
		items.push(it);
		labelMap[labels[i]] = use_limit;
	}
	int n = 0;
	int res = 0;
	item* it;
	while (n < num_wanted && !items.empty())
	{
		it = items.top();
		items.pop();
		//if label did not use more than use_limit
		if (labelMap[it->label] > 0) {
			res += it->value;
			labelMap[it->label]--;
			n++;
		}

	}
	return res;
}

int main()
{
	vector<int> values = { 5, 4, 3, 2, 1 }, labels = { 1, 1, 2, 2, 3 };
	int num_wanted = 3, use_limit = 1;
	std::cout << largestValsFromLabels(values, labels, num_wanted, use_limit) << endl;

	values = { 5, 4, 3, 2, 1 }, labels = { 1, 3, 3, 3, 2 };
	num_wanted = 3, use_limit = 2;
	std::cout << largestValsFromLabels(values, labels, num_wanted, use_limit) << endl;

	values = { 9, 8, 8, 7, 6 }, labels = { 0, 0, 0, 1, 1 };
	num_wanted = 3, use_limit = 1;
	std::cout << largestValsFromLabels(values, labels, num_wanted, use_limit) << endl;

	values = { 9, 8, 8, 7, 6 }, labels = { 0, 0, 0, 1, 1 };
	num_wanted = 3, use_limit = 2;
	std::cout << largestValsFromLabels(values, labels, num_wanted, use_limit) << endl;
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
