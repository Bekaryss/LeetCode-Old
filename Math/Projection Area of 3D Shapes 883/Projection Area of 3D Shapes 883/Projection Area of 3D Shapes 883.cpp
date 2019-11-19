// Projection Area of 3D Shapes 883.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int projectionArea(vector<vector<int>>& grid) {
	int ans = 0;
	int n = 0;
	vector<int> yz(grid.size());
	vector<int> xz(grid[0].size());
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] != 0) {
				n++;
			}
			if (xz[j] < grid[i][j]) {
				xz[j] = grid[i][j];
			}
			if (yz[i] < grid[i][j]) {
				yz[i] = grid[i][j];
			}
		}
	}
	for (int i = 0; i < yz.size(); i++)
	{
		ans = ans + yz[i];
	}
	for (int j = 0; j < xz.size(); j++)
	{
		ans = ans + xz[j];
	}
	ans = ans + n;
	return ans;
}

int main()
{
	
	vector<vector<int>> input = { {2} };
	vector<vector<int>> input1 = { {1, 2}, { 3, 4} };
	vector<vector<int>> input2 = { {1, 0}, { 0, 2} };
	vector<vector<int>> input3 = { {1, 1, 1}, { 1, 0, 1}, {1, 1, 1} };
	vector<vector<int>> input4 = { {2, 2, 2}, { 2, 1, 2}, {2, 2, 2} };
    std::cout << "5 == " << projectionArea(input) << endl;
	std::cout << "17 == " << projectionArea(input1) << endl;
	std::cout << "8 == " << projectionArea(input2) << endl;
	std::cout << "14 == " << projectionArea(input3) << endl;
	std::cout << "21 == " << projectionArea(input4) << endl;

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
