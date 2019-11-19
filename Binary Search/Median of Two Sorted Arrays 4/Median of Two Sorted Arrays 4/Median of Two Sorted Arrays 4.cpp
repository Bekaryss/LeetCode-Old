// Median of Two Sorted Arrays 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) {
			return findMedianSortedArrays(nums2, nums1);
		}
		int x = nums1.size();
		int y = nums2.size();
		int low = 0, high = x;
		while (low <= high) {
			int partX = (low + high) / 2;
			int partY = (x + y + 1) / 2 - partX;

			int maxLeftX = (partX == 0) ? INT32_MIN : nums1[partX - 1];
			int minRightX = (partX == x) ? INT32_MAX : nums1[partX];

			int maxLeftY = (partY == 0) ? INT32_MIN : nums2[partY - 1];
			int minRightY = (partY == y) ? INT32_MAX : nums2[partY];

			if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
				if ((x + y) % 2 == 0) {
					return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
				}
				else {
					return (double)max(maxLeftX, maxLeftY);
				}
			}
			else if (maxLeftX > minRightY) {
				high = partX - 1;
			}
			else {
				low = partX + 1;
			}
		}
		return -1;
}

int main()
{
	vector<int> nums1 = {  };
	vector<int> nums2 = { 1 };
	std::cout << "2.0 == " << findMedianSortedArrays(nums1, nums2) << endl;
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
