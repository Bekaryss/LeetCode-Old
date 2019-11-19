// Merge Two Sorted Lists 21.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* res = nullptr;
	ListNode* first = nullptr;
	while (l1 != nullptr || l2 != nullptr) {
		if (l2 == nullptr && l1!= nullptr) {
			if (res == nullptr) {
				res = l1;
				first = res;
			}
			else {
				res->next = l1;
				res = res->next;
			}
			l1 = l1->next;
		}
		else if (l1 == nullptr && l2 != nullptr) {
			if (res == nullptr) {
				res = l2;
				first = res;
			}
			else {
				res->next = l2;
				res = res->next;
			}
			l2 = l2->next;
		}else if (l1->val < l2->val) {
			if (res == nullptr) {
				res = l1;
				first = res;
			}
			else {
				res->next = l1;
				res = res->next;
			}
				
			l1 = l1->next;
		}
		else {
			if (res == nullptr) {
				res = l2;
				first = res;
			}
			else {
				res->next = l2;
				res = res->next;
			}
			l2 = l2->next;
		}
	}
	return first;
}

ListNode* mergeTwoListsSolution(ListNode* l1, ListNode* l2) {
	ListNode dummy(INT_MIN);
	ListNode* tail = &dummy;

	while (l1 && l2) {
		if (l1->val < l2->val) {
			tail->next = l1;
			l1 = l1->next;
		}
		else {
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}

	tail->next = l1 ? l1 : l2;
	return dummy.next;
}

ListNode* mergeTwoListsR(ListNode* l1, ListNode* l2) {
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if (l1->val < l2->val) {
		l1->next = mergeTwoListsR(l1->next, l2);
		return l1;
	}
	else {
		l2->next = mergeTwoListsR(l2->next, l1);
		return l2;
	}
}

int main()
{

	vector<int> input1 = { 1,2,4 };
	ListNode* inputN1 = createNodes(input1);
	vector<int> input2 = { 1,3,4 };
	ListNode* inputN2 = createNodes(input2);
	ListNode* res = mergeTwoListsR(inputN1, inputN2);
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
