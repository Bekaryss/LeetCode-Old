// LRU Cache 146.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Entry {
	int key;
	int val;
	Entry* left;
	Entry* right;

	Entry(int _key, int _value) {
		key = _key;
		val = _value;
		left = NULL;
		right = NULL;
	}
};

class LRUCache {
private:
	unordered_map<int, Entry*> cache;
	Entry* start, * end;
	int _capacity;

	void addAtTop(Entry* node) {
		node->right = start;
		node->left = NULL;
		if (start != NULL) {
			start->left = node;
		}
		start = node;
		if (end == NULL) {
			end = start;
		}
	}

	void removeItem(Entry* node) {
		if (node->left != NULL) {
			node->left->right = node->right;
		}
		else {
			start = node->right;
		}

		if (node->right != NULL) {
			node->right->left = node->left;
		}
		else {
			end = node->left;
		}
	}

public:
	LRUCache(int capacity) {
		_capacity = capacity;
		start = NULL;
		end = NULL;
	}

	int get(int key) {
		if (cache.find(key) != cache.end()) {
			Entry* node = cache[key];
			removeItem(node);
			addAtTop(node);
			return node->val;
		}

		return -1;
	}

	void put(int key, int value) {
		if (cache.find(key) != cache.end()) {
			Entry* node = cache[key];
			node->val = value;
			removeItem(node);
			addAtTop(node);
		}
		else {
			Entry* node = new Entry(key, value);
			if (cache.size() >= _capacity) {
				cache.erase(end->key);
				removeItem(end);
				addAtTop(node);
			}
			else {
				addAtTop(node);
			}
			cache.insert({ key, node });
		}
	}
};

int main()
{
	LRUCache cache = LRUCache(1);

	cache.put(2, 1);
	cache.get(2);
	cache.put(3, 2);
	cache.get(2);
	cache.get(3);
}

	// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
	// Debug program: F5 or Debug > Start Debugging menu

	// Tips for Getting Started:
	//   1. Use the Solution Explorer window to add/manage files
	//   2. Use the Team Explorer window to connect to source control
	//   3. Use the Output window to see build output and other messages
	//   4. Use the Error List window to view errors
	//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
	//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
