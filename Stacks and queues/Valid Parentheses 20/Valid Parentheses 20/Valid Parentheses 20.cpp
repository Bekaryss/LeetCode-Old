﻿// Valid Parentheses 20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
	stack<char> sc;
	for (char c : s) {
		if (!sc.empty()) {
			if (sc.top() == '(' && c == ')') {
				sc.pop();
			}
			else  if (sc.top() == '{' && c == '}') {
				sc.pop();
			}
			else if (sc.top() == '[' && c == ']') {
				sc.pop();
			}
			else {
				sc.push(c);
			}
		}
		else {
			sc.push(c);
		}
	}
	if (!sc.empty())
		return false;
	else
		return true;
}

int main()
{
	std::cout << (isValid("(])") == true ? "true" : "false") << endl;
	std::cout << (isValid("()") == true ? "true" : "false") << endl;
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
