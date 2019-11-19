// Interval List Intersections 986.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
	if (A.size() == 0) {
		return A;
	}
	if (B.size() == 0) {
		return B;
	}

	int i = 0, j = 0;
	vector<vector<int>> res;
	while (i < A.size() && j < B.size()) {
		int maxF = max(A[i][0], B[j][0]);
		int minS = min(A[i][1], B[j][1]);
		if(maxF <= minS)
			res.push_back({ maxF, minS });
		if (A[i][1] > B[j][1]) {
			j++;
		}
		else {
			i++;
		}
	}
	return res;
}

void PrintRes(vector<vector<int>> res) {
	for (int i = 0; i < res.size(); i++) {
		cout << res[i][0] << ", " << res[i][1] << endl;
	}
	cout << endl;
}

int main()
{
	vector<vector<int>> A = { {0, 2}, {5, 10}, {13, 23}, {24, 25} }, B = { {1, 5}, {8, 12}, {15, 24}, {25, 26} };
	PrintRes(intervalIntersection(A, B));

	vector<vector<int>> A1 = { {4, 7}, {8, 14} }, B1 = { {3,4} };
	PrintRes(intervalIntersection(A1, B1));
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
