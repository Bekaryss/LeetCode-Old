// Escape The Ghosts 789.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

float distance(int x1, int y1, int x2, int y2)
{
	return abs(x2 - x1) + abs(y2 - y1);
}

bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
	float distanceToTarget = distance(0, 0, target[0], target[1]);
	for (int i = 0; i < ghosts.size(); i++) {
		float curDist = distance(target[0], target[1], ghosts[i][0], ghosts[i][1]);
		if (curDist <= distanceToTarget) {
			return false;
		}
	}
	return true;
}

int main()
{
	vector<vector<int>> ghosts = { {1,0}, {0,3} };
	vector<int> target = { 0,1 };
	vector<vector<int>> ghosts1 = { {1, 8}, {-9, 0}, {-7, -6},{4, 3},{1, 3} };
	vector<int> target1 = { 6, -9 };
	std::cout << "true == " << (escapeGhosts(ghosts, target) == 1 ? "true": "false") << endl;
	std::cout << "false == " << (escapeGhosts(ghosts1, target1) == 1 ? "true" : "false") << endl;
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
