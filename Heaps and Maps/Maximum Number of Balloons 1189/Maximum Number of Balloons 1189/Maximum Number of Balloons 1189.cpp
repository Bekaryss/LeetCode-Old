// Maximum Number of Balloons 1189.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maxNumberOfBalloons(string text) {
	unordered_map<char, int> map;
	string s = "balloon";
	for (char i : s) {
		map[i] = 0;
	}
	for (int i = 0; i < text.size(); i++) {
		if (map.find(text[i]) != map.end()) {
			map[text[i]]++;
		}
	}
	int res = INT_MAX;
	for (auto i : map) {
		if (i.first == 'l' || i.first == 'o') {
			res = min(i.second / 2, res);
		}
		else {
			res = min(i.second, res);
		}
	}
	return res;
}

int main()
{
	std::cout << maxNumberOfBalloons("nlaebolko") << endl;
	std::cout << maxNumberOfBalloons("loonbalxballpoon") << endl;
	std::cout << maxNumberOfBalloons("leetcode") << endl;
	std::cout << maxNumberOfBalloons("balon") << endl;
	std::cout << maxNumberOfBalloons("krhizmmgmcrecekgyljqkldocicziihtgpqwbticmvuyznragqoyrukzopfmjhjjxemsxmrsxuqmnkrzhgvtgdgtykhcglurvppvcwhrhrjoislonvvglhdciilduvuiebmffaagxerjeewmtcwmhmtwlxtvlbocczlrppmpjbpnifqtlninyzjtmazxdbzwxthpvrfulvrspycqcghuopjirzoeuqhetnbrcdakilzmklxwudxxhwilasbjjhhfgghogqoofsufysmcqeilaivtmfziumjloewbkjvaahsaaggteppqyuoylgpbdwqubaalfwcqrjeycjbbpifjbpigjdnnswocusuprydgrtxuaojeriigwumlovafxnpibjopjfqzrwemoinmptxddgcszmfprdrichjeqcvikynzigleaajcysusqasqadjemgnyvmzmbcfrttrzonwafrnedglhpudovigwvpimttiketopkvqw") << endl;
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
