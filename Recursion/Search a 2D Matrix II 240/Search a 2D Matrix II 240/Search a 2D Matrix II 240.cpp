// Search a 2D Matrix II 240.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	// check bad input
	int m = matrix.size();
	if (m == 0)
		return false;
	int n = matrix[0].size();
	if (n == 0)
		return false;
	return binarySearch(matrix, target, 0, m - 1, 0, n - 1);
}

bool binarySearch(vector<vector<int>>& matrix, int target, int min_i, int max_i, int min_j, int max_j) {
	if (min_i > max_i)
		return false;
	if (min_j > max_j)
		return false;
	int i = (min_i + max_i) / 2;
	int j = (min_j + max_j) / 2;

	int value = matrix[i][j];
	if (value == target)
		return true;
	else if (value < target)
	{
		return binarySearch(matrix, target, min_i, max_i, j + 1, max_j)
			|| binarySearch(matrix, target, i + 1, max_i, min_j, j);
	}
	else
	{
		return binarySearch(matrix, target, min_i, max_i, min_j, j - 1)
			|| binarySearch(matrix, target, min_i, i - 1, j, max_j);
	}
}

int main()
{
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
