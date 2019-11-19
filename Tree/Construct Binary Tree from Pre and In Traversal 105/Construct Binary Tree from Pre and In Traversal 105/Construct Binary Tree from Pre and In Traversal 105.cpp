// Construct Binary Tree from Pre and In Traversal 105.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(int is, int ie, vector<int>& preorder, int ps, int pe, unordered_map<int, int>& hm) {
	if (is > ie || ps > pe)
		return NULL;

	TreeNode* node = new TreeNode(preorder[ps]);
	int ri = hm[preorder[ps]];
	TreeNode* leftChild = buildTree(is, ri - 1, preorder, ps + 1, ps + ri - is, hm);
	TreeNode* rightChild = buildTree(ri + 1, ie, preorder, ps + 1 + ri - is, pe, hm);
	node->left = leftChild;
	node->right = rightChild;
	return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (inorder.size() == 0 || preorder.size() == 0 || inorder.size() != preorder.size()) {
		return NULL;
	}
	unordered_map<int, int> hm;
	for (int i = 0; i < inorder.size(); i++) {
		hm[inorder[i]] = i;
	}
	return buildTree(0, inorder.size() - 1, preorder, 0, preorder.size() - 1, hm);
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
