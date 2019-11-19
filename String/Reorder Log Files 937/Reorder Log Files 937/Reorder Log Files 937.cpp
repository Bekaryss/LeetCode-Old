// Reorder Log Files 937.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> reorderLogFiles(vector<string>& logs) {
	sort(logs.begin(), logs.end(), [&](const string & a, const string & b) {
		int i = a.find(' ');
		int j = b.find(' ');

		if (!isdigit(a[i + 1]) && !isdigit(b[j + 1])) {
			if (a.substr(i + 1) == b.substr(j + 1)) {
				return a.substr(0, i + 1) < b.substr(0, j + 1);
			}
			else {
				return a.substr(i + 1) < b.substr(j + 1);
			}
		}
		else {
			if (isdigit(a[i + 1]) == false)
				return true;
			else {
				return false;
			}
		}
	});
	return logs;
}

int main()
{
	vector<string> input = { "l5sh 6 3869 08 1295", "16o 94884717383724 9", "43 490972281212 3 51", "9 ehyjki ngcoobi mi", "2epy 85881033085988", "7z fqkbxxqfks f y dg", "9h4p 5 791738 954209", "p i hz uubk id s m l", "wd lfqgmu pvklkdp u", "m4jl 225084707500464", "6np2 bqrrqt q vtap h", "e mpgfn bfkylg zewmg", "ttzoz 035658365825 9", "k5pkn 88312912782538", "ry9 8231674347096 00", "w 831 74626 07 353 9", "bxao armngjllmvqwn q", "0uoj 9 8896814034171", "0 81650258784962331", "t3df gjjn nxbrryos b" };
	vector<string> ans = reorderLogFiles(input);

	for (int i = 0; i < ans.size(); i++)
	{
		cout << " [" << ans[i] << "]" << endl;
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
