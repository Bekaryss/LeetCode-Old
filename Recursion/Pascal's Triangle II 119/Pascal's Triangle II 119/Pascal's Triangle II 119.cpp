﻿// Pascal's Triangle II 119.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
	vector<int> res;
	if (rowIndex == 0) {
		res.push_back(1);
		return res;
	}
	else
	{
		vector<int> last = getRow(rowIndex - 1);
		for (int i = 0; i < last.size(); i++)
		{
			if (i == 0) {
				res.push_back(1);
			}
			if (i > 0) {
				res.push_back(last[i] + last[i - 1]);
			}
			if (i == last.size() - 1) {
				
			}	
		}
		res.push_back(1);
	}
	return res;
}

int main()
{
	vector<int> res = getRow(3);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
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
