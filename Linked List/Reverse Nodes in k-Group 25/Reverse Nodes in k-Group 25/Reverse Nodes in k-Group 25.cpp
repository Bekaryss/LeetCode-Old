// Reverse Nodes in k-Group 25.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

ListNode* reverseKGroup(ListNode* head, int k) {
	if (head == NULL || k == 1) return head;
	ListNode * node = head;
	int count = 0;
	while (node != NULL) {
		node = node->next;
		count++;
	}
	ListNode header = ListNode(0);
	header.next = head;
	ListNode* pre = &header, * cur = pre->next, * nex = NULL;
	while (count >= k) {
		cur = pre->next;
		nex = cur->next;
		for (int i = 1; i < k; i++)
		{	
			cur->next = nex->next;
			nex->next = pre->next;
			pre->next = nex;
			nex = cur->next;
		}
		pre = cur;
		count -= k;
	}
	return header.next;
}

int main()
{
	vector<int> input = { 1, 2, 3, 4, 5 };
	ListNode* inputN = createNodes(input);
	ListNode* res = reverseKGroup(inputN, 2);
	PrintOut(res);

	vector<int> input1 = { 1, 2, 3, 4, 5 };
	ListNode* inputN1 = createNodes(input1);
	res = reverseKGroup(inputN1, 3);
	PrintOut(res);
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
