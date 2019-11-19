// Binary Tree Preorder Traversal 144.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

void preorderTraversalRecursive(TreeNode* root, vector<int>& res) {
	if (root != NULL)
		res.push_back(root->val);
	else
		return;
	preorderTraversalRecursive(root->left, res);
	preorderTraversalRecursive(root->right, res);
}


vector<int> preorderTraversalRecursive(TreeNode* root) {
	vector<int> res;
	preorderTraversalRecursive(root, res);
	return res;
}

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> res;
	if (root == NULL)
		return res;
	stack<TreeNode*> rights;
	while (root != NULL) {
		res.push_back(root->val);
		if (root->right != NULL) {
			rights.push(root->right);
		}
		root = root->left;
		if (root == NULL && !rights.empty()) {
			root = rights.top();
			rights.pop();
		}
	}
	return res;
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
