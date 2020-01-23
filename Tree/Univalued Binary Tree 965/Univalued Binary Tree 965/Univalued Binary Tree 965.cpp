// Univalued Binary Tree 965.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool dfs(TreeNode* root, int val) {
	if (root == NULL)
		return true;
	if (val != root->val)
		return false;
	else {
		bool left = dfs(root->left, val);
		bool right = dfs(root->right, val);
		return left & right;
	}
}

bool isUnivalTree(TreeNode* root) {
	int val = root->val;
	return dfs(root, val);
}

bool isUnivalTreeSolution(TreeNode* root, int val = -1) {
	if (root == NULL)
		return true;
	if (val > 0)
		val = root->val;
	return root->val == val && isUnivalTreeSolution(root->left) && isUnivalTreeSolution(root->right);
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
