// N-Queens II 52.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool isValid(vector<int>& colP) {
	int rowId = colP.size() - 1;
	for (int i = 0; i < rowId; i++) {
		int diff = abs(colP[i] - colP[rowId]);
		if (diff == 0 || diff == rowId - i) {
			return false;
		}
	}
	return true;
}

void totalNQueens(int n, int row, vector<int>& colP, int& res) {
	if (row == n) {
		res++;
	}
	else {
		for (int i = 0; i < n; i++)
		{
			colP.push_back(i);
			if (isValid(colP)) {
				totalNQueens(n, row + 1, colP, res);
			}
			colP.pop_back();
		}
	}
}

int totalNQueens(int n) {
	int res = 0;
	vector<int> colP;
	totalNQueens(n, 0, colP, res);
	return res;
}

int main()
{
	cout << "2 == " << totalNQueens(4) << endl;
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
