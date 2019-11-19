// BN with Alternating Bits 693.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

bool hasAlternatingBits(int n) {
	int one = 0;
	int zero = 0;
	while (n != 0) {
		if (n % 2 != 0) {
			one++;
			if (zero > 0) {
				zero--;
			}
			
		}
		else {
			zero++;
			if (one > 0) {
				one--;
			}
		}
		if (one == 2  || zero == 2) {
			return false;
		}
		n /= 2;
	}
	return true;
}

bool hasAlternatingBitsSolution(int n) {
	return !((n ^= n / 2) & n + 1);
}

int main()
{
	std::cout << "false == " << (hasAlternatingBitsSolution(6) == true ? "true" : "false") << endl;
	std::cout << "false == " << (hasAlternatingBitsSolution(4) == true ? "true" : "false") << endl;
	std::cout << "true == " << (hasAlternatingBitsSolution(5) == true ? "true" : "false") << endl;
	std::cout << "false == " << (hasAlternatingBitsSolution(7) == true ? "true" : "false") << endl;
	std::cout << "false == " << (hasAlternatingBitsSolution(11) == true ? "true" : "false") << endl;
	std::cout << "true == " << (hasAlternatingBitsSolution(10) == true ? "true" : "false") << endl;
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
