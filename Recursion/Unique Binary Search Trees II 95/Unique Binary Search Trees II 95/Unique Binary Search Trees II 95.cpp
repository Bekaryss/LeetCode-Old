// Unique Binary Search Trees II 95.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

vector<TreeNode*> generateBST(int lo, int hi) {
	vector<TreeNode*> res;
	if (lo > hi) {
		res.push_back(NULL);
		return res;
	}
	for(int i = lo; i <= hi; i++) {
		for (TreeNode* left : generateBST(lo, i - 1)) {
			for (TreeNode* right : generateBST(i + 1, hi)) {
				TreeNode* root = new TreeNode(i);
				root->left = left;
				root->right = right;
				res.push_back(root);
			}
		}
	}
	return res;
}

vector<TreeNode*> generateTrees(int n) {
	if (n == 0)
		return {};
	return generateBST(1, n);
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
