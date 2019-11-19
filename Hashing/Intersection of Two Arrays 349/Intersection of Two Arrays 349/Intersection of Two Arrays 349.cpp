// Intersection of Two Arrays 349.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> n1, n2;
	for (int i : nums1)
		n1.insert(i);
	for (int i : nums2)
		n2.insert(i);

	unordered_map<int, int> mres;
	for (int i : n1) {
		mres[i]++;
	}
	for (int i : n2) {
		mres[i]++;
	}
	vector<int> res;
	for (auto i : mres) {
		if (i.second > 1) {
			res.push_back(i.first);
		}
	}
	return res;
}

int main()
{
	vector<int> nums1 = { 1, 2, 2, 1 }, nums2 = { 2, 2 };
	vector<int> res = intersection(nums1, nums2);
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
