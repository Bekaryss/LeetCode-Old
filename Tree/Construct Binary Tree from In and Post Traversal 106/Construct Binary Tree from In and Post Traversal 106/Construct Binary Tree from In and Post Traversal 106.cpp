// Construct Binary Tree from In and Post Traversal 106.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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


TreeNode* buildTree(int is, int ie, vector<int>& postorder, int ps, int pe, unordered_map<int, int>& hm) {
	if (is > ie || ps > pe)
		return NULL;

	TreeNode* node = new TreeNode(postorder[pe]);
	int ri = hm[postorder[pe]];
	TreeNode* leftChild = buildTree(is, ri - 1, postorder, ps, ps + (ri - 1 - is), hm);
	TreeNode* rightChild = buildTree(ri + 1, ie, postorder, ps + ri - is, pe - 1, hm);
	node->left = leftChild;
	node->right = rightChild;
	return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	if (inorder.size() == 0 || postorder.size() == 0 || inorder.size() != postorder.size()) {
		return NULL;
	}
	unordered_map<int, int> hm;
	for (int i = 0; i < inorder.size(); i++) {
		hm[inorder[i]] = i;
	}
	return buildTree(0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hm);
}


int main()
{
	int n = 0;
	for (int i = 6; i < 126; i++) {
		if (i % 2 != 0 && i % 3 != 0) {
			cout << i << " ";
			n++;
		}
	}
	cout << endl << n << endl;
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
