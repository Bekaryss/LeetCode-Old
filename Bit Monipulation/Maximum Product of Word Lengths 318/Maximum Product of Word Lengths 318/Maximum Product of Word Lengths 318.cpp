// Maximum Product of Word Lengths 318.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<string>& words) {
	vector<int> masks(words.size(), 0);
	for (int i = 0; i < words.size(); i++) {
		int mask = 0;
		for (char c : words[i]) {
			masks[i] |= 1 << (c - 'a');
		}
	}
	int maxim = 0;
	for (int i = 0; i < masks.size(); i++) {
		int count = 0;
		for (int j = i+1; j < masks.size(); j++) {
			if ((masks[i] & masks[j]) == 0) {
				maxim = max(maxim, (int)(words[i].size() * words[j].size()));
			}
		}
	}
	return maxim;
}

int main()
{
	vector<string> input = { "abcw","baz","foo","bar","xtfn","abcdef" };
    std::cout << "16 == " << maxProduct(input) << endl; 
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
