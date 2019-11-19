// Distribute Candies to People 1103.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
	vector<int> ans(num_people, 0);
	int n = 0;
	while (candies > 0) {
		for (int i = 0; i < num_people; i++)
		{
			n++;
			if (n <= candies) {
				ans[i] = ans[i] + n;
			}
			else if(candies-n > 0) {
				ans[i] = ans[i] + (candies - n);
			}
			else if (n > candies) {
				ans[i] = ans[i] + candies;
			}
			candies = candies - n;
			if (candies < 0) {
				break;
			}
		}
	}
	return ans;
}

int main()
{
	vector<int> ans = distributeCandies(10, 3);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
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
