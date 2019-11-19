// Delete Node in a Linked List 237.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
}

ListNode* getNodeWithV(ListNode* input, int value) {
	ListNode* del = input;
	while (del != nullptr) {
		if (del->val == value) {
			return del;
		}
		else {
			del = del->next;
		}
	}
	return del;
}

void deleteNode(ListNode* node) {
	node->val = node->next->val;
	node->next = node->next->next;
}

int main()
{
	vector<int> input = { 4,5,1,9 };
	ListNode* inputN = createNodes(input);
	deleteNode(getNodeWithV(inputN, 5));
	PrintOut(inputN);
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
