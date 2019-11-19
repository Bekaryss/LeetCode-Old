// Long Pressed Name 925.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isLongPressedName(string name, string typed) {
	vector<int> res;
	int current = 0;
	for (int i = 0; i < typed.size(); i++) {
		if (name[current] == typed[i] && current < name.size()) {
			current++;
			res.push_back(typed[i]);
		}
	}
	if (res.size() == name.size()) {
		return true;
	}
	else {
		return false;
	}
}


bool isLongPressedNameSolution(string name, string typed) {
	int j = 0, n = name.size();
	for (int i = 0; i < typed.size(); i++) {
		if (name[j] == typed[i] && j < n) {
			j++;
		}
		else if(i == 0 || typed[i] != typed[i-1]){
			return false;
		}
	}
	return j == n;
}

int main()
{
	std::cout << "true == " << (isLongPressedNameSolution("alex", "aaleex") == true ? "true" : "false") << endl;
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
