// Sudoku Solver 37.cpp : Этот файл содержит функцию 'main'. Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool isValid(int row, int col, char charToP, vector<vector<char>>& board) {
	for (vector<char> element : board) {
		if (charToP == element[col]) {
			return false;
		}
	}
	for (int i = 0; i < board.size(); i++) {
		if (charToP == board[row][i]) {
			return false;
		}
	}

	int regionSize = (int)sqrt(board.size()); // gives us the size of a sub-box

	int I = row / regionSize;
	int J = col / regionSize;

	int topLeftOfSubBoxRow = regionSize * I; // the row of the top left of the block
	int topLeftOfSubBoxCol = regionSize * J; // the column of the tol left of the block

	for (int i = 0; i < regionSize; i++) {
		for (int j = 0; j < regionSize; j++) {

			/*
			  i and j just define our offsets from topLeftOfBlockRow
			  and topLeftOfBlockCol respectively
			*/
			if (charToP == board[topLeftOfSubBoxRow + i][topLeftOfSubBoxCol + j]) {
				return false;
			}

		}
	}

	return true;
}

bool solveSudoku(int row, int col, vector<vector<char>>& board) {
	if (col == board[row].size()) {
		col = 0;
		row++;
		if (row == board.size()) {
			return true;
		}
	}
	

	if (board[row][col] != '.') {
		return solveSudoku(row, col + 1, board);
	}

	for (int i = 1; i <= board.size(); i++) {
		char charToP = (char)(i + '0');
		if (isValid(row, col, charToP, board)) {
			board[row][col] = charToP;
			if (solveSudoku(row, col + 1, board)) {
				return true;
			}

		}
	}
	board[row][col] = '.';
	return false;
}

void solveSudoku(vector<vector<char>>& board) {
	solveSudoku(0, 0, board);
}

void PrintRes(vector<vector<char>>& res) {
	for (vector<char> i : res) {
		for (char j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	vector<vector<char>> input = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	solveSudoku(input);
	PrintRes(input);
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
