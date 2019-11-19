// Flipping an Image 832.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;


//With hint
vector<vector<int>> flipAndInvertImageSolution(vector<vector<int>>& A) {
	int c = A[0].size() - 1;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j <= c / 2; j++) {
			int tmp = A[i][j] == 0 ? 1 : 0;
			A[i][j] = A[i][c - j] == 0 ? 1 : 0;
			A[i][c - j] = tmp;
		}
	}
	return A;
}

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	vector<vector<int>> ans;
	for (int i = 0; i < A.size(); i++) {
		vector<int> curAns;
		for (int j = A[i].size() - 1; j >= 0; j--) {
			if (A[i][j] == 0)
				curAns.push_back(1);
			else
				curAns.push_back(0);
		}
		ans.push_back(curAns);
	}
	return ans;
}

int main()
{
	vector<vector<int>> input = { {1,1,0},{1,0,1},{0,0,0} };
	vector<vector<int>> input1 = { {1, 1, 0, 0}, { 1, 0, 0, 1 }, { 0, 1, 1, 1 }, { 1, 0, 1, 0 }};
	vector<vector<int>> ans = flipAndInvertImageSolution(input1);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
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
