// Heaters 475.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Using dp;
class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		vector<int> res(houses.size(), INT_MAX);
		for (int i = 0, h = 0; i < houses.size() && h < heaters.size();) {
			if (houses[i] <= heaters[h]) {
				res[i] = heaters[h] - houses[i];
				i++;
			}
			else {
				h++;
			}
		}

		for (int i = houses.size() - 1, h = heaters.size() - 1; i >= 0 && h >= 0;) {
			if (houses[i] >= heaters[h]) {
				res[i] = min(houses[i] - heaters[h], res[i]);
				i--;
			}
			else {
				h--;
			}
		}
		int maxv = 0;
		for (int i : res) {
			maxv = max(i, maxv);
		}
		return maxv;
	}
};


//Binary Search
class Solution1 {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(heaters.begin(), heaters.end());
		int minValue = INT_MIN;
		for (int i = 0; i < houses.size(); i++) {
			minValue = max(minValue, bs(houses[i], heaters));
		}
		return minValue;
	}

private:
	int bs(int target, vector<int>& heaters) {
		int i = 0, j = heaters.size() - 1;
		while (i + 1 < j) {
			int mid = i + (j - i) / 2;
			if (heaters[mid] == target)
				return 0;
			else if (heaters[mid] < target)
				i = mid;
			else
				j = mid;
		}
		return min(abs(target - heaters[i]), abs(target - heaters[j]));
	}
};

//lower_bound
class Solution2 {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		int ans = 0, n = houses.size();
		sort(heaters.begin(), heaters.end());
		for (int i = 0; i < n; ++i)
		{
			int t1 = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
			int t2;
			if (t1 == 0)
				t2 = heaters[t1] - houses[i];
			else if (t1 == heaters.size())
				t2 = houses[i] - heaters[t1 - 1];
			else
				t2 = min(heaters[t1] - houses[i], houses[i] - heaters[t1 - 1]);
			ans = max(ans, t2);
		}
		return ans;
	}
};

int main()
{
	Solution2 s;
	vector<int> houses = { 1,2,3 }, heaters = { 2 };
	std::cout << s.findRadius(houses, heaters) << endl;

	houses = { 1, 2, 3, 4 }, heaters = { 1, 4 };
	std::cout << s.findRadius(houses, heaters) << endl;
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
