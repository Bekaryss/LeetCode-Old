// Insert Delete GetRandom O(1) 380.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
private:
	unordered_map<int, int> vals;
	vector<int> keys;
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (vals.find(val) == vals.end()) {
			vals[val] = keys.size();
			keys.push_back(val);
			return true;
		}
		else {
			return false;
		}
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (vals.find(val) != vals.end()) {
			vals[keys[keys.size() - 1]] = vals[val];
			keys[vals[val]] = keys[keys.size() - 1];
			keys.pop_back();
			vals.erase(val);
			return true;
		}
		else {
			return false;
		}
	}

	/** Get a random element from the set. */
	int getRandom() {
		if (keys.size() > 0) {
			int r = rand() % keys.size();
			return keys[r];
		}
	}
};


int main()
{
	RandomizedSet randomSet;

	// Inserts 1 to the set. Returns true as 1 was inserted successfully.
	randomSet.insert(1);

	// Returns false as 2 does not exist in the set.
	randomSet.remove(2);

	// Inserts 2 to the set, returns true. Set now contains [1,2].
	randomSet.insert(2);

	// getRandom should return either 1 or 2 randomly.
	randomSet.getRandom();

	// Removes 1 from the set, returns true. Set now contains [2].
	randomSet.remove(1);

	// 2 was already in the set, so return false.
	randomSet.insert(2);

	// Since 2 is the only number in the set, getRandom always return 2.
	randomSet.getRandom();
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
