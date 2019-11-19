﻿// Number of Digit One 233.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

int countDigitOneBF(int n) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == '1') {
				count++;
			}
		}
	}
	return count;
}

int countDigitOne(int n) {
	int count = 0;
	for (long long k = 1; k <= n; k *= 10)
	{
		long long r = n / k, m = n % k;
		count += (r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0);
	}
	return count;
}

int main()
{
	std::cout << "6 == " << countDigitOne(13) << endl;
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
