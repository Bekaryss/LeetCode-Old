// Max Chunks To Make Sorted II 768.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxChunksToSorted(vector<int>& arr) {
	vector<int> sorted = arr;
	long long sum1 = 0, sum2 = 0, ans = 0;
	sort(sorted.begin(), sorted.end());
	for (int i = 0; i < arr.size(); i++)
	{
		sum1 += arr[i];
		sum2 += sorted[i];
		if (sum1 == sum2)
			ans++;
	}
	return ans;
}

int main()
{
	vector<int> input =  { 1, 1, 0, 0, 1 };
	vector<int> input1 = { 2, 1, 3, 4, 4 };
	vector<int> input2 = { 5, 4, 3, 2, 1 };
	vector<int> input3 = { 1, 0, 1, 3, 2 };
	vector<int> input4 = { 4, 0, 0, 2, 4 };
	std::cout << "2 == " << maxChunksToSorted(input) << endl;
	std::cout << "4 == " << maxChunksToSorted(input1) << endl;
	std::cout << "1 == " << maxChunksToSorted(input2) << endl;
	std::cout << "3 == " << maxChunksToSorted(input3) << endl;
	std::cout << "2 == " << maxChunksToSorted(input4) << endl;
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
