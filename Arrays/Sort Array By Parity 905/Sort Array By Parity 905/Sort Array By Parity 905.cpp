// Sort Array By Parity 905.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

//Most voted solution
vector<int> sortArrayByParitySolution(vector<int>& A) {
	for (int i = 0, j = 0; j < A.size(); j++) {
		if (A[j] % 2 == 0) {
			swap(A[i++], A[j]);
		}
	}
	return A;
}

vector<int> sortArrayByParity(vector<int>& A) {
	vector<int> ans;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] % 2 == 0) {
				ans.insert(ans.begin(), A[i]);
			}
			else {
				ans.push_back(A[i]);
			}
		}
		return ans;
}

int main()
{
	vector<int> input = { 3,1,2,4 };
	vector<int> ans = sortArrayByParitySolution(input);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	std::cout << "Hello World!\n";
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
