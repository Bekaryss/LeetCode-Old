// Longest Substring Without Repeating Characters 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
	if (s == "")
		return 0;
	unordered_map<char, int> re;
	int max = INTMAX_MAX;
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (re.find(s[i]) == re.end()) {
			count++;
			if (max < count)
				max = count;
		}
		else {
			i = re[s[i]] + 1;
			re.clear();
			count = 1;
		}
		re[s[i]] = i;
	}
	return max;
}

int lengthOfLongestSubstringSolution(string s) {
	if (s == "")
		return 0;
	unordered_map<char, int> re;
	int maxv = INTMAX_MAX;
	int count = 0;
	for (int j = 0, i = 0; j < s.size(); j++) {
		if (re.find(s[j]) != re.end()) {
			i = max(re[s[j]], i);
		}
		count = max(count, j - i + 1);
		re[s[j]]= j + 1;
	}
	return count;
}

int main()
{
    std::cout << lengthOfLongestSubstring("aab") << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
