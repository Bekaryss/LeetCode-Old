// Prime Number of Set Bits in BR 762.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <set>

using namespace std;

int countPrimeSetBits(int L, int R) {
	int ans = 0;
	for (int i = L; i <= R; i++) {
		string s = "";
		int n = i;
		int count = 0;
		while (n != 0) {
			if (n % 2 != 0) {
				count++;
			}
			n /= 2;
		}
		bool flag = false;
		if (count < 2) {
			flag = true;
		}
		for (int j = 2; j <= count / 2; j++)
		{
			if (count % j == 0)
			{
				flag = true;
				break;
			}
		}
		if (flag == false) {
			ans++;
		}
	}
	return ans;
}
int countPrimeSetBitssolution(int L, int R) {
	set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19};
	int cnt = 0;
	for (int i = L; i <= R; i++) {
		int bits = 0;
		for (int n = i; n; n >>= 1)
			bits += n & 1;
		cnt += primes.count(bits);
	}
	return cnt;
}

int main()
{
	std::cout << "4 == " << countPrimeSetBits(6, 10) << endl;
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
