// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

void generate(vector<vector<int>>& list, int numRows) {
	if (numRows == 1)
		list.push_back({ 1 });
	else if (numRows > 1) {
		generate(list, numRows - 1);
		vector<int> prevL = list[numRows - 2];
		vector<int> curL;
		for (int i = 0; i < prevL.size(); i++)
		{
			if (i == 0)
				curL.push_back(1);
			if (i > 0) {
				curL.push_back(prevL[i] + prevL[i - 1]);
			}
			if (i == prevL.size() - 1)
				curL.push_back(1);
		}
		list.push_back(curL);
	}
}


vector<vector<int>> generate(int numRows) {
	vector<vector<int>> res;
	generate(res, numRows);
	return res;
}


int main()
{
	vector<vector<int>> res = generate(4);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
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
