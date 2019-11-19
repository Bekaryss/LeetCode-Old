// Combination Sum III 216.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

void combinationSum3(int begin, vector<int>& candidate, int k, int n, vector<vector<int>>& res) {
	if (k == 0 && n <= 0) {
		res.push_back(candidate);
		return;
	}
	for (int i = begin; i <= 9; i++) {
		candidate.push_back(i);
		if (n >= i)
			combinationSum3(i + 1, candidate, k-1, n - i, res);
		candidate.pop_back();
	}
}

vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> res;
	vector<int> candidate;
	combinationSum3(1, candidate, k, n, res);
	return res;
}

void PrintRes(vector<vector<int>> res) {
	for (auto i : res) {
		for (int j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	PrintRes(combinationSum3(3, 7));
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
