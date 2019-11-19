// Binary Watch 401.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> hour = { 1, 2, 4, 8 }, minute = { 1, 2, 4, 8, 16, 32 };

void readBinaryWatch(int num, int start, pair<int, int>& time, vector<string>& res) {
	if (num == 0) {
		res.push_back(to_string(time.first) + (time.second < 10 ? ":0" : ":") + to_string(time.second));
		return;
	}
	else {
		for (int i = start; i < hour.size() + minute.size(); i++) {
			if (i < hour.size()) {
				time.first += hour[i];
				if (time.first < 12)
					readBinaryWatch(num - 1, i + 1, time, res);
				time.first -= hour[i];
			}
			else {
				time.second += minute[i - hour.size()];
				if (time.second < 60)
					readBinaryWatch(num - 1, i + 1, time, res);     // "minute" should be less than 60.
				time.second -= minute[i - hour.size()];
			}
		}
	}
}

vector<string> readBinaryWatch(int num) {
	vector<string> res;
	pair<int, int> time = { 0, 0 };
	readBinaryWatch(num, 0, time, res);
	return res;
}

void PrintRes(vector<string> res) {
	for (string s : res) {
		cout << s << " ";
	}
	cout << endl;
}


int main()
{
	PrintRes(readBinaryWatch(1));
	PrintRes(readBinaryWatch(2));
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
