// Clumsy Factorial 1006.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int clumsySolution(int N) {
	if (N <= 2) {
		return N;
	}
	if (N <= 4) {
		return N + 3;
	}
	if ((N - 4) % 4 == 0) {
		return N + 1;
	}
	else if ((N - 4) % 4 <= 2) {
		return N + 2;
	}
	else {
		return N - 1;
	}
}

int clumsy(int N) {
	int count = 0;
	int sum = -1;
	vector<int> ans;
	for (int i = N; i >= 1; i--) {
		if (count == 0) {
			sum = i;
		}else
		if (count == 1) {
			sum = sum * i;
		}
		else if (count == 2) {
			sum = sum / i;
		}
		else if (count == 3) {
			ans.push_back(sum);
			ans.push_back(i);
			sum = -1;
			count = -1;
		}
		count++;
	}
	if (sum != -1) {
		ans.push_back(sum);
	}
	
	if (ans.size() > 0) {
		count = 0;
		sum = 0;
		for (int i = 0; i < ans.size(); i++) {
			if (count == 0) {
				sum = ans[i];
			}
			else if (count == 1) {
				sum = sum + ans[i];
			}
			else if (count == 2) {
				sum = sum - ans[i];
				count = 0;
			}
			count++;
		}
		return sum;
	}
	else {
		return sum;
	}
}

int main()
{
    std::cout << "7 == " << clumsySolution(4) << endl;
	std::cout << "12 == " << clumsySolution(10) << endl;
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
