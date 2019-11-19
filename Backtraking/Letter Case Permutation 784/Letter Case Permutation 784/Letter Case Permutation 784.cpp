// Letter Case Permutation 784.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void letterCasePermutation(int ulcase, int index, string& s, vector<string>& res) {
	if (index == s.size()) {
		res.push_back(s);
	}
	else {
		for (int i = 0; i < 2; i++) {

			if (isalpha(s[index])) {
				if (i == 0) {
					if (!islower(s[index])) {
						s[index] = tolower(s[index]);
					}
				}
				else {
					if (islower(s[index])) {
						s[index] = toupper(s[index]);
					}
				}
			}
			letterCasePermutation(i, index + 1, s, res);
			if (isdigit(s[index])) {
				return;
			}
		}
	}
}

vector<string> letterCasePermutation(string S) {
	vector<string> res;
	letterCasePermutation(0, 0, S, res);
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
	PrintRes(letterCasePermutation("a1b2"));
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
