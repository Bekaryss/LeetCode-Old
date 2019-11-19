// Bitwise AND of Numbers Range 201.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int rangeBitwiseAnd(int m, int n) {
	int ans = 0;
	for (int i = 0; i < 32; i++)
	{
		int mask = 1 << i;
		int mv = mask & m;
		int nv = mask & n;
		if ((n - m) <= pow(2, i)) {
			ans |= (mv & nv);
		}
	}
	return ans;
}

int rangeBitwiseAndSolution(int m, int n) {
	int c = 0;
	while (m != n) {
		m >>= 1;
		n >>= 1;
		++c;
	}
	return n << c;
}

int main()
{
	std::cout << "6 == " << rangeBitwiseAndSolution(6, 7) << endl;
	std::cout << "8 == " << rangeBitwiseAndSolution(8, 13) << endl;
    std::cout << "4 == " << rangeBitwiseAndSolution(5, 7) << endl;
	std::cout << "4 == " << rangeBitwiseAndSolution(4, 7) << endl;
	std::cout << "0 == " << rangeBitwiseAndSolution(0, 1) << endl;
	std::cout << "0 == " << rangeBitwiseAndSolution(0, 5) << endl;
	std::cout << "0 == " << rangeBitwiseAndSolution(1, 2) << endl;
	std::cout << "1 == " << rangeBitwiseAndSolution(1, 1) << endl;
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
