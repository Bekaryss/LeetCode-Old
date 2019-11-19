// First Missing Positive 41.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

int firstMissingPositiveSolution(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++)
	{
		while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
			cout << "swap " << nums[i] << " " << nums[nums[i] - 1] << endl;
			swap(nums[i], nums[nums[i] - 1]);
			
		}
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != i + 1)
			return i + 1;
	}

	return nums.size() + 1;
}

int firstMissingPositive(vector<int>& nums) {
	vector<int> arr(nums.size() + 1, 0);
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] >= 0 && nums[i] <= nums.size())
			arr[nums[i]] = nums[i];
	}
	if (arr.size() == 0) {
		return 1;
	}
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] == 0) {
			return i;
		}
	}
	return nums.size() + 1;
}

int main()
{
	vector<int> input = { 1, 2, 0 };
	vector<int> input1 = { 3, 4, -1, 1 };
	vector<int> input2 = { 7, 8, 9, 11, 12 };
	vector<int> input3 = { 0 };
	vector<int> input4 = { 1,1 };
	vector<int> input5 = { -10, -3, -100, -1000, -239, 1 };
	vector<int> input6 = { 1,2,2,2,2,3,1 };
	vector<int> input7 = { 1,2,3,10,2147483647,9 };
	std::cout << "3 == " << firstMissingPositive(input) << endl;
	std::cout << "2 == " << firstMissingPositive(input1) << endl;
	std::cout << "1 == " << firstMissingPositive(input2) << endl;
	std::cout << "1 == " << firstMissingPositive(input3) << endl;
	std::cout << "2 == " << firstMissingPositive(input4) << endl;
	std::cout << "2 == " << firstMissingPositive(input5) << endl;
	std::cout << "4 == " << firstMissingPositive(input6) << endl;
	std::cout << "4 == " << firstMissingPositive(input7) << endl;

	std::cout << "Sol 3 == " << firstMissingPositiveSolution(input) << endl;
	std::cout << "Sol 2 == " << firstMissingPositiveSolution(input1) << endl;
	std::cout << "Sol 1 == " << firstMissingPositiveSolution(input2) << endl;
	std::cout << "Sol 1 == " << firstMissingPositiveSolution(input3) << endl;
	std::cout << "Sol 2 == " << firstMissingPositiveSolution(input4) << endl;
	std::cout << "Sol 2 == " << firstMissingPositiveSolution(input5) << endl;
	std::cout << "Sol 4 == " << firstMissingPositiveSolution(input6) << endl;
	std::cout << "Sol 4 == " << firstMissingPositiveSolution(input7) << endl;
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
