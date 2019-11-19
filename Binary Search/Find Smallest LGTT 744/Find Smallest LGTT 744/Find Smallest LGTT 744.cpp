// Find Smallest LGTT 744.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
	if (letters.size() > 0) {
		if (letters[letters.size() - 1] < target) {
			return letters[0];
		}
		if (letters[0] > target) {
			return letters[0];
		}
	}
	int left = 0, right = letters.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (letters[mid] == target) {
			if (mid + 1 <= letters.size() - 1) {
				if (letters[mid + 1] == target) {
					while (letters[mid] == target) {
						mid++;
						if (mid == letters.size()) {
							return letters[0];
						}
					}
					return letters[mid];
				}
				else {
					return letters[mid + 1];
				}				
			}
			else {
				return letters[0];
			}
		}
		else if (letters[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return letters[left];
}

char nextGreatestLetterSolution(vector<char>& letters, char target) {
	auto it = upper_bound(letters.begin(), letters.end(), target);
	return it == letters.end() ? letters[0] : *it;
}

int main()
{
	vector<char> input = { 'c', 'f', 'j' };
	std::cout << "c == " << nextGreatestLetterSolution(input, 'a') << endl;
	vector<char> input1 = { 'c', 'f', 'j' };
	std::cout << "f == " << nextGreatestLetterSolution(input1, 'c') << endl;
	vector<char> input2 = { 'c', 'f', 'j' };
	std::cout << "f == " << nextGreatestLetterSolution(input2, 'd') << endl;
	vector<char> input3 = { 'c', 'f', 'j' };
	std::cout << "j == " << nextGreatestLetterSolution(input3, 'g') << endl;
	vector<char> input4 = { 'c', 'f', 'j' };
	std::cout << "c == " << nextGreatestLetterSolution(input4, 'j') << endl;
	vector<char> input5 = { 'c', 'f', 'j' };
	std::cout << "c == " << nextGreatestLetterSolution(input5, 'k') << endl;
	vector<char> input6 = { 'e','e','e','e','e','e','n','n','n','n'};
	std::cout << "n == " << nextGreatestLetterSolution(input6, 'e') << endl;
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
