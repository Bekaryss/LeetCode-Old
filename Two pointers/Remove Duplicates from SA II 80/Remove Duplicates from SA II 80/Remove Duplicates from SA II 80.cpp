// Remove Duplicates from SA II 80.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	int i = 0, j = 0;
	while (i < nums.size()) {
		int cur = nums[i];
		int count = 0;
		while (j < nums.size()) {
			if (cur != nums[j]) {
				count = 0;
				break;
			}else if (count >= 2) {
				nums.erase(nums.begin() + j);
				j--;
			}
			else if (cur == nums[j]) {
				count++;
			}
			j++;
		}
		i = j;
	}
	return nums.size();
}

int removeDuplicatesSolution(vector<int>& nums) {
	int i = 0;
	for (int n : nums)
		if (i < 2 || n > nums[i - 2])
			nums[i++] = n;
	return i;
}

int main()
{
	vector<int> input = { 1,1,1,2,2,3 };
    std::cout << "5 == " << removeDuplicatesSolution(input) << endl;

	input = { 0,0,1,1,1,1,2,3,3 };
	std::cout << "7 == " << removeDuplicatesSolution(input) << endl;
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
