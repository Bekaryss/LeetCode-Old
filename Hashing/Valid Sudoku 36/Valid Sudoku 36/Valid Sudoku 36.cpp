// Valid Sudoku 36.cpp : Этот файл содержит функцию 'main'. Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
	unordered_set<char> v;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (isdigit(board[i][j])) {
				if (v.find(board[i][j]) != v.end())
					return false;
				v.insert(board[i][j]);
			}
		}
		v.clear();
	}
	v.clear();
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (isdigit(board[j][i])) {
				if (v.find(board[j][i]) != v.end())
					return false;
				v.insert(board[j][i]);
			}
		}
		v.clear();
	}
	v.clear();
	int iStart = 0, jStart = 0;
	int i = 0, j = 0;
	while (i != 9) {
		while (j != 9) {
			if (isdigit(board[i][j])) {
				if (v.find(board[i][j]) != v.end())
					return false;
				v.insert(board[i][j]);
			}
			j++;
			if (j == jStart + 3) {
				j = jStart;
				break;
			}
			
		}
		i++;
		if (i == iStart + 3) {
			i = iStart;
			jStart += 3;
			j = jStart;
			v.clear();
		}
		if (j == 9) {
			jStart = 0;
			j = jStart;
			iStart += 3;
			i = iStart;
		}
	}
	return true;
}

bool isValidSudokuSolution(vector<vector<char>>& board) {
	unordered_set<char> row, col, cube;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != '.') {
				if (row.find(board[i][j]) != row.end())
					return false;
				row.insert(board[i][j]);
			}
			if (board[j][i] != '.') {
				if (col.find(board[j][i]) != col.end())
					return false;
				col.insert(board[j][i]);
			}
			int RowIndex = 3 * (i / 3);
			int ColIndex = 3 * (i % 3);

			if (board[RowIndex + j / 3][ColIndex + j % 3] != '.') {
				if (cube.find(board[RowIndex + j / 3][ColIndex + j % 3]) != cube.end())
					return false;
				cube.insert(board[RowIndex + j / 3][ColIndex + j % 3]);
			}
		}
		row.clear();
		col.clear();
		cube.clear();

	}
	return true;
}

int main()
{
	vector<vector<char>> input =
	{
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	cout << "true == " << (isValidSudokuSolution(input) == true ? "true" : "false") << endl;
}

// Запуск программы: CTRL+F5 или меню 'Отладка' > 'Запуск без отладки'
// Отладка программы: F5 или меню 'Отладка' > 'Запустить отладку'

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне 'Выходные данные' можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне 'Список ошибок' можно просматривать ошибки.
//   5. Последовательно выберите пункты меню 'Проект' > 'Добавить новый элемент', чтобы создать файлы кода, или 'Проект' > 'Добавить существующий элемент', чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню 'Файл' > 'Открыть' > 'Проект' и выберите SLN-файл.
