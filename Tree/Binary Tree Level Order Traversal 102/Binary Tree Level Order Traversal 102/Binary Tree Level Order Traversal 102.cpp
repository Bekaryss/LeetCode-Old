// Binary Tree Level Order Traversal 102.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> res;
	if (root == NULL)
		return res;
	queue<TreeNode*> levels;
	levels.push(root);
	while (!levels.empty()) {
		int size = levels.size();
		vector<int> breadth;
		for (int i = 0; i < size; i++) {
			root = levels.front();
			levels.pop();
			breadth.push_back(root->val);
			if (root->left != NULL) {
				levels.push(root->left);
			}
			if (root->right != NULL) {
				levels.push(root->right);
			}
		}
		res.push_back(breadth);
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
