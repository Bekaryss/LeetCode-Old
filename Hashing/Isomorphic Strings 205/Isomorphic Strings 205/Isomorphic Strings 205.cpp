﻿// Isomorphic Strings 205.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

bool isIsomorphic(string s, string t) {
	unordered_map<char, char> um;
	unordered_set<char> us1, us2;
	for (int i = 0; i < s.size(); i++) {
		if (um.find(s[i]) != um.end()) {
			if (um[s[i]] != t[i])
				return false;
		}
		else {
			um[s[i]] = t[i];
		}
		us1.insert(s[i]);
		us2.insert(t[i]);
	}
	return us1.size() == us2.size();
}

int main()
{
    std::cout << "true == " << (isIsomorphic("egg","add") == true ?"true":"false") << endl;
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
