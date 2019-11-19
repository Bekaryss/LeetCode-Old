// Fibonacci Number 509.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

static unordered_map<int, int> cache;

int fib(int N) {
	if (N == 0 || N == 1) {
		return N;
	}
	else {
		vector<int> fibo = { 0,1 };
		for (int i = 2; i <= N; i++) {
			fibo.push_back(fibo[i - 1] + fibo[i - 2]);
		}
		return fibo[N];
	}
	
}

int fibRecursion(int N) {
	if (cache.find(N) != cache.end()) {
		return cache[N];
	}
	int res;
	if (N < 2)
		res = N;
	else
		res = fibRecursion(N - 1) + fibRecursion(N - 2);
	cache[N] = res;
	return res;
}

int fibN(int N) {
	int first = 0;
	int second = 1;
	for (int i = 2; i <= N; i++) {
		int third = first + second;
		first = second;
		second = third;
	}
	return second;
}

int fibLastNumber(int N) {
	int first = 0;
	int second = 1;
	for (int i = 2; i <= N; i++) {
		int third = first + second;
		first = second;
		second = third;
		first = first % 10;
		second = second % 10;
	}
	return second;
}

int fibM(int n, int m) {
	double first = 0%m;
	double second = 1%m;
	for (int i = 2; i <= n; i++) {
		int third = first + second;
		first = second;
		second = third % m;
	}
	return second;
}

int main()
{
	std::cout << fibN(1) << endl;
	std::cout << fibN(2) << endl;
	std::cout << fibN(3) << endl;
	std::cout << fibN(4) << endl;
	std::cout << fibN(5) << endl;
	std::cout << fibN(8) << endl;
	std::cout << fibN(9) << endl;
	std::cout << fibN(10) << endl;
	cout << endl;
	std::cout << fibM(1, 3) << endl;
	std::cout << fibM(2, 3) << endl;
	std::cout << fibM(3, 3) << endl;
	std::cout << fibM(4, 3) << endl;
	std::cout << fibM(5, 3) << endl;
	std::cout << fibM(6, 3) << endl;
	std::cout << fibM(7, 3) << endl;
	std::cout << fibM(8, 3) << endl;
	std::cout << fibM(9, 3) << endl;
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
