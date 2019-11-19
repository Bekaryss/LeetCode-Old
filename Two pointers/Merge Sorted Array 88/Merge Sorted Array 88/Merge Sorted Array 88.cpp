// Merge Sorted Array 88.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	for (int i = 0; i < nums2.size(); i++) {
		int j = 0;
		if (m > 0) {
			j = m - 1;
			while (j >= 0) {
				if (nums1[j] <= nums2[i]) {
					nums1[j + 1] = nums2[i];
					m++;
					break;
				}
				else {
					nums1[j + 1] = nums1[j];
					if (j - 1 < 0) {
						nums1[j] = nums2[i];
						m++;
					}
					else {
						nums1[j] = 0;
					}
				}
				j--;
			}
		}
		else {
			for (int j = 0; j < nums1.size(); j++) {
				nums1[j] = nums2[j];
			}
		}		
	}
	//end
}

void PrintOut(vector<int>& res) {
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 }, nums2 = { 2, 5, 6 };
	merge(nums1, 3, nums2, 3);
	PrintOut(nums1);

	vector<int> nums11 = { 0 }, nums12 = { 1 };
	merge(nums11, 0, nums12, 1);
	PrintOut(nums11);

	vector<int> nums21 = { 2, 0 }, nums22 = { 1 };
	merge(nums21, 1, nums22, 1);
	PrintOut(nums21);

	vector<int> nums31 = { 4, 5, 6, 0, 0, 0 }, nums32 = { 1, 2, 3 };
	merge(nums31, 3, nums32, 3);
	PrintOut(nums31);
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
