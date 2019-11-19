// Find and Replace Pattern 890.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
	vector<string> ans;
	for (int i = 0; i < words.size(); i++) {
		unordered_map<char, char> patternMap;
		bool match = true;
		for (int j = 0; j < words[i].size(); j++) {
			if (patternMap.size() != 0) {
				for (auto f = patternMap.begin(); f != patternMap.end(); f++) {
					if (f->first != pattern[j] && f->second == words[i][j]) {
						match = false;
					}
					else if (f->first == pattern[j] && f->second != words[i][j]) {
						match = false;
					}
				}
			}
			if(match != false)
				patternMap.insert(std::pair<char, char>(pattern[j], words[i][j]));
			
		}
		if (match == true) {
			ans.push_back(words[i]);
		}
	}
	return ans;
}

int main()
{
	vector<string> words = { "abc", "deq", "mee", "aqq", "dkd", "ccc" };
	string pattern = "abb";
	vector<string> ans = findAndReplacePattern(words, pattern);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
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
