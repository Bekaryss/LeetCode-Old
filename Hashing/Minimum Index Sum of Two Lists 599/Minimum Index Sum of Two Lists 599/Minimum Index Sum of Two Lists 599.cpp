// Minimum Index Sum of Two Lists 599.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
	unordered_map<string, int> uml1;
	for (int i = 0; i < list1.size(); i++) {
		uml1[list1[i]] = i;
	}	
	int min = INT32_MAX;
	unordered_map<string, int> res;
	for (int i = 0; i < list2.size(); i++) {
		if (uml1.find(list2[i]) != uml1.end()) {
			int cur = uml1[list2[i]] + i;
			res[list2[i]] = cur;
			if (min > cur) {
				min = cur;
			}
		}
	}
	vector<string> ans;
	for (auto i:res) {
		if (i.second == min) {
			ans.push_back(i.first);
		}
	}
	return ans;
}

int main()
{
	vector<string> input1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" },
		input2 = { "KFC", "Burger King", "Tapioca Express", "Shogun" };
	vector<string> res = findRestaurant(input1, input2);
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
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
