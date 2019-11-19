// Implement Queue using Stacks 232.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue {
	stack<int> pushS;
	stack<int> popS;
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		pushS.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (!popS.empty()) {
			int res = popS.top();
			popS.pop();
			return res;
		}
		else {
			while (!pushS.empty()) {
				popS.push(pushS.top());
				pushS.pop();
			}
			int res = popS.top();
			popS.pop();
			return res;
		}
	}

	/** Get the front element. */
	int peek() {
		if (!popS.empty()) {
			return popS.top();
		}
		else {
			while (!pushS.empty()) {
				popS.push(pushS.top());
				pushS.pop();
			}
			return popS.top();
		}
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (pushS.size() == 0 && popS.size() == 0)
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
