// Merge Two Binary Trees 617.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* dfs(TreeNode* t1, TreeNode* t2) {
	TreeNode* node = NULL;
	if (t1 == NULL && t2 == NULL)
		return NULL;
	else {
		if (t1 != NULL && t2 != NULL) {
			node = new TreeNode(t1->val + t2->val);
			node->left = dfs(t1->left, t2->left);
			node->right = dfs( t1->right, t2->right);
		}
		else if (t1 != NULL && t2 == NULL) {
			node = new TreeNode(t1->val);
			node->left = dfs(t1->left, NULL);
			node->right = dfs(t1->right, NULL);
		}
		else if (t1 == NULL && t2 != NULL) {
			node = new TreeNode(t2->val);
			node->left = dfs(NULL, t2->left);
			node->right = dfs(NULL, t2->right);
		}
		return node;
	}
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	TreeNode* head = dfs(t1, t2);
	return head;
}

int main()
{
	std::cout << "Hello World!\n";
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
