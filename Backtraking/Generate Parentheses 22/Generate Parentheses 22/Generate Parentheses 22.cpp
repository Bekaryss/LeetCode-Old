// Generate Parentheses 22.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParenthesis(int l, int r, string sres, vector<string>& res) {
	if (l == 0 && r == 0) {
		res.push_back(sres);
	}
	else {
		if (l > 0) {
			generateParenthesis(l-1, r, sres + "(", res);
		}
		if (r > l) {
			generateParenthesis(l, r-1, sres + ")", res);
		}
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> res;
	string sres;
	generateParenthesis(n, n, sres, res);
	return res;
}

int main()
{
    std::cout << "Hello World!\n";
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
