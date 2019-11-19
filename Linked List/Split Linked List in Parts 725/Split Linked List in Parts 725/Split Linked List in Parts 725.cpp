// Split Linked List in Parts 725.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createNodes(vector<int> input) {
	ListNode* listNode = nullptr;
	ListNode* first = nullptr;
	for (int i = 0; i < input.size(); i++) {
		ListNode* cur = new ListNode(input[i]);
		if (listNode == nullptr) {
			first = cur;
			listNode = cur;
		}
		else {
			listNode->next = cur;
			listNode = cur;
		}
	}
	return first;
}

void PrintOut(ListNode* res) {
	while (res != nullptr) {
		cout << (*res).val << " ";
		res = (*res).next;
	}
	cout << endl;
}

vector<ListNode*> splitListToParts(ListNode* root, int k) {
	vector<ListNode*> res(k, nullptr);
	ListNode* node = root;
	int count = 0;
	while (node != NULL) {
		node = node->next;
		count++;
	}
	int part = count / k; //minimum guaranteed part size
	int diff = count % k; //extra nodes spread to the first r parts
	ListNode* head = root, *prev = nullptr;
	for (int i = 0; head && i < k; i++, diff--) {
		res[i] = head;
		for (int j = 0; j < part + (diff > 0); j++) {
			prev = head;
			head = head->next;
		}
		prev->next = NULL;
	}
	return res;
}

int main()
{
	vector<int> input = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	ListNode* inputN = createNodes(input);
	vector<ListNode*> res = splitListToParts(inputN, 3);
	for(ListNode* node:res)
	{
		PrintOut(node);
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
