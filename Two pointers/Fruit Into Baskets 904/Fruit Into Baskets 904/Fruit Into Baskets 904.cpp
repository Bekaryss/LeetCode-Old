// Fruit Into Baskets 904.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int totalFruit(vector<int>& tree) {
	unordered_map<int, int> counter;
	int next = 0;
	int ans = 0;
	int maxAns = 0;
	for (int i = 0; i < tree.size(); i++)
	{
		ans = 0;
		counter.clear();
		int j = i;
		bool first = true;
		while (j < tree.size()) {
			counter[tree[j]]++;
			if (counter.size() < 3) {
				ans++;
			}
			if (counter.size() == 3) {
				if (maxAns == 0) {
					maxAns = ans;
				}
				else {
					maxAns = max(ans, maxAns);
				}
				break;
			}
			if (counter.size() == 2 && first == true) {
				next = j;
				first = false;
			}
			j++;
			if (j == tree.size() - 1) {
				i = j;
			}
		}
		if(counter.size() == 3)
			i = next - 1;
	}
	return max(maxAns, ans);
}

int main()
{
	vector<int> input = { 1,2,1 };
	std::cout << "3 == " << totalFruit(input) << endl;

	input = { 0,1,2,2 };
	std::cout << "3 == " << totalFruit(input) << endl;

	input = { 1,2,3,2,2 };
	std::cout << "4 == " << totalFruit(input) << endl;

	input = { 3,3,3,1,2,1,1,2,3,3,4 };
	std::cout << "5 == " << totalFruit(input) << endl;

	input = { 0, 1, 6, 6, 4, 4, 6 };
	std::cout << "5 == " << totalFruit(input) << endl;
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
