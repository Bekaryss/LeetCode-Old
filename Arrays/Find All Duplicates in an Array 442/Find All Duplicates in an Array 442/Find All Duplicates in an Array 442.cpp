// Find All Duplicates in an Array 442.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDuplicatesSolution(vector<int>& nums) {
	vector<int> ans;
	for (int i = 0; i < nums.size(); i++) {
		nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
		if (nums[abs(nums[i]) - 1] > 0) {
			ans.push_back(abs(nums[i]));
		}
	}
	return ans;
}

vector<int> findDuplicates(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<int> ans;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == nums[i - 1]) {
			ans.push_back(nums[i]);
		}
	}
	return ans;
}

int main()
{
	vector<int> input = { 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int> ans = findDuplicates(input);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
    std::cout << "Hello World!\n"; 
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
