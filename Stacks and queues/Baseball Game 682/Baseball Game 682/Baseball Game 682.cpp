// Baseball Game 682.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int calPoints(vector<string>& ops) {
	stack<int> st;
	int res = 0;
	for (string s : ops) {
		if (isdigit(s[0]) || s.size() > 1) {
			st.push(stoi(s));
			res += stoi(s);
		}
		else if (s == "D") {
			if (!st.empty()) {
				int cur = st.top() + st.top();
				st.push(cur);
				res += cur;
			}
		}
		else if (s == "C") {
			if (!st.empty()) {
				res -= st.top();
				st.pop();
			}
		}
		else if (s == "+") {
			if (st.size() >= 2) {
				int last = st.top();
				st.pop();
				int cur = st.top() + last;
				st.push(last);
				st.push(cur);
				res += cur;
			}
		}
	}
	return res;
}

int main()
{
	vector<string> input = { "5","2","C","D","+" };
	std::cout << "30 == " << calPoints(input) << endl;

	input = { "5", "-2", "4", "C", "D", "9", "+", "+" };
	std::cout << "27 == " << calPoints(input) << endl;

	input = { "-60", "D", "-36", "30", "13", "C", "C", "-33", "53", "79" };
	std::cout << "-117 == " << calPoints(input) << endl;
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
