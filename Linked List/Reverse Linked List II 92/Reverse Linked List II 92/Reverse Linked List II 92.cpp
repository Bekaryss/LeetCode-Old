// Reverse Linked List II 92.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode dummy = ListNode(0), * pre = &dummy, * cur = NULL;
	dummy.next = head;
	for (int i = 0; i < m - 1; i++)
	{
		pre = pre->next;
	}
	cur = pre->next;
	for (int i = 0; i < n - m; i++) {
		ListNode* temp = pre->next;
		pre->next = cur->next;
		cur->next = cur->next->next;
		pre->next->next = temp;
		PrintOut(dummy.next);
	}
	return dummy.next;
}

int main()
{
	vector<int> input = { 1, 2, 3, 4, 5 };
	ListNode* inputN = createNodes(input);
	ListNode* res = reverseBetween(inputN, 1, 5);
	PrintOut(res);

	vector<int> input1 = { 1, 2 };
	ListNode* inputN1 = createNodes(input1);
	res = reverseBetween(inputN1, 1, 2);
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
