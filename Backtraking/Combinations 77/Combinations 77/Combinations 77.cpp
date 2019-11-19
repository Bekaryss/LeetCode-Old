// Combinations 77.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

void combine(int s, int n, int k, vector<int>& snippet, vector<vector<int>>& res) {
	if (k == snippet.size()) {
		res.push_back(snippet);
	}
	else {
		int spaceLeftSnippet = k - snippet.size();
		for (int i = s; i <= n && spaceLeftSnippet <= n - i + 1; i++)
		{
			snippet.push_back(i);
			combine(i + 1, n, k, snippet, res);
			snippet.pop_back();
		}
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;
	vector<int> snippet;
	combine(1, n, k, snippet, res);
	return res;
}

void PrintRes(vector<vector<int>> res) {
	for (auto i : res)
	{
		for (int j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	PrintRes(combine(4, 2));
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
