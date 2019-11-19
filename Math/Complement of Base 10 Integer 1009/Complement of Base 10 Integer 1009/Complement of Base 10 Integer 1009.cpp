// Complement of Base 10 Integer 1009.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int bitwiseComplement(int N) {
	if (N == 0) {
		return 1;
	}
	vector<int> ans;
	for (int i = 31; i >= 0; --i)
	{
		if ((N >> i)  > 0) {
			ans.push_back(((N >> i) % 2) == 0 ? 1 : 0);
		}
	}
	int n = 0;
	for(int i = 0; i < ans.size(); i++)
	{
		n += (ans[i] * pow(2, ans.size() - 1 - i));
	}
	return n;
}

int bitwiseComplementSolution(int N) {
	int X = 1;
	while (N > X) X = X * 2 + 1;
	return N ^ X;
}


int main()
{
    std::cout << "2 == " << bitwiseComplementSolution(5) << endl;
	std::cout << "0 == " << bitwiseComplementSolution(7) << endl;
	std::cout << "5 == " << bitwiseComplementSolution(10) << endl;
	std::cout << "1 == " << bitwiseComplementSolution(0) << endl;
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
