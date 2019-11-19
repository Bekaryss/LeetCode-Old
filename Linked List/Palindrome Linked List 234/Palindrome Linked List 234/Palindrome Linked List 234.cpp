// Palindrome Linked List 234.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

bool isPalindrome(ListNode* head) {
	if (head == nullptr || head->next == nullptr) return true;

	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}

	//revert list
	ListNode* prev = slow;
	ListNode* p = slow->next;
	slow->next = nullptr;
	while (p!= nullptr)
	{
		ListNode* tmp = p->next;
		p->next = prev;
		prev = p;
		p = tmp;
	}

	ListNode* l = head;
	ListNode* r = prev;
	while (l != nullptr && r != nullptr) {
		if (l->val != r->val) {
			return false;
		}
		l = l->next;
		r = r->next;
	}
	return true;
}

int main()
{
	vector<int> input = { 1,2 };
	ListNode* inputN = createNodes(input);
	cout << "false == " << (isPalindrome(inputN) == true ? "true" : "false") << endl;

	vector<int> input1 = { 1,2,2,1 };
	ListNode* inputN1 = createNodes(input1);
	cout << "true == " << (isPalindrome(inputN1) == true ? "true" : "false") << endl;
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
