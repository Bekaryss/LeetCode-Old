// Letter Combinations of a Phone Number 17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, string> mapping = { {'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}, };

void letterCombinations(string& digits, int digit, string& partialRes, vector<string>& res) {
	if (digit == digits.size()) {
		res.push_back(partialRes);
	}
	else {
		for (int i = 0; i < mapping[digits[digit]].size(); i++) {
			char c = mapping[digits[digit]][i];
			partialRes[digit] = c;
			letterCombinations(digits, digit+1, partialRes, res);
		}
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> res;
	if (digits.size() == 0) {
		return res;
	}
	string partialRes(digits.size(), '.');
	letterCombinations(digits, 0, partialRes, res);
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
	PrintRes(letterCombinations("23"));
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
