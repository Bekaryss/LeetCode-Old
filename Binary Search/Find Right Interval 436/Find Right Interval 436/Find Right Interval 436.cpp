// Find Right Interval 436.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		unordered_map<int, int> map;
		for (int i = 0; i < intervals.size(); i++) {
			int first = intervals[i][0];
			map[first] = i;
		}
		vector<vector<int>> intCopy = intervals;
		sort(intCopy.begin(), intCopy.end(), [](vector<int> first, vector<int> second) {
			return first[0] < second[0];
			});

		vector<int> res;
		for (auto i : intervals) {
			int index = INT_MIN;
			int left = 0, right = intervals.size() - 1;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (i[1] == intCopy[mid][0]) {
					index = intCopy[mid][0];
					break;
				}
				else if (intCopy[mid][0] <= i[1]) {
					left = mid + 1;

				}
				else {
					index = intCopy[mid][0];
					right = mid - 1;

				}
			}
			if (index != INT_MIN) {
				res.push_back(map[index]);
			}
			else {
				res.push_back(-1);
			}
		}
		return res;
	}
};

class Solution1 {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		map<int, int> hash;
		vector<int> res;
		int n = intervals.size();
		for (int i = 0; i < n; i++) {
			hash[intervals[i][0]] = i;
		}
		for (auto in : intervals) {
			auto itr = hash.lower_bound(in[1]);
			if (itr != hash.end()) {
				res.push_back(itr->second);
			}
			else {
				res.push_back(-1);
			}
		}
		return res;
	}
};
void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	Solution1 s;
	vector<vector<int>> input = { {1, 2} };
	PrintRes(s.findRightInterval(input));
	input = { {3, 4}, {2,3}, {1,2} };
	PrintRes(s.findRightInterval(input));
	input = { {4, 5}, {2, 3}, {1, 2} };
	PrintRes(s.findRightInterval(input));
	input = { {-100,-98},{-99,-97},{-98,-96},{-97,-95},{-96,-94},{-95,-93},{-94,-92},{-93,-91},{-92,-90},{-91,-89},{-90,-88},{-89,-87},{-88,-86},{-87,-85},{-86,-84},{-85,-83},{-84,-82},{-83,-81},{-82,-80},{-81,-79},{-80,-78},{-79,-77},{-78,-76},{-77,-75},{-76,-74},{-75,-73},{-74,-72},{-73,-71},{-72,-70},{-71,-69},{-70,-68},{-69,-67},{-68,-66},{-67,-65},{-66,-64},{-65,-63},{-64,-62},{-63,-61},{-62,-60},{-61,-59},{-60,-58},{-59,-57},{-58,-56},{-57,-55},{-56,-54},{-55,-53},{-54,-52},{-53,-51},{-52,-50},{-51,-49},{-50,-48},{-49,-47},{-48,-46},{-47,-45},{-46,-44},{-45,-43},{-44,-42},{-43,-41},{-42,-40},{-41,-39},{-40,-38},{-39,-37},{-38,-36},{-37,-35},{-36,-34},{-35,-33},{-34,-32},{-33,-31},{-32,-30},{-31,-29},{-30,-28},{-29,-27},{-28,-26},{-27,-25},{-26,-24},{-25,-23},{-24,-22},{-23,-21},{-22,-20},{-21,-19},{-20,-18},{-19,-17},{-18,-16},{-17,-15},{-16,-14},{-15,-13},{-14,-12},{-13,-11},{-12,-10},{-11,-9},{-10,-8},{-9,-7},{-8,-6},{-7,-5},{-6,-4},{-5,-3},{-4,-2},{-3,-1},{-2,0},{-1,1},{0,2},{1,3},{2,4},{3,5},{4,6},{5,7},{6,8},{7,9},{8,10},{9,11},{10,12},{11,13},{12,14},{13,15},{14,16},{15,17},{16,18},{17,19},{18,20},{19,21},{20,22},{21,23},{22,24},{23,25},{24,26},{25,27},{26,28},{27,29},{28,30},{29,31},{30,32},{31,33},{32,34},{33,35},{34,36},{35,37},{36,38},{37,39},{38,40},{39,41},{40,42},{41,43},{42,44},{43,45},{44,46},{45,47},{46,48},{47,49},{48,50},{49,51},{50,52},{51,53},{52,54},{53,55},{54,56},{55,57},{56,58},{57,59},{58,60},{59,61},{60,62},{61,63},{62,64},{63,65},{64,66},{65,67},{66,68},{67,69},{68,70},{69,71},{70,72},{71,73},{72,74},{73,75},{74,76},{75,77},{76,78},{77,79},{78,80},{79,81},{80,82},{81,83},{82,84},{83,85},{84,86},{85,87},{86,88},{87,89},{88,90},{89,91},{90,92},{91,93},{92,94},{93,95},{94,96},{95,97},{96,98},{97,99},{98,100},{99,101} };
	PrintRes(s.findRightInterval(input));
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
