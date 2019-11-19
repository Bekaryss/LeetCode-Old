// Next Greater Element I 496.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> map;
	stack<int> st;
	for (int num : nums2) 
	{
		while (!st.empty() && st.top() < num) {
			map[st.top()] = num;
			st.pop();
		}
		st.push(num);
	}
	for (int i=0; i<nums1.size(); i++)
	{
		if (map.find(nums1[i]) != map.end()) {
			nums1[i] = map[nums1[i]];
		}
		else {
			nums1[i] = -1;
		}
	}
	return nums1;
}

void PrintRes(vector<int> res) {
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> nums1 = { 4, 1, 2 }, nums2 = { 1, 3, 4, 2 };
	PrintRes(nextGreaterElement(nums1, nums2));
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
