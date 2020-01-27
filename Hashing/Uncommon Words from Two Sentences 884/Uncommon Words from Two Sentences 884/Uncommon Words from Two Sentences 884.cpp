// Uncommon Words from Two Sentences 884.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

void GetWords(string s, unordered_map<string, int>& words) {
	int last = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ' || i == s.size()) {
			words[s.substr(last, i - last)]++;
			last = i + 1;
		}
	}
	words[s.substr(last, s.size() - last)]++;
}

vector<string> uncommonFromSentences(string A, string B) {
	vector<string> res;
	unordered_map<string, int> map;
	GetWords(A, map);
	GetWords(B, map);
	for (auto i : map) {
		if (i.second == 1) {
			res.push_back(i.first);
		}
	}
	return res;
}

vector<string> uncommonFromSentencesSolution(string A, string B) {
	unordered_map<string, int> count;
	istringstream iss(A + " " + B);
	while (iss >> A) count[A]++;
	vector<string> res;
	for (auto w : count)
		if (w.second == 1)
			res.push_back(w.first);
	return res;
}

void PrintRes(vector<string> res) {
	for (string s : res) {
		cout << s << " ";
	}
	cout << endl;
}

int main()
{
	string A = "this apple is sweet", B = "this apple is sour";
	PrintRes(uncommonFromSentencesSolution(A, B));
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
