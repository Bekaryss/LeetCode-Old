// Same Tree 100.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

bool isSameTree(TreeNode* p, TreeNode* q) {
	stack<TreeNode*> ps;
	stack<TreeNode*> qs;
	if (p)
		ps.push(p);
	if (q)
		qs.push(q);
	while (!ps.empty() && !qs.empty()) {
		TreeNode* pt = ps.top();
		TreeNode* qt = qs.top();
		ps.pop();
		qs.pop();
		if (pt->val != qt->val)
			return false;
		if (pt->left != NULL)
			ps.push(pt->left);
		if (qt->left != NULL)
			qs.push(qt->left);
		if (ps.size() != qs.size())
			return false;
		if (pt->right != NULL)
			ps.push(pt->right);
		if (qt->right != NULL)
			qs.push(qt->right);
		if (ps.size() != qs.size())
			return false;
	}
	return ps.size() == qs.size();
}

bool isSameTreeR(TreeNode* p, TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	if (p->val != q->val)
		return false;
	return isSameTreeR(p->left, q->left) && isSameTreeR(p->right, q->right);
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
