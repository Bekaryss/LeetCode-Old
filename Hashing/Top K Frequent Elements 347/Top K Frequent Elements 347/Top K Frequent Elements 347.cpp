// Top K Frequent Elements 347.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> counter;
	vector<int> res;
	for (int i : nums) {
		counter[i]++;
	}

	auto comp = [](pair<int, int> n1, pair<int, int> n2)
	{
		return (n1.second > n2.second);
	};
	vector<pair<int, int>> pre;
	
	for (auto i : counter) {
		pre.push_back(i);
	}
	sort(pre.begin(), pre.end(), comp);
	for (auto i : pre) {
		if (k > 0) {
			res.push_back(i.first);
		}
		else {
			break;
		}
		k--;
	}
	return res;
}

void PrintRes(vector<int> res) {
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector <int> nums = { 1, 1, 1, 2, 2, 3 };
	int k = 2;
	PrintRes(topKFrequent(nums, k));
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
