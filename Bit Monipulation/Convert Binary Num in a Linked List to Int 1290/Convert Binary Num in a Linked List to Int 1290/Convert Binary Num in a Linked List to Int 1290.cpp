// Convert Binary Num in a Linked List to Int 1290.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getNode(vector<int> input) {
    ListNode* head = NULL;
    ListNode* node, * cur = NULL;
    for (int i : input) {
        node = new ListNode(i);
        if (cur != NULL) {
            cur->next = node;
        }
        cur = node;
        if (head == NULL)
            head = node;
    }
    return head;
}

int getDecimalValue(ListNode* head) {
    int res = 0;
    while (head != NULL) {
        res = res << 1;
        if (head->val == 1) {
            res += 1;
        }
        
        head = head->next;
    }
    return res;
}

int getDecimalValueSolution(ListNode* head) {
    int res = 0;
    while (head != NULL) {
        res = (res << 1) | head->val;
        head = head->next;
    }
    return res;
}

int main()
{
    vector<int> input = { 1 };
    ListNode* node = getNode(input);
    std::cout << getDecimalValue(node) << endl;
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
