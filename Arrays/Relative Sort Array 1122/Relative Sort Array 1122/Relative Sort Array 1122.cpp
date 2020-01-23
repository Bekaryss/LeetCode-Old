// Relative Sort Array 1122.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
	vector<int> res, tmp;
	unordered_map<int, int> map;
	for (int i : arr2) {
		map[i] = 0;
	}
	for (int i : arr1) {
		if (map.find(i) != map.end()) {
			map[i]++;
		}
		else {
			tmp.push_back(i);
		}
	}
	sort(tmp.begin(), tmp.end());
	for (int i : arr2) {
		int j = 0;
		while (j < map[i]) {
			res.push_back(i);
			j++;
		}
	}
	for (int i : tmp) {
		res.push_back(i);
	}
	return res;
}

int main()
{
	vector<int> arr1 = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, arr2 = { 2, 1, 4, 3, 9, 6 };
	vector<int> res = relativeSortArray(arr1, arr2);
	for (int i : res) {
		cout << i << " ";
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
