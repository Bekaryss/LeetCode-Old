// Design Circular Queue 622.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
	vector<int> q;
	int head, tail, N;
	bool empty;

public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		head = 0;
		tail = 0;
		N = k;
		q = vector<int>(k);
		empty = true;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (isFull()) return false;
		empty = false;
		q[tail] = value;
		tail = (tail + 1) % N;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty()) return false;
		q[head] = 0;
		head = (head + 1) % N;
		if (head == tail) empty = true;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (isEmpty()) return -1;
		return q[head];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (isEmpty()) return -1;
		return q[((tail - 1) + N) % N];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return empty;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return (empty) ? false : head == tail;
	}
};

int main()
{
	MyCircularQueue circularQueue = MyCircularQueue(3); // set the size to be 3
	circularQueue.enQueue(1);  // return true
	circularQueue.enQueue(2);  // return true
	circularQueue.enQueue(3);  // return true
	circularQueue.enQueue(4);  // return false, the queue is full
	circularQueue.Rear();  // return 3
	circularQueue.isFull();  // return true
	circularQueue.deQueue();  // return true
	circularQueue.enQueue(4);  // return true
	circularQueue.Rear();  // return 4
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
