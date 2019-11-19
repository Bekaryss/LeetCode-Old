// Implement Stack using Queues 225.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
	queue<int> sq;
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		sq.push(x);
		for (int i = 0; i < sq.size()-2; i++)
		{
			sq.push(sq.front());
			sq.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int res = sq.front();
		sq.pop();
		return res;
	}

	/** Get the top element. */
	int top() {
		int res = sq.front();
		return res;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		if (sq.size() == 0)
			return true;
		else
			return false;
	}
};

int main()
{
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
