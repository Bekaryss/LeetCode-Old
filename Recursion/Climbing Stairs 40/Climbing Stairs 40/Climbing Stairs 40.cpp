﻿// Climbing Stairs 40.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int i, int n, vector<int>& memo) {
	if (i > n) {
		return 0;
	}
	if (i == n) {
		return 1;
	}
	if (memo[i] > 0) {
		return memo[i];
	}
	memo[i] =  climbStairs(i + 1, n, memo) + climbStairs(i + 2, n, memo);
	return memo[i];
}

int climbStairs(int n) {
	vector<int> memo(n + 1);
	return climbStairs(0, n, memo);
}

int main()
{
    std::cout << climbStairs(3);
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
