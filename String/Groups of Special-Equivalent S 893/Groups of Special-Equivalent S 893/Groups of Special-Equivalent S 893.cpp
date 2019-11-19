// Groups of Special-Equivalent S 893.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int numSpecialEquivGroups(vector<string>& A) {
	int n = 0;
	unordered_set<string> ans;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i].size() == 1) {
			ans.insert(A[i]);
		}
		else {
			string even = "", odd = "";
			for (int j = 0; j < A[i].size(); j++) {
				if (j % 2 == 0) {
					even += A[i][j];
				}
				else {
					odd += A[i][j];
				}
			}
			sort(even.begin(), even.end());
			sort(odd.begin(), odd.end());
			ans.insert(even + odd);
		}
	}
	return ans.size();
}

int main()
{
	vector<string> input = { "a", "b", "c", "a", "c", "c" };
	std::cout << "3 == " << numSpecialEquivGroups(input) << endl;
	vector<string> input1 = { "aa","bb","ab","ba" };
	std::cout << "4 == " << numSpecialEquivGroups(input1) << endl;
	vector<string> input2 = { "abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx" };
	std::cout << "3 == " << numSpecialEquivGroups(input2) << endl;
	
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
