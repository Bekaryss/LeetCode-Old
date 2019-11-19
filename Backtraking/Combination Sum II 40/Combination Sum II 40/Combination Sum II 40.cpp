// Combination Sum II 40.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationSum2(int begin, vector<int>& candidates, vector<int>& candidate, int target, vector<vector<int>>& res) {
	if (target <= 0) {
		res.push_back(candidate);
		return;
	}
	for (int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
		candidate.push_back(candidates[i]);
		if (i == begin || candidates[i] != candidates[i - 1])
			combinationSum2(i + 1, candidates, candidate, target - candidates[i], res);
		candidate.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> res;
	vector<int> candidate;
	combinationSum2(0, candidates, candidate, target, res);
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
	/*vector<int> candidates = { 2, 3, 6, 7 };
	int target = 7;
	PrintRes(combinationSum(candidates, target));
*/
	vector<int> candidates = { 10,1,2,7,6,1,5 };
	int target = 8;
	PrintRes(combinationSum2(candidates, target));
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
