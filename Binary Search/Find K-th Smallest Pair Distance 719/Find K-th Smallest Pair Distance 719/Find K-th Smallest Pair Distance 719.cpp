// Find K-th Smallest Pair Distance 719.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int smallestDistancePair(vector<int>& nums, int k) {
	// since order doesn't matter here we can sort the array 
	sort(begin(nums), end(nums));

	// We will perform binary search on the range - [0,max element - min element + 1)
	// Within each search we will examine the middle element  med and we will figure out how many pairs 
	// have a distance less than or equal to m.
	// When we are done counting, we compare the count to k. If it is less than k, then our med value is too
	// small and we need to adjust the "start" of our search.
	// Otherwise, we need to reduce the range of our search from above.
	// It is important to note that even if our count is exactly k, we  continue the search.
	// Eventually our algorithm will converge when we find a count = K for a given m and every count             
	// between [start,m) will be smaller than k, forcing start to be incremented to the point where start == m which is  our result.
	int start = 0;
	for (int end = nums.back() - nums[0] + 1; start < end;) {
		int med = (start + end) / 2;
		int count = 0;
		for (int i = 0, j = 1; i <= j && j < nums.size();) {
			if (nums[j] - nums[i] <= med) {
				count += j - i;
				j++;
			}
			else {
				i++;
			}
		}

		if (count >= k) {
			end = med;
		}
		else {
			start = med + 1;
		}
	}

	return start;
}
int main()
{
	vector<int> input = { 1, 3, 1 };
	std::cout << "0 == " << smallestDistancePair(input, 1) << endl;
	vector<int> input1 = { 1, 6, 1 };
	std::cout << "5 == " << smallestDistancePair(input1, 3) << endl;

	vector<int> input2 = { 62, 100, 4 };
	std::cout << "58 == " << smallestDistancePair(input2, 2) << endl;


	vector<int> input3 = { 9, 10, 7, 10, 6, 1, 5, 4, 9, 8 };
	std::cout << "? == " << smallestDistancePair(input3, 18) << endl;

	vector<int> input4 = { 10, 6, 2, 10, 5, 4, 0, 1, 5, 2, 5, 5, 5, 0, 4, 9, 8, 6, 7, 9, 1, 10, 4, 8, 6, 3, 6, 2, 1, 7, 5, 0, 2, 6, 10, 10, 0, 3, 9, 0, 8, 3, 5, 9, 4, 4, 5, 2, 2, 7};
	std::cout << "? == " << smallestDistancePair(input4, 444) << endl;


	vector<int> input5 = { 2, 2, 0, 1, 0, 1, 2, 0, 2, 1, 1, 1, 1, 0, 1, 2, 1, 1, 1, 2, 1, 2, 1, 0, 1, 0, 1, 1, 0, 2, 1, 0, 0, 2, 2, 1, 1, 1, 2, 2, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 1, 2, 2, 2, 2, 2, 2, 1, 1, 0, 1, 0, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 0, 1, 2, 2, 2, 0, 0, 2, 0, 1, 2, 2, 1, 2, 0, 2, 1, 0, 0, 2, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 2, 0, 0, 1, 2, 2, 2, 2, 2, 2, 0, 2, 1, 1, 1, 1, 1, 2, 0, 2, 2, 2, 0, 2, 0, 1, 0, 1, 2, 1, 0, 1, 2, 1, 2, 1, 2, 0, 2, 0, 1, 0, 1, 2, 2, 1, 2, 2, 1, 0, 0, 1, 2, 1, 1, 0, 0, 2, 1, 0, 2, 1, 2, 0, 0, 1, 0, 2, 0, 1, 2, 2, 2, 1, 2, 0, 2, 2, 2, 2, 2, 0, 0, 0, 1, 0, 2, 0, 0, 1, 1, 0, 0, 2, 2, 1, 0, 0, 0, 2, 0, 1, 1, 1, 2, 1, 1, 2, 1, 1, 0, 1, 0, 1, 1, 1, 2, 0, 0, 2, 2, 2, 1, 1, 1, 2, 2, 2, 0, 1, 0, 0, 0, 0, 1, 0, 2, 2, 0, 2, 2, 1, 1, 1, 2, 1, 1, 1, 0, 2, 0, 2, 1, 1, 2, 2, 1, 1, 2, 0, 0, 2, 1, 2, 0, 1, 1, 1, 2, 2, 0, 1, 2, 2, 2, 1, 1, 0, 1, 0, 0, 1, 2, 1, 1, 0, 1, 0, 2, 2, 2, 0, 1, 1, 0, 1, 0, 1, 2, 2, 2, 1, 1, 0, 1, 0, 0, 2, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 1, 1, 2, 2, 1, 2, 2, 0, 2, 1, 0, 2, 1, 2, 0, 1, 2, 1, 2, 2, 2, 2, 2, 0, 0, 1, 0, 0, 2, 2, 0, 1, 0, 0, 0, 2, 1, 0, 1, 2, 1, 1, 0, 0, 1, 1, 0, 0, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, 0, 1, 1, 2, 1, 0, 0, 0, 2, 2, 1, 2, 2, 0, 0, 1, 0, 1, 0, 0, 1, 2, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 1, 2, 1, 1, 1, 2, 2, 0, 2, 1, 0, 2, 1, 0, 2, 1, 1, 0, 2, 0, 2, 1, 0, 0, 0, 1, 1, 0, 1, 0, 2, 2, 2, 1, 2, 0, 1, 2, 0, 0, 0, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 0, 1, 0, 0, 1 };
	std::cout << "? == " << smallestDistancePair(input5, 62500) << endl;
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
