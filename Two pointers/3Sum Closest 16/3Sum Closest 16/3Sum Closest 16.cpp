// 3Sum Closest 16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	if (nums.size() < 3) return 0;
	int closest = nums[0] + nums[1] + nums[2];
	int sum = 0;
	sort(nums.begin(), nums.end());
	for (int f = 0; f < nums.size() - 2; f++)
	{
		int s = f + 1;
		int l = nums.size() - 1;
		while (s < l) {
			sum = nums[f] + nums[s] + nums[l];
			if (sum == target)
				return sum;
			if (abs(target - sum) < abs(target - closest)) {
				closest = sum;
			}
			if (sum > target) {
				l--;
			}
			else {
				s++;
			}
		}
	}
	return closest;
}

int main()
{
	vector<int> input = { -1, 2, 1, -4 };
	std::cout << "2 == " << threeSumClosest(input, 1) << endl;

	vector<int> input1 = { 1, 1, -1, -1, 3 };
	std::cout << "3 == " << threeSumClosest(input1, 3) << endl;

	vector<int> input2 = { 0, 0, 0 };
	std::cout << "0 == " << threeSumClosest(input2, 1) << endl;
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
