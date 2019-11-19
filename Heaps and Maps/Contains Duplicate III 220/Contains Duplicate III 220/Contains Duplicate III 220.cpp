// Contains Duplicate III 220.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	if (k < 1 || t < 0)
		return false;
	map<long, int> buckets;
	long minv = INT_MAX;
	for (int i : nums) {
		if (minv > i) {
			minv = i;
		}
	}
	for (int i = 0; i < nums.size(); i++) {
		long remap = (long)nums[i] - minv;
		long bucket = remap / ((long)t + 1);
		if (buckets.count(bucket)
			|| (buckets.count(bucket - 1) && remap - buckets[bucket - 1] <= t)
			|| (buckets.count(bucket + 1) && buckets[bucket + 1] - remap <= t)) {
			return true;
		}
		if (buckets.size() >= k) {
			long lastb = ((long)nums[i - k] - minv) / ((long)t + 1);
			buckets.erase(lastb);
		}
		buckets[bucket] = remap;
	}
	return false;
}

int main()
{
	int a = 0 / 5;
	vector<int> nums = { 1, 2, 3, 1 };
	int k = 3, t = 0;
	std::cout << "true == " << (containsNearbyAlmostDuplicate(nums, k, t) == true ? "true" : "false") << endl;
	nums = { 1,0,1,1 };
	k = 1, t = 2;
	std::cout << "true == " << (containsNearbyAlmostDuplicate(nums, k, t) == true ? "true" : "false") << endl;
	nums = { 1,5,9,1,5,9 };
	k = 2, t = 3;
	std::cout << "false == " << (containsNearbyAlmostDuplicate(nums, k, t) == true ? "true" : "false") << endl;
	nums = { -3, 3 };
	k = 2, t = 4;
	std::cout << "false == " << (containsNearbyAlmostDuplicate(nums, k, t) == true ? "true" : "false") << endl;
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
