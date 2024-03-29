﻿// 4Sum II 454.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	unordered_map<int, int> sums;
	int count = 0;
	for (int i : A) {
		for (int j : B) {
			sums[i + j]++;
		}
	}

	for (int i : C) {
		for (int j : D) {
			int sum = -(i + j);
			if (sums.find(sum) != sums.end()) {
				count += sums[sum];
			}
		}
	}
	return count;
}

int main()
{
	vector<int> A = { 1, 2 },
		B = { -2, -1 },
		C = { -1, 2 },
		D = { 0, 2 };
	std::cout << fourSumCount(A, B, C, D) << endl;
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
