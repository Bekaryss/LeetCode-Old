// Combination Sum 39.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

void combinationSum(int begin, vector<int>& candidates, vector<int>& candidate, int target, vector<vector<int>>& res) {
	if (target <= 0) {
		res.push_back(candidate);
		return;
	}
	for (int i = begin; i < candidates.size(); i++) {
		candidate.push_back(candidates[i]);
		if(target >= candidates[i])
			combinationSum(i, candidates, candidate, target - candidates[i], res);
		candidate.pop_back();
	}
	
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	vector<int> candidate;
	combinationSum(0, candidates, candidate, target, res);
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
	vector<int> candidates = { 8,7,4,3 };
	int target = 11;
	PrintRes(combinationSum(candidates, target));
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
