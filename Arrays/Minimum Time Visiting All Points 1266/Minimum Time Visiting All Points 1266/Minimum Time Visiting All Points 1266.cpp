// Minimum Time Visiting All Points 1266.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    bool first = false;
    int x = 0, y = 0;
    int res = 0;
    for (auto i : points) {
        if (first == false) {
            x = i[0];
            y = i[1];
            first = true;
        }
        while (x != i[0] || y != i[1]) {
            if (x < i[0]) {
                x++;
            }
            else if(x>i[0]){
                x--;
            }
            if (y < i[1]) {
                y++;
            }
            else if (y > i[1]) {
                y--;
            }
            res++;
        }
    }
    return res;
}

int minTimeToVisitAllPointsSolution(vector<vector<int>>& points) {
    int res = 0;
    for (int i = 1; i < points.size(); i++) {
        vector<int> cur = points[i], prev = points[i-1];
        res += max(abs(cur[0] - prev[0]), abs(cur[1] - prev[1]));
    }
    return res;
}

int main()
{
    vector<vector<int>> points = { {1, 1},{3, 4},{-1, 0} };
    std::cout << minTimeToVisitAllPointsSolution(points) << endl;
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
