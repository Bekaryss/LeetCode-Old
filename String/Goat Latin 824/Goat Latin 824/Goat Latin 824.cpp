// Goat Latin 824.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string toGoatLatin(string S) {
	vector<string> words;
	stringstream ss(S);
	string item = "";
	while (getline(ss, item, ' ')) {
		words.push_back(item);
	}
	vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
	int n = 0;
	string ans = "";
	for (int i = 0; i < words.size(); i++) {
		bool vowel = false;
		for (int j = 0; j < vowels.size(); j++) {
			if (words[i][0] == vowels[j] || words[i][0] == vowels[j] - 32) {
				vowel = true;
			}
		}
		if (vowel == true) {
			words[i] += "ma";
		}
		else {
			words[i].push_back(words[i][0]);
			words[i].erase(0, 1);
			words[i] += "ma";
		}
		for (int x = 0; x <= n; x++) {
			words[i] += 'a';
		}
		n++;
		if (n <= words.size() - 1) {
			ans = ans + words[i] + " ";
		}
		else {
			ans = ans + words[i] ;
		}
	}
	return ans;
}

int main()
{
	string input = "I speak Goat Latin";
	std::cout << toGoatLatin(input) << endl;
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
