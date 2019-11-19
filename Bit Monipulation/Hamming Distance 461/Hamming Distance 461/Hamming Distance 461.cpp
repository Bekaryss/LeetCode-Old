// Hamming Distance 461.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

string toBinary(int n)
{
	std::string r;
	if (n == 0) {
		return "0";
	}
	while (n != 0) 
	{ 
		r = (n % 2 == 0 ? "0" : "1") + r; 
		n /= 2; 
	}
	return r;
}

int hammingDistance(int x, int y) {
	string xR = toBinary(x);
	string yR = toBinary(y);
	if (xR.size() < yR.size()) {
		while (xR.size() < yR.size())
		{
			xR.insert(xR.begin(), '0');
		}
	}
	else {
		while (yR.size() < xR.size())
		{
			yR.insert(yR.begin(), '0');
		}
	}
	int n = 0;
	for (int i = 0; i < xR.size(); i++) 
	{
		int a = xR[i] == '0' ? 0 : 1, b = yR[i] == '0' ? 0 : 1;
		int ans = a ^ b;
		if (ans == 1) {
			n++;
		}
	}
	return n;
}

int hammingDistanceSolution(int x, int y) {
	int dist = 0, n = x ^ y;
	while (n) {
		++dist;
		n &= n - 1;
	}
	return dist;
}

int main()
{
	std::cout << "2 == " << hammingDistanceSolution(1, 4) << endl;
	std::cout << "2 == " << hammingDistanceSolution(2, 4) << endl;
	std::cout << "1 == " << hammingDistanceSolution(1, 3) << endl;
	std::cout << "1 == " << hammingDistanceSolution(0, 1) << endl;
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
