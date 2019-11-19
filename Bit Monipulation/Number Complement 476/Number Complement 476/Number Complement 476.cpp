// Number Complement 476.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string posToNeg(int num) {
	string s = "";
	while (num != 0) {
		s = (num % 2 == 0 ? "1" : "0") + s;
		num /= 2;
	}
	s = "1" + s;
	int i = s.size() - 1;
	bool hasOne = false;
	while (i >= 0) {
		if (s[i] == '1') {
			if (hasOne == true) {
				s.replace(s.begin() + i, s.begin() + i + 1, 1, '1');
				hasOne = false;
				break;
			}
			else {
				s.replace(s.begin() + i, s.begin() + i + 1, 1, '0');
				hasOne = true;
			}
		}
		else {
			s.replace(s.begin() + i, s.begin() + i + 1, 1, '1');
			break;
		}
		i--;
	}
	return s;
}

int findComplement(int num) {
	string s = "";
	if (num >= 0) {
		while (num != 0) {
			s = (num % 2 == 0 ? "1" : "0") + s;
			num /= 2;
		}
	}
	else {
		s = posToNeg(num);
		string cur = "";
		for (auto el : s) {
			if (el == '0') {
				cur += '1';
			}
			else {
				cur += '0';
			}
		}
		s = cur;
	}
	int ans = stoi(s, nullptr, 2);

	return ans;
}

int findComplementSolution(int num) {
	unsigned mask = ~0;
	while (num & mask) {
		mask <<= 1;
	}
	return ~mask & ~num;
}

int main()
{
    std::cout << "2 == " << findComplementSolution(5) << endl;
	std::cout << "4 == " << findComplementSolution(-5) << endl;
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
