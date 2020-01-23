// Unique Number of Occurrences 1207.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
	unordered_map<int, int> occ;
	unordered_set<int> counter;
	for (int i : arr) {
		occ[i]++;
	}
	for (auto i : occ) {
		if (counter.find(i.second) != counter.end()) {
			return false;
		}
		counter.insert(i.second);
	}
	return true;
}

int main()
{
	vector<int> arr = { 1, 2, 2, 1, 1, 3 };
	std::cout << (uniqueOccurrences(arr) == true ? "true" : "false") << endl;
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
