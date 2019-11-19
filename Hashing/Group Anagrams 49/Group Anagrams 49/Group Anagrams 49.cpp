// Group Anagrams 49.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string>> ca;
	for (string i : strs) {
		string s = i;
		sort(s.begin(), s.end());
		ca[s].push_back(i);
	}
	vector<vector<string>> res;
	for (auto i : ca) {
		res.push_back(i.second);
	}
	return res;
}

int main()
{
	vector<string> input = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string >> res = groupAnagrams(input);
	for (auto i : res) {
		for (string j : i) {
			cout << j << " ";
		}
		cout << endl;
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
