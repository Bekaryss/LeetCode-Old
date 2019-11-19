// Design HashSet 705.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

class MyHashSet {
private:
	vector<bool> h;
public:
	/** Initialize your data structure here. */
	MyHashSet()
		: h(1024, false)
	{

	}

	void add(int key) {
		while(key > h.size()) {
			h.resize(h.size() * 2);
		}
		h[key] = true;
	}

	void remove(int key) {
		if(key < h.size())
			h[key] = false;
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		return key < h.size() && h[key];
	}
};

int main()
{
	MyHashSet hashSet;
	hashSet.add(1);
	hashSet.add(2);
	hashSet.contains(1);    // returns true
	hashSet.contains(3);    // returns false (not found)
	hashSet.add(2);
	hashSet.contains(2);    // returns true
	hashSet.remove(2);
	hashSet.contains(2);    // returns false (already removed)
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
