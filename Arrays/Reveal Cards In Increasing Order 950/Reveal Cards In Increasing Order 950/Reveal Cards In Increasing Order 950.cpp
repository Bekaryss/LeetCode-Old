// Reveal Cards In Increasing Order 950.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
	int size = deck.size();
	vector<int> ans(size);
	sort(deck.begin(), deck.end());
	deque<int> deq;
	for (int i = 0; i < size; i++)
		deq.push_back(i);
	for (int i = 0; i < size; i++) {
		int index = deq.front();
		deq.pop_front();
		ans[index] = deck[i];
		if (deq.size() > 0) {
			deq.push_back(deq.front());
			deq.pop_front();
		}		
	}
	return ans;
}

int main()
{
	vector<int> input = { 1,2,3,4,5,6,7,8 };
	vector<int> ans = deckRevealedIncreasing(input);
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
