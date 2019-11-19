﻿// Pow x n.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

double myPow(double x, int n) {
	if (n < 0) {
		return 1 / x * myPow(1 / x, -(n + 1));
	}

	if (n == 0) {
		return 1;
	}

	if (n == 2) {
		return x * x;
	}

	if (n % 2 == 0) {
		double y = myPow(x, n / 2);
		return y * y;
	}
	else {
		return x * myPow(x, n - 1);
	}
}

int main()
{
    std::cout << myPow(2.00000, 10) << endl;
	std::cout << myPow(2.00000, -2) << endl;
	std::cout << myPow(1.00000, -214748364) << endl;
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
