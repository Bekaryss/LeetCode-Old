// Binary String WSR 1 To N 1016.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool qs(string S, int N) {
	string binr = "";
	int i = 0;
	while (N > 0) {

		// storing remainder in binary array 
		binr += (N % 2) == 1 ? "1" : "0";
		N = N / 2;
		i++;
	}
	reverse(binr.begin(), binr.end());
	if (S.find(binr) == string::npos) {
		return false;
	}
	return true;
}

bool queryString(string S, int N) {
	for (int i = 1; i <= N; i++) {
		if (qs(S, i) == false) {
			return false;
		}
	}
	return true;
}

int main()
{
	string S = "0110";
	int N = 3;
	std::cout << "true == " << (queryString(S, N) == true ? "true" : "false") << endl;

	string S1 = "10010111100001110010";
	int N1 = 10;
	std::cout << "false == " << (queryString(S1, N1) == true ? "true" : "false") << endl;


	string S2 = "110101011011000011011111000000";
	int N2 = 15;
	std::cout << "false == " << (queryString(S2, N2) == true ? "true" : "false") << endl;
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
