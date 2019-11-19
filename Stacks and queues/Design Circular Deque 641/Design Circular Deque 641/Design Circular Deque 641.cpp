// Design Circular Deque 641.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

		class MyCircularDeque {
		public:
			vector<int> darray;
			int size = 0;
			/** Initialize your data structure here. Set the size of the deque to be k. */
			MyCircularDeque(int k) {
				size = k;
			}

			/** Adds an item at the front of Deque. Return true if the operation is successful. */
			bool insertFront(int value) {
				if (darray.size() < size) {
					darray.insert(darray.begin(), value);
					return true;
				}
				else {
					return false;
				}
			}

			/** Adds an item at the rear of Deque. Return true if the operation is successful. */
			bool insertLast(int value) {
				if (darray.size() < size) {
					darray.push_back(value);
					return true;
				}
				else {
					return false;
				}
			}

			/** Deletes an item from the front of Deque. Return true if the operation is successful. */
			bool deleteFront() {
				if (darray.size() > 0) {
					darray.erase(darray.begin(), darray.begin()+ 1);
					return true;
				}
				else {
					return false;
				}
			}

			/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
			bool deleteLast() {
				if (darray.size() > 0) {
					darray.erase(darray.end() - 1, darray.end());
					return true;
				}
				else {
					return false;
				}
			}

			/** Get the front item from the deque. */
			int getFront() {
				if (darray.size() > 0) {
					return darray[0];
				}
				else {
					return -1;
				}
		
			}

			/** Get the last item from the deque. */
			int getRear() {
				if (darray.size() > 0) {
					return darray[darray.size() - 1];
				}
				else {
					return -1;
				}
			}

			/** Checks whether the circular deque is empty or not. */
			bool isEmpty() {
				if (darray.size() == 0) {
					return true;
				}
				else {
					return false;
				}
			}

			/** Checks whether the circular deque is full or not. */
			bool isFull() {
				if (darray.size() == size) {
					return true;
				}
				else {
					return false;
				}
			}
		};

int main()
{
	MyCircularDeque circularDeque(3);  // set the size to be 3
	circularDeque.insertLast(1);			// return true
	circularDeque.insertLast(2);			// return true
	circularDeque.insertFront(3);			// return true
	circularDeque.insertFront(4);			// return false, the queue is full
	circularDeque.getRear();  			// return 2
	circularDeque.isFull();				// return true
	circularDeque.deleteLast();			// return true
	circularDeque.insertFront(4);			// return true
	circularDeque.getFront();			// return 4
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
