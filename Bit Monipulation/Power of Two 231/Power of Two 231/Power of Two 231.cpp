// Power of Two 231.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <bitset>

using namespace std;

bool isPowerOfTwo(int n) {
	if (n == 0) {
		return false;
	}
	long long ans = 0;
	long long num = n;
	while (num != 0) {
		num &= num - 1;
		ans++;
		if (ans > 1) {
			return false;
		}
	}
	return true;
}

bool isPowerOfTwoSolution(int n) {
	if (n <= 0) 
		return false;
	return !(n & (n - 1));
}

int main()
{
    std::cout << "true == " << (isPowerOfTwoSolution(1) == true ? "true" : "false") << endl;
	std::cout << "false == " << (isPowerOfTwoSolution((int)-1) == true ? "true" : "false") << endl;
	std::cout << "false == " << (isPowerOfTwoSolution(0) == true ? "true" : "false") << endl;
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
