// Repeated DNA Sequences 187.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <bitset>

using namespace std;

void showBit(int id) {
	bitset<32> show(id);
	cout << show << endl;
}

vector<string> findRepeatedDnaSequences(string s) {
	int32_t id = 0;
	unordered_map<int32_t, int32_t> freq;
	unordered_map<char, int32_t> nuc_val = {
	  {'A', 0},
	  {'C', 1},
	  {'G', 2},
	  {'T', 3} };
	for (int i = 0; i < 9; i++) {
		id = (id << 2) | nuc_val[s[i]];
	}
	vector<string> ans;
	int32_t mask = (1 << 20) - 1;
	for (int i = 9; i < s.size(); i++) {
		id = ((id << 2) & mask);
		id |= nuc_val[s[i]];
		if (++freq[id] == 2) {
			ans.push_back(s.substr(i - 9, 10));
		}
	}
	return ans;
}

void PrintOut(vector<string> ans) {
	for (string s : ans) {
		cout << s << endl;
	}
	cout << "---------------" << endl;
}

int main()
{
	string input = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	PrintOut(findRepeatedDnaSequences(input));
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
