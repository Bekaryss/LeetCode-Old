// Next Greater Node In Linked List 1019.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

void PrintOut(vector<int> res) {
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}

vector<int> nextLargerNodes(ListNode* head) {
	if (head == nullptr) return {};
	stack<int> ge;
	vector<int> res;
	ListNode* current = head;
	int i = 0;
	while (current != nullptr) {
		res.push_back(0);
		if (ge.empty() || ge.top() > current->val) {
			ge.push(current->val);
		}
		else {
			int j = i;
			while (!ge.empty() && ge.top() < current->val) {
				j--;
				if (res[j] == 0) {
					ge.pop();
					res[j] = current->val;
				}
			}
			ge.push(current->val);
		}
		i++;
		current = current->next;
	}
	return res;
}
int main()
{
	vector<int> input = { 2,1,5 };
	ListNode* inputN = createNodes(input);
	vector<int> res = nextLargerNodes(inputN);
	PrintOut(res);

	vector<int> input1 = { 1,7,5,1,9,2,5,1 };
	ListNode* inputN1 = createNodes(input1);
	vector<int> res1 = nextLargerNodes(inputN1);
	PrintOut(res1);

	vector<int> input2 = { 9,7,6,7,6,9 };
	ListNode* inputN2 = createNodes(input2);
	vector<int> res2 = nextLargerNodes(inputN2);
	PrintOut(res2);

	vector<int> input3 = { 4,3,2,5,1,8,10 };
	ListNode* inputN3 = createNodes(input3);
	vector<int> res3 = nextLargerNodes(inputN3);
	PrintOut(res3);
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
