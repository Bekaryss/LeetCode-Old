// Serialize and Deserialize Binary Tree 297.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <iterator>



using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode* root) {
	if (root == NULL)
		return "null";
	return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

template <class Container>
void split(const std::string& str, Container& cont,
	char delim = ' ')
{
	std::size_t current, previous = 0;
	current = str.find(delim);
	while (current != std::string::npos) {
		cont.push(str.substr(previous, current - previous));
		previous = current + 1;
		current = str.find(delim, previous);
	}
	cont.push(str.substr(previous, current - previous));
}


TreeNode* deserialize(queue<string>& data) {
	if (data.front() == "null") {
		data.pop();
		return NULL;
	}
	else {
		int val = stoi(data.front());
		data.pop();
		TreeNode* node = new TreeNode(val);
		if (data.size() > 0)
			node->left = deserialize(data);
		if (data.size() > 0)
			node->right = deserialize(data);
		return node;
	}
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
	queue<string> input;
	split(data, input, ',');
	return deserialize(input);
}

int main()
{
	TreeNode* res =  deserialize("1,2,null,null,3,4,null,null,5,null,null");
	string s = serialize(res);
	cout << s;
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
