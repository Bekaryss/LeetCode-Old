// Parsing A Boolean Expression 1106.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool parseBoolExpr(string expression) {
	stack<char> s;
	for (auto ch : expression) {
		if (ch == ')') {
			auto hasT = false, hasF = false;
			while (s.top() == 't' || s.top() == 'f') {
				hasT |= s.top() == 't';
				hasF |= s.top() == 'f';
				s.pop();
			}
			auto op = s.top();
			s.pop();
			s.push(op == '!' ? hasF ? 't' : 'f' : op == '&' ? !hasF ? 't' : 'f' : hasT ? 't' : 'f');
		}
		else if (ch != ',' && ch != '(') s.push(ch);
	}
	return s.top() == 't' ? true : false;
} 

int main()
{
	string expression = "!(f)";
	std::cout << "true == " << (parseBoolExpr(expression) == true ? "true" : "false") << endl;

	string expression1 = "|(&(t,f,t),!(t))";
	std::cout << "false == " << (parseBoolExpr(expression1) == true ? "true" : "false") << endl;
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
