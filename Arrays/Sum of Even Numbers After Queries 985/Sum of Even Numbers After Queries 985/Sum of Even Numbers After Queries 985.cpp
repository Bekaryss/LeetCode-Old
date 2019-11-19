// Sum of Even Numbers After Queries 985.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
	vector<int> ans = A;
	long long n = 0;
	for (int j = 0; j < A.size(); j++) {
		if (A[j] % 2 == 0) {
			n = n + A[j];
		}
	}

	for (int i = 0; i < queries.size(); i++)
	{
		if (A[queries[i][1]] % 2 == 0) {
			int curVal = A[queries[i][1]] + queries[i][0];
			if (curVal % 2 == 0) {
				n += queries[i][0];
			}
			else {
				n -= A[queries[i][1]];
			}
		}
		else if ((A[queries[i][1]] + queries[i][0]) % 2 == 0) {
			long long cal = A[queries[i][1]] + queries[i][0];
			n += cal;
		}
		A[queries[i][1]] = A[queries[i][1]] + queries[i][0];
		ans[i] = n;
	}
	return ans;
}

int main()
{
	vector<int> A = { 4,4,4 };
	vector<vector<int>> queries = { {4, 1}, {3, 1}, {3,2} };
	vector<int> ans = sumEvenAfterQueries(A, queries);
	for (int i = 0; i < ans.size(); i++)
	{
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
