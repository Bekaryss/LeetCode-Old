// Insert Interval 57.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	vector<vector<int>> ans;
	int index = 0;
	while (index < intervals.size() && intervals[index][1] < newInterval[0]) {
		ans.push_back(intervals[index++]);
	}
	while (index < intervals.size() && intervals[index][0] <= newInterval[1]) {
		newInterval[0] = min(newInterval[0], intervals[index][0]);
		newInterval[1] = max(newInterval[1], intervals[index][1]);
		index++;
	}
	ans.push_back(newInterval);
	while (index < intervals.size()) {
		ans.push_back(intervals[index++]);
	}
	return ans;
}

void ShowInterval(vector<vector<int>> intervals) {
	for (int i = 0; i < intervals.size(); i++)
	{
		for (int j = 0; j < intervals[i].size(); j++) {
			cout << intervals[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<int>> intervals = { { 1, 3 }, { 6, 9 } };
	vector<int> newInterval = { 2, 5 };
	vector<vector<int>> ans = insert(intervals, newInterval);
	ShowInterval(ans);
	cout << "------------------" << endl;
	
	vector<vector<int>> intervals1 = { {1,2},{3,5},{6,7},{8,10},{12,16} };
	vector<int> newInterval1 = { 4, 8 };
	vector<vector<int>> ans1 = insert(intervals1, newInterval1);
	ShowInterval(ans1);
	cout << "------------------" << endl;

	vector<vector<int>> intervals2 = { { 1, 5 } };
	vector<int> newInterval2 = { 0, 1 };
	vector<vector<int>> ans2 = insert(intervals2, newInterval2);
	ShowInterval(ans2);


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
