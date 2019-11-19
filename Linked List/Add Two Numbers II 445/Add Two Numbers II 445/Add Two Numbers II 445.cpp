// Add Two Numbers II 445.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <stack>

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (l1 == NULL and l2 == NULL) return NULL;
	else if (l1 == NULL) return l2;
	else if (l2 == NULL) return l1;
	stack<int> sl1, sl2, preRes;

	ListNode * hl1 = l1;
	ListNode * hl2 = l2;
	int countA = 0, countB = 0;
	while (l1 != nullptr || l2 != nullptr)
	{
		if (l1 != nullptr)
		{
			sl1.push(l1->val);
			l1 = l1->next;
			countA++;
		}
		if (l2 != nullptr)
		{
			sl2.push(l2->val);
			l2 = l2->next;
			countB++;
		}
	}
	int carry = 0;
	while (!sl1.empty() || !sl2.empty()) {
		int val = 0, a = 0, b = 0;
		if (!sl1.empty()) {
			a = sl1.top();
			sl1.pop();
		}
		if (!sl2.empty()) {
			b = sl2.top();
			sl2.pop();
		}
		val = a + b + carry;
		preRes.push(val % 10);
		carry = val / 10;
	}
	if (carry != 0) {
		preRes.push(carry);
	}

	ListNode* node = nullptr;
	ListNode* head = nullptr;
	if (countA < preRes.size() && countB < preRes.size()) {
		node = new ListNode(preRes.top());
		head = node;
		if (countA > countB) {
			node->next = hl1;
		}
		else {
			node->next = hl2;
		}
		preRes.pop();
		node = node->next;
		while(!preRes.empty())
		{
			node->val = preRes.top();
			node = node->next;
			preRes.pop();
		}
	}
	else {
		if (countA > countB) {
			node = hl1;
		}
		else {
			node = hl2;
		}
		head = node;
		while (!preRes.empty())
		{
			node->val = preRes.top();
			node = node->next;
			preRes.pop();
		}
	}
	return head;
}

int main()
{
	vector<int> inputA = { 7, 2, 4, 3 };
	vector<int> inputB = { 5, 6, 4 };
	ListNode* inputNA = createNodes(inputA);
	ListNode* inputNB = createNodes(inputB);
	ListNode* res = addTwoNumbers(inputNA, inputNB);
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
