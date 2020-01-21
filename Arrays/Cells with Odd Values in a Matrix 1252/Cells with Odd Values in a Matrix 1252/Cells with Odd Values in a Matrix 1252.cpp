﻿// Cells with Odd Values in a Matrix 1252.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int oddCells(int n, int m, vector<vector<int>>& indices) {
    vector<vector<int>> matrix(n, vector<int>(m));
    for (auto index : indices) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (index[0] == i) {
                    matrix[i][j] += 1;
                }
                if (index[1] == j) {
                    matrix[i][j] += 1;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] % 2 != 0) {
                res++;
            }
        }
    }
    return 0;
}

int main()
{
    int n = 2, m = 3;
    vector<vector<int>> indices = { {0,1}, {1,1} };
    std::cout << oddCells(n, m, indices) << endl;
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
