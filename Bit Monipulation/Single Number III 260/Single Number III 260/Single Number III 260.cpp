// Single Number III 260.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
	int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
	diff &= -diff;
	vector<int> rets = { 0, 0 };
	for (int num : nums) {
		if ((num & diff) == 0) {
			rets[0] ^= num;
		}
		else {
			rets[1] ^= num;
		}
	}
	return rets;
}

void Print(vector<int> ans) {
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> input = { 1,2,1,3,2,5 };
	Print(singleNumber(input));
	vector<int> input1 = { 1,1,2,3,4,4,5,5 };
	Print(singleNumber(input1));
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
