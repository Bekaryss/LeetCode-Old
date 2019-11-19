// N-Queens 51.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;


bool isValid(vector<string>& colP) {
	int rowId = colP.size() - 1;
	for (int i = 0; i < rowId; i++) {
		int diff = abs((int)colP[i].find('Q') - (int)colP[rowId].find('Q'));
		if (diff == 0 || diff == rowId - i) {
			return false;
		}
	}
	return true;
}

void solveNQueens(int n, int row, vector<string>& colP, vector<vector<string>>& res) {
	if (row == n) {
		res.push_back(colP);
	}
	else {
		string s(n, '.');
		string d = s;
		for (int i = 0; i < n; i++) {
			s[i] = 'Q';
			colP.push_back(s);
			if (isValid(colP)) {
				solveNQueens(n, row + 1, colP, res);
			}
			colP.pop_back();
			s = d;
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> res;
	vector<string> colP;
	solveNQueens(n, 0, colP, res);
	return res;
}

void PrintRes(vector<vector<string>> res) {
	for (auto i : res) {
		for (string j : i) {
			cout << j << endl;
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	PrintRes(solveNQueens(4));
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
